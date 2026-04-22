// https://leetcode.com/problems/top-k-frequent-words/description/
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

class Sorter
{
public:
  bool operator()(pair<string, int> p1, pair<string, int> p2)
  {
    if (p1.second == p2.second)
    {
      return p1.first > p2.first;
    }

    return p1.second < p2.second;
  }
};

class Solution
{
public:
  vector<string> topKFrequent(vector<string> &words, int k)
  {
    priority_queue<pair<string, int>, vector<pair<string, int>>, Sorter> pq;
    unordered_map<string, int> m;
    for (string &w : words)
    {
      m[w]++;
    }

    for (auto &[k, v] : m)
    {
      pq.push({k, v});
    }

    vector<string> answer;
    while (k-- > 0)
    {
      answer.push_back(pq.top().first);
      pq.pop();
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.topKFrequent(*new vector<string>{"i", "love", "leetcode", "i", "love", "coding"}, 2);
  auto result2 = solution.topKFrequent(*new vector<string>{"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"}, 4);
}