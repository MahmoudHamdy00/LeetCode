class Solution {
public:
    int getSum(int a, int b) {
        bitset<33>bta = a;
        bitset<33>btb = b;
        bitset<34>btc;
        for (int i = 0; i < 33; i++) {
            if (bta[i] && btb[i]) {
                if(btc[i])
                    btc[i]=1;
                else 
                    btc[i]=0;
                btc[i+1]=1;
            }
            else if((bta[i]||btb[i])&&btc[i]){
                btc[i+1]=1;
                btc[i]=0;
            }
            else if(bta[i]||btb[i]){
                btc[i]=bta[i]||btb[i];
            }
        }
        return btc.to_ulong();
    }
};