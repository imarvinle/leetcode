//
// Created by marvinle on 2019/3/19 11:39 PM.
//

// leetcode 191题

class Solution {
public:
    // 利用位运算 n & (n-1)是消除n的最后一个1的特点，加速统计过程
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while(n > 0){
            cnt++;
            n = n & (n-1);
        }
        return cnt;
    }
};