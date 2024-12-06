class Solution {
public:
    int myAtoi(string s) {
        int i = 0, sign = 1;
        long long result = 0;

        // Ignore leading whitespaces
        while (i < s.size() && s[i] == ' ') {
            i++;
        }

        // Check for sign
        if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Convert digits to integer
        while (i < s.size() && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            if (result * sign >= INT_MAX) return INT_MAX;
            if (result * sign <= INT_MIN) return INT_MIN;
            i++;
        }

        return static_cast<int>(result * sign);
    }
};