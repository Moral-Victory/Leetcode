class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        // int m=s1.size();
        // int n=s2.size();

        // if(m>n){
        //     return false;
        // }

        // sort(s1.begin(),s1.end());

        // for(int i=0; i<n-m+1; i++){
        //     string sub = s2.substr(i, m);

        //     sort(sub.begin(),sub.end());

        //     if(sub==s1){
        //         return true;
        //     }
        // }

        // return false;

        unordered_map<int, int> mpp1;
        unordered_map<int, int> mpp2;

        int m=s1.size();
        int n=s2.size();

        for(int i=0; i<m; i++){
            mpp1[s1[i]]+=1;
        }

        int l=0;
        int r=0;

        while(r<n){
            mpp2[s2[r]]++;

            if(r-l+1==m){
                if(mpp1==mpp2){
                    return true;
                }
                mpp2[s2[l]]--;
                if(mpp2[s2[l]]==0){
                    mpp2.erase(s2[l]);
                }
                l++;
            }
            r++;

        }



        return false;

    }
};