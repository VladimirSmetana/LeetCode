class Solution {
public:
bool isValid(std::string s) {
    std::stack<char> stack;
    std::unordered_map<char, char> brackets = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

    for (char c : s) {
        if (brackets.count(c)) {
            if (stack.empty() || stack.top() != brackets[c]) {
                return false;
            }
            stack.pop();
        } else {
            stack.push(c);
        }
    }

    return stack.empty();
}
};