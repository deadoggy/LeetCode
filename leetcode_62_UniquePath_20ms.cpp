//make a number table
// another solution is to calculate the C(m-1,n+m-1) with double
class Solution {
public:
     Solution()
     {
         NumTable = new int*[201];
         for(int i = 0; i < 201; i++)
         {
             NumTable[i] = new int[201]();
         }
         NumTable[0][0] = 1;
         NumTable[1][0] = 1;
         NumTable[1][1] = 1;
         
         for(int i = 2; i < 201; i++)
         {
             for(int j = 0; j <= i ; j++)
             {
                 if(j > 100)
                 {
                     break;
                 }
                 
                 if(0 == j || i == j)
                 {
                     NumTable[i][j] = 1;
                 }
                 else
                 {
                     NumTable[i][j] = NumTable[i-1][j] + NumTable[i-1][j-1];
                 }
             }
         }
     }
    int** NumTable;
    int uniquePaths(int m, int n) {
        return NumTable[n+m-2][m-1];
    }
};
