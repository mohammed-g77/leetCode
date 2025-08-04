class Solution {
public:
    string convert(string s, int r) {
      
     if (r == 1 || r >=  s.size()) return s;
        
        vector<string> rows(r);
        int currRow = 0;
        bool goDown = false;
        
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            rows[currRow] += c;
            
            if (currRow == 0 || currRow == r - 1)
                goDown =!goDown;
            
            currRow += goDown ? 1 : -1;
        }
        
        string res;
        for (int i = 0; i < r; i++) {
            res += rows[i];
        }
        return res;
    }
};