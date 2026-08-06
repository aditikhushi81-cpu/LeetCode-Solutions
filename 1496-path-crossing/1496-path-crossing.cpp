class Solution {
public:
    bool isPathCrossing(string path) {

        unordered_set<string> visited;

        int x = 0;
        int y = 0;

        visited.insert("0,0");

        for (char dir : path) {

            if (dir == 'N')
                y++;

            else if (dir == 'S')
                y--;

            else if (dir == 'E')
                x++;

            else
                x--;

            string position = to_string(x) + "," + to_string(y);

            if (visited.find(position) != visited.end()) {
                return true;
            }

            visited.insert(position);
        }

        return false;
    }
};