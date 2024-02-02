// https://leetcode.com/problems/sequential-digits/description/?envType=daily-question&envId=2024-02-02
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
  vector<int> sequentialDigits(int low, int high)
  {
    vector<int> answer;
    string nums = "123456789";
    int start = 0;
    int end = 0;

    for (int i = 0; i < nums.size(); i++)
    {
      for (int j = i; j < nums.size(); j++)
      {
        int num = 0;
        for (int start = i; start <= j; start++)
        {
          num *= 10;
          num += nums[start] - '0';
        }
        if (num >= low && num <= high)
        {
          answer.push_back(num);
        }
      }
    }

    sort(answer.begin(), answer.end());

    return answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.sequentialDigits(100, 300);
  auto result2 = solution.sequentialDigits(1000, 13000);
  auto result3 = solution.sequentialDigits(10, 1000000000);
}