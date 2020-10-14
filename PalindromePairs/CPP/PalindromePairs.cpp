#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

class Trie
{
public:
    void TryAddChild(char &c)
    {
        map<char, Trie *>::iterator it = children.find(c);
        if (it == children.end())
        {
            Trie *newTrie = new Trie();
            children[c] = newTrie;
        }
    }

    Trie *TryGetChild(char &c)
    {
        map<char, Trie *>::iterator it = children.find(c);
        if (it == children.end())
        {
            return nullptr;
        }

        return children[c];
    }

    void AddPalindrome(int p)
    {
        palindromes.push_back(p);
    }

    vector<int> *GetPalindromes(int exclude)
    {
        return Filter(palindromes, exclude);
    }

    vector<int> *GetEmpties(int exclude)
    {
        return Filter(empties, exclude);
    }

    void AddEmpty(int i)
    {
        empties.push_back(i);
    }

    vector<int> *GetFullPalindromes(int exclude)
    {
        return Filter(fullPalindromes, exclude);
    }

    void AddFullPalindrome(int i)
    {
        fullPalindromes.push_back(i);
    }

    vector<int> *GetPartialPalindromes(int exclude)
    {
        return Filter(partialPalindromes, exclude);
    }

    void AddPartialPalindrome(int i)
    {
        partialPalindromes.push_back(i);
    }

private:
    vector<int> palindromes;
    map<char, Trie *> children;
    vector<int> empties;
    vector<int> fullPalindromes;
    vector<int> partialPalindromes;

    vector<int> *Filter(vector<int> &source, int exclude)
    {
        vector<int> *filtered = new vector<int>();

        for (int i : source)
        {
            if (i != exclude)
            {
                filtered->push_back(i);
            }
        }

        return filtered;
    }
};

class Solution
{
public:
    vector<vector<int>> palindromePairs(vector<string> &words)
    {
        vector<vector<int>> result;

        if (words.empty())
        {
            return result;
        }

        Trie *trie = BuildTree(words);

        int index = 0;
        vector<string>::iterator it;
        for (it = words.begin(); it != words.end(); it++, index++)
        {
            Trie *node = trie;
            string *word = &(words[index]);
            int lastIndex = word->size() - 1;
            set<int> indeces;

            if (word->size() == 0)
            {
                vector<int> *fullPalindromes = trie->GetFullPalindromes(index);
                if (fullPalindromes->size() > 0)
                {
                    for (int fp : *fullPalindromes)
                    {
                        result.push_back(vector<int>{index, fp});
                    }
                }

                vector<int> *empties = trie->GetEmpties(index);
                if (empties->size() > 0)
                {
                    for (int e : *empties)
                    {
                        result.push_back(vector<int>{index, e});
                    }
                }
            }

            if (IsPalindrome(*word, 0, lastIndex))
            {
                vector<int> *empties = trie->GetEmpties(index);
                if (empties->size() > 0)
                {
                    for (int e : *empties)
                    {
                        result.push_back(vector<int>{index, e});
                    }
                }
            }

            for (int i = 0; i < word->size(); i++)
            {
                Trie *nextNode = node->TryGetChild((*word)[i]);
                if (nextNode)
                {
                    if (i == lastIndex)
                    {
                        vector<int> *palindromes = nextNode->GetPalindromes(index);
                        vector<int> *partials = nextNode->GetPartialPalindromes(index);
                        palindromes->insert(palindromes->end(), partials->begin(), partials->end());
                        if (palindromes->size() > 0)
                        {
                            for (int p : *palindromes)
                            {
                                if (!indeces.count(p))
                                {
                                    result.push_back(vector<int>{index, p});
                                    indeces.insert(p);
                                }
                            }
                        }
                    }
                    else if (IsPalindrome(*word, i + 1, lastIndex))
                    {
                        vector<int> *palindromes = nextNode->GetPalindromes(index);
                        if (palindromes->size() > 0)
                        {
                            for (int p : *palindromes)
                            {
                                if (!indeces.count(p))
                                {
                                    result.push_back(vector<int>{index, p});
                                    indeces.insert(p);
                                }
                            }
                        }
                    }

                    node = nextNode;
                }
                else
                {
                    if (IsPalindrome(*word, i, lastIndex))
                    {
                        vector<int> *palindromes = node->GetPalindromes(index);
                        if (palindromes->size() > 0)
                        {
                            for (int p : *palindromes)
                            {
                                if (!indeces.count(p))
                                {
                                    result.push_back(vector<int>{index, p});
                                    indeces.insert(p);
                                }
                            }
                        }
                    }

                    break;
                }
            }
        }

        return result;
    }

private:
    bool IsPalindrome(string &word, int start, int end)
    {
        if (start >= end || (start == end - 1 && word[start] == word[end]))
        {
            return true;
        }

        if (word[start] != word[end])
        {
            return false;
        }

        return IsPalindrome(word, start + 1, end - 1);
    }

    Trie *BuildTree(vector<string> &words)
    {
        Trie *trie = new Trie();

        vector<string>::iterator it;
        int index = 0;

        for (it = words.begin(); it != words.end(); it++, index++)
        {
            string *word = &(words[index]);

            if (word->size() == 0)
            {
                trie->AddEmpty(index);
                continue;
            }

            if (IsPalindrome(*word, 0, word->size() - 1))
            {
                trie->AddFullPalindrome(index);
            }

            Trie *child = trie;
            for (int i = word->size() - 1; i >= 0; i--)
            {
                char c = (*word)[i];
                child->TryAddChild(c);
                Trie *newChild = child->TryGetChild(c);
                child = newChild;

                if (i > 0 && IsPalindrome(*word, 0, i - 1))
                {
                    child->AddPartialPalindrome(index);
                }
            }

            child->AddPalindrome(index);
        }

        return trie;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> resultOne = solution.palindromePairs(vector<string>{"abcd", "dcba", "lls", "s", "sssll"});
    vector<vector<int>> resultTwo = solution.palindromePairs(vector<string>{"bat", "tab", "cat"});
    vector<vector<int>> resultThree = solution.palindromePairs(vector<string>{"a", ""});
    vector<vector<int>> resultFour = solution.palindromePairs(vector<string>{"a", "abc", "aba", ""});           //[0,3][3,0][2,3][3,2]
    vector<vector<int>> resultFive = solution.palindromePairs(vector<string>{"a", "b", "c", "ab", "ac", "aa"}); //[3,0][1,3][4,0][2,4][5,0][0,5]
}