class Node{
public:
    int key;
    int val;
    Node *next;
    Node(int key,int val){
        this->key=key;
        this->val=val;
        this->next=nullptr;
    }
};
class LinkedList{
public:
    Node * head;
    LinkedList(){
        head=nullptr;
    }
    void add(int key,int val){
        Node*tmp=head,*prv=head;
        if(head==nullptr){
            head =new Node(key,val);
            return;
        }
        while(tmp->next!=nullptr){
            if(tmp->key==key){
                tmp->val=val;
                return;
            }
            tmp=tmp->next;
        }
         if(tmp->key==key){
                tmp->val=val;
                return;
        }
        tmp->next=new Node(key,val);
    }
    int get(int key){
        Node*tmp=head;
        while(tmp!=nullptr){
            if(tmp->key==key){
                return tmp->val;
            }
            tmp=tmp->next;
        }
        return -1;
    }
    void remove(int key){
        Node*tmp=head,*prv=nullptr;
        while(tmp!=nullptr){
            if(tmp->key==key){
                if(prv==nullptr)head=tmp->next;
                else prv->next=tmp->next;
                return;
            }
            prv=tmp;
            tmp=tmp->next;
        }
    }
};
class MyHashMap {
private:
    const static int SIZE=1000000;
    LinkedList hashMap[SIZE];
public:
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        int idx=key%SIZE;
        hashMap[idx].add(key,value);
    }
    
    int get(int key) {
        int idx=key%SIZE;
        return hashMap[idx].get(key);
    }
    
    void remove(int key) {
        int idx=key%SIZE;
        hashMap[idx].remove(key);
    }
};


/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */