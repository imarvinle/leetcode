//
// Created by marvinle on 2019/3/13 10:01 PM.
//

// 51. N皇后


class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        int *result = new int[n];
        vector<vector<string> > s;
        nQueens(0, n, result, s);
        return s;
    }
    // 判断[row, colum]位置能不能放，思路就是向上和左上和右上扫描，如果有存在这三条线上的就不能放
    bool isOk(int row, int colum, int *result, int n) {
        int leftup = colum - 1;
        int rightup = colum + 1;
        row--;
        while(row >= 0) {
            if(result[row] == colum) // 在正上
                return false;
            if(leftup >= 0 && result[row] == leftup) // 在左上
                return false;
            if(rightup < n && result[row] == rightup) // 右上
                return false;
            row--;
            leftup--;
            rightup++;
        }
        return true;
    }

    // 自上而下扫描
    void nQueens(int row, int n,int *result, vector<vector<string> > &strs) {
        if(row == n) {
            cout << "ok" << endl;
            vector<string> temp;
            for(int i = 0; i < n; i++) {
                string s;
                for(int j = 0; j < n ; j++) {
                    if(result[i] == j)
                        s.push_back('Q');
                    else
                        s.push_back('.');
                }
                temp.push_back(s);
            }
            strs.push_back(temp);
            return;
        }
        // 每一row都从左到右扫描，如果可以放，则递归下一层
        for(int i = 0; i < n; i++) {
            if(isOk(row, i, result, n)){
                result[row] = i;
                nQueens(row+1, n, result, strs);
            }
        }
    }
};
