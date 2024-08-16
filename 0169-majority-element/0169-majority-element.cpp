class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int majority_condition =  n/2;

        unordered_map<int,int> countmap;

        for( int i = 0 ; i< n ; i++){
            
            countmap[nums[i]]++;     

            if(countmap[nums[i]] >= majority_condition){
                return nums[i] ;
            }
       }
        return 0;
    }
};