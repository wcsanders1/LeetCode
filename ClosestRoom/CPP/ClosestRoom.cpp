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
};

class SizeSorter
{
public:
  bool operator()(RoomSize s1, RoomSize s2)
  {
    return s1.size > s2.size;
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
      ids.push_back(kv.first);
      sizes.push_back(kv.second);
    }

    sort(ids.begin(), ids.end());
    sort(sizes.begin(), sizes.end(), SizeSorter());

    sizes[0].idsAtLeastThisSize = ids;
  }

private:
  int getIndex(vector<int> &ints, int value)
  {
  }
};