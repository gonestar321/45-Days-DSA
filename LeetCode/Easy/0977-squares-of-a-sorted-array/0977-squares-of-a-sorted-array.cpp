class Solution {
public:
    int squares( int a ){
        return a * a;
    }
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();

        vector<int> result;
        // the array is sorted in ascending order

        int left = 0 , right = n-1;

        while( left<=right){
            if( abs(nums[left]) > abs(nums[right]) ){
                result.push_back(squares(nums[left]));
                left++;
            }else{
                result.push_back(squares(nums[right]));
                right--;
            }
        }
        reverse(result.begin() , result.end());
        return result;

        
    }
};