/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int>dim=binaryMatrix.dimensions();
        int n=dim[0];
        int m=dim[1];
       if(!n||!m)return -1;
        int ret=-1;
        int i=0,j=m-1;
        while(i<n&&j>=0){
            if(binaryMatrix.get(i,j)==1){
                ret=j;
                j--;
            }
            else i++;
        }
        return ret;
    }
};