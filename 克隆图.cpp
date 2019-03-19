//
// Created by marvinle on 2019/3/19 6:52 PM.
//

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    // DFS
    Node* cloneGraph(Node* node) {
        if(node == nullptr)
            return node;
        Node* ret = new Node(node->val, vector<Node*>());
        mp[node] = ret;
        for(auto x : node->neighbors){
            auto it = mp.find(x);
            if(it != mp.end()){
                ret->neighbors.push_back(it->second);
            } else {
                ret->neighbors.push_back(cloneGraph(x));
            }
        }
        return ret;
    }
private:
    map<Node*, Node*> mp; //新旧节点对应
};