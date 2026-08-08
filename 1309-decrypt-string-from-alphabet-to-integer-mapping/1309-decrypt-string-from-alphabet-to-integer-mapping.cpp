class Solution {
public:
    string freqAlphabets(string s) {

        string ans = "";

        for (int i = 0; i < s.length(); ) {

            int num;

            if (i + 2 < s.length() && s[i + 2] == '#') {

                num = (s[i] - '0') * 10 + (s[i + 1] - '0');

                ans += ('a' + num - 1);

                i += 3;
            }
            else {

                num = s[i] - '0';

                ans += ('a' + num - 1);

                i++;

            }
        }

        return ans;
    }
};