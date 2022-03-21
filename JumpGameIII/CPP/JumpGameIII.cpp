// https://leetcode.com/problems/jump-game-iii/
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
  bool canReach(vector<int> &arr, int start)
  {
    vector<bool> visited(arr.size(), false);
    return canReach(arr, start, visited);
  }

private:
  bool canReach(vector<int> &arr, int start, vector<bool> &visited)
  {
    int jump = arr[start];
    int forward = start + jump;
    int back = start - jump;

    bool forwardReach = false;
    if (forward < arr.size() && !visited[forward])
    {
      visited[forward] = true;
      forwardReach = arr[forward] == 0 || canReach(arr, forward, visited);
    }

    bool backReach = false;
    if (back >= 0 && !visited[back])
    {
      visited[back] = true;
      backReach = arr[back] == 0 || canReach(arr, back, visited);
    }

    return forwardReach || backReach;
  }
};

int main()
{
  Solution solution;

  bool result1 = solution.canReach(vector<int>{4, 2, 3, 0, 3, 1, 2}, 5);
  bool result2 = solution.canReach(vector<int>{4, 2, 3, 0, 3, 1, 2}, 0);
  bool result3 = solution.canReach(vector<int>{3, 0, 2, 1, 2}, 2);
}