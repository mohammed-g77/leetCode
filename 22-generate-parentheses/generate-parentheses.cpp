class Solution {
public:
    void backtrack(vector<string>& res, string s, int open, int close, int n) {
        if (s.length() == 2 * n) {
            res.push_back(s);
            return;
        }
        if (open < n) backtrack(res, s + '(', open + 1, close, n);
        if (close < open) backtrack(res, s + ')', open, close + 1, n);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(res, "", 0, 0, n);
        return res;
    }

};