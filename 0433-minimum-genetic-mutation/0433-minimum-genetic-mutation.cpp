class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<pair<string, int>> q;
        q.push({startGene, 0});
        set<string> st(bank.begin(), bank.end());
        st.erase(startGene);
        string genes = "ACGT";
        while (!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if (word == endGene) {
                return steps;
            }
            for (int i = 0; i < word.size(); i++) {
                char original = word[i];
                for (char ch:genes) {
                    word[i] = ch;
                    if (st.find(word) != st.end()) {
                        st.erase(word);
                        q.push({word, steps + 1});
                    }
                }
                word[i] = original;
            }
        }
        return -1;
    }
};