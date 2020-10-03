#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &A)
    {
        int position = 0;
        int size = A.size();
        vector<int> result(size);

        for (int i = 0; i < size; i++)
        {
            int num = A[i];
            if (num < 0 && i < size - 1 && num * -1 > A[i + 1])
            {
                int subPosition = getPosition(0, size - 1, num * -1, A) - i;
                result[subPosition] = num * num;
            }
            else
            {
                while (result[position] != 0)
                {
                    position++;
                }

                result[position++] = num * num;
            }
        }

        return result;
    }

private:
    int getPosition(int start, int end, int num, vector<int> &nums)
    {
        if (start >= end)
        {
            return start;
        }

        int mid = (end + start) / 2;

        if (nums[mid] == num)
        {
            return mid;
        }

        if (mid > 0 && mid < nums.size() - 1)
        {
            if (nums[mid - 1] < num && nums[mid] > num)
            {
                return mid - 1;
            }

            if (nums[mid - 1] < num && nums[mid + 1] > num)
            {
                return mid;
            }
        }

        if (nums[mid] > num)
        {
            return getPosition(start, mid, num, nums);
        }

        return getPosition(mid + 1, end, num, nums);
    }
};

int main()
{
    Solution solution;
    vector<int> resultOne = solution.sortedSquares(vector<int>{-4, -1, 0, 3, 10});
    vector<int> resultTwo = solution.sortedSquares(vector<int>{-7, -3, 2, 3, 11});
    vector<int> resultThree = solution.sortedSquares(vector<int>{-11, -9, -8, -7, -3, 2, 3, 11});
    vector<int> resultFour = solution.sortedSquares(vector<int>{-1, 2, 2});
    vector<int> resultFive = solution.sortedSquares(vector<int>{1, 2, 3});
    vector<int> resultSix = solution.sortedSquares(vector<int>{-5, -3, -1, 2});
    vector<int> resultSeven = solution.sortedSquares(vector<int>{-5, -3, -1});
    vector<int> resultEight = solution.sortedSquares(vector<int>{-9, -7, -5, -3, -1, 2, 4, 4, 7, 10});
    vector<int> resultNine = solution.sortedSquares(vector<int>{-9, -7, -5, -5, -5, 2, 4, 4, 4, 10});
}