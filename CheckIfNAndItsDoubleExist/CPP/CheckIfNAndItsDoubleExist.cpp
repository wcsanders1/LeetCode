// https://leetcode.com/problems/check-if-n-and-its-double-exist/description/?envType=daily-question&envId=2024-12-01
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
  bool checkIfExist(vector<int> &arr)
  {
    sort(arr.begin(), arr.end());
    unordered_set<int> s;
    for (int i : arr)
    {
      if (s.count(i) > 0)
      {
        return true;
      }

      if (i < 0)
      {
        if (i % 2 == 0)
        {
          s.insert(i / 2);
        }
      }
      else
      {
        s.insert(i * 2);
      }
    }

    return false;
  }
};

int main()
{
  Solution solution;

  bool result1 = solution.checkIfExist(*new vector<int>{10, 2, 5, 3});      // true
  bool result2 = solution.checkIfExist(*new vector<int>{3, 1, 7, 11});      // false
  bool result3 = solution.checkIfExist(*new vector<int>{-10, 12, -20, 15}); // true
}