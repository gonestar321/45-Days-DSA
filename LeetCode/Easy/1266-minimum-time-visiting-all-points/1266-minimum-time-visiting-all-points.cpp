class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        int time = 0 ;

        for( int i = 0 ; i < n-1 ; ++i){
            int x = points[i][0] , y = points[i][1];
            int u = points[i+1][0]  , v = points[i+1][1];

            int timeToJump = max( abs(u-x) , abs(v-y));

            time += timeToJump ;

        }
        return time;
    }
};