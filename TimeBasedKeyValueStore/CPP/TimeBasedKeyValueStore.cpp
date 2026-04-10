// https://leetcode.com/problems/time-based-key-value-store/description/
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

class TimeMap
{
public:
  TimeMap()
  {
  }

  void set(string key, string value, int timestamp)
  {
    m[key].push_back({value, timestamp});
  }

  string get(string key, int timestamp)
  {
    if (m.find(key) == m.end())
    {
      return "";
    }
    return getVal(m[key], timestamp);
  }

private:
  unordered_map<string, vector<pair<string, int>>> m;
  string getVal(vector<pair<string, int>> &vals, int timestamp)
  {
    if (vals.size() == 0 || vals[0].second > timestamp)
    {
      return "";
    }

    int start = 0;
    int end = vals.size() - 1;
    while (start < end)
    {
      int mid = (end + start) / 2;
      if (vals[mid].second == timestamp)
      {
        return vals[mid].first;
      }

      if (vals[mid].second < timestamp)
      {
        if (mid + 1 < vals.size() && vals[mid + 1].second > timestamp)
        {
          return vals[mid].first;
        }
        start = mid + 1;
      }
      else
      {
        end = mid - 1;
      }
    }

    return vals[start].first;
  }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

int main()
{
  auto timeMap = new TimeMap();

  timeMap->set("foo", "bar", 1);
  string result1 = timeMap->get("foo", 1);
  string result2 = timeMap->get("foo", 3);
  timeMap->set("foo", "bar2", 4);
  string result3 = timeMap->get("foo", 4);
  string result4 = timeMap->get("foo", 5);

  auto timeMap2 = new TimeMap();

  timeMap2->set("love", "high", 10);
  timeMap2->set("love", "low", 20);
  string result5 = timeMap2->get("love", 5);
  string result6 = timeMap2->get("love", 10);
  string result7 = timeMap2->get("love", 15);
  string result8 = timeMap2->get("love", 20);
  string result9 = timeMap2->get("love", 25);
}