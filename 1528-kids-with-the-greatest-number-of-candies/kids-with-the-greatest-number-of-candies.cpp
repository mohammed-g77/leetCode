
#include <algorithm>
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    
     vector<bool> res(candies.size()) ;  
     int maxumimCandies = *max_element(candies.begin(), candies.end());
     for(int i=0; i<candies.size();i++){
        if(candies[i]+extraCandies >=maxumimCandies){
        res[i] = (candies[i] + extraCandies >= maxumimCandies);

        }
      }

      return res;
    }
 
     
};