class Solution {
public:
    string removeKdigits(string num, int k) {
        
        stack<char> st;
        
        for(int i=0;i<num.size();i++){
            while(!st.empty() && (st.top()-'0')>(num[i]-'0') && k>0){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k>0){//to remove elems if they come in ascending order
            st.pop();// inside the stack and none of them is removed
            k--;//EC3
        }
        if(st.empty()){
            return "0";
        }
        string res = "";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        

        while(res.size()!=0 && res.back()=='0'){
            res.pop_back();
        }
        reverse(res.begin(),res.end());

        if(res.empty()){
            return "0";
        }// check this again at end as as there may be like [00000 elems in stack
        //they will go undetected in starting case
        //and after removal of 0s in prev EC, we may have empty stack
        return res;
    }
};