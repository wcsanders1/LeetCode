// https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/description/?envType=daily-question&envId=2024-08-06
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
  int minimumPushes(string word)
  {
    vector<pair<int, char>> count(26);
    for (char &c : word)
    {
      int i = 'z' - c;
      count[i].second = c;
      count[i].first++;
    }

    sort(count.begin(), count.end(), greater<>());

    int answer = 0;
    for (int i = 0; i < count.size(); i++)
    {
      int offset = (i / 8) + 1;
      answer += count[i].first * offset;
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minimumPushes("abcde");
  int result2 = solution.minimumPushes("xyzxyzxyzxyz");
  int result3 = solution.minimumPushes("aabbccddeeffgghhiiiiii");
}