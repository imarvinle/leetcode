//
// Created by marvinle on 2018/10/27 上午9:57.
//

// 题号: 310

#include <vector>
#include <set>
#include <iostream>

using namespace std;

class Solution {
public:
    struct node{
        set<int> neibors;
        bool isleaf(){return neibors.size() == 1;}
    };
    // 思路 一层一层的将叶节点去掉,最后剩下的就是最长路径中间的那个节点
    vector<int> findMinHeightTrees(int n, vector<pair<int, int> >& edges) {
        if( n == 0) {
            vector<int> b;
            return b;
        }
        if(n == 1) {
            vector<int> a;
            a.push_back(0);
            return a;
        }
        vector<node> tree(n);
        for(auto p : edges)
        {
            tree[p.first].neibors.insert(p.second);
            tree[p.second].neibors.insert(p.first);
        }
        vector<int> cur_leafs;
        vector<int> next_leafs;
        for(int i = 0 ;i < n  ; i++)
        {
            if(tree[i].isleaf())
                cur_leafs.push_back(i);
        }

        while(1)
        {
            for(auto leaf : cur_leafs)
            {
                set<int> neibors = tree[leaf].neibors;
                for(auto neibor : neibors)
                {
                    tree[neibor].neibors.erase(leaf);
                    if(tree[neibor].isleaf())
                        next_leafs.push_back(neibor);
                }
            }
            if(next_leafs.empty())
                break;
            cur_leafs.clear();
            swap(cur_leafs, next_leafs);
        }
        return cur_leafs;
    }
};

int main()
{
    vector<pair<int,int> > a;
    a.push_back(pair<int,int>(1,0));
    a.push_back(pair<int,int>(1,2));
    a.push_back(pair<int,int>(1,3));
    Solution solution;
    vector<int>  b = solution.findMinHeightTrees(4, a);
    cout << b.size() << endl;
    for(auto a : b)
    {
        cout << a << " ";
    }
}