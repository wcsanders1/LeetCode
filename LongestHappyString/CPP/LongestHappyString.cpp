// https://leetcode.com/problems/longest-happy-string/description/?envType=daily-question&envId=2024-10-16
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
  string longestDiverseString(int a, int b, int c)
  {
    priority_queue<pair<int, char>> letters;
    if (a > 0)
      letters.push({a, 'a'});
    if (b > 0)
      letters.push({b, 'b'});
    if (c > 0)
      letters.push({c, 'c'});
    string answer = "";
    auto current = letters.top();
    pair<int, char> prev;
    while (!letters.empty())
    {
      pair<int, char> notUse{0, '0'};
      if (letters.top().second == prev.second)
      {
        if (prev.first == 2)
        {
          notUse = letters.top();
          letters.pop();
          if (letters.empty())
          {
            return answer;
          }
          prev = {1, letters.top().second};
        }
        else
        {
          prev.first++;
        }
      }
      else
      {
        prev = {1, letters.top().second};
      }

      if (letters.empty())
      {
        return answer;
      }

      auto current = letters.top();
      letters.pop();
      answer += current.second;
      current.first--;

      if (current.first > 0)
      {
        letters.push(current);
      }

      if (notUse.first > 0)
      {
        letters.push(notUse);
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  string result1 = solution.longestDiverseString(1, 1, 7);
  string result2 = solution.longestDiverseString(7, 1, 0);
  string result3 = solution.longestDiverseString(0, 8, 11);
}