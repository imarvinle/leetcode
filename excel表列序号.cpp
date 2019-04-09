//
// Created by marvinle on 2019/4/9 9:46 PM.
//
#include <unordered_map>

using namespace std;

class Solution {
public:
    Solution() {
        for(char i = 'A'; i <= 'Z'; i++){
            c2imap[i] = static_cast<int>(i-'A'+1);
        }
    }
    int titleToNumber(string s) {
        int total = 0;
        for(auto c : s){
            total  *= 26;
            total += c2imap[c];
        }
        return total;
    }

private:
    unordered_map<char, int> c2imap;
};