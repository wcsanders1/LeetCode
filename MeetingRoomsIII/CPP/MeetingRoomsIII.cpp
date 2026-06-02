// https://leetcode.com/problems/meeting-rooms-iii/description/
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

class CompareRooms
{
public:
  bool operator()(vector<long long> &a, vector<long long> &b)
  {
    if (a[1] != b[1])
    {
      return a[1] > b[1];
    }

    return a[0] > b[0];
  }
};

class Solution
{
public:
  int mostBooked(int n, vector<vector<int>> &meetings)
  {
    sort(meetings.begin(), meetings.end());
    priority_queue<vector<long long>, vector<vector<long long>>, CompareRooms> roomsInUse;
    priority_queue<int, vector<int>, greater<int>> freeRooms;
    vector<int> roomUse(n, 0);

    for (int i = 0; i < n; i++)
    {
      freeRooms.push(i);
    }

    for (auto &meeting : meetings)
    {
      while (!roomsInUse.empty() && roomsInUse.top()[1] <= meeting[0])
      {
        auto room = roomsInUse.top();
        roomsInUse.pop();
        freeRooms.push(room[0]);
      }

      if (!freeRooms.empty())
      {
        int room = freeRooms.top();
        freeRooms.pop();
        roomUse[room]++;
        roomsInUse.push({room, meeting[1]});
      }
      else
      {
        auto room = roomsInUse.top();
        roomsInUse.pop();
        roomUse[room[0]]++;
        roomsInUse.push({room[0], meeting[1] + (room[1] - meeting[0])});
      }
    }

    int answer = 0;
    int mx = 0;
    for (int i = 0; i < roomUse.size(); i++)
    {
      if (roomUse[i] > mx)
      {
        mx = roomUse[i];
        answer = i;
      }
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.mostBooked(2, *new vector<vector<int>>{{0, 10}, {1, 5}, {2, 7}, {3, 4}});               // 0
  int result2 = solution.mostBooked(3, *new vector<vector<int>>{{1, 20}, {2, 10}, {3, 5}, {4, 9}, {6, 8}});      // 1
  int result3 = solution.mostBooked(4, *new vector<vector<int>>{{18, 19}, {3, 12}, {17, 19}, {2, 13}, {7, 10}}); // 0
}