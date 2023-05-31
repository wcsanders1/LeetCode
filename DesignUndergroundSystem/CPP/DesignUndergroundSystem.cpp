#include <vector>
#include <unordered_set>
#include <queue>
#include <unordered_map>

using namespace std;

class UndergroundSystem
{
public:
  UndergroundSystem()
  {
  }

  void checkIn(int id, string stationName, int t)
  {
    travelers[id] = {stationName, t};
  }

  void checkOut(int id, string stationName, int t)
  {
    auto &[startStation, startTime] = travelers[id];
    int totalTime = t - startTime;
    if (times.count(startStation + "-" + stationName) == 0)
    {
      times[startStation + "-" + stationName] = {totalTime, 1};
    }
    else
    {
      auto &[existingTime, traveled] = times[startStation + "-" + stationName];
      times[startStation + "-" + stationName] = {existingTime + totalTime, traveled + 1};
    }
  }

  double getAverageTime(string startStation, string endStation)
  {
    auto &[totalTime, traveled] = times[startStation + "-" + endStation];
    return (double)totalTime / (double)traveled;
  }

private:
  unordered_map<string, pair<long long, long long>> times;
  unordered_map<int, pair<string, int>> travelers;
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
