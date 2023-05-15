// https://leetcode.com/problems/number-of-senior-citizens/
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
  int countSeniors(vector<string> &details)
  {
    int answer = 0;

    for (string &d : details)
    {
      if (d[11] > '6' || (d[11] == '6' && d[12] > '0'))
      {
        answer++;
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.countSeniors(*new vector<string>{"7868190130M7522", "5303914400F9211", "9273338290F4010"});
  int result2 = solution.countSeniors(*new vector<string>{"1313579440F2036", "2921522980M5644"});
}