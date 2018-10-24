//
// Created by marvinle on 2018/10/24 下午12:17.
//

// 题号: 42
#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    // 双指针，第一个指针指向首次遇到的高度大于0的，继续移动第二个指针直到遇到第一个高度大于等于第一个指针的，计算它们之间的容量
    // 如果直到移动末尾都没有比第一个指针高的， 将第一个指针向后移动一个单位，继续重复
    int trap(vector<int>& height) {
        if(height.size() <= 2)
            return 0;
        int start = 0;
        while(height[start+1] >= height[start] && start < height.size() - 2)
            start++;
        int midmin = height[start+1];
        int midmax = height[start+1];
        int capcity = 0;
        int end = start+2;
        int target = height[start];
        while( (start < height.size()-2) && (end < height.size()))
        {
            if(height[start] > 0)
            {
                if(height[end] >= target){
                    for(int i = start+1; i < end; i++) {
                        if(target > height[i]) {
                            capcity += (target - height[i]);
                        }
                    }
                    start = end;
                    while(height[start+1] >= height[start] && start < height.size() - 2)
                        start++;
                    end = start+2;
                    target = height[start];
                    midmin = height[start+1];
                    midmax = height[start+1];
                } else {
                    if(height[end] < midmin) {
                        midmin = height[end];
                    }
                    if(height[end] > midmax) {
                        midmax = height[end];
                    }

                    end++;
                    if(end == height.size())
                    {
                        if(midmin < midmax){
                            target--;
                            if(target <= 0){
                                start++;
                                while(height[start+1] >= height[start] && start < height.size() - 2)
                                    start++;
                                end = start+2;
                                target = height[start];
                            } else {
                                end = start+2;
                                midmin = height[start+1];
                                midmax = height[start+1];
                            }

                        } else {
                            start++;
                            while(height[start+1] >= height[start] && start < height.size() - 2)
                                start++;
                            target = height[start];
                            end = start+2;
                            midmin = height[start+1];
                            midmax = height[start+1];
                        }
                    }
                }
            } else {
                start++;
                while(height[start+1] >= height[start] && start < height.size() - 2)
                    start++;
                target = height[start];
                end = start+2;
                midmin = height[start+1];
                midmax = height[start+1];
            }
        }
        return capcity;
    }
};

int main()
{
    int a[12] = {4,9,4,5,3,2};
    vector<int> b(a, a+6);
    Solution solution;
    cout << solution.trap(b) << endl;
}