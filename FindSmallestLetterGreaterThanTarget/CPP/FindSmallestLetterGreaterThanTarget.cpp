// https://leetcode.com/problems/find-smallest-letter-greater-than-target/
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution
{
public:
  char nextGreatestLetter(vector<char> &letters, char target)
  {
    int n = letters.size();
    int index = getIndex(letters, target, 0, n - 1);

    if (letters[index] > target)
    {
      return letters[index];
    }

    while (letters[index] <= target && ++index < n)
    {
      if (letters[index] > target)
      {
        return letters[index];
      }
    }

    return letters[0];
  }

private:
  int getIndex(vector<char> &letters, char target, int start, int end)
  {
    if (start == end)
    {
      return start;
    }

    int mid = (start + end) / 2;
    if (letters[mid] == target)
    {
      return mid;
    }

    if (letters[mid] > target)
    {
      return getIndex(letters, target, start, mid);
    }

    return getIndex(letters, target, mid + 1, end);
  }
};

int main()
{
  Solution solution;

  char result1 = solution.nextGreatestLetter(*new vector<char>{'c', 'f', 'j'}, 'a');
  char result2 = solution.nextGreatestLetter(*new vector<char>{'c', 'f', 'j'}, 'c');
  char result3 = solution.nextGreatestLetter(*new vector<char>{'x', 'x', 'y', 'y'}, 'z');
  char result4 = solution.nextGreatestLetter(*new vector<char>{'c', 'f', 'j'}, 'd');
}