//
// Created by marvinle on 2019/3/16 12:04 AM.
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

    // 思路就是层次遍历， 层次遍历有个技巧就是每到一个新层
    // 可以用一个新的变量记住当前层的个数，避免队列既在插入又在取出size变化
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr)
            return vector<int>();
        vector<int> result;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* temp;
        while(!q.empty()) {
            int size = q.size();
            for(int i =0 ;i < size; i++){
                temp = q.front();
                q.pop();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            result.push_back(temp->val);
        }
        return result;
    }
};