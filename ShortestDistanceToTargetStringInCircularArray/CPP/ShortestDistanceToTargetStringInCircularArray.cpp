// https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/description/?envType=daily-question&envId=2026-04-15
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
  int closestTarget(vector<string> &words, string target, int startIndex)
  {
    int distance = INT32_MAX;
    int n = words.size();
    for (int i = 0; i < n; i++)
    {
      if (words[i] == target)
      {
        int d1 = abs(startIndex - i);
        int d2 = startIndex > i
                     ? (n - startIndex) + i
                     : startIndex + (n - i);
        distance = min(distance, min(d1, d2));
      }
    }

    return distance == INT32_MAX ? -1 : distance;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.closestTarget(*new vector<string>{"hello", "i", "am", "leetcode", "hello"}, "hello", 1);
  int result2 = solution.closestTarget(*new vector<string>{"a", "b", "leetcode"}, "leetcode", 0);
  int result3 = solution.closestTarget(*new vector<string>{"i", "eat", "leetcode"}, "ate", 0);
}