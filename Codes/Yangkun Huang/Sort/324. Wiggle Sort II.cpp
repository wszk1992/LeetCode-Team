void wiggleSort(vector<int>& nums) {
        // in-place? how?
        int n = nums.size();
        
        // Find a median.
        auto midptr = nums.begin() + n / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;
        
        // Index-rewiring.
        #define A(i) nums[(1+2*(i)) % (n|1)]
            
        // 3-way-partition-to-wiggly in O(n) time with O(1) space.
        
        int i = 0, j = 0, k = n - 1;
        while (j <= k) {
            if (A(j) > mid)
            swap(A(i++), A(j++));        
            else if (A(j) < mid)
            swap(A(j), A(k--));
            else
            j++;
        }
        
    //     for(int i=1,j=0;i<nums.size();i++)
    //     {
    //         if(nums[i]==nums[i-1])
    //         {
                
    //             for(j=i;nums[j]==nums[i-1];j++);
    //             swap(nums[i],nums[j]);
    //         }
    //         if(i%2==1&&nums[i]<nums[i-1])
    //          swap(nums[i],nums[i-1]);
    //         if(i%2==0&&nums[i]>nums[i-1])
    //          swap(nums[i],nums[i-1]);
    //     }
        
}