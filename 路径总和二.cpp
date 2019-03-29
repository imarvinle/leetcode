//
// Created by marvinle on 2019/3/25 8:16 AM.
//
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Solution {
public:
    // all, dfs
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int>> result;
        vector<int> curv;
        if (root == nullptr)
            return result;
        dfs(result, curv, root, 0, sum);
        return result;
    }

    void dfs(vector<vector<int>> &result, vector<int> curv, TreeNode *root, int cur, int sum) {
        if (root->left == nullptr && root->right == nullptr) {
            if (cur + root->val == sum) {
                curv.push_back(root->val);
                result.push_back(curv);
            }
            return;
        }
        if (root->left) {
            vector<int> temp = curv;
            temp.push_back(root->val);
            dfs(result, temp, root->left, cur + root->val, sum);
        }
        if (root->right) {
            vector<int> temp = curv;
            temp.push_back(root->val);
            dfs(result, temp, root->right, cur + root->val, sum);
        }
    }
};