    // recursive method
    int findMin(vector<int>& nums) {
        return findMin(0, nums.size()-1, nums);
    }
    
    int findMin(int low, int high, vector<int>& nums){
        if(low==high)
            return nums[low];
        int mid=(low+high)/2;
        if(nums[low]==nums[mid])
            return min(findMin(low, mid, nums), findMin(mid+1, high, nums));
        if(nums[low]>nums[mid])
            return findMin(low, mid, nums);
        else
            return min(nums[low], findMin(mid+1, high, nums));
    }
    
    // iterative method
    int findMin(vector<int> &num) {
        int lo = 0, hi = num.size() - 1;
        
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (num[mid] > num[hi]) {
                lo = mid + 1;
            }
            else if (num[mid] < num[hi]) {
                hi = mid;
            }
            else { // when num[mid] and num[hi] are same
                hi--;
            }
        }
        return num[lo];
    }
