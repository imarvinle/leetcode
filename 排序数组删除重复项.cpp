//
// Created by marvinle on 2019/3/16 8:49 AM.
//


class Solution {
public:
    // 思路就是双指针
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if(size == 0)
            return 0;
        int first = 0;
        for(int i = 1; i < size; ){
            if(nums[i] ==  nums[first]){
                i++;
            } else if ((i-1) > first) {
                nums[++first] = nums[i++];
            }  else{
                i++;
                first++;
            }
        }
        return  first+1;
    }
};