// https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/description/
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

class Solution
{
public:
  bool isValidSerialization(string preorder)
  {
    vector<string> nums;
    stringstream ss(preorder);
    string segment;
    while (getline(ss, segment, ','))
    {
      nums.push_back(segment);
    }

    return isValid(nums, 0) == (nums.size() - 1);
  }

private:
  int isValid(vector<string> &preorder, int index)
  {
    if (index >= preorder.size())
    {
      return -1;
    }

    if (preorder[index] == "#")
    {
      return index;
    }

    int left = isValid(preorder, index + 1);
    if (left == -1)
    {
      return -1;
    }

    return isValid(preorder, left + 1);
  }
};

int main()
{
  Solution solution;

  bool result1 = solution.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#");
  bool result2 = solution.isValidSerialization("1,#");
  bool result3 = solution.isValidSerialization("9,#,#,1");
}