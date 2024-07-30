class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_val= INT_MAX;
        int max_val = INT_MIN;
        int max_profit = 0;

        int size = prices.size();
        for( int i= 0; i<size; i++){
            if(prices[i] < min_val){
                min_val= prices[i];
            }
             else if( prices[i] - min_val > max_profit){
                max_profit = prices[i] - min_val; 
            }
        }

        return max_profit;
    }
};