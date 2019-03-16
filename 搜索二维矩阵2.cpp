//
// Created by marvinle on 2019/3/16 8:20 AM.
//


class Solution {
public:
    // 从右上角开始，可以二分搜索
    // cur < target
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0)
            return false;
        int rows  = matrix.size();
        int cols  = matrix[0].size();
        int row = 0;
        int col = cols-1;
        while(row < rows && col >= 0) {
            if(matrix[row][col] == target)
                return true;
            if(matrix[row][col]  < target) {
                row++;
            } else {
                col--;
            }
        }
        return false;

    }
};