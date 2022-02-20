class Solution
{
public:
  int integerBreak(int n)
  {
    if (n == 2)
      return 1;
    if (n == 3)
      return 2;
    if (n == 4)
      return 4;
    if (n == 5)
      return 6;

    int answer = 6;
    int next = 2;
    int last = 2;

    for (int i = 6; i <= n; i++)
    {
      int y = answer / last;
      if (next == 4)
      {
        next = 2;
        answer = y * 6;
        last = 2;
      }
      else
      {
        answer = y * ++next;
        last = next;
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;
  int result1 = solution.integerBreak(5);
  int result2 = solution.integerBreak(6);
  int result3 = solution.integerBreak(7);
  int result4 = solution.integerBreak(8);
  int result5 = solution.integerBreak(9);
  int result6 = solution.integerBreak(10);
  int result7 = solution.integerBreak(11);
  int result8 = solution.integerBreak(12);
  int result9 = solution.integerBreak(13);
  int result10 = solution.integerBreak(14);
}

// 2: 1 x 1              = 1
// 3: 2 x 1              = 2
// 4: 2 x 2              = 4
// 5: 3 x 2              = 6
// 6: 3 x 3              = 9
// 7: 4 x 3 OR 2 x 2 x 3 = 12
// 8: 3 x 3 x 2          = 18
// 9: 3 x 3 x 3          = 27
// 10: 3 x 3 x 4         = 36
// 11: 3 x 3 x 3 x 2     = 54
// 12: 3 x 3 x 3 x 3     = 81
// 13: 3 x 3 x 3 x 4     = 108
// 14: 3 x 3 x 3 x 3 x 2 = 162