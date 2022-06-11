// https://leetcode.com/problems/maximum-average-pass-ratio/
#include <vector>
#include <queue>
#include <functional>

using namespace std;

struct Tracker
{
    pair<double, double> *value;
    int index;
    Tracker(vector<int> *v, int i)
    {
        value = new pair<double, double>((double)(*v)[0], (double)(*v)[1]);
        index = i;
    }

    Tracker(pair<double, double> *p, int i)
    {
        value = p;
        index = i;
    }
};

bool compare(Tracker *tOne, Tracker *tTwo)
{
    pair<double, double> one = *(tOne->value);
    pair<double, double> two = *(tTwo->value);
    double x1 = (double)((double)one.first + 1) / (double)((double)one.second + 1);
    double x2 = (double)((double)one.first) / (double)((double)one.second);
    double y1 = (double)((double)two.first + 1) / (double)((double)two.second + 1);
    double y2 = (double)((double)two.first) / (double)((double)two.second);

    double diff1 = x1 - x2;
    double diff2 = y1 - y2;

    return diff1 < diff2;
}

class Solution
{
public:
    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
    {
        priority_queue<Tracker *, vector<Tracker *>, function<bool(Tracker *, Tracker *)>> heap(compare);
        for (int i = 0; i < classes.size(); i++)
        {
            heap.push(new Tracker(&classes[i], i));
        }

        for (int i = 0; i < extraStudents; i++)
        {
            Tracker *t = heap.top();
            pair<double, double> c = *t->value;
            heap.pop();
            t->value->first++;
            t->value->second++;
            classes[t->index][0]++;
            classes[t->index][1]++;
            heap.push(t);
        }

        double answer = 0;
        for (vector<int> c : classes)
        {
            answer += ((double)c[0] / (double)c[1]);
        }

        return answer / classes.size();
    }
};

int main()
{
    Solution solution;

    double result1 = solution.maxAverageRatio(*new vector<vector<int>>{vector<int>{1, 2}, vector<int>{3, 5}, vector<int>{2, 2}}, 2);
    double result2 = solution.maxAverageRatio(*new vector<vector<int>>{vector<int>{2, 4}, vector<int>{3, 9}, vector<int>{4, 5}, vector<int>{2, 10}}, 4);
}