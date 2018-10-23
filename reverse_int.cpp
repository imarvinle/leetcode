//
// Created by marvinle on 2018/10/20.
//
#include <cmath>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int a = abs(x);
        int newnum = 0;
        while(a != 0){
            newnum = newnum*10 + (a % 10);
            if(newnum < a){
                return 0;
            }
            a = a/10;
        }
        if(x < 0){
            return -newnum;
        }
        return newnum;
    }
};
int main(){
    string s = "    ds";
    cout << (int)s[0] << endl;
    cout << '9'-'0' << endl;
}

