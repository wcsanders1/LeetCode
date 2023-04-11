// https://leetcode.com/problems/removing-stars-from-a-string/
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <queue>
#include <numeric>
#include <stack>

using namespace std;

class Solution
{
public:
  string removeStars(string s)
  {
    stack<char> chars;

    for (char c : s)
    {
      if (c == '*')
      {
        chars.pop();
      }
      else
      {
        chars.push(c);
      }
    }

    vector<char> nonStars;
    while (!chars.empty())
    {
      nonStars.push_back(chars.top());
      chars.pop();
    }

    string answer(nonStars.begin(), nonStars.end());
    reverse(answer.begin(), answer.end());

    return answer;
  }
};

int main()
{
  Solution solution;

  string result1 = solution.removeStars("leet**cod*e");
  string result2 = solution.removeStars("erase*****");
}