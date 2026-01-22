class Solution {
public:
    int calculate(string s) {
        long long ans=0;
        long long nos=0;
        long long sign=1;
        long long i=0;
        stack<long long> st;
        while(i<s.size()){
            if(isdigit(s[i])){
                nos=nos*10+(s[i]-'0');
            }
            else if(s[i]=='+'){
                ans+=nos*sign;
                nos=0;
                sign=1;
            }
            else if(s[i]=='-'){
                ans+=nos*sign;
                nos=0;
                sign=-1;
            }
            else if(s[i]=='('){
                st.push(ans);
                st.push(sign);
                ans=0;
                sign=1;
            }
            else if(s[i]==')'){
                ans+=nos*sign;
                nos=0;
                ans*=st.top();
                st.pop();
                ans+=st.top();
                st.pop();
            }
        i++;
        }
    ans+=(nos*sign);
    return (int)ans;
    }
};