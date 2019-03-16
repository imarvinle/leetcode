//
// Created by marvinle on 2019/3/16 8:51 AM.
//

class Solution {
public:
    // 因为是无线买入卖出，如果第二天的价格比第一天高，就可以加入利润等于两者之差
    int maxProfit(vector<int>& prices) {
        int sum = 0;
        int size = prices.size();
        for(int i = 0; i < size - 1; i++){
            if(prices[i] < prices[i+1])
                sum += (prices[i+1] - prices[i]);
        }
        return sum;
    }
};