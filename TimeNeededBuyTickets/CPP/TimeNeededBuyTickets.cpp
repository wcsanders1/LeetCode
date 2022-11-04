// https://leetcode.com/problems/time-needed-to-buy-tickets/
#include <vector>

using namespace std;

class Solution
{
public:
  int timeRequiredToBuy(vector<int> &tickets, int k)
  {
    int answer = 0;
    int num = tickets[k];
    for (int i = 0; i < tickets.size(); i++)
    {
      int t = tickets[i];
      answer += min(t, num);
      if (i > k && t >= num)
      {
        answer--;
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.timeRequiredToBuy(*new vector<int>{2, 3, 2}, 2);                      // 6
  int result2 = solution.timeRequiredToBuy(*new vector<int>{5, 1, 1, 1}, 0);                   // 8
  int result3 = solution.timeRequiredToBuy(*new vector<int>{84, 49, 5, 24, 70, 77, 87, 8}, 3); // 154
}