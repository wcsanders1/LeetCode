// https://leetcode.com/problems/merge-bsts-to-create-single-bst/
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
        vector<bool> merged(trees.size(), false);
        unordered_map<int, vector<TreeNode *>> leafMap;
        unordered_map<TreeNode *, TreeNode *> rootMap;

        mapLeaves(leafMap, trees);
        mapRoots(rootMap, trees);

        for (int i = 0; i < trees.size(); i++)
        {
            TreeNode *tree = trees[i];
            int val = tree->val;
            int max = getMax(tree);
            int min = getMin(tree);

            if (leafMap.find(val) == leafMap.end())
            {
                continue;
            }

            int removeIndex = -1;
            int diff = INT32_MAX;
            for (int j = 0; j < leafMap[val].size(); j++)
            {
                TreeNode *parent = leafMap[val][j];
                if (parent == tree)
                {
                    continue;
                }

                if (parent->left == nullptr && parent->right == nullptr)
                {
                    removeIndex = j;
                    break;
                }

                int newDiff = abs(parent->val - val);
                if (newDiff >= diff)
                {
                    continue;
                }

                if (parent->left != nullptr && parent->left->val == val)
                {
                    if (max < rootMap[parent->left]->val)
                    {
                        removeIndex = j;
                        diff = newDiff;
                    }
                }
                else if (parent->right != nullptr && parent->right->val == val)
                {
                    if (min > rootMap[parent->right]->val)
                    {
                        removeIndex = j;
                        diff = newDiff;
                    }
                }
            }

            if (removeIndex >= 0)
            {
                merged[i] = true;
                TreeNode *t = leafMap[val][removeIndex];
                leafMap[val].erase(leafMap[val].begin() + removeIndex);

                if (t->left != nullptr && t->left->val == val)
                {
                    t->left = tree;
                }
                else if (t->right != nullptr && t->right->val == val)
                {
                    t->right = tree;
                }

                if (tree->left != nullptr)
                {
                    rootMap[tree->left] = t;
                }

                if (tree->right != nullptr)
                {
                    rootMap[tree->right] = t;
                }
            }
        }

        TreeNode *answer = nullptr;
        for (int i = 0; i < merged.size(); i++)
        {
            if (!merged[i])
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

private:
    int getMax(TreeNode *tree)
    {
        if (tree->right != nullptr)
        {
            return getMax(tree->right);
        }

        return tree->val;
    }

    int getMin(TreeNode *tree)
    {
        if (tree->left != nullptr)
        {
            return getMin(tree->left);
        }

        return tree->val;
    }

    void mapRoots(unordered_map<TreeNode *, TreeNode *> &rootMap, vector<TreeNode *> &trees)
    {
        for (TreeNode *tree : trees)
        {
            if (tree->left != nullptr)
            {
                rootMap.emplace(tree->left, tree);
            }

            if (tree->right != nullptr)
            {
                rootMap.emplace(tree->right, tree);
            }
        }
    }

    void mapLeaves(unordered_map<int, vector<TreeNode *>> &leafMap, vector<TreeNode *> &trees)
    {
        for (TreeNode *tree : trees)
        {
            if (tree->left == nullptr && tree->right == nullptr)
            {
                if (leafMap.find(tree->val) == leafMap.end())
                {
                    leafMap.emplace(tree->val, vector<TreeNode *>{tree});
                }
                else
                {
                    leafMap[tree->val].push_back(tree);
                }

                continue;
            }

            if (tree->left != nullptr)
            {
                mapLeaves(leafMap, tree->left, tree);
            }

            if (tree->right != nullptr)
            {
                mapLeaves(leafMap, tree->right, tree);
            }
        }
    }

    void mapLeaves(unordered_map<int, vector<TreeNode *>> &leafMap, TreeNode *tree, TreeNode *parent)
    {
        if (tree->left == nullptr && tree->right == nullptr)
        {
            if (leafMap.find(tree->val) == leafMap.end())
            {
                leafMap.emplace(tree->val, vector<TreeNode *>{parent});
            }
            else
            {
                leafMap[tree->val].push_back(parent);
            }

            return;
        }

        if (tree->left != nullptr)
        {
            mapLeaves(leafMap, tree->left, tree);
        }

        if (tree->right != nullptr)
        {
            mapLeaves(leafMap, tree->right, tree);
        }
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
}