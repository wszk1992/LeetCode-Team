    // iterative solution not backtracking
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > totalset = {{}};
        sort(S.begin(),S.end());
        for(int i=0; i<S.size();){
            int count = 0; // num of elements are the same
            while(count + i<S.size() && S[count+i]==S[i])  // record number of duplicate
                count++;
            int previousN = totalset.size();
            for(int k=0; k<previousN; k++){
                vector<int> instance = totalset[k];     // attach duplicate to all previous subset
                for(int j=0; j<count; j++){
                    instance.push_back(S[i]);           // every single number of duplicate attach once
                    totalset.push_back(instance);
                }
            }
            i += count;
        }
        return totalset;
    }
    
    // backtracking recursive solution
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        vector<vector<int> > result;
        vector<int> path;
        dfs(nums, path, 0, result); // return subset from 0 to end and an emptu path vector
        return result;
    }

    static void dfs(const vector<int> &S, vector<int> &path, int step, vector<vector<int> > &result) {
        result.push_back(path);
        for (auto i = step; i < S.size(); i++) {    // replace a recursion with a for-loop
            if (i != step && S[i] == S[i-1]) 
                continue;
            path.push_back(S[i]);  // add current element
            dfs(S, path, i + 1, result); // then attach subset of following elements
            path.pop_back();            // clean up and go to next element
        }
    }
    
    
    // the simplest way is to check before push_back
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        vector<vector<int> > result;
        vector<int> path;
        subsets(nums, path, 0, result); // return subset from 0 to end and an emptu path vector
        return result;
    }

    static void subsets(const vector<int> &S, vector<int> &path, int step, vector<vector<int> > &result) {
        if (step == S.size()) {
            if(find(result.begin(), result.end(), path)==result.end())
                result.push_back(path);
            return;
        }
        // current element is S[step]
        subsets(S, path, step + 1, result);  // first return all possible subsets of following elements from step+1 to end
        path.push_back(S[step]);             // add current element S[step]
        subsets(S, path, step + 1, result);  // attach all subsets of following elements
        path.pop_back();                     // backtracking -- clean up and return to previous element
    }
