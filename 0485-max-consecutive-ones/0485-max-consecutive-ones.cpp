class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int n = nums.size();

        int consecutive = 0 ; 
         int count = 0;
        for( int i = 0 ; i < n ; i++){

           
            
            if(nums[i] == 1){
                count++;
                if( count > consecutive ){
                    consecutive = count;
                }

            }
            if( nums[i] == 0 ){
                count = 0;
            }
            



        }
        return consecutive;
    }
};