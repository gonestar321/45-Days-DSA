class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // int n= nums.size();
        // int dupe[n];

       
        // // int pos = (i+k)%n;

        // for(  int i = 0;  i<n ; i++){
        //     int pos = (i+k)%n;
        //     dupe[pos]=nums[i];
        // }

        // for(  int i = 0;  i<n ; i++){
            
        //     nums[i] = dupe[i];
        //     }
        int n = nums.size();
        if(n==0 || k==0){
            return;
        }
        k = k%n;
        
        reverse(nums.begin(), nums.end());
        reverse(nums.begin() , nums.begin()+k);
        reverse(nums.begin()+k , nums.end());

}
};