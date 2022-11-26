// https://leetcode.com/problems/duplicate-zeros/
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
  void duplicateZeros(vector<int> &arr)
  {
    vector<int> n(arr.size(), 0);
    int i = 0;
    int j = 0;
    while (i < arr.size())
    {
      if (arr[j] == 0)
      {
        i += 2;
        j++;
      }
      else
      {
        n[i++] = arr[j++];
      }
    }

    arr = n;
  }
};

int main()
{
  Solution solution;

  solution.duplicateZeros(*new vector<int>{1, 0, 2, 3, 0, 4, 5, 0});
  solution.duplicateZeros(*new vector<int>{1, 2, 3});
  solution.duplicateZeros(*new vector<int>{1, 0, 0, 3, 4, 6, 7});
  solution.duplicateZeros(*new vector<int>{0, 0, 0, 0, 0, 0, 0});
  solution.duplicateZeros(*new vector<int>{0, 1, 7, 6, 0, 2, 0, 7});
}