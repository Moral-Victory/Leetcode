class Solution {
public:
bool carry;
    vector<int> plusOne(vector<int>& digits) {
        if(digits.size()==1){
            if(digits[0]==9){
                vector<int> v = {1, 0};
                return v;
            }
        }
        int n=digits.size();
        for(int i=n-1; i>=0; i--){
            digits[i]+=1;
            if(digits[i]<10){
                carry=false;
                break;
            }
            if(digits[i]>=10){
                carry = true;
                digits[i]=0;
            }
        }
        if(carry==true){
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};