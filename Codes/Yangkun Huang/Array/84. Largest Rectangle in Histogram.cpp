    int largestRectangleArea(vector<int>& heights) {
        int res=0;
        int h=heights.size();
        if(!h)  return 0;
        vector<int> leftMostSmaller(h,0), rightMostSmaller(h,0);
        // ??? 
        leftMostSmaller[0]=-1;
        rightMostSmaller[h-1]=h;
        for(int i=1;i<h;i++){
            if(heights[i-1]<heights[i])
                leftMostSmaller[i]=i-1;
            else{
                int p=i-1;
                // >=0!!!
                while(p>=0&&heights[p]>=heights[i])
                    p=leftMostSmaller[p];   // dynamic programming
                leftMostSmaller[i]=p;
            }
            for(int j=0; j<n; j++) { // compute left (from left to right)
                if(matrix[i][j]=='1') 
                    left[j]=max(left[j],cur_left); // compare position of rightmost left zero at row i-1(left[j]) with row i(cur_left)
                else {
                    left[j]=0;
                    cur_left=j+1;
                }
            }
            for(int j=n-1; j>=0; j--) {
                if(matrix[i][j]=='1') 
                    right[j]=min(right[j],cur_right); // leftmost right zero
                else {
                    right[j]=n;
                    cur_right=j;
                }    
            }
            for(int j=0; j<n; j++)
                maxA = max(maxA,(right[j]-left[j])*height[j]);
        }
        // h-2??
        for(int i=h-2;i>=0;i--){
            if(heights[i+1]<heights[i])
                rightMostSmaller[i]=i+1;
            else{
                int p=i+1;
                // <h !!! not <h-1
                // >=!!!
                while(p<h&&heights[p]>=heights[i])
                    p=rightMostSmaller[p];
                rightMostSmaller[i]=p;
            }
        }
        for(int i=0;i<h;i++)
            res=max(res, heights[i]*(rightMostSmaller[i]-leftMostSmaller[i]-1));
        return res;
    }
