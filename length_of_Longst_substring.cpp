//
// Created by marvinle on 2018/10/19.
//
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    // 时间复杂度O(n^2)
    int lengthOfLongestSubstring(string s) {
       set<char> st ;             // 这里可以采用hash_set(unordered_set优化)
       int max = 0;
       for(int i = 0; i < s.size(); i++){
           for(int j = i; j < s.size(); j++){
               if(st.count(s[j])){
                   if(st.size() > max)
                       max = st.size();
                   st.clear();
                   break;
               } else {
                   st.insert(s[j]);
               }
           }
       }
       if(st.size() > max)
            return st.size();
       return max;
    }

    // 使用滑动窗口
    int lengthOfLongestSubstring2(string s) {
        unordered_set<char> st;
        int max = 0;
        int size  = s.size();
        int i =0;
        int j = 0;
        while(i < size && j < size ){
            if(st.count(s[j])){
                st.erase(s[i++]);
            } else {
                st.insert(s[j++]);
                if(st.size() > max)
                    max = st.size();
            }
        }
        return max;

    }

    // 优化的滑动窗口
    int lengthOfLongestSubstring3(string s) {
        unordered_map<char,int> mp;
        int max1 = 0;
        int size = s.size();
        int j = 0;
        for(int i = 0; i < size; i++){
            if(mp.count(s[i]) && mp[s[i]] >= j){
                j = mp[s[i]]+1;
                mp[s[i]] = i;
            } else {
                mp[s[i]] = i;
                int temp = i - j +1;
                if(temp > max1)
                    max1 = temp;
            }
        }
        return max1;
    }
};

int main(void)
{
    Solution solution;
    string s = "tmmzuxt";
    cout << solution.lengthOfLongestSubstring3(s) << endl;

}