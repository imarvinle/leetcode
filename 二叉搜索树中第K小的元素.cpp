//
// Created by marvinle on 2019/4/9 9:54 PM.
//

#include <stack>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 思路是利用二叉搜索树中序遍历是递增的顺序，得到第K小
// 非递归中序遍历吧
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        int cnt = 1;
        while (!st.empty() || root != nullptr){
            while (root != nullptr) {
                st.push(root);
                root = root->left;
            }
            if (!st.empty()) {
                root = st.top();
                st.pop();
                if(cnt == k)
                    return root->val;
                else
                    cnt++;
                root = root->right;
            }
        }
        return 0;
    }

};

