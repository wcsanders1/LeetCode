// https://leetcode.com/problems/sort-array-by-increasing-frequency/
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Counter
{
  int value;
  int count;
  Counter(int v) : value(v), count(0) {}
  Counter() {}
};

struct Sorter
{
  inline bool operator()(const Counter &counter1, const Counter &counter2)
  {
    if (counter1.count == counter2.count)
    {
      return counter1.value > counter2.value;
    }

    return counter1.count < counter2.count;
  }
};

class Solution
{
public:
  vector<int> frequencySort(vector<int> &nums)
  {
    unordered_map<int, Counter> m;
    for (int n : nums)
    {
      if (m.count(n) == 0)
      {
        m[n] = Counter(n);
      }

      m[n].count++;
    }

    vector<Counter> counters;
    for (auto kv : m)
    {
      counters.push_back(kv.second);
    }

    sort(counters.begin(), counters.end(), Sorter());

    vector<int> answer;
    for (auto counter : counters)
    {
      while (counter.count-- > 0)
      {
        answer.push_back(counter.value);
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.frequencySort(*new vector<int>{1, 1, 2, 2, 2, 3});
  auto result2 = solution.frequencySort(*new vector<int>{2, 3, 1, 3, 2});
  auto result3 = solution.frequencySort(*new vector<int>{-1, 1, -6, 4, 5, -6, 1, 4, 1});
}