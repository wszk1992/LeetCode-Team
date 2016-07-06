    // how to make sure a division can cover all the subproblems
    int minDistance(string word1, string word2) {
        // add two conditions of empty string
        int m=word1.size()+1, n=word2.size()+1;
        // the key is: consider the states when each i and j are different 
        // v[i][j] means the number of steps for converting word1[0...i] to word2[0...j]
        vector<vector<int>> v(m, vector<int>(n,0));
        for(int i=1;i<m;i++)
            v[i][0]=i;
        for(int j=1;j<n;j++)
            v[0][j]=j;
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                // why i-1 not i???
                // one position mismatch
                if(word1[i-1]==word2[j-1])
                    v[i][j]=v[i-1][j-1]; // v[i][j] represents the steps for converting word1[0...i-1] to word2[0...j-1]
                // v[i-1][j-1]+1 replace
                // v[i-1][j]+1 delete word1[i-1] -- convert word1[0...i-2] to word2[0...j-1] and delete word1[i-1]
                // v[i][j-1]+1 insert -- convert word1[0...i-1] to word2[0...j-2] and then insert word2[j-1]
                else
                    v[i][j]=min(v[i-1][j-1]+1, min(v[i-1][j]+1, v[i][j-1]+1));
            }
        }
        return v[m-1][n-1];
    }
    
    // reduce to one vector
    int minDistance(string word1, string word2) {
        int m=word1.size()+1, n=word2.size()+1;
        vector<int> last_row(n,0);
        for(int j=1;j<n;j++)
            last_row[j]=j;
        for(int i=1;i<m;i++){
            // update the head element
            int left_up=last_row[0];
            last_row[0]=i;
            for(int j=1;j<n;j++){
                int temp=last_row[j];
                if(word1[i-1]==word2[j-1])
                    last_row[j]=left_up;
                else
                    last_row[j]=min(left_up+1, min(last_row[j]+1, last_row[j-1]+1));
                left_up=temp;
            }
        }
        return last_row[n-1];
    }
