    // since the condition holds at both ends, we can simply consider elements between [left, right]
    // the key is to find where the condition breaks(element less than left or less than right), so linear and binary search can be used
    int findPeakElement(vector<int>& nums) {
        // how to use binary search when the array was not sorted
        int mid = 0, l = 0, h = nums.size() - 1;
        
        while (l < h) {                         // since division is rounding down, if use mid-1 need to round up mid = (l+h)/2+1
            mid = (l + h) / 2;                  // mid = (l + h) / 2 + 1;
            if (nums[mid] > nums[mid + 1])      // if (nums[mid] < nums[mid - 1])
                h = mid;                        //      h = mid-1;
            if (nums[mid] < nums[mid + 1])      // if (nums[mid] > nums[mid - 1])
                l = mid + 1;                    //      l = mid;    
        }
        return l;
    }
    
    
    // linear search but it is O(n)
    int findPeakElement(vector<int>& num) {
        for(int i = 1; i < num.size(); i ++)
            if(num[i] < num[i-1])
                return i-1;
        return num.size()-1;
    }
