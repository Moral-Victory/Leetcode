class Solution {
public:
    int countCollisions(string directions) {
        int i = 0;
        int n = directions.size();
        int j = directions.size() - 1;
        int count = 0;
        while(i<n && directions[i]=='L'){
            i++;
        }
        while(j>=0 && directions[j]=='R'){
            j--;
        }
        while(i<=j){
            if(directions[i]!='S'){
                count++;
            }
            i++;
        }
        return count;
    }
};