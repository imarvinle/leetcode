//
// Created by marvinle on 2018/10/23 下午10:55.
//

//  题号: 111

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;

        int left = minDepth(root->left);
        int right = minDepth(root->right);

        if((left == 0 && right != 0) || (left != 0 && right == 0))
        {
            int val = left < right ? right:left;
            return val+1;
        }
        return min(left, right)+1;
    }
};
