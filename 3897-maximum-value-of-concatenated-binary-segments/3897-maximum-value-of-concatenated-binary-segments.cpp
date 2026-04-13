// class Solution {
// public:
//     int maxValue(vector<int>& nums1, vector<int>& nums0) {
//         // int n1=nums1.size();
//         // // int n0=nums0.size();
//         // int nos_1s=0;
//         // int nos_0s=0;
//         // // vector<int> temp;
//         // priority_queue<pair<int, pair<int, int>>> pq;
//         // for(int i=0; i<n1; i++){
//         //     nos_1s=nums1[i];
//         //     nos_0s=nums0[i];
//         //     int diff=nos_1s-nos_0s;
//         //     pq.push({diff, {nos_1s, nos_0s}});
//         // }
//         // string ans="";
//         // vector<int> ones_lol;
//         // vector<int> twos_lol;
//         // while(!pq.empty()){
//         //     auto it = pq.top();
//         //     pq.pop();
//         //     ones_lol.push_back(it.second.first);
//         //     twos_lol.push_back(it.second.second);
//         //     while(it.second.first>0){
//         //         ans+='1';
//         //         it.second.first--;
//         //     }
//         //     while(it.second.second>0){
//         //         ans+='0';
//         //         it.second.second--;
//         //     }
//         // }


        
//         // int res=stoi(ans, nullptr, 2);
//         // return res;

//         int n = nums1.size();

//         priority_queue<pair<int, pair<int,int>>> pq;

//         for(int i = 0; i < n; i++){
//             int diff = nums1[i] - nums0[i];
//             pq.push({diff, {nums1[i], nums0[i]}});
//         }

//         int res = 0;

//         while(!pq.empty()){
//             auto it = pq.top();
//             pq.pop();

//             int ones = it.second.first;
//             int zeros = it.second.second;

//             while(ones--){
//                 res = (res << 1) | 1;   // add '1'
//             }

//             while(zeros--){
//                 res = (res << 1);       // add '0'
//             }
//         }

//         return res;

        
//     }
// };


class Solution {
public:
    
const int mod=1e9+7;
#define ll long long
    int maxValue(vector<int>& nums1, vector<int>& nums0) {

        priority_queue<pair<int,int>, vector<pair<int,int>> >pq;

        //we want heighest 1 lowest 0
        //if a string has no 0 add that to very left
        //pq will have f1,-f0
        
        vector<int>ones;
        for(int i=0;i<nums1.size();i++){
            int f0=nums0[i];
            int f1=nums1[i];
            if(f0==0)ones.push_back(f1);
            else pq.push({f1,-f0});            
        }

        string s="";
        for(int ele : ones){
            for(int i=0;i<ele;i++)s+='1';
        }
        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();

            int f1=p.first;
            int f0=p.second*-1;
            // cout<<f1<<" "<<f0<<endl;

            for(int i=0;i<f1;i++)s+='1';
            for(int j=0;j<f0;j++)s+='0';
            
        }
        // cout<<s<<endl;

        ll ans=0;
        // return 2;
        ll pow=1;


        int l=s.length();
        for(int i=l-1;i>=0;i-- ){
            if(s[i]=='1'){
                ans+=pow;
                ans%=mod;
            }
            pow*=2;
            pow%=mod;
            
        }
        ans%=mod;
        return ans;
        
    }
  
};