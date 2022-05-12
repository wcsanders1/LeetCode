// https://leetcode.com/problems/largest-number/
// not mine
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
  string largestNumber(vector<int> &nums)
  {
    vector<string> strings;
    for (int i : nums)
    {
      strings.push_back(to_string(i));
    }

    sort(begin(strings), end(strings), [](string &s1, string &s2)
         { return s1 + s2 > s2 + s1; });

    string answer;
    for (string s : strings)
    {
      answer += s;
    }

    if (answer[0] == '0')
    {
      return "0";
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  string result1 = solution.largestNumber(vector<int>{10, 2});
  string result2 = solution.largestNumber(vector<int>{3, 30, 34, 5, 9});
  string result3 = solution.largestNumber(vector<int>{33, 339, 333});
  string result4 = solution.largestNumber(vector<int>{9, 90, 999});
  string result5 = solution.largestNumber(vector<int>{111311, 1113}); // 1113111311
  string result6 = solution.largestNumber(vector<int>{1311, 13});     // 131311
}