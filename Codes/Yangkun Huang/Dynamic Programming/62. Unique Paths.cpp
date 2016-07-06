    int uniquePaths(int m, int n) {
        if(m==1||n==1) return 1;
        int currCeil=0, left=1;
        vector<int> upCeil(n,1);
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                currCeil=left+upCeil[j];
                left=currCeil;
                upCeil[j]=currCeil;
            }
            left=1;
        }
        return currCeil;
    }
