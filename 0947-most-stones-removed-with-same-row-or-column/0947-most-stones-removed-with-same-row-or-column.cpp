#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    

public:
    vector<int> parent, size, rankv;
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
    int removeStones(vector<vector<int>>& stones) {
        int V=stones.size();
        DisjointSet dstr(V);
        int groups=0;
        for(int i=0; i<V; i++){
            for(int j=i+1; j<V; j++){
                if(stones[i][0]==stones[j][0]||stones[i][1]==stones[j][1]){
                    dstr.unionBySize(i, j);
                }
            }
        }
        for(int i=0; i<V; i++){
            if(i==dstr.findUPar(i)){
                groups++;
            }
        }
        return V-groups;
    }
};