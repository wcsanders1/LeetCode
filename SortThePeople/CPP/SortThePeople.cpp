// https://leetcode.com/problems/sort-the-people/description/?envType=daily-question&envId=2024-07-22
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
  vector<string> sortPeople(vector<string> &names, vector<int> &heights)
  {
    int n = heights.size();
    vector<vector<int>> indexes;
    for (int i = 0; i < n; i++)
    {
      indexes.push_back({heights[i], i});
    }

    sort(indexes.begin(), indexes.end(), greater<vector<int>>());
    vector<string> answer;
    for (auto &index : indexes)
    {
      answer.push_back(names[index[1]]);
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.sortPeople(*new vector<string>{"Mary", "John", "Emma"}, *new vector<int>{180, 165, 170});
  auto result2 = solution.sortPeople(*new vector<string>{"Alice", "Bob", "Bob"}, *new vector<int>{155, 185, 150});
}