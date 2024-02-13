// https://leetcode.com/problems/find-first-palindromic-string-in-the-array/description/?envType=daily-question&envId=2024-02-13
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
  string firstPalindrome(vector<string> &words)
  {
    for (string &w : words)
    {
      int start = 0;
      int end = w.size() - 1;

      while (start < end)
      {
        if (w[start] != w[end])
        {
          break;
        }

        start++;
        end--;
      }

      if (start >= end)
      {
        return w;
      }
    }

    return "";
  }
};

int main()
{
  Solution solution;

  string result1 = solution.firstPalindrome(*new vector<string>{"abc", "car", "abba", "ada", "racecar", "cool"});
  string result2 = solution.firstPalindrome(*new vector<string>{"notapalendrome", "racecar"});
  string result3 = solution.firstPalindrome(*new vector<string>{"def", "ghi"});
}