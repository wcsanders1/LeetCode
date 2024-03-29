#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        if (s3.length() != s1.length() + s2.length())
        {
            return false;
        }

        bool **table = new bool *[s1.length() + 1];
        for (int i = 0; i < s1.length() + 1; i++)
        {
            table[i] = new bool[s2.length() + 1];
        }

        for (int i = 0; i < s1.length() + 1; i++)
            for (int j = 0; j < s2.length() + 1; j++)
            {
                if (i == 0 && j == 0)
                    table[i][j] = true;
                else if (i == 0)
                    table[i][j] = (table[i][j - 1] && s2[j - 1] == s3[j - 1]);
                else if (j == 0)
                    table[i][j] = (table[i - 1][j] && s1[i - 1] == s3[i - 1]);
                else
                    table[i][j] = (table[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (table[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }

        bool result = table[s1.length()][s2.length()];

        for (int i = 0; i < s1.length() + 1; i++)
        {
            delete[] table[i];
        }
        delete[] table;

        return result;
    }
};

int main()
{
    Solution solution;
    bool result1 = solution.isInterleave("aabcc", "dbbca", "aadbbcbcac"); // true
    bool result2 = solution.isInterleave("aabcc", "dbbca", "aadbbbaccc"); // false
    bool result3 = solution.isInterleave("", "", "");                     // true
    bool result4 = solution.isInterleave("a", "b", "a");                  // false
}