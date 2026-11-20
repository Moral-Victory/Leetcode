class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int s=tasks.size();
        priority_queue<int> pq;
        unordered_map<char, int> mpp;
        int ans=0;

        for(int i=0; i<s; i++){
            mpp[tasks[i]]++;
        }

        for(auto it:mpp){
            pq.push(it.second);
        }

        while(!pq.empty()){
            vector<int> vec;
            for(int i=0; i<n+1; i++){
                if(!pq.empty()){
                    auto temp=pq.top();
                    pq.pop();
                    vec.push_back({temp-1});
                }
            }
            
            int cap=1;
            int cnt=0;
            for(int i=0; i<vec.size(); i++){
                if (vec[i] > 0) {
                    pq.push(vec[i]);
                }
            }
            
            if(pq.empty()){
                ans+=vec.size();
            }
            else{
                ans+=(n+1);
            }

        }
        return ans;




    }
};