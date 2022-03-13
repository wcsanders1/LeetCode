#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  vector<int> largestDivisibleSubset(vector<int> &nums)
  {
    sort(nums.begin(), nums.end(), greater<>());
    unordered_map<int, vector<int>> graph;
    vector<int> greatestSubset(1, nums[0]);

    for (int i = 0; i < nums.size(); i++)
    {
      populateGraph(graph, nums, i);
    }

    for (auto it : graph)
    {
      if (it.second.size() > greatestSubset.size())
      {
        greatestSubset = it.second;
      }
    }

    return greatestSubset;
  }

private:
  void populateGraph(unordered_map<int, vector<int>> &graph, vector<int> &nums, int position)
  {
    int num = nums[position];
    vector<int> subset(1, num);
    for (int i = position + 1; i < nums.size(); i++)
    {
      if (num % nums[i] != 0)
      {
        continue;
      }

      if (graph.count(nums[i]) == 0)
      {
        populateGraph(graph, nums, i);
      }

      if (graph[nums[i]].size() + 1 > subset.size())
      {
        subset.clear();
        subset.push_back(num);
        for (int num : graph[nums[i]])
        {
          subset.push_back(num);
        }
      }
    }

    graph[num] = subset;
  }
};

int main()
{
  Solution solution;
  vector<int> result1 = solution.largestDivisibleSubset(*new vector<int>{1, 2, 3});
  vector<int> result2 = solution.largestDivisibleSubset(*new vector<int>{1, 2, 4, 8});
  vector<int> result3 = solution.largestDivisibleSubset(*new vector<int>{1, 2, 5, 8, 10});
  vector<int> result4 = solution.largestDivisibleSubset(*new vector<int>{1});
  vector<int> result5 = solution.largestDivisibleSubset(*new vector<int>{3, 17});
  vector<int> result6 = solution.largestDivisibleSubset(*new vector<int>{1, 2, 4, 8, 9, 72});
}