    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // basic idea: check every element pair of nums and generate triples, and quadraples...
        // question: how to generate triples from pairs -- in lack of some restriction
        
        // in a sorted array, a new element can be added if it can divide the minimum number or is divisible by the maximum of exsiting subarray
        sort(nums.begin(), nums.end()); 
        int n=nums.size(), max_size=0, max_index=0;
        vector<int> T(n, 0); // T[n] means the maximum length of subset which has nums[n] as its maximum 
        vector<int> parent(n, 0); // parent[n] means the prior element of nums[n]
        for (int i=0;i<n;i++){
            for(int j=i; j>=0; j--){ // if from i to 0?
                if(nums[i] % nums[j]==0 && T[i]<T[j]+1){
                    T[i]=T[j]+1;
                    parent[i]=j;
                    if(max_size < T[i]){
                        max_size = T[i];
                        max_index = i;
                    }
                }
            }
        }
        vector<int> res;
        for(int i=0;i<max_size;i++){
            res.push_back(nums[max_index]);
            max_index=parent[max_index];
        }
        return res;
    }
