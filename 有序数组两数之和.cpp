//
// Created by marvinle on 2019/3/15 11:41 PM.
//

// leetcode 167

class Solution {
public:
    // 双指针移动
    vector<int> twoSum(vector<int>& numbers, int target) {
        if(numbers.size() < 2)
            return vector<int>();
        int lo = 0;
        int hi = numbers.size()-1;
        while(lo < hi) {
            int sum = numbers[lo] + numbers[hi];
            if(sum < target){
                lo++;
            } else if(sum > target){
                hi--;
            } else {
                return vector<int>({lo+1, hi+1});
            }
        }
        return vector<int>();
    }
};