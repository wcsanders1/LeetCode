// https://leetcode.com/problems/determine-if-string-halves-are-alike/description/?envType=daily-question&envId=2024-01-12
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution
{
public:
  bool halvesAreAlike(string s)
  {
    int a = 0;
    int b = 0;
    int n = s.size();
    int h = n / 2;

    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

    for (int i = 0; i < n; i++)
    {
      if (vowels.count(s[i]) > 0)
      {
        if (i < h)
        {
          a++;
        }
        else
        {
          b++;
        }
      }
    }

    return a == b;
  }
};

int main()
{
  Solution solution;

  bool result1 = solution.halvesAreAlike("book");
  bool result2 = solution.halvesAreAlike("textbook");
}