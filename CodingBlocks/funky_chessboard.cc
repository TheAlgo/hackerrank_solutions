#include <iostream>
#include <climits>

using namespace std;

int res = INT_MAX ;           //Variable to store the final answer

//Cells marked 0 are not in the board
//Cells marked 1 are in the board but not visited
//Cells marked 2 are in the board and visited already
bool knight(int board[][15],int n,int r,int c,int count)
{
    //Base cases
    if(board[r][c]==2){
       //Already visited
       return false;   
    }

    if(r>=n || r<0 ||c<0 || c>=n || board[r][c] == 0){
        //Out of bounds
        return false;
    }

    if(board[r][c]==1){
        //Mark the cell has visited and reduce the count of unvisited cells
        count--;
        board[r][c] = 2;    
    }
    
    //Try to move the knight in all 8 possible ways
    bool x1 = knight(board,n,r-2,c-1,count);
    bool x2 = knight(board,n,r-2,c+1,count);
    bool x3 = knight(board,n,r-1,c-2,count);
    bool x4 = knight(board,n,r-1,c+2,count);
    bool x5 = knight(board,n,r+1,c-2,count);
    bool x6 = knight(board,n,r+1,c+2,count);
    bool x7 = knight(board,n,r+2,c-1,count);
    bool x8 = knight(board,n,r+2,c+1,count);

    //Backtrack
    board[r][c] = 1;
    count++;

    if(!(x1||x2||x3||x4||x5||x6||x7||x8)){
        //If all return false , knight is stuck 
        //Store the least number of unvisited cells in res
        res = min(res,count-1);
        return true;
    }

    return false;
}

int main() 
{
    int board[15][15];
    int n;
    int count = 0;		//Variable to store the number of unvisited cells
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){    
            cin>>board[i][j];
            if(board[i][j] == 1){
                count++;
            }
        }
    }
    
    knight(board,n,0,0,count);

    cout<<res<<endl;

    return 0;
}
