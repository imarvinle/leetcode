//
// Created by marvinle on 2019/3/18 7:33 PM.
//

class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1)
            return x;
        unsigned int lo = 1;
        unsigned int hi = x;
        unsigned int mid;
        unsigned int t;
        unsigned int res = lo;
        while(lo <= hi){
            mid = lo + ((hi-lo)>>1);
            // 这里如果使用mid * mid 和 x比较的话可能会越界
            if(mid < x/mid){
                lo = mid+1;
                res = mid;
            } else if(mid > x/mid){
                hi = mid-1;
            } else {
                return mid;
            }
        }
        return res;
    }
};