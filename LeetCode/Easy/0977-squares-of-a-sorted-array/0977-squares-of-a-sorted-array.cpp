class Solution {
public:
    int square(int x){
        return x*x;
    }
    vector<int> sortedSquares(vector<int>& nums) {
        
        int n = nums.size();
        int left = 0 ;
        int right = n-1;
        vector<int> result(n);
        int pos = n-1;
        while(left<=right){

          if( abs(nums[left]) > abs(nums[right])){
            result[pos] = square(nums[left]);
            left++ , pos--;
          }
          else {
            result[pos] = square(nums[right]);
            right-- , pos--;
          }

        }
       // reverse(result.begin(), result.end()); 
        return result;

        
    }
};