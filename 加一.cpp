//
// Created by marvinle on 2019/3/19 9:35 PM.
//


class Solution {
public:
    // 关键考虑进位和溢出
    vector<int> plusOne(vector<int>& digits) {
        int index = digits.size()-1;
        bool on = false; // 是否进位
        while(true){
            if(index < 0){
                digits.insert(digits.begin(), 1);
                break;
            }
            int temp = digits[index]+1;

            if(temp >= 10){
                temp = temp%10;
                on = true;
            }

            digits[index] = temp;

            if(on){
                index--;
                on = false;
            } else {
                break;
            }

        }
        return digits;
    }
};