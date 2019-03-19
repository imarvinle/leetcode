//
// Created by marvinle on 2019/3/19 11:42 PM.
//

// leetcode 231

class Solution {
public:
    // 2 的幂次方有个特点就是 只有1位为1，
    // 那么利用 n & (n-1)会消除n的最后一位1的特点就能实现
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n-1)) == 0;
    }
};