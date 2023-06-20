Brute Force:
if zero is encountered, marks whole row of that element -1. and whole column too, except zero.

better: 
create an n sized row array and n sized column array. 
and if there is atleast 1 zero in that row/column, mark that 0 in those vectors
 as 1. 

 optimized: take first row and first column as markers. and work for that 3*3 matrix. before this take two integer x and y =1. and if any number is 0 in first row and first col mark x andy as 0 . in that 3*3 matrix mark those rows and column as 0 where markers are 0. and lastly if x==0 mark 0th row also as 0. and if y==0 , marks 0th col as 0. 

 void setZeroes(vector<vector<int>>& matrix) {
       


        int m =matrix.size();
        int n = matrix[0].size();
        int x =1;
        int y =1;
        for(int j=0;j<n;j++)
        {
            if(matrix[0][j]==0)x=0;
            
        }
        
        for(int i=0;i<m;i++)
        {
            if(matrix[i][0]==0)y=0;
        }
       
            
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        
        
         for(int j=1;j<n;j++)
        {
           if(matrix[0][j]==0)
           {
               for(int i=1;i<m;i++)
                   matrix[i][j]=0;
           }
        }
        
        for(int i=1;i<m;i++)
        {
            if(matrix[i][0]==0)
            {
                for(int j=0;j<n;j++)
                    matrix[i][j]=0;
            }
        }
        
        if(y==0)
        {
            for(int i=0;i<m;i++)
            {
                matrix[i][0]=0;
            }
        }
        
         if(x==0)
        {      
             for(int j=0;j<n;j++)
            matrix[0][j]=0;
        
        }
     }

