// https://leetcode.com/problems/merge-bsts-to-create-single-bst/
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *canMerge(vector<TreeNode *> &trees)
    {
        vector<bool> merged(trees.size(), false);

        TreeNode *answer = nullptr;
        for (int i = 0; i < merged.size(); i++)
        {
            if (merged[i])
            {
                if (answer != nullptr)
                {
                    return nullptr;
                }

                answer = trees[i];
            }
        }

        return answer;
    }
};