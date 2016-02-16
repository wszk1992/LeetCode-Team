int singleNumber(vector<int>& nums) {
        // all the identical numbers must be put in together
        // method 1           
        // int x = 0;
        // for (auto i : nums) {
        //     x ^= i;
        // }
        // return x;
    
       // method 2                                                     // accumulate() STL
       return accumulate(nums.begin(), nums.end(), 0, bit_xor<int>()); // bit_xor<int>()


        //unordered_map<int,bool> m;  
        // for(int i=0;i<nums.size();i++)
        // {
        //     if(!m.find(nums[i]))
        //     insert;
        //     else
        //     ->second=true;
        // }
        // find(value==false)?
        // return 0;
    }