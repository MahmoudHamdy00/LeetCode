class Trie {
private:
    struct Node{
        vector<Node*> childrens = vector<Node*>(26);
        bool isWord=0;
    };
    Node* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root=new Node;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* cur=root;
        for(char ch:word){
            if(cur->childrens[ch-'a']==NULL){
                cur->childrens[ch-'a']=new Node();
            }
            cur=cur->childrens[ch-'a'];
        }
        cur->isWord=1;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* cur=root;
        for(char ch:word){
            if(cur->childrens[ch-'a']==NULL){
                return 0;
            }
            cur=cur->childrens[ch-'a'];
        }
        return cur->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* cur=root;
        for(char ch:prefix){
            if(cur->childrens[ch-'a']==NULL){
                return 0;
            }
            cur=cur->childrens[ch-'a'];
        }
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */