//
// Created by marvinle on 2019/3/19 1:03 PM.
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

// 递归实现
// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> result;
//         preorder(result, root);
//         return result;
//     }
//     void preorder(vector<int>& result, TreeNode* root){
//         if(root){
//             result.push_back(root->val);
//             preorder(result, root->left);
//             preorder(result, root->right);
//         }
//     }
// };

// 非递归 栈实现
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == nullptr)
            return vector<int>();
        stack<TreeNode*> st;
        st.push(root);
        vector<int> result;
        while(!st.empty()){
            root = st.top();
            st.pop();
            result.push_back(root->val);
            if(root->right)
                st.push(root->right);
            if(root->left)
                st.push(root->left);
        }
        return result;
    }
};