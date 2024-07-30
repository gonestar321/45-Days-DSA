class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int profit=0;
        for( int i =0; i< size-1 ; ++i){

            if(prices[i] < prices[i+1]){
                int diff = prices[i+1] - prices[i];

                profit+= diff; 
            }
        }
        return profit;

        
    }
};