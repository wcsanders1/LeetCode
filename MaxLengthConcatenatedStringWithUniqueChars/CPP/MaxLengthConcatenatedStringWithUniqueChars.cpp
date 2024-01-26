// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/description/?envType=daily-question&envId=2024-01-23
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
  int maxLength(vector<string> &arr)
  {
    string s = "";
    return maxLength(arr, s, 0);
  }

private:
  int maxLength(vector<string> &arr, string &current, int index)
  {
    if (!charsAreUnique(current))
    {
      return 0;
    }

    int answer = current.size();
    for (int i = index; i < arr.size(); i++)
    {
      string t = current + arr[i];
      answer = max(answer, maxLength(arr, t, i + 1));
    }
    return answer;
  }

  bool charsAreUnique(string &s)
  {
    unordered_set<char> chars;
    for (char &c : s)
    {
      if (chars.count(c) > 0)
      {
        return false;
      }
      chars.insert(c);
    }
    return true;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.maxLength(*new vector<string>{"un", "iq", "ue"});
  int result2 = solution.maxLength(*new vector<string>{"cha", "r", "act", "ers"});
  int result3 = solution.maxLength(*new vector<string>{"abcdefghijklmnopqrstuvwxyz"});
  int result4 = solution.maxLength(*new vector<string>{"aa", "bb"});
  int result5 = solution.maxLength(*new vector<string>{"ab", "ba", "cd", "dc", "ef", "fe", "gh", "hg", "ij", "ji", "kl", "lk", "mn", "nm", "op", "po"}); // 16
  int result6 = solution.maxLength(*new vector<string>{"a", "b", "dx", "ey", "am", "bn", "abc", "def"});                                                 // 8
}