class DisjointSet {
    vector<int> parent, size, rankv;

public:
    // Constructor
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        rankv.resize(n + 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
            rankv[i] = 0;   // Initial rank = 0
        }
    }

    // Find with Path Compression
    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    // ✅ Union by Size
    void unionBySize(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);

        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }

    // ✅ Union by Rank
    void unionByRank(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);

        if (pu == pv) return;

        if (rankv[pu] < rankv[pv]) {
            parent[pu] = pv;
        }
        else if (rankv[pv] < rankv[pu]) {
            parent[pv] = pu;
        }
        else {
            parent[pv] = pu;
            rankv[pu]++;   // Increase rank only when equal
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        unordered_map<string, int> mpp;
        DisjointSet dstr(n);
        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){
                string mail=accounts[i][j];
                if(mpp.find(mail)==mpp.end()){
                    mpp[mail]=i;
                }
                else{
                    dstr.unionByRank(i, mpp[mail]);
                }
            }
        }
        vector<vector<string>> merged(n);
        for(auto it:mpp){
            string mail=it.first;
            int node=dstr.findUPar(it.second);
            merged[node].push_back(mail);
        }

         vector<vector<string>> ans;

        for(int i = 0; i < n; i++) {
            if(merged[i].size() == 0) continue;

            sort(merged[i].begin(), merged[i].end());

            vector<string> temp;
            temp.push_back(accounts[i][0]);

            for(auto &mail : merged[i])
                temp.push_back(mail);

            ans.push_back(temp);
        }

        return ans;
    }
};




