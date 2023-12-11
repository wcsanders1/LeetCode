// https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/?envType=daily-question&envId=2023-12-11
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <set>

using namespace std;

class Solution
{
public:
  int findSpecialInteger(vector<int> &arr)
  {
    int answer = arr[0];
    int count = 1;
    int greatest = 1;
    for (int i = 1; i < arr.size(); i++)
    {
      if (arr[i] == arr[i - 1])
      {
        count++;
      }
      else
      {
        count = 1;
      }

      if (count > greatest)
      {
        greatest = count;
        answer = arr[i];
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.findSpecialInteger(*new vector<int>{1, 2, 2, 6, 6, 6, 6, 7, 10});
  int result2 = solution.findSpecialInteger(*new vector<int>{1, 1});
}