//
// Created by marvinle on 2019/3/15 4:04 PM.
//


class Solution {
public:
    // 思路: 爬到第n梯可以是n-1爬一级，也可以是n-2爬两级
    // 所以 f(n) = f(n-1) + f(n-2)
    // f(1) = 1 , f(2) = 2
    // 可以递归，但是递归有很多重复计算，所以自低向上迭代比较好
    int climbStairs(int n) {
        int result[3] = {0,1,2};
        if(n <= 2)
            return result[n];
        int one = 1;
        int second = 2;
        int N;
        for(int i = 3; i <= n; i++) {
            N  = one + second;
            one = second;
            second = N;
        }
        return N;
    }
};