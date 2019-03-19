//
// Created by marvinle on 2019/3/19 2:35 PM.
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
// // 取巧的方法
// class Solution {
// public:
//     // 思路，利用二叉树的前序遍历顺序为 root->left->right
//     // 二叉树后序遍历思路为 left->right->root;
//     // 所以把前序顺序调一下: root->right->left就恰好和后序相反，
//     // 最后翻转一下就好了
//     vector<int> postorderTraversal(TreeNode* root) {
//         if(root == nullptr)
//             return vector<int>();

//         vector<int> result;
//         stack<TreeNode*> st;
//         st.push(root);
//         while(!st.empty()) {
//             root = st.top();
//             st.pop();
//             if(root == nullptr)
//                 continue;
//             result.push_back(root->val);
//             // 先push left因为要先遍历右边
//             st.push(root->left);
//             st.push(root->right);
//         }
//         vector<int> temp(result.rbegin(), result.rend());
//         return temp;
//     }
// };


class Solution{
public:
    // 后序遍历的难点在于，当我们把栈中元素出栈时，并不知道该继续遍历右节点还是直接遍历当前节点
    // 所以我们记录一下前一个被访问的节点
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* pre;
        while(root != nullptr || !st.empty()){
            if(root != nullptr){ // 一直向左
                st.push(root);
                root = root->left;
            } else {
                // 左边走到头了，出栈往右，如果出栈后发现前一个访问的就是右节点，则访问当前节点
                // 或者是右节点直接为空也直接访问当前节点，否则就将当前节点压栈，并更新root为
                // 右节点
                root = st.top();
                // 暂时不要pop
                if(root->right == nullptr || pre == root->right){
                    result.push_back(root->val);
                    pre = root;
                    st.pop();
                    root = nullptr;  //让下一次继续弹出栈
                } else {
                    // 访问右边
                    root = root->right;
                }
            }
        }
        return result;
    }
};