//
// Created by marvinle on 2019/3/15 11:49 PM.
//

// leetcode 633

class Solution {
public:
    // a 和 b一定是小于c的
    // 双指针，[0, sqrt(c)]逐渐向中间逼近
    bool judgeSquareSum(int c) {
        long long i = 0, j = sqrt(c);
        while(i <= j) {
            long long sum = i*i + j*j;
            if(sum < c)
                i++;
            else if (sum > c)
                j--;
            else
                return true;
        }
        return false;
    }
};