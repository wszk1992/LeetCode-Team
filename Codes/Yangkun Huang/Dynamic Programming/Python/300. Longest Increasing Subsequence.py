def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums)==0:
            return 0
        dp=[float('Inf')]
        for i in range(len(nums)):
            l,r=0,len(dp)-1
            m=(l+r)/2
            if nums[i]>dp[r]:
                dp.append(nums[i])
            else:
                while l<r:
                    m=(l+r)/2
                    if dp[m]>nums[i]:
                        r=m
                    elif dp[m]<nums[i]:
                        l=m+1
                    else:
                        break
                m=(l+r)/2
                dp[m]=nums[i]
        return len(dp)
