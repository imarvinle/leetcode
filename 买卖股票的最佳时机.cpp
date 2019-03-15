//
// Created by marvinle on 2019/3/15 3:57 PM.
//

// leetcode 121

class Solution {
public:

    // 注意这里只允许买卖一次
    // 思路， min记录目前为止的最小值
    // 每遇到一个比min大的值就计算当前值-min所获利润并更新cur
    // 如果比min小，就更新min
    int maxProfit(vector<int>& prices) {
        int m = prices.size();
        if(m == 0)
            return 0;
        int min = prices[0];
        int cur = 0;
        for(int i = 1; i < m; i++){
            if(prices[i] < min)
                min = prices[i];
            else {
                int temp = prices[i] - min;
                if(temp > cur)
                    cur = temp;
            }
        }
        return cur;
    }
};

