class MyQueue {
    stack<int>main,slave;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!main.empty()){
            slave.push(main.top());
            main.pop();
        }
        main.push(x);
        while(!slave.empty()){
            main.push(slave.top());
            slave.pop();
        }
        
    }
    
    int pop() {
        int x=main.top();
        main.pop();
        return x;
    }
    
    int peek() {
        return main.top();
    }
    
    bool empty() {
        return main.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */