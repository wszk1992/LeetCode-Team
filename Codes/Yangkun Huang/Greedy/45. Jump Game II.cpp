// 当前步骤能够到达的最大范围内寻找下一步能到达的范围
// 不要按照每一步的具体停留位置来寻找
int jump(vector<int>& nums) {
        if(nums.size()<2)
        return 0;
        for(int left=0,right=0, count=0;;)
        {
            count++;
            int old_right=right;
            for(int i=left;i<=old_right;i++)
            {
                if(i+nums[i]>=nums.size()-1)
                    return count;
                if(i+nums[i]>right)
                    right=i+nums[i];
            }
            left=old_right+1; 
        }
}