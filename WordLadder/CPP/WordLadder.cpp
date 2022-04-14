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

  int result1 = solution.ladderLength("hit", "cog", vector<string>{"hot", "dot", "dog", "lot", "log", "cog"});
  int result2 = solution.ladderLength("hit", "cog", vector<string>{"hot", "dot", "dog", "lot", "log"});
  int result3 = solution.ladderLength("a", "c", vector<string>{"a", "b", "c"});
}