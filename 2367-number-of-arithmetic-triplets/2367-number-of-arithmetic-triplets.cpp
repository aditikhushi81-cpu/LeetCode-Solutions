class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_set<int> st;
        for(int num : nums){
            st.insert(num);
        }
        int count = 0;
        for(int num : nums){
            if(st.find(num + diff) != st.end() && st.find(num + 2* diff) != st.end()){
                count++;
            }
        }
        return count;

        
    }
};