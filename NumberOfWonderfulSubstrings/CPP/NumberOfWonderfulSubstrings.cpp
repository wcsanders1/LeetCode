// https://leetcode.com/problems/number-of-wonderful-substrings/description/?envType=daily-question&envId=2024-04-30
// NOT MINE: https://leetcode.com/problems/number-of-wonderful-substrings/solutions/1299525/count-bitmasks-with-picture/?envType=daily-question&envId=2024-04-30
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  long long wonderfulSubstrings(string word)
  {
    unordered_map<int, long long> masks;
    masks[0]++;
    int current = 0;
    long long answer = 0;

    for (int i = 0; i < word.size(); i++)
    {
      current ^= 1 << (word[i] - 'a');
      answer += masks[current];

      for (int j = 0; j <= 'j' - 'a'; j++)
      {
        answer += masks[current ^ (1 << j)];
      }

      masks[current]++;
    }

    return answer;
  }
};

int main()
{
  Solution solution;

  long long result1 = solution.wonderfulSubstrings("aba");               // 4
  long long result2 = solution.wonderfulSubstrings("aabb");              // 9
  long long result3 = solution.wonderfulSubstrings("he");                // 2
  long long result4 = solution.wonderfulSubstrings("ehaehcjjaafjdceac"); // 29
}