#include <set>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  bool isItPossible(string word1, string word2)
  {
    unordered_map<char, int> count1;
    unordered_map<char, int> count2;

    for (char i = 'a'; i <= 'z'; i++)
    {
      count1[i] = 0;
      count2[i] = 0;
    }

    for (char c : word1)
    {
      count1[c]++;
    }

    for (char c : word2)
    {
      count2[c]++;
    }

    for (auto &m1 : count1)
    {
      if (m1.second == 0)
      {
        continue;
      }

      count1[m1.first]--;
      for (auto &m2 : count2)
      {
        if (m2.second == 0)
        {
          continue;
        }

        count2[m2.first]--;
        count2[m1.first]++;
        count1[m2.first]++;

        int d1 = getDistinctCount(count1);
        int d2 = getDistinctCount(count2);
        if (d1 == d2)
        {
          return true;
        }

        count2[m2.first]++;
        count2[m1.first]--;
        count1[m2.first]--;
      }

      count1[m1.first]++;
    }

    return false;
  }

private:
  int getDistinctCount(unordered_map<char, int> &m)
  {
    int c = 0;
    for (auto &e : m)
    {
      c += e.second > 0 ? 1 : 0;
    }

    return c;
  }
};

int main()
{
  Solution solution;

  bool result1 = solution.isItPossible("ac", "b");
  bool result2 = solution.isItPossible("abcc", "aab"); // true
  bool result3 = solution.isItPossible("abcde", "fghij");
  bool result4 = solution.isItPossible("ab", "abcc"); // false
  bool result5 = solution.isItPossible("a", "bb");
  bool result6 = solution.isItPossible("aa", "bcd");
  bool result7 = solution.isItPossible("a", "bb"); // false
}