class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        
        unordered_map<int , int > umap;
        vector<int> answer;
        int n = nums.size();

        for( int i = 0 ; i < n ; i++ ){
            umap[nums[i]]++;
        }

        for(int i = 0  ; i < n ; i ++){
            int smallerNums = 0 ; 
            int x = nums[i];

            for( auto it = umap.begin() ; it!= umap.end() ; ++it ){
                int key = it->first;

                if(key < x ){
                    smallerNums += it->second;
                }
            }
            answer.push_back(smallerNums);
        }
        return answer;
    }
};