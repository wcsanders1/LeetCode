// https://leetcode.com/problems/design-browser-history/
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

class BrowserHistory
{
public:
  BrowserHistory(string homepage)
  {
    visited.push_back(homepage);
    position = 0;
  }

  void visit(string url)
  {
    if (position < visited.size() - 1)
    {
      visited.erase(visited.begin() + position + 1, visited.end());
    }
    visited.push_back(url);
    position = visited.size() - 1;
  }

  string back(int steps)
  {
    int p = position - steps;
    position = p < 0 ? 0 : p;
    return visited[position];
  }

  string forward(int steps)
  {
    int p = position + steps;
    position = p >= visited.size() ? visited.size() - 1 : p;
    return visited[position];
  }

private:
  vector<string> visited;
  int position;
};

int main()
{
  BrowserHistory *bh = new BrowserHistory("leetcode.com");

  bh->visit("google.com");
  bh->visit("facebook.com");
  bh->visit("youtube.com");
  auto result1 = bh->back(1);
  auto result2 = bh->back(1);
  auto result3 = bh->forward(1);
  bh->visit("linkedin.com");
  auto result4 = bh->forward(2);
  auto result5 = bh->back(2);
  auto result6 = bh->back(7);
}