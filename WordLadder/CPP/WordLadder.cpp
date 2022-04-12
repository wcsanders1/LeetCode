// https://leetcode.com/problems/word-ladder/
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList)
  {
    unordered_map<string, vector<string>> graph;
    for (string word : wordList)
    {
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
        }
      }

      if (graph.count(word) == 0)
      {
        graph[word] = vector<string>(0);
      }
    }

    for (auto const &kv : graph)
    {
      string key = kv.first;
    }
  }
};