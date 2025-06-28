class Solution {
public:
const int M= 1e9+7;
    long long power_nos(long long x,long long n){
        long long ans=1;
        long long m=n;
        if(n < 0){
            n = -n;
        }

        while(n>0){
        if(n%2==0){
            x=(x*x)%M;
            n=n/2;
        }
        else{
            ans=(ans*x)%M;
            n = n-1;
        }
            
        }
        if(m<0){
            return (long long)1.0/((long long)ans)%M;
        }
        return ans;
    }


    long long countGoodNumbers(long long n) {
        return power_nos(5,(n+1)/2)*power_nos(4,n/2)%M;
    }
};