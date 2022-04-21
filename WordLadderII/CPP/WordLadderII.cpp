// https://leetcode.com/problems/word-ladder-ii/
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
  // not mine
public:
  vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
  {
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    unordered_set<string> visited;
    vector<vector<string>> answer;
    queue<vector<string>> q;
    q.push({beginWord});

    while (!q.empty())
    {
      int qSize = q.size();
      while (qSize-- > 0)
      {
        vector<string> currentPath = q.front();
        q.pop();
        string lastWord = currentPath.back();
        for (int i = 0; i < lastWord.size(); i++)
        {
          string temp = lastWord;
          for (char c = 'a'; c <= 'z'; c++)
          {
            temp[i] = c;
            if (wordSet.find(temp) != wordSet.end())
            {
              vector<string> newPath = currentPath;
              newPath.push_back(temp);
              visited.insert(temp);
              if (temp == endWord)
              {
                answer.push_back(newPath);
              }
              else
              {
                q.push(newPath);
              }
            }
          }
        }
      }

      for (const string &s : visited)
      {
        wordSet.erase(s);
      }
      visited.clear();
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  vector<vector<string>> result1 = solution.findLadders("hit", "cog", vector<string>{"hot", "dot", "dog", "lot", "log", "cog"});
  vector<vector<string>> result2 = solution.findLadders("hit", "cog", vector<string>{"hot", "dot", "dog", "lot", "log"});
  vector<vector<string>> result3 = solution.findLadders("a", "c", vector<string>{"a", "b", "c"});
}