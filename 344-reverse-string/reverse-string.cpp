class Solution {
public:

    void reverse(int left,int right,vector<char>& s){
        if(left>=right){
            return;
        }
        swap(s[left],s[right]);
        reverse(left+1,right-1,s);
    }

    void reverseString(vector<char>& s) {
    int n=s.size();
    reverse(0,n-1,s);
    }
};