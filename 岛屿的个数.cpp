//
// Created by marvinle on 2019/3/24 11:14 AM.
//

class Solution {
public:
    // 思路一: 可以使用染色的方法，即出现1，就将1周围可以组成岛屿的变成0，然后计数+1，一直这样遍历
    // 其实就是dfs
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0)
            return 0;
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j =0; j < n; j++){
                if(grid[i][j] == '1'){
                    // dfs染色
                    dfs(grid, i, j);
                    count++;

                }
            }
        }
        return count;
    }

    void dfs(vector<vector<char>> &grid, int i, int j){
        int dirctions[][2] = {{-1,0}, {1,0}, {0,1},{0,-1}};
        int m = grid.size();
        int n = grid[0].size();

        grid[i][j] = '0';
        for(auto dir: dirctions){
            int nr = i+dir[0];
            int nc = j+dir[1];
            if(nr >= 0 && nr < m && nc >= 0 && nc < n &&  grid[nr][nc] == '1'){
                dfs(grid, nr, nc);
            }
        }

    }

};



// class Solution {
// public:
//     // 思路二: 可以使用并查集的方法
//     int numIslands(vector<vector<char>>& grid) {
//         if(grid.size() == 0)
//             return 0;
//         int m = grid.size();
//         int n = grid[0].size();
//         int *root = new int[m * n];
//         //初始化
//        int count = 0;
//        for(int i = 0; i < m; i++){
//            for(int j = 0; j < n; j++){
//                if(grid[i][j] == '1'){
//                    root[i*n+j] = i*n+j;
//                    count++; // 每次遇到一个1就将岛屿数+1
//                } else {
//                    root[i*n+j] = -1;
//                }
//            }
//        }
//         // 方向数组
//         int dirctions[][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
//         for(int i = 0; i < m; i++){
//            for(int j = 0; j < n; j++){
//                if(grid[i][j] == '0'){
//                   continue;
//                }
//                for(auto dir: dirctions){
//                    int nr = i+dir[0];
//                    int nc = j+dir[1];
//                    if(nr>=0 && nc >=0 && nr < m && nc < n && grid[nr][nc] == '1'){
//                        uniond(root, i*n+j, nr*n+nc, count);
//                    }
//                }
//            }
//        }
//         return count;
//     }

//     int find(int *root, int i){
//         int parent;
//         while((parent=root[i]) != i){
//             i = parent;
//         }
//         return parent;
//     };

//     void uniond(int *root, int i, int j, int &count){
//         int rooti = find(root, i);
//         int rootj = find(root, j);
//         if(rooti != rootj){
//             root[rootj] = rooti;
//             count--;
//         }
//     }
// };
