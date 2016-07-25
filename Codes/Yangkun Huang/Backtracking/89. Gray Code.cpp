     // backtracking solution
     vector<int> grayCode(int n) {
        vector<int> ans;
        ans.push_back(0);
        int curr=0;
        while(ans.size()<(1<<n)){
            for(int i=0;i<n;i++){
                int mask=1<<i;
                int candidate=curr^mask; // change every single bit
                if(find(ans.begin(), ans.end(), candidate)==ans.end()){ // and check if there already exist one
                    ans.push_back(candidate);
                    curr=candidate;
                    break;
                }
            }
        }
        return ans;
     }
    
    
    // not a backtracking solution
    vector<int> grayCode(int n) {
        vector<int> ans(1<<n);
        for (int i=0; i<(1<<n); i++)  // since the sequnce of (i^(i>>1)) each differs in one bit, use it form gray code
            ans[i] = i^(i>>1);        // i^(i>>1) ^ (i+1)^((i+1)>>1) = i^(i+1) ^ (i+1)^((i+1)>>1)
        return ans;                   // i^(i+1) and (i+1)^((i+1)>>1) differs only in the highest bit
    }
