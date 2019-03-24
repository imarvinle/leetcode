//
// Created by marvinle on 2019/3/23 12:52 PM.
//


// leetcode 120

// class Solution {
// public:
//     // 第一种解法: dfs, 递归，每次都走两条路径，然后比较两者大小一致递归下去
//     int minimumTotal(vector<vector<int>>& triangle) {
//          if(triangle.size() == 0)
//              return 0;
//         return traverse(triangle, 0, 0, 0);
//     }

//     int traverse(vector<vector<int>>& triangle, int i, int j, int sum){
//         if(i == triangle.size()){
//             return sum;
//         }
//         int left = traverse(triangle, i+1, j, sum + triangle[i][j]);
//         int right = traverse(triangle, i+1, j+1, sum + triangle[i][j]);
//         return min(left,right);
//     }
// };

// dfs会超时， 因为其实存在大量的重复子问题，可以采用 dfs + 记忆化搜索

// 从下往上，动态规划
    //  dp[i][j] = row[i][j] + min(dp[i+1][j], dp[i+1][j+1]);

class Solution {
public:
    // 如果要O(n)时间复杂度的话，直接定义一个和最后一层一样大的数组
    // 因为每次只需要下面相邻一层，并且更新到最前面

    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size() == 0)
            return 0;
        for(int i = triangle.size()-2; i >= 0; i--){
            vector<int> temp =  triangle[i];
            int size = temp.size();
            for(int j = 0; j < size; j++){
                triangle[i][j] = triangle[i][j] + min(triangle[i+1][j], triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
};
