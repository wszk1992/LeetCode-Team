    // method 1 O(nlgn)
    int findDuplicate(vector<int>& nums) {
        int low=1, high=nums.size()-1;  // [1, n]
        while(low<high){    // O(lgn)
            int mid=(low+high)/2;
            int count=0;
            for(int i=0;i<nums.size();i++)      // O(n)
                nums[i]>mid ? count++:count;
            count > nums.size()-1-mid ? low=mid+1 : high=mid;
        }
        return low;
    }
    
    // method 2 O(n)
    // since the maximum value n is less than nums.size()=n+1, then nums[nums[i]] cannot be overflow
    // the only duplicate number form a circle
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
		int fast = nums[nums[0]];
		while (slow != fast){
			slow = nums[slow];
			fast = nums[nums[fast]];
		}
		fast = 0;
		while (fast != slow){
			fast = nums[fast];
			slow = nums[slow];
		}
		return slow;
    }
    // When they meet, assume slow tag move s steps, fast tag move 2s steps, the circle length is c.
    // There must be:
    // 2s = s + n*c => s = n*c....(1)
    // Then, assume the length from start point to entry point is x, and the length from the entry point to the meet point is a.
    // There must be: s = x+a....(2)
    // x+a = s = n*c
    // => x+a = n*c
    // => x+a = (n-1)*c+c
    // => x = (n-1)*c+c-a
    //  in the second loop the two are guaranteed to meet
