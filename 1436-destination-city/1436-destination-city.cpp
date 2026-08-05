class Solution {
public:
    string destCity(vector<vector<string>>& paths) {

        unordered_set<string> sourceCities;

        // Store all source cities
        for (auto path : paths) {
            sourceCities.insert(path[0]);
        }

        // Find destination city
        for (auto path : paths) {

            if (sourceCities.find(path[1]) == sourceCities.end()) {
                return path[1];
            }
        }

        return "";
    }
};