class Bitset {
    string bt[2];
    int frq[2];
public:
    Bitset(int size) {
        frq[0]=size;
        frq[1]=0;
        bt[0]=string(size,'0');
        bt[1]=string(size,'1');
    }
    
    void fix(int idx) {
        if(bt[0][idx]!='1'){
        ++frq[1];
        --frq[0];
        }
        bt[0][idx]='1';
        bt[1][idx]='0';
       


    }
    
    void unfix(int idx) {
         if(bt[0][idx]!='0'){
        ++frq[0];
        --frq[1];
        }
        bt[0][idx]='0';
        bt[1][idx]='1';
       

    }
    
    void flip() {

        swap(bt[0],bt[1]);      
        swap(frq[0],frq[1]);


    }
    
    bool all() {
        return (frq[1]==bt[0].size());
    }
    
    bool one() {

        return frq[1]!=0;

    }
    
    int count() {

        return frq[1];

    }
    
    string toString() {
        return bt[0];

    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */