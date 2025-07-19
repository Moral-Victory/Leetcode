class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ngi;
        stack<int> st;
        for(int i=(2*n-1);i>=0;i--){
            while(!st.empty() && st.top()<=nums[i%n]){
                st.pop();
            }
            if(i<n){
                if(!st.empty()){
                    ngi.push_back(st.top());
                }
                else{
                    ngi.push_back(-1);
                }
            }
            st.push(nums[i%n]);
        }
        reverse(ngi.begin(), ngi.end());
        return ngi;
    }
};