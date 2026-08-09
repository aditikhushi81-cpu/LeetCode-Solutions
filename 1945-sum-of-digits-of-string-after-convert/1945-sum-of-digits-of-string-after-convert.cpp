class Solution {
public:
    int getLucky(string s, int k) {
        string num = "";
        for(char ch : s){
            int value = ch - 'a' + 1;
            num += to_string(value);

        }
        int result = 0;
        while(k--){
            result = 0;
            for(char ch : num){
                 result += ch - '0';
            }
            num = to_string(result);

        }
        return result;
    }
};