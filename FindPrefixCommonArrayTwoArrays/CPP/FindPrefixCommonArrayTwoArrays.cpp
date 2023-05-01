// https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <numeric>

using namespace std;

class Solution
{
public:
  vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
  {
    unordered_set<int> aset;
    unordered_set<int> bset;
    vector<int> answer;
    int n = A.size();

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
      aset.insert(A[i]);
      bset.insert(B[i]);

      if (A[i] == B[i])
      {
        sum++;
        answer.push_back(sum);
        continue;
      }

      if (aset.count(B[i]) == 1)
      {
        sum++;
      }

      if (bset.count(A[i]) == 1)
      {
        sum++;
      }

      answer.push_back(sum);
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.findThePrefixCommonArray(*new vector<int>{1, 3, 2, 4}, *new vector<int>{3, 1, 2, 4});
  auto result2 = solution.findThePrefixCommonArray(*new vector<int>{2, 3, 1}, *new vector<int>{3, 1, 2});
}