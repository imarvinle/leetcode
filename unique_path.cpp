//
// Created by marvinle on 2018/10/16.
//

#include <iostream>

using namespace std;

#define max(m,n) (m)>(n)?(m):(n)
#define min(m,n) (m)<(n)?(m):(n)

class Solution {
public:
    int uniquePaths(int m, int n) {
        int max = max(m,n);


        int less = min(m,n) - 1;
        int more = max(m,n);
        cout << "ed  " << c(3) << endl;
        return c(more)/(c(less)*c(more-less));
    }
private:
    int c(int n){
        int val = 1;
        if(n == 0 || n == 1)
            return val;
        for(int i = n; i >= 1; i--){
                val *= i;
        }
        return val;
    }
};

int main(){
    Solution solution;
    cout << solution.uniquePaths(51,9) << endl;
}