class Solution {
public:
    string sortVowels(string s) {
        vector<int> lowercase(26, 0);
        vector<int> uppercase(26, 0);

        for(int i=0; i<s.size(); i++){
            if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
                uppercase[s[i]-'A']++;
                s[i]='#';
            }
            else if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                lowercase[s[i]-'a']++;
                s[i]='#';
            }
        }
        string ans;
        for(int i=0; i<26; i++){
            char c='A'+i;
            while(uppercase[i]){
                ans+=c;
                uppercase[i]--;
            }
        }

        for(int i=0; i<26; i++){
            char c='a'+i;
            while(lowercase[i]){
                ans+=c;
                lowercase[i]--;
            }
        }
        
        int idx=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='#'){
                s[i]=ans[idx];
                idx++;
            }
        }
        return s;

    }
};