// https://leetcode.com/problems/closest-room/
#include <vector>
#include <unordered_map>
#include <algorithm>

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
    unordered_map<int, RoomSize> sizeMap;
    for (vector<int> room : rooms)
    {
      int id = room[0];
      int size = room[1];
      if (sizeMap.count(size) == 0)
      {
        sizeMap[size] = RoomSize(size);
      }
      sizeMap[size].idsThisSize.push_back(id);
    }

    vector<RoomSize> sizes;
    vector<int> ids;
    for (auto kv : sizeMap)
    {
      for (int id : kv.second.idsThisSize)
      {
        ids.push_back(id);
      }
      sizes.push_back(kv.second);
    }

    sort(ids.begin(), ids.end());
    sort(sizes.begin(), sizes.end(), SizeSorter());

    sizes[0].idsAtLeastThisSize = ids;
    for (int i = 1; i < sizes.size(); i++)
    {
      RoomSize prev = sizes[i - 1];
      vector<int> v = vector<int>(prev.idsAtLeastThisSize.begin(), prev.idsAtLeastThisSize.end());
      for (int id : prev.idsThisSize)
      {
        int index = getIndex(v, id, 0, v.size() - 1);
        v.erase(v.begin() + index);
      }

      sizes[i].idsAtLeastThisSize = v;
    }

    vector<int> answer = vector(queries.size(), -1);
    for (int i = 0; i < queries.size(); i++)
    {
      vector<int> q = queries[i];
      int bestId = q[0];
      int minSize = q[1];

      int sizeIndex = getIndex(sizes, minSize, 0, sizes.size() - 1);
      if (sizeIndex == -1)
      {
        continue;
      }

      if (sizes[sizeIndex].size < minSize)
      {
        continue;
      }

      int idIndex = getIndex(sizes[sizeIndex].idsAtLeastThisSize, bestId, 0, sizes[sizeIndex].idsAtLeastThisSize.size() - 1);
      if (idIndex == -1)
      {
        continue;
      }

      answer[i] = sizes[sizeIndex].idsAtLeastThisSize[idIndex];
    }

    return answer;
  }

private:
  int getIndex(vector<int> &ints, int value, int start, int end)
  {
    if (start > end)
    {
      return -1;
    }

    if (start == end)
    {
      return start;
    }

    int mid = (start + end) / 2;
    int v = ints[mid];
    if (v == value)
    {
      return mid;
    }

    if (v > value)
    {
      return getIndex(ints, value, start, mid - 1);
    }

    return getIndex(ints, value, mid + 1, end);
  }

  int getIndex(vector<RoomSize> &sizes, int value, int start, int end)
  {
    if (start > end)
    {
      return -1;
    }

    if (start == end)
    {
      return start;
    }

    int mid = (start + end) / 2;
    RoomSize v = sizes[mid];
    if (v.size == value)
    {
      return mid;
    }

    if (v.size > value)
    {
      return getIndex(sizes, value, start, mid - 1);
    }

    return getIndex(sizes, value, mid + 1, end);
  }
};

int main()
{
  Solution solution;

  // auto result1 = solution.closestRoom(*new vector<vector<int>>{{2, 2}, {1, 2}, {3, 2}}, *new vector<vector<int>>{{3, 1}, {3, 3}, {5, 2}});
  auto result2 = solution.closestRoom(*new vector<vector<int>>{{1, 4}, {2, 3}, {3, 5}, {4, 1}, {5, 2}}, *new vector<vector<int>>{{2, 3}, {2, 4}, {2, 5}});
}