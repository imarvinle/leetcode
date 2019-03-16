//
// Created by marvinle on 2019/3/16 12:18 AM.
//

// leetcode 103

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // 从左往右的时候可以push_back
        // 从右往左的时候可以push_front
        // 从左往右可以pop_front
        // 从右往左 pop_back;
        if(root == nullptr)
            return vector<vector<int>>();
        vector<vector<int>> result;

        bool ltor = true;
        deque<TreeNode*> d;
        d.push_back(root);
        while(!d.empty()) {
            int size = d.size();
            vector<int> vt;
            TreeNode *temp;
            // 从左到右遍历
            if(ltor){
                for(int i = 0; i< size; i++){
                    temp = d.front();
                    d.pop_front();
                    vt.push_back(temp->val);
                    if(temp->left)
                        d.push_back(temp->left);
                    if(temp->right)
                        d.push_back(temp->right);
                }
                ltor = false;
            } else {
                for(int i = 0; i< size; i++){
                    temp = d.back();
                    d.pop_back();
                    vt.push_back(temp->val);
                    if(temp->right)
                        d.push_front(temp->right);
                    if(temp->left)
                        d.push_front(temp->left);
                }
                ltor = true;
            }
            result.push_back(vt);
        }
        return result;
    }
};