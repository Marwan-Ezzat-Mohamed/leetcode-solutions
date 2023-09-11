class Solution {
public:
    int n,m;
    
    
    void dfs(vector<vector<int>>& grid,int x,int y,int time,int start){
        if(x>=n || y>=m||x<0 ||y<0 || grid[x][y]<0 && -grid[x][y]<time)return;
        if(grid[x][y]==0)return;
        
        if(grid[x][y]==2 && !start)
            return;
       
        grid[x][y]=-time;
      
  
        dfs(grid,x-1,y,time+1,false);
        dfs(grid,x,y+1,time+1,false);
        dfs(grid,x+1,y,time+1,false);
        dfs(grid,x,y-1,time+1,false);
 
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        n = grid.size();
        m= grid[0].size();

        for(int row=0;row<grid.size();row++){
            for(int col=0;col<grid[0].size();col++){
                if(grid[row][col] == 2){
                    dfs(grid,row,col,0,true);
                }
            }
        }
        
        int mxTime = 0;
        for(int i=0;i<n;i++){
             for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
                mxTime=max(mxTime,-grid[i][j]);
            }
        }
        return mxTime;
        
    }
};