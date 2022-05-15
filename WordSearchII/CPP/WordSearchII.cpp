// https://leetcode.com/problems/word-search-ii/
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

struct Point
{
public:
    int x;
    int y;
    Point(int x, int y) : x(x), y(y) {}
};

class Solution
{
public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
    }

private:
    unordered_map<char, vector<Point>> *makeGraph(vector<vector<char>> &board)
    {
        auto *graph = new unordered_map<char, vector<Point>>();

        return graph;
    }
};