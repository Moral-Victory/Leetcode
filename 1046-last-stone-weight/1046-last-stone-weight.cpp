class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();

        priority_queue<int> pq;

        for(int i=0; i<n; i++){
            pq.push(stones[i]);
        }

        while(pq.size()!=1 && pq.size()!=0){
            auto first=pq.top();
            pq.pop();
            auto second=pq.top();
            pq.pop();

            if(first==second){
                continue;
            }
            else{
                pq.push(abs(first-second));
            }

        }

        if(!pq.empty()){
            return pq.top();
        }
        return 0;



    }
};