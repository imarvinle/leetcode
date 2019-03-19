
//
// Created by marvinle on 2019/3/19 9:26 PM.
//


class Solution {
public:
    // 思路：把原数组划分为两个部分来看：前 n - k 个元素 [1,2,3,4]和 后k个元素 [5,6,7]，进行分开处理
    //  分别对两部分反转，再对整体反转
    void rotate(vector<int>& nums, int k) {
        if(nums.size() == 0 || k == 0)
            return ;
        k = k % nums.size();
        reverse(nums,0, nums.size()-k-1);
        reverse(nums, nums.size()-k, nums.size()-1);
        // 整体
        reverse(nums, 0, nums.size()-1);
    }
    void reverse(vector<int> &nums, int start, int end){
        while(start < end){
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
};