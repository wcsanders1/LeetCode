// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/?envType=daily-question&envId=2023-10-30
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
  vector<int> sortByBits(vector<int> &arr)
  {
    auto sortByOneBits = [this](const int i1, const int i2)
    {
      int b1 = getNumberOneBits(i1);
      int b2 = getNumberOneBits(i2);

      if (b1 == b2)
      {
        return i1 <= i2;
      }
      return b1 < b2;
    };

    sort(arr.begin(), arr.end(), sortByOneBits);

    return arr;
  }

private:
  int getNumberOneBits(int i)
  {
    int num = 0;
    while (i > 0)
    {
      num = (i & 1) == 1 ? num + 1 : num;
      i >>= 1;
    }

    return num;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.sortByBits(*new vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8});
  auto result2 = solution.sortByBits(*new vector<int>{1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1});
}