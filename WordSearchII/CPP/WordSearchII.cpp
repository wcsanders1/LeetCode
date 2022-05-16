// https://leetcode.com/problems/word-search-ii/
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

struct Point
{
public:
    int row;
    int col;
    Point(int row, int col) : row(row), col(col) {}
};

class Solution
{
public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        auto graph = makeGraph(board);
        vector<string> foundWords;
        for (string word : words)
        {
            if (findWord(*graph, word))
            {
                foundWords.push_back(word);
            }
        }

        delete graph;

        return foundWords;
    }

private:
    bool findWord(unordered_map<char, vector<Point>> &graph, string &word)
    {
        return false;
    }

    bool findWord(unordered_map<char, vector<Point>> &graph, string &word, vector<vector<bool>> &visited, Point start)
    {
        return false;
    }

    unordered_map<char, vector<Point>> *makeGraph(vector<vector<char>> &board)
    {
        auto *graph = new unordered_map<char, vector<Point>>();
        for (int row = 0; row < board.size(); row++)
        {
            for (int col = 0; col < board[0].size(); col++)
            {
                char c = board[row][col];
                if (graph->find(c) == graph->end())
                {
                    (*graph)[c] = vector<Point>();
                }

                (*graph)[c].push_back(Point(row, col));
            }
        }

        return graph;
    }
};

int main()
{
    Solution solution;

    auto result1 = solution.findWords(*new vector<vector<char>>{{'o', 'a', 'a', 'n'}, {'e', 't', 'a', 'e'}, {'i', 'h', 'k', 'r'}, {'i', 'f', 'l', 'v'}},
                                      *new vector<string>{"oath", "pea", "eat", "rain"});
}