// https://leetcode.com/problems/minimize-deviation-in-array/
// NOT MINE: https://leetcode.com/problems/minimize-deviation-in-array/solutions/955262/c-intuitions-and-flip/?orderBy=most_votes
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <queue>

using namespace std;

class Solution
{
public:
  int minimumDeviation(vector<int> &nums)
  {
    priority_queue<int> q;
    int least = INT32_MAX;
    for (int n : nums)
    {
      if (n % 2 == 1)
      {
        n *= 2;
      }
      q.push(n);
      least = min(least, n);
    }

    int deviation = INT32_MAX;
    while (q.top() % 2 == 0)
    {
      deviation = min(deviation, q.top() - least);
      least = min(least, q.top() / 2);
      q.push(q.top() / 2);
      q.pop();
    }

    return min(deviation, q.top() - least);
  }
};

int main()
{
  Solution solution;

  int result1 = solution.minimumDeviation(*new vector<int>{1, 2, 3, 4});
  int result2 = solution.minimumDeviation(*new vector<int>{4, 1, 5, 20, 3});
  int result3 = solution.minimumDeviation(*new vector<int>{2, 10, 8});
  int result4 = solution.minimumDeviation(*new vector<int>{3, 5});                                             // 1
  int result5 = solution.minimumDeviation(*new vector<int>{10, 4, 3});                                         // 2
  int result6 = solution.minimumDeviation(*new vector<int>{8, 1, 2, 1});                                       // 0
  int result7 = solution.minimumDeviation(*new vector<int>{399, 908, 648, 357, 693, 502, 331, 649, 596, 698}); // 315
}