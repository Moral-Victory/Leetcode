class Solution {
public:
    string sortSentence(string s) {
        vector<string> ans(10);
        string sentences;
        string temp;
        int count=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]==' '){
                int position=temp.back()-'0';
                temp.pop_back();
                ans[position]=temp;
                temp.clear();
                count++;
            }
            else{
                temp+=s[i];
            }
        }
        int position=temp.back()-'0';
        temp.pop_back();
        ans[position]=temp;
        temp.clear();

        for(int i=1; i<=count+1; i++){
            sentences+=ans[i];
            sentences+=' ';
        }
        sentences.pop_back();
        return sentences;
    }
};