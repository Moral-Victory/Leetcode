class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_map<int, int> mpp;
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++){
            if(leftChild[i]!=-1){
                if(mpp.count(leftChild[i])) return false;
                mpp[leftChild[i]]=i;
                adj[i].push_back(leftChild[i]);
            }
            if(rightChild[i]!=-1){
                if(mpp.count(rightChild[i])) return false;
                mpp[rightChild[i]]=i;
                adj[i].push_back(rightChild[i]);
            }
        }

        int root=-1;
        for(int i=0; i<n; i++){
            if(mpp.find(i)==mpp.end()){
                if(root!=-1){
                    return false;
                }
                root=i;
            }
        }
        if(root==-1){
            return false;
        }

        
        vector<int> vis(n, 0);
        int count = 0;
        queue<int> q;
        q.push(root);
        vis[root] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            for(auto i: adj[node]) {
                if(vis[i]!=1){
                    vis[i]=1;
                    q.push(i);
                }
            }
        }
        // if(count==n){
        //     return true;
        // }
        return count==n;
    }
};