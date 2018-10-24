//
// Created by marvinle on 2018/10/23 下午11:06.
//

// 题号:112


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return false;
        return has2(root, sum);
    }
    bool has2(TreeNode* root, int sum)
    {
        if(root == NULL)
        {
            if(sum == 0)
                return true;
            else
                return false;
        }
        if(root->left == NULL && root->right!= NULL)
        {
            return has2(root->right,sum - root->val);
        }
        if(root->left != NULL && root->right == NULL)
        {
            return has2(root->left, sum - root->val);
        }
        if(root->left == NULL && root->right == NULL)
        {
            return sum == root->val;
        }
        if(root->left != NULL && root->left != NULL)
        {
            bool left = has2(root->left, sum -root->val);
            bool right = has2(root->right, sum - root->val);
            return left || right;
        }
    }
};

