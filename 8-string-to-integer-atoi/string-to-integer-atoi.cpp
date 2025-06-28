class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        while(i<s.size() && s[i]==' '){
            i++;
        }
        s = s.substr(i);

        long long ans = 0;
        int sign = +1;
        
        if(s[0] == '-') sign = -1;
        
        int MAX = INT_MAX, MIN = INT_MIN;
        
        if(s[0] == '+' || s[0] == '-'){
            i=1;
        }
        else{
            i=0;
        }

        while(i < s.length()) {
            if(s[0] == ' ' || !isdigit(s[i])) break;
            
            ans = ans * 10 + s[i]-'0';

            if(sign == -1 && -1*ans < MIN) return MIN;
            if(sign == 1 && ans > MAX) return MAX;
            
            i++;
        }
        return (int)(ans*sign);
    }
};