class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        return sum_max(nums) - sum_min(nums);
    }
    vector<int> find_psse(vector<int>& arr) {
        int n = arr.size();
        vector<int> psee(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                psee[i] = -1;
            } else {
                psee[i] = st.top();
            }
            st.push(i);
        }
        return psee;
    }

    vector<int> find_nse(vector<int>& arr) {
        int n = arr.size();
        vector<int> nsee(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                nsee[i] = n;
            } else {
                nsee[i] = st.top();
            }
            st.push(i);
        }
        return nsee;
    }

    long long sum_min(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse = find_nse(arr);
        vector<int> psse = find_psse(arr);

        long long total = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - psse[i];
            long long right = nse[i] - i;
            total = (total + (arr[i] * left * right ));
        }
        return total;
    }

    vector<int> find_plee(vector<int>& arr) {
        int n = arr.size();
        vector<int> plee(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                plee[i] = -1;
            } else {
                plee[i] = st.top();
            }
            st.push(i);
        }
        return plee;
    }

    vector<int> find_nle(vector<int>& arr) {
        int n = arr.size();
        vector<int> nle(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                nle[i] = n;
            } else {
                nle[i] = st.top();
            }
            st.push(i);
        }
        return nle;
    }

    long long sum_max(vector<int>& arr) {
        int n = arr.size();
        vector<int> nle = find_nle(arr);
        vector<int> plee = find_plee(arr);

        long long total = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - plee[i];
            long long right = nle[i] - i;
            total = (total + (arr[i] * left * right ));
        }
        return total;
    }

};