// https://leetcode.com/problems/word-ladder/
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList)
  {
    unordered_map<string, vector<string>> graph;
    wordList.push_back(beginWord);
    for (string word : wordList)
    {
      graph[word] = vector<string>(0);

      for (auto const &kv : graph)
      {
        string key = kv.first;
        int differences = 0;
        for (int i = 0; i < key.length(); i++)
        {
          if (key[i] != word[i])
          {
            differences++;
          }
        }

        if (differences == 1)
        {
          graph[key].push_back(word);
          graph[word].push_back(key);
        }
      }
    }

    int answer = 0;
    queue<string> q;
    unordered_set<string> visited;
    q.emplace(beginWord);
    visited.insert(beginWord);

    while (!q.empty())
    {
      answer++;
      string word = q.front();
      q.pop();

      vector<string> connections = graph[word];
      if (connections.size() == 0)
      {
        return 0;
      }

      for (string connection : connections)
      {
        if (connection == endWord)
        {
          return answer;
        }

        if (visited.find(connection) == visited.end())
        {
          visited.insert(connection);
          q.emplace(connection);
        }
      }
    }

    return 0;
  }
};

int main()
{
  Solution solution;

  int result1 = solution.ladderLength("hit", "cog", vector<string>{"hot", "dot", "dog", "lot", "log", "cog"});
  int result2 = solution.ladderLength("hit", "cog", vector<string>{"hot", "dot", "dog", "lot", "log"});
}