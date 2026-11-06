class Solution {
public:

    // bool solve(int num, vector<int>& arr1, vector<int>& arr2, int d, int m, int n){
    //     int low=0;
    //     int high=n-1;
    //     while(low<=high){
    //         int mid=(low+high)/2;
    //         if(abs(num-arr2[mid])>d){
    //             high=mid-1;
    //         }
    //         else{
    //             return false;
    //         }
    //     }
    //     return true;
    // }

    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int m=arr1.size();
        int n=arr2.size();
        // sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
        // int low=0;
        // int high=m-1;
        // int ans=0;
        // for(int i=0; i<m; i++){
        //     if(solve(arr1[i], arr1, arr2, d, m, n)){
        //         ans+=1;
        //     }
        // }
        // return ans;
        // int count =0;
        // for(int i=0; i<m; i++){
        //     int flag=0;
        //     for(int j=0; j<n; j++){
                
        //         if(abs(arr1[i]-arr2[j])<=d){
        //             break;
        //         }
        //         flag+=1;
        //     }
        //     if(flag==n) count+=1;
        // }
        // return count;

        int cnt=0;
        for(int i=0; i<m; i++){
            
            
            int ind = lower_bound(arr2.begin(), arr2.end(), arr1[i]) - arr2.begin();

            if(ind==n){
                if(abs(arr1[i]-arr2[n-1])>d){
                    cnt+=1;
                    
                }
                continue;
            }

            if(ind==0){
                if(abs(arr1[i]-arr2[0])>d){
                    cnt+=1;
                    
                }
                continue;
            }



            if((abs(arr1[i]-arr2[ind])>d) && (abs(arr1[i]-arr2[ind-1])>d)){
                cnt+=1;
            }
            

        }
    return cnt;

    }



    
};