//NEED TO THINK AGAIN!!!!!!
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int num_zero;
        int num_non_zero;
        int zero_index;
        int non_zero_index;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                zero_index = i;
                non_zero_index = zero_index+checkzeronum(nums,zero_index);
                break;
            }
        }
        for(int i=zero_index;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                non_zero_index+=checkzeronum(nums,non_zero_index);
                if(non_zero_index==nums.size())
                    break;
                iter_swap(nums.begin()+i,nums.begin()+non_zero_index);
                non_zero_index++;
            }
        }
    }
    //check continuous number of zeros starting from index;   
    int checkzeronum(vector<int> nums, int index)
    {
        int num=0;
        for(int i=index;i<nums.size();i++)
        {
            if(nums[i]!=0)
                break;
            else
                num++;
        }
        return num;
    }
    int checknonzeronum(vector<int> nums, int index)
    {
        int num=0;
        for(int i=index;i<nums.size();i++)
        {
            if(nums[i]==0)
                break;
            else
                num++;
        }
        return num;     
    }
};
