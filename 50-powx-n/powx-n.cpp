class Solution {
public:
    double myPow(double x, long n) {
        double ans=1;
        long long m=n;
        if(n < 0){
            n = -n;
        }

        while(n>0){
        if(n%2==0){
            x=x*x;
            n=n/2;
        }
        else{
            ans=ans*x;
            n = n-1;
        }
            
        }
        if(m<0){
            return (double)1.0/(double)ans;
        }
        return ans;
    }
};