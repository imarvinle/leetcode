//
// Created by marvinle on 2019/3/13 6:36 PM.
//

class Solution {
public:
    // 思路: 循环每个加油站，如果积累到当前的油量不够下一阶段则break
    // 关键就是循环队列 %size
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0;
        int cnt;
        int size = gas.size();
        for(int i = 0; i < size; i++){
            cnt = 0;
            sum = 0;
            for(int j = i ; cnt < size; j++, cnt++) {

                sum += gas[j%size];
                if(sum < cost[j%size]) {
                    break;
                }
                sum -= cost[j%size];
            }
            if(cnt ==  size)
                return i;
        }

        return -1;
    }
};