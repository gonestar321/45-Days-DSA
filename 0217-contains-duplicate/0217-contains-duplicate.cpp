class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_map<int,int> umap; // value and frequency 

        for( int i = 0 ; i < nums.size() ; ++i){

            int x = nums[i];

            if( umap.count(x)){
                return true;
            }
            else{
                umap[x]++; // this increments the frequency and adds if the element isn't already there

            }
        }
        return false;
    }
};