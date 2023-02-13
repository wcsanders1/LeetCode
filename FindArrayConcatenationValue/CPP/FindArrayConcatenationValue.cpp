#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution
{
public:
  long long findTheArrayConcVal(vector<int> &nums)
  {
    int start = 0;
    int end = nums.size() - 1;
    long long answer = 0;

    while (start <= end)
    {
      if (start == end)
      {
        string t = to_string(nums[start++]);
        answer += stoi(t);
      }
      else
      {

        string t = to_string(nums[start++]) + to_string(nums[end--]);
        answer += stoi(t);
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.findTheArrayConcVal(*new vector<int>{7, 52, 2, 4});
  auto result2 = solution.findTheArrayConcVal(*new vector<int>{5, 14, 13, 8, 12});
  auto result3 = solution.findTheArrayConcVal(*new vector<int>{5});
}