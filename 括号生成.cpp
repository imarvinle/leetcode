//
// Created by marvinle on 2019/3/18 4:55 PM.
//

//leetcode 22

class Solution {
public:
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
            string temp = cur;
            temp.push_back('(');
            helper(result, temp, left-1, right);
        }
        if(left <  right){
            string temp = cur;
            temp.push_back('(');
            helper(result, temp, left-1, right);
            cur.push_back(')');
            helper(result, cur, left, right-1);
        }
    }

};