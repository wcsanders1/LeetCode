// https://leetcode.com/problems/shifting-letters/
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
  string shiftingLetters(string s, vector<int> &shifts)
  {
    int init = shifts[shifts.size() - 1] >= 26 ? shifts[shifts.size() - 1] % 26 : shifts[shifts.size() - 1];
    s[s.size() - 1] = getShift(s[s.size() - 1], init);
    for (int i = shifts.size() - 2; i >= 0; i--)
    {
      int t = shifts[i] + shifts[i + 1];
      shifts[i] = t >= 26 ? t % 26 : t;
      s[i] = getShift(s[i], shifts[i]);
    }

    return s;
  }

private:
  char getShift(char c, int shift)
  {
    int s = (int)c + shift;
    if (s <= (int)'z')
    {
      return s;
    }

    return (int)'a' + (s - (int)'z') - 1;
  }
};

int main()
{
  Solution solution;

  string result1 = solution.shiftingLetters("abz", *new vector<int>{3, 5, 9});
  string result2 = solution.shiftingLetters("aaa", *new vector<int>{1, 2, 3});
  string result3 = solution.shiftingLetters("z", *new vector<int>{52});
}