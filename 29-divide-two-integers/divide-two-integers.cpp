class Solution {
public:
    int divide(long long dividend, long long divisor) {

        if (dividend==divisor){
            return 1;
        }
            
        
        bool sign = true;
        if(dividend>=0 && divisor<0){
            sign =false;
        }

        if(dividend<=0 && divisor>0){
            sign =false;
        }

        dividend = abs((long long)dividend);
        divisor = abs((long long)divisor);
        long long ans =0;

        while (dividend >= divisor) {
            int count = 0;
            while (dividend >= (divisor<< (count+1))) {
                count+=1;
            }
            ans+=(1<<count);
            dividend = dividend - (divisor<< (count));
        }

        if(ans==(1<<31) && sign){
            return INT_MAX;
        }

        if(ans==(1<<31) && !sign){
            return INT_MIN;
        }

        if(sign){
            return ans;
        }
        else{
            return -ans;
        }
    }
};
