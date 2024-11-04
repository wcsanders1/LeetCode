// https://leetcode.com/problems/string-compression-iii/description/?envType=daily-question&envId=2024-11-04
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  string compressedString(string word)
  {
    string comp = "";
    int start = 0;
    int end = 1;
    while (start < word.size())
    {
      while (word[start] == word[end] && end - start < 9)
      {
        end++;
      }

      comp += to_string(end - start) + word[start];
      start = end;
      end++;
    }

    return comp;
  }
};

int main()
{
  Solution solution;

  string result1 = solution.compressedString("abcde");
  string result2 = solution.compressedString("aaaaaaaaaaaaaabb");
  string result3 = solution.compressedString("a");
}