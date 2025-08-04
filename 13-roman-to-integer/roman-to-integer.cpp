#include <unordered_map>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman={
        {'I',1},{'V',5},{'X',10}, {'L', 50},{'C', 100},{'D', 500},{'M', 1000}

        };

       int Sum=0;
       for(int i=0;i<s.length();i++){
       if(i+1<s.length() && roman[s[i]]<roman[s[i+1]])
       { 
         Sum-=roman[s[i]];
       }
       else   Sum+=roman[s[i]];
     }

     return Sum;


    }
};