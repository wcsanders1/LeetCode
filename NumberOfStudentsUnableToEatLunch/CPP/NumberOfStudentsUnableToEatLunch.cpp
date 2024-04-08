// https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description/?envType=daily-question&envId=2024-04-08
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
  int countStudents(vector<int> &students, vector<int> &sandwiches)
  {
    int n = students.size();
    stack<int> sandwichStack;
    queue<int> studentQueue;
    for (int i = 0; i < n; i++)
    {
      studentQueue.push(students[i]);
      sandwichStack.push(sandwiches[n - 1 - i]);
    }

    int reduced = INT32_MAX;
    while (studentQueue.size() < reduced)
    {
      reduced = studentQueue.size();
      int s = studentQueue.size();
      while (s-- > 0)
      {
        if (studentQueue.front() == sandwichStack.top())
        {
          sandwichStack.pop();
        }
        else
        {
          studentQueue.push(studentQueue.front());
        }
        studentQueue.pop();
      }
    }

    return studentQueue.size();
  }
};

int main()
{
  Solution solution;

  int result1 = solution.countStudents(*new vector<int>{1, 1, 0, 0}, *new vector<int>{0, 1, 0, 1});
  int result2 = solution.countStudents(*new vector<int>{1, 1, 1, 0, 0, 1}, *new vector<int>{1, 0, 0, 0, 1, 1});
}