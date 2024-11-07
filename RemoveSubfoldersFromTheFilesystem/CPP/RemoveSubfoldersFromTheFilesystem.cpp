// https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/description/?envType=daily-question&envId=2024-10-25
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

struct Node
{
  string value;
  unordered_map<string, Node *> kids;
  bool end;
};

class Solution
{
public:
  vector<string> removeSubfolders(vector<string> &folder)
  {
    unordered_map<string, Node *> folders;
    for (string &f : folder)
    {
      stringstream s(f);
      queue<string> q;
      string seg;
      while (getline(s, seg, '/'))
      {
        if (seg != "")
        {
          q.push(seg);
        }
      }

      if (q.empty())
      {
        continue;
      }

      if (folders.count(q.front()) == 0)
      {
        Node *next = new Node();
        next->value = q.front();
        folders[q.front()] = next;
        q.pop();
        while (!q.empty())
        {
          Node *nextNext = new Node();
          nextNext->value = q.front();
          next->kids[q.front()] = nextNext;
          next = nextNext;
          q.pop();
        }
        next->end = true;
      }
      else
      {
        Node *current = folders[q.front()];
        q.pop();
        while (!q.empty())
        {
          if (current->kids.count(q.front()) > 0)
          {
            current = current->kids[q.front()];
          }
          else
          {
            auto next = new Node();
            next->value = q.front();
            current->kids[q.front()] = next;
            current = next;
          }
          q.pop();
        }
        current->end = true;
      }
    }
    vector<string> parents;
    getParents(parents, folders);
    return parents;
  }

private:
  void getParents(vector<string> &parents, unordered_map<string, Node *> &folders, string current = "")
  {
    for (auto &[k, v] : folders)
    {
      string next = current + "/" + k;
      if (v->end)
      {
        parents.push_back(next);
      }
      else
      {
        getParents(parents, v->kids, next);
      }
    }
  }
};

int main()
{
  Solution solution;

  auto result1 = solution.removeSubfolders(*new vector<string>{"/a", "/a/b", "/c/d", "/c/d/e", "/c/f"});
  auto result2 = solution.removeSubfolders(*new vector<string>{"/a", "/a/b/c", "/a/b/d"});
  auto result3 = solution.removeSubfolders(*new vector<string>{"/a/b/c", "a/b/ca", "/a/b/d"});
}