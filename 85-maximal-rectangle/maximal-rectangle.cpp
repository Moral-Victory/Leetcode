class Solution {
public:
    int hist_calc(vector<int>& heights) {
        stack<int> st;
        int max_area = 0;
        int nse;
        int pse;
        int element;
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                element = st.top();
                st.pop();
                nse = i;
                if (st.empty()) {
                    pse = -1;
                } else {
                    pse = st.top();
                }
                max_area = max(heights[element] * (nse - pse - 1), max_area);
            }
            st.push(i);
        }

        while (!st.empty()) {
            nse = heights.size();
            element = st.top();
            st.pop();
            if (st.empty()) {
                pse = -1;
            } else {
                pse = st.top();
            }
            max_area = max(heights[element] * (nse - pse - 1), max_area);
        }
        return max_area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> prefix_sum_matrix(m, vector<int>(n, 0));

        int max_area = 0;
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int i = 0; i < m; i++) {
                sum += matrix[i][j] - '0';
                if (matrix[i][j] == '0') {
                    sum = 0;
                }
                prefix_sum_matrix[i][j] = sum;
            }
        }
        for (int i = 0; i < m; i++) {
            max_area = max(max_area, hist_calc(prefix_sum_matrix[i]));
        }
        return max_area;
    }
};