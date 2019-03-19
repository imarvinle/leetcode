//
// Created by marvinle on 2019/3/19 11:47 PM.
//

// leetcode 338


class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1, 0);
        // 有一定技巧， 利用i&(i-1)来求递推的前一个
        for(int i = 1; i <= num; i++){
            res[i] = res[i&(i-1)] + 1;
        }
        return res;
    }
};