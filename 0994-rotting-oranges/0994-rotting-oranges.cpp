class Solution {
public:
    vector<vector<int>> vis;
    vector<vector<int>> rotten;
    int n,m,cnt=0,mxTime=0;
    
    
    void dfs(vector<vector<int>>& grid,int x,int y,int time,int start){
        if(x>=n || y>=m||x<0 ||y<0 || grid[x][y]==9 && rotten[x][y]<time)return;
        if(grid[x][y]==0)return;
        
        if(grid[x][y]==2 && !start)
            return;
       
        vis[x][y]=1;
        grid[x][y]=9;
        rotten[x][y]=time;
  
        dfs(grid,x-1,y,time+1,false);
        dfs(grid,x,y+1,time+1,false);
        dfs(grid,x+1,y,time+1,false);
        dfs(grid,x,y-1,time+1,false);
 
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        n = grid.size();
        m= grid[0].size();
        cnt=0;
        mxTime = 0;
        vis.resize(n,vector<int>(m, 0));
        rotten.resize(n,vector<int>(m, 0));

        int hasUnrotten = 0;
        for(int row=0;row<grid.size();row++){
            for(int col=0;col<grid[0].size();col++){
                if(grid[row][col] == 1){
                   hasUnrotten = 1;
                }
            }
        }
        
        if(!hasUnrotten)return 0;
        
        
        for(int row=0;row<grid.size();row++){
            for(int col=0;col<grid[0].size();col++){
                if(grid[row][col] == 2){
                    dfs(grid,row,col,0,true);
                }
            }
        }
        
        for(int i=0;i<n;i++){
             for(int j=0;j<m;j++){
              
                 cout<<rotten[i][j];
                
            }
            cout<<endl;
        }
        
        for(int i=0;i<n;i++){
             for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
                mxTime=max(mxTime,rotten[i][j]);
            }
        }
        cout<<mxTime;
        return mxTime;
        
    }
};