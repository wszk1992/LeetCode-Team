   void sortColors(vector<int>& nums) {
        // method 1
        // put red at the begin, blue at the end, thus white at the middle
        // int red = 0, blue = nums.size() - 1;
        // for (int i = 0; i < blue + 1;) {
        //     if (nums[i] == 0)
        //     swap(nums[i++], nums[red++]);
        //     else if (nums[i] == 2)
        //     swap(nums[i], nums[blue--]);
        //     else
        //     i++;
        // }
        
        // method 2
        // put 0 at left, set pivot as new beginning
        // put 1 at left, put 2 at the other side of the new pivot
        partition(partition(nums.begin(), nums.end(), bind1st(equal_to<int>(), 0)),nums.end(), bind1st(equal_to<int>(), 1));

        // method 3
        // rewrite partition 
        // partition(partition(nums.begin(), nums.end(), bind1st(equal_to<int>(), 0)),nums.end(), bind1st(equal_to<int>(), 1));
        template<typename ForwardIterator, typename UnaryPredicate>
        ForwardIterator partition(ForwardIterator first, ForwardIterator last,UnaryPredicate pred) 
        {
            auto pos = first;
            for (; first != last; ++first)
            if (pred(*first))
            swap(*first, *pos++);
            return pos;
            
        }
        
        // method 4
        // cost large amount of space
        // vector<int> u,v,w;
        // for(int i=0;i<nums.size();i++)
        // if(nums[i]==0)
        // u.push_back(nums[i]);
        // for(int i=0;i<nums.size();i++)
        // if(nums[i]==1)
        // v.push_back(nums[i]);
        // for(int i=0;i<nums.size();i++)
        // if(nums[i]==2)
        // w.push_back(nums[i]);
        // for(int i=0;i<nums.size();i++)
        // {
        //     if(i<u.size())
        //     nums[i]=u[i];
        //     else if(i<u.size()+v.size())
        //     nums[i]=v[i-u.size()];
        //     else
        //     nums[i]=w[i-u.size()-v.size()];
        // }
    }