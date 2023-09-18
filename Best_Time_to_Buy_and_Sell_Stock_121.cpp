//runtime 80ms, beats 95.89% of other users
//memory 93.77MB, beats 8.40% of other users
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int min_price = prices[0];
        int max_price = min_price;
        int max_index = 0;
        int current_profit = 0;
        for (int i = 1; i < prices.size(); i++){
            if (prices[i] > max_price && i > max_index){
                max_price = prices[i];
                max_index = i;
                if (max_price - min_price > current_profit){
                    current_profit = max_price - min_price;
                }
                
            }

            if (prices[i] < min_price){
                min_price = prices[i];
                max_price = min_price;
                max_index = i;
            }
        }
        return current_profit;
    }

};
