//
// Created by 李春霖 on 2018/10/22.
//
#include "mystd.h"
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size() < 2)
            return 0;
        int start = 0;
        int end = height.size()-1;
        int max_area = 0;
        while(start != end)
        {
            max_area = max(max_area, min(height[start], height[end]) * (end-start));
            if(height[start] <= height[end])
                start++;
            else
                end--;
        }
        return max_area;
    }
};