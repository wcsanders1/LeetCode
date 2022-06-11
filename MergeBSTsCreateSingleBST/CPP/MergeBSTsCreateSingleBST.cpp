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

        mapLeaves(leafMap, trees);

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
                    if (max < parent->val)
                    {
                        removeIndex = j;
                        diff = newDiff;
                    }
                }
                else if (parent->right != nullptr && parent->right->val == val)
                {
                    if (min > parent->val)
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
                    t->right == tree;
                }
            }
        }

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
                leafMap.emplace(tree->val, vector<TreeNode *>{tree});
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