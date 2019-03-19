//
// Created by marvinle on 2019/3/19 9:45 PM.
//

// leetcode 637

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
    // 层次遍历,统计和
    vector<double> averageOfLevels(TreeNode* root) {
        if(root == nullptr)
            return vector<double>();
        queue<TreeNode*> q;
        q.push(root);
        vector<double> result;
        while(!q.empty()){
            int size = q.size();
            double sum = 0.0;
            for(int i = 0; i < size; i++){
                root = q.front();
                q.pop();
                sum += root->val;
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
            }
            result.push_back(sum/size);
        }
        return result;
    }
};