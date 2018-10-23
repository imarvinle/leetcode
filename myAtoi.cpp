//
// Created by marvinle on 2018/10/20.
//


#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int i = 0;
        while(i < str.size() && str[i] == ' '){++i;
            cout << 'here' << endl;
        }
        if(i == str.size() || !(str[i] == '+' || str[i] == '-' || (str[i]>='0' && str[i] <='9'))){
            cout << "xixi" << endl;
            return 0;
        }
        char c = '+';
        if(str[i] == '+' || str[i] == '-')
        {
            c = str[i++];
            cout << "c=" << c << endl;
        }
        int num = 0;
        int newnum = 0;
        while(i < str.size() && (str[i] >= '0'&&str[i] <= '9')){
            int temp = str[i]-'0';
            newnum = num*10 +temp;
            if(newnum < temp) {
                cout << "ds="<<(newnum-temp)/10 << endl;
                if(c == '-')
                    return INT_MIN;
                return INT_MAX;
            }
            num = newnum;
            i++;
        }
        if(num == INT_MIN && c == '+'){
            return INT_MAX;
        }
        if(c == '-')
            return -num;
        return num;
    }
};

int main(){
    Solution solution;
    cout << solution.myAtoi("-2147483649") << endl;
    cout << INT_MAX << endl;
}
