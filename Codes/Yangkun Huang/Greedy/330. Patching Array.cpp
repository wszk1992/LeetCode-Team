  // method 1 8ms
  int minPatches(vector<int>& nums, int n) {
    int cnt=0,i=0;   
	// maxNum starts at 0
    long long maxNum=0; // use long long to deal with MAX_INT otherwitse maxNum can be negative
    while (maxNum<n){
       if (i<nums.size() && nums[i]<=maxNum+1)
            maxNum+=nums[i++];
       else{
            maxNum+=maxNum+1;
			cnt++;
       }
	}
	return cnt;
}

// method 2 12ms
 int minPatches(vector<int>& nums, int n) {
        int result = 0, index = 0;
		// maxNum starts at 1
        // maxNum����˵�ǰ����nums���ۼӵ������Χ[1, maxNum)
        for (int maxNum = 1; maxNum <=n; )
        {
            if(maxNum<0) // to deal with MAX_INT
                break;
            // ������Ԫ��С��maxNumʱ�����ۼӵ�sum��������Ϊ// maxNum + nums[index]��Ȼ����������ֵ��1
            if (index < nums.size()  && nums[index] <= maxNum)
                maxNum += nums[index++];
            else
            {   
                maxNum <<= 1; // ����Ԫ�غ󣬿��ۼӵ�sum��Χ�ӱ�
                ++result;
            }
        }
        return result;
    }