#include <vector>

using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        auto num1Pointer = m - 1;
        auto num2Pointer = n - 1;

        for (auto i = (m + n) - 1; i >= 0; i--)
        {
            if (num1Pointer < 0)
            {
                nums1[i] = nums2[num2Pointer--];
            }
            else if (num2Pointer < 0)
            {
                nums1[i] = nums1[num1Pointer--];
            }
            else if (nums1[num1Pointer] <= nums2[num2Pointer])
            {
                nums1[i] = nums2[num2Pointer--];
            }
            else
            {
                nums1[i] = nums1[num1Pointer--];
            }
        }
    }
};

int main()
{
    Solution solution;
    solution.merge(vector<int>{1, 2, 3, 0, 0, 0}, 3, vector<int>{2, 5, 6}, 3);
}