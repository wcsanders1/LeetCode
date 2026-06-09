// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
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
  vector<string> letterCombinations(string digits)
  {
    vector<string> combinations;
    getCombinations(digits, combinations);
    return combinations;
  }

private:
  unordered_map<char, string> letters =
      {
          {'2', "abc"},
          {'3', "def"},
          {'4', "ghi"},
          {'5', "jkl"},
          {'6', "mno"},
          {'7', "pqrs"},
          {'8', "tuv"},
          {'9', "wxyz"}};

  void getCombinations(string &digits, vector<string> &combinations, string current = "")
  {
    if (current.size() == digits.size())
    {
      combinations.push_back(current);
      return;
    }

    for (char &c : letters[digits[current.size()]])
    {
      getCombinations(digits, combinations, current + c);
    }
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.letterCombinations("23");
  auto result2 = solution.letterCombinations("2");
}