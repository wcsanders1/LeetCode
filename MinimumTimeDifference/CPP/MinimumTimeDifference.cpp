// https://leetcode.com/problems/minimum-time-difference/description/?envType=daily-question&envId=2024-09-16
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
  int findMinDifference(vector<string> &timePoints)
  {
    int n = timePoints.size();
    vector<int> minutes;
    for (string &tp : timePoints)
    {
      int m = (stoi(tp.substr(0, 2)) * 60) + stoi(tp.substr(3, 2));
      minutes.push_back(m);
    }

    sort(minutes.begin(), minutes.end());
    int answer = ((60 * 24) - minutes[n - 1]) + minutes[0];
    for (int i = 1; i < n; i++)
    {
      answer = min(answer, (minutes[i] - minutes[i - 1]));
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.findMinDifference(*new vector<string>{"23:59", "00:00"});
  int result2 = solution.findMinDifference(*new vector<string>{"00:00", "23:59", "00:00"});
}