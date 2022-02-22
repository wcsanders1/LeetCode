// not mine
#include <vector>

using namespace std;

class Solution
{
public:
    int maxCoins(vector<int> &nums)
    {
        int size = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(size + 2, vector<int>(size + 2, 0));

        for (int length = 1; length <= size; length++)
        {
            for (int left = 1; left < size - length + 2; left++)
            {
                int right = left + length - 1;
                for (int last = left; last < right + 1; last++)
                {
                    dp[left][right] = max(dp[left][right],
                                          dp[left][last - 1] + nums[left - 1] * nums[last] * nums[right + 1] + dp[last + 1][right]);
                }
            }
        }

        return dp[1][size];
    }
};

int main()
{
    Solution solution;
    int result1 = solution.maxCoins(vector<int>({3, 1, 5, 8}));
}