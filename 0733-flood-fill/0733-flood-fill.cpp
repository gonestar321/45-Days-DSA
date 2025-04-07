class Solution {

private:

    void dfs( vector<vector<int>> & image , int i , int j , int color , vector<vector<bool>> & vis ,int delX[] , int delY[] , int target ){
        //visit karde start node ko
        vis[i][j] = true;
        // color the node at hand
        image[i][j] = color;
       
        for(int k = 0 ; k < 4 ; k++ ){
            int newRow = i + delX[k];
            int newCol = j + delY[k];
//check validity for domain of points , check for similar pixels , check for unvisited
            if( newRow >=0 && newRow < image.size() && newCol >=0 && newCol < image[0].size() && image[newRow][newCol] == target && vis[newRow][newCol] == false ){
                dfs( image , newRow , newCol , color , vis , delX , delY , target);
            }
        }
        return;


    }

public:
//DFS Code likhte hain


    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        // visited array banaya
        vector<vector<bool>> vis(n , vector<bool>(m,false));
         // prepare to check for 4 adjacent nodes of the selected ones
        int delX[] = { 0 , -1 , 0 , 1 };
        int delY[] = {-1 , 0 , 1 , 0 };

        // record the color of node at hand
            int target = image[sr][sc];
        // directly start row and start column se shuru karte h
       
        dfs(image , sr ,sc , color , vis , delX , delY, target);
        return image;
    }
};