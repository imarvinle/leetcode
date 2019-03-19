//
// Created by marvinle on 2019/3/19 2:42 PM.
//

// leetcode 107

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
    // 直接层次遍历， 加反转
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == nullptr)
            return vector<vector<int>>();
        queue<TreeNode*> q;
        vector<vector<int>> result;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> temp;
            for(int i = 0; i < size; i++){
                root = q.front();
                q.pop();
                temp.push_back(root->val);
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
            }
            result.push_back(temp);
        }
        return vector<vector<int>>(result.rbegin(), result.rend());
    }
};