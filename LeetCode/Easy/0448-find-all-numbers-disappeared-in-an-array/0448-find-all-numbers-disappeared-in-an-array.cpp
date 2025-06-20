class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        vector<int> answer ; 

        set<int> s( nums.begin() , nums.end());

        int n = nums.size();

        for( int i = 1 ; i <= n ; i++ ){
            if( s.find(i) == s.end()){
                answer.push_back(i);
            }
        }
        return answer;
    }
};