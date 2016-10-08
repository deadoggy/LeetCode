/*According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state.

Follow up: 
1.Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?
2.Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

Subscribe to see which companies asked this question*/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        
        int direction[8][2] = {
            {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}
        };
        
        int row = board.size();
        int col = board[0].size();
        int** temp_board = new int*[row];
        for(int i=0; i<row; i++)
        {
            temp_board[i] = new int[col]();
        }
        
        for(int cur_row=0; cur_row<row; cur_row++)
        {
            for(int cur_col=0; cur_col<col; cur_col++)
            {
                if(0==board[cur_row][cur_col])//如果是0就不用加到周围的值里
                {
                    continue;
                }
                //把该值加到周围所有八个cell中
                for(int dir=0; dir<8; dir++)
                {
                    int tar_row = cur_row + direction[dir][0];
                    int tar_col = cur_col + direction[dir][1];
                    if((tar_row >=0 && tar_row <row)
                        &&
                       (tar_col >=0 && tar_col <col))
                       {
                           temp_board[tar_row][tar_col] += board[cur_row][cur_col];
                       }
                }
            }
        }
        
        for(int cur_row=0; cur_row<row; cur_row++)
        {
            for(int cur_col=0; cur_col<col; cur_col++)
            {
                if(
                    (1==board[cur_row][cur_col] && (temp_board[cur_row][cur_col] >=2 && temp_board[cur_row][cur_col] <=3))
                    ||
                    (0==board[cur_row][cur_col] && (3==temp_board[cur_row][cur_col]))
                  )
                  {
                      board[cur_row][cur_col]=1;
                  }
                else
                {
                    board[cur_row][cur_col]=0;
                }
            }
        }
        
    }
};
