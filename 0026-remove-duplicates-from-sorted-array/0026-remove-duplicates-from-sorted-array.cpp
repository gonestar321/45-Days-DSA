class Solution {
public:
    void replace(int& a, int& b) {
    int c = a;
    a = b;
    b = c;
}


    int removeDuplicates(vector<int>& nums) {

    //two pointer initialisation

    int n = nums.size();
    if(n==0){
        return 0;
    }
    int first = 0 ;

    for( int i =0 ; i< n ; i++){

        if( nums[first] != nums[i]){
            first++;
            nums[first] = nums[i];
        }
    }
//using this approach , we won't be using any extra space.
//we'll be replacing within the array itself























        // int n = nums.size();
       
        // unordered_set<int> uniques;
        // int j = 0;

        // for( int i = 0; i<n ; i++ ){
        //     if(uniques.find(nums[i])== uniques.end()){
        //     uniques.insert(nums[i]);
        //      nums[j++] = nums[i];
        //     }
        // }

       
        // return j;
        return first +1;
    }
};