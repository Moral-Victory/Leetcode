class Solution {
public:
    string removeDuplicates(string s) {
        
        stack<char> st;
        st.push(s[0]);
        for(int i=1; i<s.size(); i++){
            
            if(!st.empty() && st.top()==s[i]){
                st.pop();
                continue;
            }
            else{
                st.push(s[i]);
            }
        }
        string result;
        while(!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};