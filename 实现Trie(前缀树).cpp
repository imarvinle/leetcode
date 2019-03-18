//
// Created by marvinle on 2019/3/18 8:42 PM.
//


class Trie {
public:
    /** Initialize your data structure here. */
    struct TrieNode{
        // 子树节点
        vector<TrieNode*> children;
        char c;
        bool end;
        TrieNode():end(false){
            children.resize(26, nullptr);
        }
    };

    Trie() {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *temp = root;
        int size = word.size();
        int i;
        for(i = 0; i < size; i++){
            int c  = word[i]-'a';
            if(temp->children[c] != nullptr){
                temp = temp->children[c];
                // 将这个位置标记为有一个单词结束
                if(i == size-1){
                    temp->end = true;
                }
            } else {
                TrieNode *newnode = new TrieNode();
                newnode->c = word[i];
                temp->children[c] = newnode;
                temp = newnode;
            }
        }
        temp->end = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *temp = root;
        int size = word.size();
        for(int i = 0 ; i < size; i++){
            int c = word[i]-'a';
            if(temp->children[c] == nullptr){
                return false;
            } else {
                temp = temp->children[c];
            }
        }
        return temp->end;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *temp = root;
        int size = prefix.size();
        for(int i = 0; i < size; i++){
            int c = prefix[i]-'a';
            if(temp->children[c] == nullptr)
                return false;
            else
                temp = temp->children[c];
        }
        return true;
    }
private:
    TrieNode *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */