#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int coin : coins)
        {
            for (int i = coin; i <= amount; i++)
            {
                dp[i] += dp[i - coin];
            }
        }

        return dp[amount];
    }
};

int main()
{
    Solution solution;
    int result1 = solution.change(5, *new vector<int>{1, 2, 5});
    int result2 = solution.change(3, *new vector<int>{2});
    int result3 = solution.change(10, *new vector<int>{10});
}