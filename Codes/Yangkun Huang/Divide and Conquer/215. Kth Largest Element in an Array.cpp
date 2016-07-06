  // method 1 use quicksort partition
    int findKthLargest(vector<int>& nums, int k) {
        return randomized_select(nums,0,nums.size()-1,k);
    }
    
    int randomized_select(vector<int>& nums,int p,int r, int i){
        if(p==r){
            return nums[p];
        }
        
        int x=nums[r], l=p;
        for(int j=p;j<r;j++){
            if(nums[j]>x){
                swap(nums[l++],nums[j]);
            }
        }
        swap(nums[l],nums[r]);
        
        int q=l;
        int k=q-p+1;
        if(i==k)
            return nums[q];
        else 
            if(i<k)
                return randomized_select(nums,p,q-1,i);
            else
                return randomized_select(nums,q+1,r,i-k);
    }
    
    // method 2 use extra space to get optimal pivot selection
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        if (n==1) return nums[0];
        int big = nums[0], small = big;
        vector<int> left;
        vector<int> right;
        for (int i = 1; i < n; i++) {
            if (nums[i] > big)
                big = nums[i];
            if (nums[i] < small) 
                small = nums[i];
        }
        const double mid = (big + small) / 2.0; // use the medium as partition pivot
        for (int i = 0; i < n; i++) { 
            if (nums[i] <= mid)
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }
        if (left.size() == n) return nums[0]; // all the elements are equal.
        if (left.size() >= n-k+1)
            return findKthLargest(left, k-right.size());
        else 
            return findKthLargest(right, k);
    }
    
    // method 3 use heapsort heapify(priority_queue, multiset)
