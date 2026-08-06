class Solution {
public:
    int secondHighest(string s) {

        unordered_set<int> st;

        // Store unique digits
        for (char ch : s) {

            if (isdigit(ch)) {
                st.insert(ch - '0');
            }
        }

        int largest = -1;
        int second = -1;

        for (int num : st) {

            if (num > largest) {

                second = largest;
                largest = num;
            }
            else if (num > second && num != largest) {

                second = num;
            }
        }

        return second;
    }
};