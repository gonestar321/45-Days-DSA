class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int> umap; // <value , index pairs>

        int n = nums.size();
        int complement = 0 ;
        vector<int> answer;

        for( int i = 0 ; i < n ; i++ ){

            complement = target - nums[i];
            if(umap.count(complement) && umap[complement] != i ){
                answer.push_back(i);
                answer.push_back(umap[complement]);
                return answer;
            }
            else{
                umap[nums[i]] = i ;
            }
        }
        return answer;
    }
};