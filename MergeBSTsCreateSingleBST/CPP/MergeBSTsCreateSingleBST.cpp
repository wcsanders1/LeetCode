// https://leetcode.com/problems/merge-bsts-to-create-single-bst/
// not mine
#include <vector>
#include <unordered_map>
#include <cmath>
#include <stdint.h>

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
        unordered_map<int, TreeNode *> m;
        unordered_map<int, int> cnt;
        for (auto &t : trees)
        {
            m[t->val] = t;
            ++cnt[t->val];
            ++cnt[t->left ? t->left->val : 0];
            ++cnt[t->right ? t->right->val : 0];
        }
        for (auto &t : trees)
            if (cnt[t->val] == 1)
                return traverse(t, m) && m.size() == 1 ? t : nullptr;
        return nullptr;
    }

private:
    bool traverse(TreeNode *r, unordered_map<int, TreeNode *> &m, int min_left = INT_MIN, int max_right = INT_MAX)
    {
        if (r == nullptr)
            return true;
        if (r->val <= min_left || r->val >= max_right)
            return false;
        if (r->left == r->right)
        {
            auto it = m.find(r->val);
            if (it != end(m) && r != it->second)
            {
                r->left = it->second->left;
                r->right = it->second->right;
                m.erase(it);
            }
        }
        return traverse(r->left, m, min_left, r->val) && traverse(r->right, m, r->val, max_right);
    }
};

int main()
{
    Solution solution;

    TreeNode *node1_1 = new TreeNode(2, new TreeNode(1), nullptr);
    TreeNode *node2_1 = new TreeNode(3, new TreeNode(2), new TreeNode(5));
    TreeNode *node3_1 = new TreeNode(5, new TreeNode(4), nullptr);
    TreeNode *result1 = solution.canMerge(*new vector<TreeNode *>{node1_1, node2_1, node3_1});

    TreeNode *node1_2 = new TreeNode(5, new TreeNode(3), new TreeNode(8));
    TreeNode *node2_2 = new TreeNode(3, new TreeNode(2), new TreeNode(6));
    TreeNode *result2 = solution.canMerge(*new vector<TreeNode *>{node1_2, node2_2});

    TreeNode *node1_3 = new TreeNode(5, new TreeNode(4), nullptr);
    TreeNode *node2_3 = new TreeNode(3);
    TreeNode *result3 = solution.canMerge(*new vector<TreeNode *>{node1_3, node2_3});

    TreeNode *node1_4 = new TreeNode(1, nullptr, new TreeNode(2));
    TreeNode *node2_4 = new TreeNode(3, new TreeNode(1), nullptr);
    TreeNode *node3_4 = new TreeNode(2, nullptr, new TreeNode(3));
    TreeNode *result4 = solution.canMerge(*new vector<TreeNode *>{node1_4, node2_4, node3_4});

    TreeNode *node1_5 = new TreeNode(4, new TreeNode(1), nullptr);
    TreeNode *node2_5 = new TreeNode(1, nullptr, new TreeNode(2));
    TreeNode *node3_5 = new TreeNode(2, nullptr, new TreeNode(3));
    TreeNode *result5 = solution.canMerge(*new vector<TreeNode *>{node1_5, node2_5, node3_5});

    TreeNode *node1_6 = new TreeNode(3, new TreeNode(1), nullptr);
    TreeNode *node2_6 = new TreeNode(1, nullptr, new TreeNode(2));
    TreeNode *node3_6 = new TreeNode(2, new TreeNode(1), nullptr);
    TreeNode *result6 = solution.canMerge(*new vector<TreeNode *>{node1_6, node2_6, node3_6});
}