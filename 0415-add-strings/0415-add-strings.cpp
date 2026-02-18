class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1.size()<num2.size()){
            swap(num1, num2);
        }
        int carry=0;
        int index1=num1.size()-1;
        int index2=num2.size()-1;
        string ans;
        int sum;
        while(index2>=0){
            sum=(num1[index1]-'0')+(num2[index2]-'0')+carry;
            carry=sum/10;
            ans+=sum%10+'0';
            index1--;
            index2--;
        }
        while(index1>=0){
            sum=(num1[index1]-'0')+carry;
            carry=sum/10;
            ans+=sum%10+'0';
            index1--;
        }
        if(carry){
            ans+=(carry+'0');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};