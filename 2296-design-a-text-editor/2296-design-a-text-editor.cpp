class TextEditor {
    string s;
    deque<char> l,r;
    int id;
public:
    TextEditor() {
        s="";
        id=0;
    }
    
    void addText(string text) {
        for(char ch:text)l.push_back(ch);
    }
    
    int deleteText(int k) {
        int ret=0;
        while(!l.empty()&&k--){
            l.pop_back();
            ++ret;
        }
        return ret;
    }
    
    string cursorLeft(int k) {
        int len=min(10,k);
        while(k--&&!l.empty()){
            r.push_front(l.back());
            cout<<l.back();
            
            l.pop_back();
        }
        string tmp="";
        int st=max(0,(int)l.size()-10);
        for(int i =st;i<st+10&&i<l.size();++i)tmp+=l[i];
        return tmp;
    }
    
    string cursorRight(int k) {
        int len=min(10,k);
        while(k--&&r.size()){
            l.push_back(r.front());
            r.pop_front();
        }
        string tmp="";
        int st=max(0,(int)l.size()-10);
        for(int i =st;i<st+10&&i<l.size();++i)tmp+=l[i];
        return tmp;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */