// https://leetcode.com/problems/largest-number/
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Trie
{
public:
  int amount = 0;
  unordered_map<int, Trie *> children;
};

class Solution
{
public:
  string largestNumber(vector<int> &nums)
  {
    Trie root;
    for (int num : nums)
    {
      vector<int> *digits = getDigits(num);
      Trie *tempNode = &root;
      for (int i = digits->size() - 1; i >= 0; i--)
      {
        int digit = (*digits)[i];
        if (tempNode->children.find(digit) == tempNode->children.end())
        {
          Trie *newNode = new Trie;
          tempNode->children[digit] = newNode;
          tempNode = newNode;
        }
        else
        {
          tempNode = tempNode->children[digit];
        }

        tempNode->amount++;
      }
    }

    string answer = "";
    for (int i = 9; i >= 0; i--)
    {
      if (root.children.find(i) != root.children.end())
      {
        bool singleUsed = false;
        while (root.children[i]->amount > 0)
        {
          if (useSingle(root.children[i], i) && !singleUsed)
          {
            singleUsed = true;
            root.children[i]->amount--;
            answer += to_string(i);
            continue;
          }

          root.children[i]->amount--;
          answer += to_string(i);
          buildLongestNumber(answer, root.children[i]);
        }
      }
    }

    return answer;
  }

private:
  bool useSingle(Trie *node, int current)
  {
    for (int i = 9; i >= 0; i--)
    {
      if (i > current && node->children.find(i) != node->children.end() && node->children[i]->amount > 0)
      {
        return false;
      }

      if (i <= current && node->children.find(i) != node->children.end() && node->children[i]->amount < node->amount)
      {
        return true;
      }
    }

    return false;
  }

  vector<int> *getDigits(int num)
  {
    vector<int> *digits = new vector<int>(0);
    while (num >= 10)
    {
      int rem = num % 10;
      digits->push_back(rem);
      num /= 10;
    }

    digits->push_back(num);
    return digits;
  }

  void buildLongestNumber(string &longest, Trie *node)
  {
    for (int i = 9; i >= 0; i--)
    {
      if (node->children.find(i) != node->children.end())
      {
        if (node->children[i]->amount > 0)
        {
          node->children[i]->amount--;
          longest += to_string(i);
          buildLongestNumber(longest, node->children[i]);
          break;
        }
      }
    }
  }
};

int main()
{
  Solution solution;

  // string result1 = solution.largestNumber(vector<int>{10, 2});
  // string result2 = solution.largestNumber(vector<int>{3, 30, 34, 5, 9});
  // string result3 = solution.largestNumber(vector<int>{33, 339, 333});
  // string result4 = solution.largestNumber(vector<int>{9, 90, 999});
  string result5 = solution.largestNumber(vector<int>{111311, 1113}); // 1113111311
}