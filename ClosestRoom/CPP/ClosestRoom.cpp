// https://leetcode.com/problems/closest-room/
// NOT MINE: https://leetcode.com/problems/closest-room/discuss/1186023/C%2B%2BJava-Sort-Queries
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct RoomSize
{
  int size;
  vector<int> idsAtLeastThisSize;
  vector<int> idsThisSize;

  RoomSize(int s)
  {
    size = s;
  }

  RoomSize() {}
};

class SizeSorter
{
public:
  bool operator()(RoomSize s1, RoomSize s2)
  {
    return s1.size < s2.size;
  }
};

class Solution
{
public:
  vector<int> closestRoom(vector<vector<int>> &rooms, vector<vector<int>> &queries)
  {
    auto by_size_desc = [](const auto &a, const auto &b)
    { return a[1] > b[1]; };
    vector<int> res(queries.size());
    for (int i = 0; i < queries.size(); ++i)
      queries[i].push_back(i);
    sort(begin(rooms), end(rooms), by_size_desc);
    sort(begin(queries), end(queries), by_size_desc);
    set<int> ids;
    for (int i = 0, j = 0; i < queries.size(); ++i)
    {
      for (; j < rooms.size() && rooms[j][1] >= queries[i][1]; ++j)
        ids.insert(rooms[j][0]);
      auto it = ids.lower_bound(queries[i][0]);
      int id1 = it == begin(ids) ? -1 : *(prev(it));
      int id2 = it == end(ids) ? -1 : *it;
      res[queries[i][2]] = min(id1, id2) == -1 ? max(id1, id2) : abs(queries[i][0] - id1) <= abs(queries[i][0] - id2) ? id1
                                                                                                                      : id2;
    }
    return res;
  }
};

int main()
{
  Solution solution;

  // auto result1 = solution.closestRoom(*new vector<vector<int>>{{2, 2}, {1, 2}, {3, 2}}, *new vector<vector<int>>{{3, 1}, {3, 3}, {5, 2}});
  // auto result2 = solution.closestRoom(*new vector<vector<int>>{{1, 4}, {2, 3}, {3, 5}, {4, 1}, {5, 2}}, *new vector<vector<int>>{{2, 3}, {2, 4}, {2, 5}});
  auto result3 = solution.closestRoom(*new vector<vector<int>>{{23, 22}, {6, 20}, {15, 6}, {22, 19}, {2, 10}, {21, 4}, {10, 18}, {16, 1}, {12, 7}, {5, 22}},
                                      *new vector<vector<int>>{{12, 5}, {15, 15}, {21, 6}, {15, 1}, {23, 4}, {15, 11}, {1, 24}, {3, 19}, {25, 8}, {18, 6}});
}