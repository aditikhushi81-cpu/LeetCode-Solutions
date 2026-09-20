class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        vector<int> st;

        for (int i = 0; i < n; i++) {

            while (!st.empty() && 
                   temperatures[i] > temperatures[st.back()]) {

                int index = st.back();
                st.pop_back();

                ans[index] = i - index;
            }

            st.push_back(i);
        }

        return ans;
    }
};