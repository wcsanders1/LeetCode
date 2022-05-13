// https://leetcode.com/problems/isomorphic-strings/
#include <unordered_map>
#include <string>

using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.size() != t.size())
        {
            return false;
        }

        unordered_map<char, char> sMap;
        unordered_map<char, char> tMap;

        for (int i = 0; i < s.size(); i++)
        {
            if (sMap.find(s[i]) == sMap.end())
            {
                sMap[s[i]] = t[i];
            }

            if (tMap.find(t[i]) == tMap.end())
            {
                tMap[t[i]] = s[i];
            }

            if (sMap[s[i]] != t[i] || tMap[t[i]] != s[i])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution solution;

    bool result1 = solution.isIsomorphic("egg", "add");
    bool result2 = solution.isIsomorphic("foo", "bar");
    bool result3 = solution.isIsomorphic("paper", "title");
    bool result4 = solution.isIsomorphic("badc", "baba");
}