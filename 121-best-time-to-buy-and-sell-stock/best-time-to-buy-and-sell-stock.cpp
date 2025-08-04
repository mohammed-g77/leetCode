#include <algorithm>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int minmumPrice = prices[0];
       int  maxmumProfit=0;
        for(int price :prices){
            if(price<minmumPrice){
                minmumPrice=price;
            }
            else{
             int profit = price - minmumPrice;
             if(profit>maxmumProfit){
                maxmumProfit=profit;
             }
            }
        }
        return maxmumProfit;
    }
};