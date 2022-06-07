// https://leetcode.com/problems/removing-minimum-number-of-magic-beans/
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  long long minimumRemoval(vector<int> &beans)
  {
    if (beans.size() < 2)
    {
      return 0;
    }

    sort(beans.begin(), beans.end());
    vector<long long> makeZero(beans.size(), 0);
    makeZero[0] = beans[0];
    for (int i = 1; i < beans.size(); i++)
    {
      makeZero[i] = makeZero[i - 1] + beans[i];
    }

    long long answer = makeZero[beans.size() - 2];
    int counter = 0;
    long long priorDiff = 0;
    for (int i = beans.size() - 2; i >= 0; i--)
    {
      long long tempDiff = beans[i + 1] - beans[i];
      long long prior = tempDiff * counter++;
      long long diff = prior + priorDiff + tempDiff;
      long long toZero = i > 0 ? makeZero[i - 1] : 0;
      answer = min(answer, diff + toZero);
      priorDiff = diff;
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  long long result1 = solution.minimumRemoval(*new vector<int>{4, 1, 6, 5});
  long long result2 = solution.minimumRemoval(*new vector<int>{2, 10, 3, 2});
}