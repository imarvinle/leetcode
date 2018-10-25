//
// Created by marvinle on 2018/10/24 下午10:52.
//

// 题号: 114

#include <stack>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    // 使用前序 非递归遍历树， 并使用right作为next指针
    void flatten(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* temp = root;
        TreeNode* pre = NULL;
        while(temp != NULL || !st.empty())
        {
            if(temp != NULL){
                if(temp == root){
                   temp = temp->left;
                    pre = root;
                   st.push(pre);
                }  else {
                    pre->left = temp;
                    pre = temp;
                    st.push(pre);
                    temp = temp->left;
                }
            } else {
                temp = st.top();
                st.pop();
                temp = temp->right;
            }
        }
        temp = root;
        while(temp != NULL)
        {
            temp->right = temp->left;
            temp->left = NULL;
            temp = temp->right;
        }
    }
};