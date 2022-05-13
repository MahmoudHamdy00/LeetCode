/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*>q;
        q.push(root);
        vector<vector<Node*>>levels;
        do{
            int sz=q.size();
            vector<Node*>tmp;
            while(sz--){
                auto cur=q.front();
                q.pop();
                if(cur==NULL)continue;
                tmp.push_back(cur);
                if(cur->left!=NULL)
                    q.push(cur->left);
                if(cur->right!=NULL)
                    q.push(cur->right);

            }
            levels.push_back(tmp);
        }while(!q.empty());
        for(auto it:levels){
            for(int i=0;i+1<it.size();++i)
                it[i]->next=it[i+1];
        }
        return root;
    }
};