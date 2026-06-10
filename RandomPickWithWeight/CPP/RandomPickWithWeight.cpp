// https://leetcode.com/problems/random-pick-with-weight/description/
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <random>

using namespace std;

class Solution
{
public:
  Solution(vector<int> &w)
  {
    weights.push_back(w[0]);
    for (int i = 1; i < w.size(); i++)
    {
      weights.push_back(w[i] + weights[i - 1]);
    }

    random_device rd;
    gen = mt19937(rd());
    distrib = uniform_int_distribution<int>(1, weights[weights.size() - 1]);
  }

  int pickIndex()
  {
    int nxt = distrib(gen);
    int begin = 0;
    int end = weights.size() - 1;
    while (begin < end)
    {
      int mid = (end + begin) / 2;
      if (weights[mid] > nxt)
      {
        if (mid == 0 || weights[mid - 1] < nxt)
        {
          return mid;
        }

        end = mid - 1;
      }
      else if (weights[mid] == nxt)
      {
        return mid;
      }
      else
      {
        begin = mid + 1;
      }
    }

    return begin;
  }

private:
  vector<int> weights;
  mt19937 gen;
  uniform_int_distribution<int> distrib;
};

int main()
{
  auto obj1 = new Solution(*new vector<int>{1});
  int result1 = obj1->pickIndex();

  auto obj2 = new Solution(*new vector<int>{1, 3});
  int result2 = obj2->pickIndex();
  int result3 = obj2->pickIndex();
  int result4 = obj2->pickIndex();
  int result5 = obj2->pickIndex();

  auto obj3 = new Solution(*new vector<int>{3, 14, 1, 7});
  int result6 = obj3->pickIndex();
  int result7 = obj3->pickIndex();
  int result8 = obj3->pickIndex();
  int result9 = obj3->pickIndex();

  auto obj4 = new Solution(*new vector<int>{5, 1, 9, 4, 1});
  int result10 = obj4->pickIndex();
  int result11 = obj4->pickIndex();
  int result12 = obj4->pickIndex();
  int result13 = obj4->pickIndex();
}