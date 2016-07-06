  // method 1 from begin and end
  // without zero: the longer the subsequence is, the larger the absolute value is
  // with zeros: 1.negative means contrary sign -- decide keep which part
  // 2.positive means same sign -- just keep all elements
  int maxProduct(vector<int>& nums) {
        const int n = nums.size();
        int ans = INT_MIN;
        int front = 0;
        int back = 0;
        for (int i=0; i<n; i++) {
            front = front ? front*nums[i] : nums[i];
            back = back ? back*nums[n-1-i] : nums[n-1-i];
            ans = max(ans, max(front, back));
        }
        return ans;
  }
    
  // method 2 both from begin
  // needs two tracks 
  // one tracks maximum positive, the other tracks minumum negative, both could be maximum product
  int maxProduct(vector<int>& nums) {
       if(!nums.size())
          return 0;
       int ans=nums[0];
       int maxP=1, minN=1;
       for(int i=0;i<nums.size();i++){
         int a=minN*nums[i], b=maxP*nums[i];
         // if no greater than max, set a new start
         maxP=max(max(a,b),nums[i]);
         // if no less than min, set a new start
         minN=min(min(a,b),nums[i]);
         ans=max(maxP,ans);
       }
       return ans;
  }
