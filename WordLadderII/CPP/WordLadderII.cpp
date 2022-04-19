// https://leetcode.com/problems/word-ladder-ii/
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
  vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
  {
    unordered_map<string, vector<string>> *graph = getGraph(beginWord, endWord, wordList);
    int shortestLength = getShortestLength(beginWord, endWord, *graph);
    if (shortestLength == 0)
    {
      return vector<vector<string>>(0);
    }

    unordered_set<string> visited;
    vector<vector<string>> paths;
    getPaths(beginWord, endWord, *graph, visited, paths, shortestLength);

    return paths;
  }

private:
  bool getPaths(string beginWord, string endWord, unordered_map<string, vector<string>> &graph, unordered_set<string> &visited, vector<vector<string>> &paths, int maxLevel, int level = 0)
  {
    if (level == maxLevel)
    {
      if (beginWord == endWord)
      {
        paths.push_back(vector<string>{endWord});
        return true;
      }
      return false;
    }

    bool pathExists = false;
    for (string connection : graph[beginWord])
    {
      if (visited.find(connection) == visited.end())
      {
        visited.insert(connection);
        if (getPaths(connection, endWord, graph, visited, paths, maxLevel, level + 1))
        {
          pathExists = true;
          for (vector<string> &path : paths)
          {
            path.insert(path.begin(), beginWord);
          }
        }

        visited.erase(connection);
      }
    }

    return pathExists;
  }

  unordered_map<string, vector<string>> *getGraph(string beginWord, string endWord, vector<string> &wordList)
  {
    unordered_map<string, vector<string>> *graph = new unordered_map<string, vector<string>>();
    wordList.push_back(beginWord);
    for (string word : wordList)
    {
      (*graph)[word] = vector<string>(0);

      for (auto const &kv : *graph)
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
          (*graph)[key].push_back(word);
          (*graph)[word].push_back(key);
        }
      }
    }

    return graph;
  }

  int getShortestLength(string beginWord, string endWord, unordered_map<string, vector<string>> &graph)
  {
    int answer = 1;
    queue<string> q;
    unordered_set<string> visited;
    q.emplace(beginWord);
    visited.insert(beginWord);

    while (!q.empty())
    {
      int qSize = q.size();
      for (int i = 0; i < qSize; i++)
      {
        string word = q.front();
        q.pop();

        if (word == endWord)
        {
          return answer;
        }

        for (string connection : graph[word])
        {
          if (visited.find(connection) == visited.end())
          {
            visited.insert(connection);
            q.emplace(connection);
          }
        }
      }

      answer++;
    }

    return 0;
  }
};

int main()
{
  Solution solution;

  vector<vector<string>> result1 = solution.findLadders("hit", "cog", vector<string>{"hot", "dot", "dog", "lot", "log", "cog"});
  vector<vector<string>> result2 = solution.findLadders("hit", "cog", vector<string>{"hot", "dot", "dog", "lot", "log"});
  vector<vector<string>> result3 = solution.findLadders("a", "c", vector<string>{"a", "b", "c"});
}