class Solution {
public:
    static bool cmp(int a, int b) {
        int pa = __builtin_popcount(a);
        int pb = __builtin_popcount(b);
        if (pa != pb) return pa < pb; // fewest 1s first
        return a < b;                 // normal ascending
    } 
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};