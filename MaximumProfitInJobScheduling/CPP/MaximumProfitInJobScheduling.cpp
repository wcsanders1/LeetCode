// https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/?envType=daily-question&envId=2024-01-06
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

struct Job
{
  int startTime;
  int endTime;
  int profit;
};

class Solution
{
public:
  int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
  {
    int n = startTime.size();
    vector<Job> jobs;
    for (int i = 0; i < n; i++)
    {
      Job job;
      job.startTime = startTime[i];
      job.endTime = endTime[i];
      job.profit = profit[i];
      jobs.push_back(job);
    }

    auto sortByStartTime = [](const Job &j1, const Job &j2)
    {
      return j1.startTime < j2.startTime;
    };

    sort(jobs.begin(), jobs.end(), sortByStartTime);

    vector<int> p(n, 0);
    p[n - 1] = jobs[n - 1].profit;
    for (int i = n - 2; i >= 0; i--)
    {
      auto job = jobs[i];
      int nextClosestIndex = getIndexOfClosestStartTime(job.endTime, jobs, i, n - 1);
      int nextClosest = 0;
      if (nextClosestIndex > -1)
      {
        nextClosest = job.profit + p[nextClosestIndex];
      }

      int currentProfit = job.profit;
      if (currentProfit < p[i + 1])
      {
        currentProfit = max(nextClosest, p[i + 1]);
      }

      p[i] = max(currentProfit, nextClosest);
    }

    return p[0];
  }

private:
  int getIndexOfClosestStartTime(int endTime, vector<Job> &jobs, int start, int end)
  {
    if (end < start)
    {
      return -1;
    }

    int mid = (start + end) / 2;
    if (jobs[mid].startTime < endTime)
    {
      return getIndexOfClosestStartTime(endTime, jobs, mid + 1, end);
    }

    if (jobs[mid].startTime == endTime)
    {
      // while (--mid >= 0)
      // {
      //   if (jobs[mid].startTime < endTime)
      //   {
      //     return mid + 1;
      //   }
      // }
      return mid;
    }

    int index = getIndexOfClosestStartTime(endTime, jobs, start, mid - 1);
    return index > -1 ? index : mid;
  }
};

int main()
{
  Solution solution;

  // int result1 = solution.jobScheduling(*new vector<int>{1, 2, 3, 3}, *new vector<int>{3, 4, 5, 6}, *new vector<int>{50, 10, 40, 70});             // 120
  // int result2 = solution.jobScheduling(*new vector<int>{1, 2, 3, 4, 6}, *new vector<int>{3, 5, 10, 6, 9}, *new vector<int>{20, 20, 100, 70, 60}); // 150
  // int result3 = solution.jobScheduling(*new vector<int>{1, 1, 1}, *new vector<int>{2, 3, 4}, *new vector<int>{5, 6, 4});
  int result4 = solution.jobScheduling(*new vector<int>{4, 2, 4, 8, 2}, *new vector<int>{5, 5, 5, 10, 8}, *new vector<int>{1, 2, 8, 10, 4}); // 18
}