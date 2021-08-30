#include <vector>

using namespace std;

class Solution
{
public:
  int findCircleNum(vector<vector<int>> &isConnected)
  {
    vector<bool> *visited = new vector<bool>(isConnected.size(), false);
    int provinces = 0;

    for (int outter = 0; outter < isConnected.size(); outter++)
    {
      if ((*visited)[outter])
      {
        continue;
      }

      provinces++;
      markVisited(*visited, isConnected, outter);

      vector<int> group = isConnected[outter];
      for (int inner = 0; inner < group.size(); inner++)
      {
        if (outter == inner || (*visited)[inner] || !isConnected[inner][outter])
        {
          continue;
        }

        markVisited(*visited, isConnected, inner);
      }
    }

    delete visited;

    return provinces;
  }

private:
  void markVisited(vector<bool> &visited, vector<vector<int>> &isConnected, int province)
  {
    visited[province] = true;
    for (int i = 0; i < isConnected[province].size(); i++)
    {
      if (isConnected[province][i] && !visited[i])
      {
        markVisited(visited, isConnected, i);
      }
    }
  }
};

int main()
{
  Solution solution;
  int result1 = solution.findCircleNum(*new vector<vector<int>>{vector<int>{1, 1, 0}, vector<int>{1, 1, 0}, vector<int>{0, 0, 1}});
  int result2 = solution.findCircleNum(*new vector<vector<int>>{vector<int>{1, 0, 0}, vector<int>{0, 1, 0}, vector<int>{0, 0, 1}});
}