//
// Created by marvinle on 2018/10/24 上午10:22.
//

// 题号: 71

#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> res;

        if(path == "")
            return path;

        split(res, path, "/");

        vector<string> newres;
        for(vector<string>::iterator it  = res.begin(); it != res.end(); ++it)
        {
            if(*it == ".")
                continue;
            if(*it == "..")
            {
                if(!newres.empty())
                    newres.pop_back();
                continue;
            }
            newres.push_back(*it);
        }
        string newpath = "/";
        for(auto s : newres)
        {
            newpath += "/";
            newpath += s;
        }
        return newpath;
    }

private:
    vector<string> split(vector<string>& res,const string& str, const string& delim)
    {
        if(str == "")
            return res;
        char *s = new char[str.length()+1];
        char *d = new char[delim.length()+1];
        strcpy(s, str.c_str());
        strcpy(d, delim.c_str());
        char *p = strtok(s, d);
        while(p)
        {
            string s = p;
            res.push_back(s);
            p = strtok(NULL, d);
        }
        delete[] s;
        delete[] d;
        return res;
    }
};

int main()
{

    Solution solution;
    cout << solution.simplifyPath("/hello/..//wewe") << endl;

}

