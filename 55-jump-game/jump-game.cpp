class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxmumReach=0;
        for(int i=0; i<nums.size();i++){
            if(i>maxmumReach){
                return false;
            }
          maxmumReach = max(maxmumReach, i + nums[i]);
          if(nums.size()-1 <=maxmumReach){
            return true;

          }
        }
        return true;
    }
};