class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) 
    {
        string result;
        result.reserve(s.size() + spaces.size()); 

        int prev = 0;
        for (int i = 0; i < spaces.size(); ++i) {
            result.append(s, prev, spaces[i] - prev);
            result.push_back(' ');
            prev = spaces[i];
        }
        result.append(s, prev, s.size() - prev);

        return result;
    }
};