// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
#include <unordered_set>
#include <string>
#include <algorithm>
#include <queue>
#include <numeric>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
  {
    int greatest = 0;
    for (int c : candies)
    {
      greatest = max(greatest, c);
    }

    vector<bool> answer;
    for (int c : candies)
    {
      answer.push_back(c + extraCandies >= greatest);
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.kidsWithCandies(*new vector<int>{2, 3, 5, 1, 3}, 3);
  auto result2 = solution.kidsWithCandies(*new vector<int>{4, 2, 1, 1, 2}, 1);
  auto result3 = solution.kidsWithCandies(*new vector<int>{12, 1, 12}, 10);
}