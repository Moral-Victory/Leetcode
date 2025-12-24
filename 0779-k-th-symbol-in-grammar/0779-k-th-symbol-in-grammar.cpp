class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1 && k==1){
            return 0;
        }
        int count = pow(2, n-1);
        int mid = count/2;
        if(k<=mid){
            return kthGrammar(n-1, k);
        }

        return !(kthGrammar(n-1, k-mid));
        
    }
};