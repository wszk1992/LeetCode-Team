    vector<vector<int>> threeSum(vector<int>& num) {
        vector<vector<int> > res;
        sort(num.begin(), num.end());
        // keep first element unmoved, move second and third element
        for (int i = 0; i < num.size(); i++) {
            int target = -num[i], front = i + 1, back = num.size() - 1;
            while (front < back) {
                int sum = num[front] + num[back];
                // Finding answer which start from number num[i]
                if (sum < target)
                    front++;
                else if (sum > target)
                    back--;
                else {
                    vector<int> triplet(3, 0);
                    triplet[0] = num[i], triplet[1] = num[front], triplet[2] = num[back];
                    res.push_back(triplet);
                    // Processing duplicates of Number 2
                    // Rolling the front pointer to the next different number forwards
                    while (front < back && num[front] == triplet[1])    front++;
                    // Processing duplicates of Number 3
                    // Rolling the back pointer to the next different number backwards
                    while (front < back && num[back] == triplet[2])     back--;
                }
            }
            // Processing duplicates of Number 1
            while (i + 1 < num.size() && num[i + 1] == num[i]) 
                i++;
        }
        return res;
    }
    
    // First of all, think is it necessary to traverse all the possible combination? If yes, is dp available to reduce time complexity?
    // If not, how to eliminate those cases
    // when both two ends are equal which pt should move?
    // reason of failure: eliminate too many cases. The key is controlled variates method.
    // vector<vector<int>> threeSum(vector<int>& nums) {
    //     vector<vector<int>> res;
    //     if(!nums.empty()){
    //         sort(nums.begin(), nums.end());
    //         auto left=nums.begin(), right=nums.end()-1, pt=left+1;
    //         while(left<right-1){ 
    //             while(pt<right){
    //                 if(*pt==-(*left+*right)){
    //                     vector<int> tmp={*left, *pt, *right};
    //                     if(find(res.begin(), res.end(), tmp)==res.end())
    //                     res.push_back(tmp);
    //                 }
    //                 pt++;
    //             }
    //             *left+*right>=0 ? right=right-1 : left=left+1; // pt= left:right OK
    //             pt=left+1;
    //         }
    //     }
    //     return res;
    // }
