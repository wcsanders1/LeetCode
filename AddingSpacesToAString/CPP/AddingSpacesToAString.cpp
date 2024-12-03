// https://leetcode.com/problems/adding-spaces-to-a-string/description/?envType=daily-question&envId=2024-12-03
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
  string addSpaces(string s, vector<int> &spaces)
  {
    string answer = "";
    int index = 0;
    int spaceSize = spaces.size();
    for (int i = 0; i < s.size(); i++)
    {
      if (index < spaceSize && spaces[index] == i)
      {
        answer += " ";
        index++;
      }
      answer += s[i];
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  string result1 = solution.addSpaces("LeetcodeHelpsMeLearn", *new vector<int>{8, 13, 15});
  string result2 = solution.addSpaces("icodeinpython", *new vector<int>{1, 5, 7, 9});
  string result3 = solution.addSpaces("spacing", *new vector<int>{0, 1, 2, 3, 4, 5, 6});
}