//https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    int steps=0;
	    queue<pair<int,int>>q;
	    vector<vector<bool>>visited(N,vector<bool>(N,false));
	    int rowlist[8]={1,1,-1,-1,-2,-2,2,2};
	    int collist[8]={2,-2,2,-2,1,-1,1,-1};
	    
	    
	    int row= KnightPos[0]-1;
	    int col= KnightPos[1]-1;
	    
	    int trow= TargetPos[0]-1;
	    int tcol= TargetPos[1]-1;
	    visited[row][col]=1;
	    
	    if(row==trow && col==tcol)return 0;
	    
	    q.push({row,col});
	    while(!q.empty()){
	        int size = q.size();
	        steps++;
	        while(size!=0){
	            
    	        int r1= q.front().first;
    	        int r2= q.front().second;
    	        q.pop();
    	        for(int i =0;i<8;i++){
    	           int nr=r1+rowlist[i];
    	           int nc=r2+collist[i];
    	           
    	           if(nr>=0 && nr<N && nc>=0 && nc<N && visited[nr][nc]==0 ){
    	               q.push({nr,nc});
    	               visited[nr][nc]=1;
    	               
    	           }
    	           if(nr==trow && nc==tcol ){
    	               return steps;
    	           }
    	        }
    	            
    	            
	                size--;
	        
	       
	           
	        }
	        
	    }
	    return steps;
	    
	    
	    
	}