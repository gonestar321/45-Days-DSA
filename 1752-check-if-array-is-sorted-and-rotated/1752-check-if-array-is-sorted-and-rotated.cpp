class Solution {
public:
    bool check(vector<int>& nums) {

       int n = nums.size();
       int count = 0;
//ascending order ke violation ek hi allowed hai
       for(int i = 1 ; i<n ; i++){
        if(nums[i-1] > nums[i] ){
            count++;
        }
       }
//agar last element first se bada hua toh 
//usko rotate karne par wo element first element se just 
//ek pehle aayega
// fir wo ascending ki condition ko violate kardega
       if( nums[n-1] > nums[0]){
        count++;
       }
//aisi ascend order ki violation hum sirf ek hi allow
// kar skte hain 
// for the array to be in ascending order and/or rotated

       return count<=1;
    }
    
};