//
// Created by 李春霖 on 2018/10/15.
//

#include <map>
#include <string>
#include <iostream>

using namespace std;


class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> map1, map2;
        for (int i = 0; i < s.size(); i++) {
            char ch = s.at(i);
            if (map1.count(ch))
                map1[ch] = map1[ch] + 1;
            else {
                map1.insert(pair<char, int>(ch,1));
            }
        }

        for (int i = 0; i < s.size(); i++) {
            char ch = t.at(i);
            if (map2.count(ch))
                map2[ch] = map2[ch] + 1;
            else {
                map2.insert(pair<char, int>(ch,1));
            }
        }

        for(map<char,int>::iterator iter = map1.begin(); iter != map1.end(); iter++){
            if(iter->second != map2[iter->first])
                return false;
            map2.erase(iter->first);
        }

        if(map2.empty())
                return true;
        return false;
    }

};

int main(){
    string s = "a";
    string s2 = "abaddcd";
    Solution solution;
    cout << solution.isAnagram(s, s2);
}
