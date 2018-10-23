//
// Created by marvinle on 2018/10/11.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char> >& grid) {
        if(grid.size() == 0)
            return 0;
        int len = grid[0].size();
        int size = grid.size() * len;
        int table[size];
        //      初始化表
        for (int i = 0; i < size; i++) {
            table[i] = i;
        }
        //读入数据开始合并
        for (int j = 0; j < grid.size(); j++) {
            for (int i = 0; i < len; i++) {
                if (grid[j][i] == '1'){
                    // 左边
                    if (i > 0){
                        if (grid[j][i-1] == '1'){
                            if (!connected(table,j*len+i,j*len+(i-1)))
                                my_union(table, j*len+i, j*len+(i-1));
                        }
                    }
                    // 右边
                    if (i < len - 1){
                        if (grid[j][i+1] == '1'){
                            if (!connected(table,j*len+i, j*len+(i+1)))
                                my_union(table,j*len+i, j*len+(i+1));
                        }
                    }
                    // 下边
                    if (j < grid.size() - 1){
                        if (grid[j+1][i] == '1'){
                            if (!connected(table,j*len+i, (j+1)*len+i))
                                my_union(table,j*len+i, (j+1)*len+i);
                        }
                    }
                     // 上边
                    if (j > 0){
                        if (grid[j-1][i] == '1'){
                            if(!connected(table, j*len+i, (j-1)*len+i))
                                my_union(table, j*len+i, (j-1)*len+i);
                        }
                    }
                }
            }

        }
        int count = 0;
        for(int i = 0; i < size; i++){
            if(table[i] == i && grid[i/len][i%len] == '1')
                count++;

        }
        return count;
    }

private:

    inline bool connected(int table[], int i, int j){
        return table[i] == table[j];
    }

    inline void my_union(int table[], int i, int j){
         int iroot = root(table,i);
         int jroot = root(table,j);
         table[i] = jroot;
    }

    inline int root(int table[], int i){
        while(i != table[i])
            i = table[i];
        return i;
    }
};

int main(void) {
    Solution solution;
    vector<vector<char> > grid(3, vector<char>(2,'1'));
    cout << solution.numIslands(grid) << endl;
}



