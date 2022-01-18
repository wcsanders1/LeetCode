#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> answer;
        vector<int> temp;

        for (int i = 0; i <= rowIndex; i++)
        {
            if (i == 0)
            {
                temp = vector<int>{1};
                answer = vector<int>{1};
            }
            else if (i == 1)
            {
                temp = vector<int>{1, 1};
                answer = vector<int>{1, 1};
            }
            else
            {
                answer = vector<int>(0, 0);
                for (int j = 0; j <= i; j++)
                {
                    if (j == 0 || j == i)
                    {
                        answer.push_back(1);
                    }
                    else
                    {
                        answer.push_back(temp[j - 1] + temp[j]);
                    }
                }
                temp = answer;
            }
        }

        return answer;
    }
};

int main()
{
    Solution solution;

    vector<int> result1 = solution.getRow(6);
    vector<int> result2 = solution.getRow(0);
    vector<int> result3 = solution.getRow(1);
}