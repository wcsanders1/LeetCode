// https://leetcode.com/problems/largest-number/
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Trie
{
public:
  bool isValue = false;
  unordered_map<string, Trie> children;
};

class Solution
{
public:
  string largestNumber(vector<int> &nums)
  {
    Trie root;
    for (int num : nums)
    {
      vector<string> *digits = getDigits(num);
      Trie tempNode = root;
      for (int i = digits->size() - 1; i >= 0; i--)
      {
        string digit = (*digits)[i];
        if (tempNode.children.find(digit) == tempNode.children.end())
        {
          Trie newNode;
          tempNode.children[digit] = newNode;
          tempNode = newNode;
        }
        else
        {
          tempNode = tempNode.children[digit];
        }

        if (i == 0)
        {
          tempNode.isValue = true;
        }
      }
    }
  }

private:
  vector<string> *getDigits(int num)
  {
    vector<string> *digits = new vector<string>(0);
    while (num > 10)
    {
      int rem = num % 10;
      digits->push_back(to_string(rem));
      num /= 10;
    }

    digits->push_back(to_string(num));
    return digits;
  }
};