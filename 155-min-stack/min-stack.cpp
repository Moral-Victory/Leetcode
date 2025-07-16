class MinStack {
public:
    std::stack<long long> st;
    long long mini = 1e9;
    MinStack() {
        
    }
    
    void push(long long val) {
        if(st.empty()){
            mini = val;
            st.push(val);
        }
        else{
            if(mini<val){
                st.push(val);
            }
            else{
                st.push(2*val-mini);
                mini = val;
            }
        }
    }
    
    void pop() {
        if(st.empty()){
            return;
        }
        long long x=st.top();
        st.pop();
        if(x<mini){
            mini = 2*mini-x;
        }
    }
    
    long long top() {
        long long x=st.top();
        if(mini<x){
            return x;
        }
        return mini;
    }
    
    long long getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */