class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int netProfit = 0 ;
        int buy = 0 , sell = 0;

        for( int i = 0 ; i < prices.size() ; i++){
            if(prices[i] < prices[buy]){
                buy = i;
            }
            else if( netProfit<(prices[i] - prices[buy])  ){
                netProfit = prices[i] - prices[buy];
            }
        }
        return netProfit;
    }
};