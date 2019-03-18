//
// Created by marvinle on 2019/3/18 4:55 PM.
//

//leetcode 22

class Solution {
public:
    // 深度优先搜索结合剪枝，剪枝就是去掉递归过程中不合适的部分，不再递归
    vector<string> generateParenthesis(int n) {
        if(n == 0)
            return vector<string>();
        vector<string> result;
        int left = n, right = n;
        string cur;
        helper(result, cur, left, right);
        return result;
    }
    void helper(vector<string>& result, string cur, int left, int right){
        if(left == 0){
            for(int i = 0; i < right; i++){
                cur.push_back(')');
            }
            result.push_back(cur);
            return;
        }
        // 只能先压左
        if(left == right){
            helper(result, cur+"(", left-1, right);
        }

        if(left <  right){
            helper(result, cur+"(", left-1, right);
            helper(result, cur+")", left, right-1);
        }
    }

};