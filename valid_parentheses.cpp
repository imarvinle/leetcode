//
// Created by marvinle on 2018/10/22.
//

#include <iostream>
#include <stack>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        map<char,char> mp;
        mp[')'] = '(';
        mp['}'] = '{';
        mp[']'] = '[';
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);
            else if(s[i] == ')' || s[i] == '}' || s[i] == ']')
            {
                char c;
                if(!st.empty())
                {
                    c = st.top();
                    st.pop();
                }
                else
                    return false;

                if(c != mp[s[i]])
                    return false;
            }
        }
        if(!st.empty())
            return false;
        return true;
    }
};

int main()
{
    Solution solution;
    string s = "()";
    cout << solution.isValid(s) << endl;
}

