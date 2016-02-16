class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vec=nums;
        vector<int> result;
        int flag=0;
        for(int i=0;i<vec.size();i++)
        {
            for(int j=i+1;j<vec.size();j++)
            {
                if(vec[i]+vec[j]==target)
                {
                     result.push_back(i+1);  
                     result.push_back(j+1);
                     flag=1;
                     break;
                }
            }
            if(flag==1)
            break;
        }
        return result;
    }
};