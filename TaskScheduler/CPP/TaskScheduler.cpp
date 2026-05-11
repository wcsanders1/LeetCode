// https://leetcode.com/problems/task-scheduler/description/
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int leastInterval(vector<char> &tasks, int n)
  {
    unordered_map<char, int> m;
    for (char &c : tasks)
    {
      m[c]++;
    }

    priority_queue<int> pq;
    for (auto &[_, v] : m)
    {
      pq.push(v);
    }

    int count = 0;
    while (!pq.empty())
    {
      int i = n;
      int c = 0;
      vector<int> nexts;
      while (i-- >= 0 && !pq.empty())
      {
        c++;
        int cur = pq.top();
        pq.pop();
        if (--cur > 0)
        {
          nexts.push_back(cur);
        }
      }

      count = nexts.empty() ? count + c : count + n + 1;
      for (int nxt : nexts)
      {
        pq.push(nxt);
      }
    }

    return count;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.leastInterval(*new vector<char>{'A', 'A', 'A', 'B', 'B', 'B'}, 2);           // 8
  int result2 = solution.leastInterval(*new vector<char>{'A', 'C', 'A', 'B', 'D', 'B'}, 1);           // 6
  int result3 = solution.leastInterval(*new vector<char>{'A', 'A', 'A', 'B', 'B', 'B'}, 3);           // 10
  int result4 = solution.leastInterval(*new vector<char>{'A', 'B', 'A'}, 2);                          // 4
  int result5 = solution.leastInterval(*new vector<char>{'B', 'C', 'D', 'A', 'A', 'A', 'A', 'G'}, 1); // 8
}