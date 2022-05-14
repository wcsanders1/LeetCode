// https://leetcode.com/problems/implement-trie-prefix-tree/
#include <string>
#include <unordered_map>

using namespace std;

class Node
{
public:
  bool isWord = false;
  char value;
  unordered_map<char, Node *> children;
  Node(char v = '\0') { value = v; }
};

class Trie
{
private:
  Node root;

public:
  Trie()
  {
    root = Node();
  }

  void insert(string word)
  {
    if (word.size() == 0)
    {
      return;
    }

    Node *current = &root;
    for (int i = 0; i < word.size(); i++)
    {
      char c = word[i];
      if (current->children.find(c) != current->children.end())
      {
        current = current->children[c];
      }
      else
      {
        Node *newNode = new Node(c);
        current->children[c] = newNode;
        current = newNode;
      }
    }
    current->isWord = true;
  }

  bool search(string word)
  {
    if (word.size() == 0)
    {
      return false;
    }

    Node *current = &root;
    for (int i = 0; i < word.size(); i++)
    {
      char c = word[i];
      if (current->children.find(c) != current->children.end())
      {
        current = current->children[c];
      }
      else
      {
        return false;
      }
    }

    return current->isWord;
  }

  bool startsWith(string prefix)
  {
    if (prefix.size() == 0)
    {
      return false;
    }

    Node *current = &root;
    for (int i = 0; i < prefix.size(); i++)
    {
      char c = prefix[i];
      if (current->children.find(c) != current->children.end())
      {
        current = current->children[c];
      }
      else
      {
        return false;
      }
    }

    return true;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main()
{
  Trie *trie = new Trie();
  trie->insert("apple");
  bool result1 = trie->search("apple");   // return True
  bool result2 = trie->search("app");     // return False
  bool result3 = trie->startsWith("app"); // return True
  trie->insert("app");
  bool result4 = trie->search("app"); // return True
}