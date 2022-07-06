#include<bits/stdc++.h>
using namespace std;
void print(vector<vector<int>> &grid)
{
    
    for(int i=0;i<6;i++)
    {
        cout<<"                                                         ";
        for(int j=0;j<6;j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}
int shortestPath(vector<vector<int>> grid,int sx,int sy,int dx,int dy) {

int row = grid.size();
int col = grid[0].size();



    queue<pair<int, int>> queue;

    queue.push(make_pair(sx,sy));

    vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};

    grid[sx][sy] = 1;

    while(!queue.empty()){
        auto curr = queue.front();
        int x = curr.first, y = curr.second;
        if( x == dx && y == dy) return grid[dx][dy];
        
        for(auto direction : directions){
            int nx = x + direction[0];
            int ny = y + direction[1];
            if(nx >= 0 && nx < row && ny >= 0 && ny < col && grid[nx][ny] == 0){
                queue.push(make_pair(nx,ny));
                grid[nx][ny] = grid[x][y] + 1;
            }
        }
        queue.pop();
    }
    return -1;
}
void solve(int x,int y,vector<vector<int>> &grid,int moves,int dx,int dy)
{
   
    
   while(moves)
   {
    enter_dir:
    int dir;
    cout<<endl;
    cout<<"In which direction you want to go?"<<endl;
    cin>>dir;


    if(dir==1)
    {
        if(x-1 < 0)
        {
            cout<<"You cannot go out of the board"<<endl;
            goto enter_dir;
        }

        else if(grid[x-1][y]==1)
        {
            cout<<"You cannot go through a wall"<<endl;
            goto enter_dir;
        }

        else
        {
        
            x--;
            grid[x][y] = 2;
            print(grid);
            cout<<endl;
            moves--;
            cout<<"moves left : "<<moves<<endl;
        }
        
    }


    else if(dir==2)
    {
        if(x+1 >= 9)
        {
            cout<<"You cannot go out of the board"<<endl;
           goto enter_dir;
        }
         else if(grid[x+1][y]==1)
        {
            cout<<"You cannot go through a wall"<<endl;
            goto enter_dir;
        }
        else{
            x++;
            grid[x][y] = 2;
            print(grid);
            cout<<endl;
            moves--;
            cout<<"moves left : "<<moves<<endl;
        }
    }


    else if(dir==3)
    {
        if(y-1 < 0)
        {
            cout<<"You cannot go out of the board"<<endl;
            goto enter_dir;
        }
         else if(grid[x][y-1]==1)
        {
            cout<<"You cannot go through a wall"<<endl;
            goto enter_dir;
        }
        else{
            y--;
            grid[x][y] = 2;
            print(grid);
            cout<<endl;
            moves--;
            cout<<"moves left : "<<moves<<endl;
        }
    }

    else if(dir==4)
    {
        if(y+1 >= 9)
        {
            cout<<"You cannot go out of the board"<<endl;
            goto enter_dir;
        }
         else if(grid[x][y+1]==1)
        {
            cout<<"You cannot go through a wall"<<endl;
            goto enter_dir;
        }
        else{
            y++;
            grid[x][y] = 2;
            print(grid);
            cout<<endl;
            moves--;
            cout<<"moves left : "<<moves<<endl;
        }
    }

   }
    if(x=dx && y==dy)
    {
        cout<<"Well Done you reached the destination in minimum number of moves"<<endl;
    }
    else
    {
        cout<<"oh no! you exhausted your moves!! Try again"<<endl;
    }
   
return;
}

int main()
{
   
    cout<<"                                                 Welcome to the MAZE GAME"<<endl;
    cout<<endl;
    cout<<"                                                 Instructions:"<<endl;
    cout<<"                                                 1. Cells marked with 1 are walls and you cannot gp through them"<<endl;
    cout<<"                                                 2. You can only move through cells marked 0"<<endl;
    cout<<"                                                 3. Cells marked with 2 are the cells you are visiting"<<endl;
    
     vector<vector<int>> grid(6,vector<int>(6));
     int sx,sy,dx,dy;
     vector<vector<int>> grid_easy(6,vector<int>(6));
    vector<vector<int>> grid_medium(6,vector<int>(6));
    vector<vector<int>> grid_hard(6,vector<int>(6));
     

    grid_easy = {{1,0,1,1,1,1},{1,0,1,1,1,1},{1,0,1,1,1,1},{1,0,0,1,1,1},{1,1,1,1,1,1},{1,1,1,1,1,1}};
    grid_medium = {{1,0,1,0,1,0},{1,0,0,0,0,1},{0,0,1,0,0,1},{0,1,0,1,0,1},{0,0,0,1,0,0},{0,0,0,1,1,0}};
    grid_hard = {{0,0,0,0,0,1},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,1,0,0,0},{0,1,0,0,0,0},{1,0,0,0,0,0}};

    int diff_lvl;
    
    cout<<"                                                 Choose the grid you want to play in:"<<endl;
    cout<<"                                                          Press 1 for Easy"<<endl;
    cout<<"                                                          Press 2 for Medium"<<endl;
    cout<<"                                                          Press 3 for hard"<<endl;
    
    
    cin>>diff_lvl;

    if(diff_lvl == 1)
    {
        grid = grid_easy;
        sx = 0;
        sy = 1;
        dx = 3;
        dy = 2;
    }

    else if(diff_lvl == 2)
    {
        grid = grid_medium;
        sx = 0;
        sy = 3;
        dx = 3;
        dy = 2;
    }
   

    else if(diff_lvl == 3)
    {
        grid = grid_hard;
        sx = 0;
        sy = 0;
        dx = 5;
        dy = 5;
    }

int moves = shortestPath(grid,sx,sy,dx,dy);
cout<<"                                               you have "<<moves-1<<" moves to reach the end"<<endl;
cout<<endl;
grid[sx][sy] = 2;
print(grid);
solve(sx,sy,grid,moves-1,dx,dy);
}