class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
      
        int n = nums.size();
      vector<int> leftArray(n, 1);
      vector<int> rightArray(n, 1);
      vector<int> result(n, 1);
        int product = 1;
      for( int i = 1 ; i< n ; i++ ){
        leftArray[i] = leftArray[i-1]*nums[i-1];
      }
      for( int j = n-2 ; j>=0 ; --j){
        rightArray[j] = rightArray[j+1]*nums[j + 1];
      }

      for (int i = 0; i < n; i++) {
        result[i] = leftArray[i] * rightArray[i];
    }

    return result;

     

    }
   
};