// https://leetcode.com/problems/arithmetic-slices/description/
#include <vector>

using namespace std;

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        if (nums.size() < 3)
        {
            return 0;
        }

        int diff = nums[0] - nums[1];
        int start = 0;
        int end = 2;
        int answer = 0;
        int t = 1;

        while (end < nums.size())
        {
            int p = 2;
            int increase = 1;
            while (end < nums.size() && nums[t] - nums[end] == diff)
            {
                if (end - start > 2)
                {
                    increase += p++;
                }
                t++;
                end++;
            }

            if (end - start > 2)
            {
                answer += increase;
            }

            start = t;
            if (end < nums.size())
            {
                diff = nums[t] - nums[end];
            }
        }

        return answer;
    }
};

int main()
{
    Solution solution;

    int result1 = solution.numberOfArithmeticSlices(*new vector<int>{1, 2, 3, 4});
    int result2 = solution.numberOfArithmeticSlices(*new vector<int>{1});
    int result3 = solution.numberOfArithmeticSlices(*new vector<int>{1, 2, 3, 4, 6, 8, 10});
    int result4 = solution.numberOfArithmeticSlices(*new vector<int>{1, 3, 5, 7, 9, 11, 12});
}
