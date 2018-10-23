//
// Created by marvinle on 2018/10/23.
//
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


class Solution {
public:
    // 从后往前看，找出每个点到终点的跳跃次数，每个点的次数等于它后面可以到达的所有点中到终点所需跳跃次数
    // 最小的那个点的次数+1
    // 超时
    int jump(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1)
            return 0;
        if(len == 2)
            return 1;

        int time[len];
        memset(time, 0 , sizeof(time));
        int target = len-2;
        int  i, tempi;

        while(target >= 0)
        {
            // 找出target能够到达的点次数最小的点
            int min = INT_MAX;
            for(i = 1 ; i <= nums[target]; i++)
            {
                tempi = i+target;
                if(tempi >= len)
                    break;
                if(time[tempi] < min)
                    min = time[tempi];
            }
            if(nums[target] == 0 || min > len)
                time[target] = INT_MAX;
            else {
                time[target] = min+1;
            }
            target--;
            min = INT_MAX;
           // cout << "target="<< target+1 << "  time[target]=" << time[target+1] << endl;
        }
        return time[0];
    }
};

int main()
{
   vector<int> b(a,a+ sizeof(a)/ sizeof(int));
   Solution solution;

   cout << solution.jump(b) << endl;


}
