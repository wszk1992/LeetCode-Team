    int LCS(string s1, string s2){
        int len=0, prev=0;
        int m=s1.size(), n=s2.size();
        vector<int> last_row(n, 0);
        for(int i = 0; i<m ; i++){
            for(int j=0;j<n;j++){
                if(s1[i]==s2[j]){
                   len = prev + 1; 
                   prev = last_row[j];
                   last_row[j] = len;
                }
                else{
                    len = max( last_row[j], last_row[j-1]);
                    prev = last_row[j];
                    last_row[j] = len;
                }
            }   
        }
        return len;
    }
