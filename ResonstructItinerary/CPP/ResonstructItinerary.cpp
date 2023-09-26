// https://leetcode.com/problems/reconstruct-itinerary/?envType=daily-question&envId=2023-09-14
// NOT MINE: https://leetcode.com/problems/reconstruct-itinerary/solutions/78768/short-ruby-python-java-c/?envType=daily-question&envId=2023-09-14
#include <vector>
#include <unordered_set>
#include <queue>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution
{
public:
  vector<string> findItinerary(vector<vector<string>> &tickets)
  {
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> m;
    for (auto &t : tickets)
    {
      string depart = t[0];
      string arrive = t[1];
      if (m.count(depart) == 0)
      {
        m[depart] = priority_queue<string, vector<string>, greater<string>>();
      }
      m[depart].push(arrive);
    }

    vector<string> answer;
    findItinerary(m, "JFK", answer);

    reverse(answer.begin(), answer.end());

    return answer;
  }

private:
  void findItinerary(unordered_map<string, priority_queue<string, vector<string>, greater<string>>> &m, string current, vector<string> &flights)
  {
    while (!m[current].empty())
    {
      string next = m[current].top();
      m[current].pop();
      findItinerary(m, next, flights);
    }
    flights.push_back(current);
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.findItinerary(*new vector<vector<string>>{{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}});
  auto result2 = solution.findItinerary(*new vector<vector<string>>{{"JFK", "SFO"}, {"JFK", "ATL"}, {"SFO", "ATL"}, {"ATL", "JFK"}, {"ATL", "SFO"}});
  auto result3 = solution.findItinerary(*new vector<vector<string>>{{"JFK", "KUL"}, {"JFK", "NRT"}, {"NRT", "JFK"}});
}