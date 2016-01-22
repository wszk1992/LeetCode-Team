class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int max=nums[0];
        int max_num=1;
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++)
        {
            if(map.find(nums[i])==map.end())
                map.insert({nums[i],1});
            else
                map[nums[i]]++;
            if(map[nums[i]]>max_num)
            {
                max_num=map[nums[i]];
                max=nums[i];
            }
            if(max_num>nums.size()/2)
                return nums[i];
            
        }
    }
};
