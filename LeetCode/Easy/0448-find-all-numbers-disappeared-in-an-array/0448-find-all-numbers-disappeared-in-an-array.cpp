class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
//USING SET GIVES O(nlog(n)) time complexity
        // vector<int> answer ; 

        // set<int> s( nums.begin() , nums.end());

        // int n = nums.size();

        // for( int i = 1 ; i <= n ; i++ ){
        //     if( s.find(i) == s.end()){
        //         answer.push_back(i);
        //     }
        // }
        // return answer; 


        vector<int> answer ; 

        unordered_map<int,int> umap;

        int n = nums.size();

        for( int i = 0 ; i <n ; i++){
            int element = nums[i];
            umap[element]++;
        }

        for( int i = 1 ; i <= n ; i++){
            if( umap.count( i ) == 0){
                answer.push_back(i);
            }
        }

        return answer;
    }
};