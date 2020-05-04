class Solution {
public:
    int findComplement(int num) {
       // num=~num;
        bitset<31>bt=num;
        bool ok=0;
        for(int i=31;i>=0;i--){
            if(bt[i]||ok){
                ok=1;
                bt.flip(i);
            }
            
        }
        return (int)(bt.to_ulong());
    }
};