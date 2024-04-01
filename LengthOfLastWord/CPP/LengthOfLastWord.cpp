// https://leetcode.com/problems/length-of-last-word/description/?envType=daily-question&envId=2024-04-01
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>

using namespace std;

class Solution
{
public:
  int lengthOfLastWord(string s)
  {
    int answer = 0;
    bool haveWord = false;
    for (int i = s.size() - 1; i >= 0; i--)
    {
      if (s[i] == ' ' && haveWord)
      {
        return answer;
      }

      if (s[i] != ' ')
      {
        answer++;
        haveWord = true;
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.lengthOfLastWord("Hello World");
  int result2 = solution.lengthOfLastWord("   fly me   to    the moon ");
}