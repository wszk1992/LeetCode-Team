class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> summary;
        if(nums.size()==0)
        {
            return summary;
        }
        int first=nums[0];
        int last=first;
        for(int i=0;i<nums.size();i++)
        {
            if(i==nums.size()-1)
            {
                if(last == nums[i])
                {
                    if(first!=nums[0])  
                        summary.push_back(to_string(first)+"->"+to_string(last));
                    else 
                    {
                        if(first == last)
                            summary.push_back(to_string(first));
                        else
                            summary.push_back(to_string(first)+"->"+to_string(last));
                    }
                }
                else
                {
                    summary.push_back(to_string(first));
                }
            }
            else if(nums[i]+1!=nums[i+1])
            {
                last = nums[i];
                if(first == last)
                    summary.push_back(to_string(first));
                else
                    summary.push_back(to_string(first)+"->"+to_string(last));
                first = nums[i+1];
            }
            else
            {
                last = nums[i+1];
            }
        }
        return summary;
    }
};
