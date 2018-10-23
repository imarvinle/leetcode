//
// Created by marvinle on 2018/10/17.
//
#include <vector>
using namespace std;


class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i = 0;
        int start = 0;
        int end = 0;
        int len  = 0;
        if(n == 0)
            return true;
        if(flowerbed.size() == 1){
            if(flowerbed[0] == 0 && n == 1)
                return true;
            else
                return false;
        }
        while(i < flowerbed.size()){
            if(flowerbed[i] == 1){
                start = i+1;
                while(++i < flowerbed.size() && flowerbed[i] == 0){}

                end = i-1;
                len = end-start+1;
                if(i==flowerbed.size() && len >=2 ){
                    int temp = (len-2)/2+1;
                    n -= temp;
                }else if(i < flowerbed.size() && len >= 3){
                    int temp = (len-1)/2;
                    n -= temp;
                }

            } else {
                start = i;
                while(++i < flowerbed.size() && flowerbed[i] == 0) {}
                end = i-1;
                len = end-start+1;
                if(len >= 2 && i < flowerbed.size()){
                    int temp = (len-2)/2+1;
                    n -= temp;
                } else if(len >= 2 && i == flowerbed.size()){
                   int temp = 0;
                   if(len == 2)
                       temp = 1;
                   else
                       temp = (len - 3)/2+2;
                   n -= temp;
                }

            }
        }
        return n <= 0;
    }
};

int main(){
    int a[] = {0,0,0};
    vector<int> v(begin(a), end(a));
    Solution solution;
}