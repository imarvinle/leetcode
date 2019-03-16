//
// Created by marvinle on 2019/3/16 8:33 AM.
//


class Solution {
public:
    // 先把nums1向后 移动n个，防止每次插入都要向后移动
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = m-1; i >= 0; i--){
            nums1[i+n] =  nums1[i];
        }
        int n1 = n;
        int n2  = 0;
        int i = 0;
        while(n1 < (n+m) && n2 < n) {
            if(nums1[n1] <  nums2[n2]){
                nums1[i++] =  nums1[n1++];
            }  else {
                nums1[i++] =  nums2[n2++];
            }
        }
        while(n2 < n){
            nums1[i++] =  nums2[n2++];
        }
    }
};


