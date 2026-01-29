class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int max_hconsec=1;
        int max_vconsec=1;

        int curr_hconsec=1;
        for(int i=1; i<hBars.size(); i++){
            if(hBars[i]-hBars[i-1]==1){
                curr_hconsec++;
            }
            else{
                curr_hconsec=1;
            }
            max_hconsec=max(curr_hconsec, max_hconsec);
        }

        int curr_vconsec=1;
        for(int i=1; i<vBars.size(); i++){
            if(vBars[i]-vBars[i-1]==1){
                curr_vconsec++;
            }
            else{
                curr_vconsec=1;
            }
            max_vconsec=max(curr_vconsec, max_vconsec);
        }
        int side=min(max_hconsec, max_vconsec)+1;
        return side*side;

    }
};