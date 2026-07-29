class Solution {
public:
    bool wordPattern(string pattern, string s) {

        vector<string> words;
        string word;

        stringstream ss(s);

        while (ss >> word) {
            words.push_back(word);
        }

        if (pattern.size() != words.size()) {
            return false;
        }

        unordered_map<char, string> mapPW;
        unordered_map<string, char> mapWP;

        for (int i = 0; i < pattern.size(); i++) {

            if (mapPW.find(pattern[i]) != mapPW.end()) {

                if (mapPW[pattern[i]] != words[i]) {
                    return false;
                }

            } else {

                mapPW[pattern[i]] = words[i];
            }

            if (mapWP.find(words[i]) != mapWP.end()) {

                if (mapWP[words[i]] != pattern[i]) {
                    return false;
                }

            } else {

                mapWP[words[i]] = pattern[i];
            }
        }

        return true;
    }
};