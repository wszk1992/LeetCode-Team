class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        while(n--)
        {
            if(nums[i]==0)
            {
                nums.insert(nums.begin(),nums[i]);
                nums.erase(nums.begin()+i+1);
                i++;
            }
            else if (nums[i]==2)
            {
                nums.insert(nums.end(),nums[i]);
                nums.erase(nums.begin()+i);
            }
            else
                i++;
        }
    }
};