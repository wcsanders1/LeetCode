// https://leetcode.com/problems/intersection-of-two-arrays-ii/description/?envType=daily-question&envId=2024-07-02
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
  {
    unordered_map<int, int> count;
    auto &smaller = nums1.size() < nums2.size() ? nums1 : nums2;
    for (int &n : smaller)
    {
      count[n]++;
    }

    auto &larger = nums1.size() < nums2.size() ? nums2 : nums1;
    vector<int> answer;
    for (int &n : larger)
    {
      if (count[n] > 0)
      {
        answer.push_back(n);
        count[n]--;
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.intersect(*new vector<int>{1, 2, 2, 1}, *new vector<int>{2, 2});
  auto result2 = solution.intersect(*new vector<int>{4, 9, 5}, *new vector<int>{9, 4, 9, 8, 4});
}