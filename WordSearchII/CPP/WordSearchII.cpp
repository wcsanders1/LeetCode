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

    bool isNextTo(Point point)
    {
        for (vector<int> move : moves)
        {
            if (row + move[0] == point.row && col + move[1] == point.col)
            {
                return true;
            }
        }

        return false;
    }

private:
    vector<vector<int>> const moves{
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
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
            vector<vector<bool>> visited(board.size(), (vector<bool>(board[0].size(), false)));
            if (findWord(*graph, word, visited))
            {
                foundWords.push_back(word);
            }
        }

        delete graph;

        return foundWords;
    }

private:
    bool findWord(unordered_map<char, vector<Point>> &graph, string &word, vector<vector<bool>> &visited)
    {
        if (graph.find(word[0]) == graph.end())
        {
            return false;
        }

        for (Point point : graph[word[0]])
        {
            visited[point.row][point.col] = true;
            string sub = word.substr(1);
            bool found = findWord(graph, sub, visited, point);
            if (found)
            {
                return true;
            }

            visited[point.row][point.col] = false;
        }

        return false;
    }

    bool findWord(unordered_map<char, vector<Point>> &graph, string &word, vector<vector<bool>> &visited, Point start)
    {
        if (word.size() == 0)
        {
            return true;
        }

        if (graph.find(word[0]) == graph.end())
        {
            return false;
        }

        for (Point point : graph[word[0]])
        {
            if (visited[point.row][point.col])
            {
                continue;
            }

            if (point.isNextTo(start))
            {
                visited[point.row][point.col] = true;
                string sub = word.substr(1);
                bool found = findWord(graph, sub, visited, point);
                if (found)
                {
                    return true;
                }
                visited[point.row][point.col] = false;
            }
        }

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
    auto result2 = solution.findWords(*new vector<vector<char>>{{'a', 'b'}, {'c', 'd'}}, *new vector<string>{"abcd"});
}