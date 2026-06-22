// https://leetcode.com/problems/design-twitter/description/
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

struct Twt
{
  int userId;
  int index;
  int timestamp;
};

struct CompareTwt
{
  bool operator()(const Twt &a, const Twt &b) const
  {
    return a.timestamp < b.timestamp;
  }
};

class Twitter
{
public:
  Twitter()
  {
    timestamp = 1;
  }

  void postTweet(int userId, int tweetId)
  {
    userTweets[userId].push_back({tweetId, timestamp++});
  }

  vector<int> getNewsFeed(int userId)
  {
    userFollows[userId].insert(userId);
    priority_queue<Twt, vector<Twt>, CompareTwt> pq;
    for (int followedId : userFollows[userId])
    {
      auto &t = userTweets[followedId];
      int index = t.size() - 1;
      if (index < 0)
      {
        continue;
      }
      int ts = t[index].second;
      pq.push({followedId, index, ts});
    }

    vector<int> feed;
    while (feed.size() < 10 && pq.size() > 0)
    {
      auto cur = pq.top();
      pq.pop();
      feed.push_back(userTweets[cur.userId][cur.index].first);
      if (cur.index > 0)
      {
        pq.push({cur.userId, cur.index - 1, userTweets[cur.userId][cur.index - 1].second});
      }
    }

    return feed;
  }

  void follow(int followerId, int followeeId)
  {
    userFollows[followerId].insert(followeeId);
  }

  void unfollow(int followerId, int followeeId)
  {
    userFollows[followerId].erase(followeeId);
  }

private:
  int timestamp;
  unordered_map<int, vector<pair<int, int>>> userTweets;
  unordered_map<int, unordered_set<int>> userFollows;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */

int main()
{
  auto t1 = new Twitter();
  t1->postTweet(1, 5);
  auto res1 = t1->getNewsFeed(1);
  t1->follow(1, 2);
  t1->postTweet(2, 6);
  auto res2 = t1->getNewsFeed(1);
  t1->unfollow(1, 2);
  auto res3 = t1->getNewsFeed(1);
}