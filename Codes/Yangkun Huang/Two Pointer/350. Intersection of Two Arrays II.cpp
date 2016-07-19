    //  Follow up:
    //  What if the given array is already sorted? How would you optimize your algorithm?
    //  What if nums1's size is small compared to nums2's size? Which algorithm is better?
    //  What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
      
    // Sort and two pointers Solution:    
    // Time: O(max(max(m, n), log(max(m, n)))) Space: O(m + n)
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        for(int i=0, j=0;i<nums1.size() && j<nums2.size();){
            if(nums1[i]==nums2[j]){
                res.push_back(nums1[i]);
                i++;
                j++;
            }
            else{
                if(nums1[i]<nums2[j])  
                    i++;
                else
                    j++;
            }
        }
        return res;
    }
    
    // hashtable (using unordered_map)
    // time complexity: max(O(m), O(n))
    // space complexity: choose one O(m) or O(n) 
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) return intersect(nums2, nums1);
        vector<int> ret;
        unordered_map<int,int> map1;
        for(int num:nums1) map1[num]++;
        for(int num:nums2) {
            if(map1.find(num)!=map1.end() && map1[num]>0) {
                ret.push_back(num);
                map1[num]--;
            }
        }
        return ret;
    }
