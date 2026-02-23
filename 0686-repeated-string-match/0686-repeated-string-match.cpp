class Solution {
public:

     void lps_find(string s, vector<int>& LPS) {
        int n=s.size();
        // vector<int> LPS(n, 0);
        int pref=0;
        int suff=1;
        while(suff<n){
            if(s[pref]==s[suff]){
                LPS[suff]=pref+1;
                suff++;
                pref++;
            }
            else{
                if(pref==0){
                    LPS[suff]=0;
                    suff++;
                }
                else{
                    pref=LPS[pref-1];
                }
            }
        }
    }

    int KMP_match(string haystack, string needle) {
        vector<int> LPS(needle.size(), 0);
        lps_find(needle, LPS);
        int first=0;
        int second=0;
        while(first<haystack.size() && second<needle.size()){
            if(haystack[first]==needle[second]){
                first++;
                second++;
            }
            else{
                if(second==0){
                    first++;
                }
                else{
                    second=LPS[second-1];   
                }
            }
        }
        if(second==needle.size()){
            return 1;
        }
        return 0;

    }

    int repeatedStringMatch(string a, string b) {
        if(a==b){
            return 1;
        }
        int repeat=1;
        string temp=a;
        while(temp.size()<b.size()){
            temp+=a;
            repeat++;
        }
        if(KMP_match(temp, b)){
            return repeat;
        }
        if(KMP_match(temp+a, b)){
            return repeat+1;
        }
        return -1;
    }
};