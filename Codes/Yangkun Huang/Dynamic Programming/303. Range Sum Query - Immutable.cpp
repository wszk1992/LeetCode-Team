public:
     NumArray(vector<int> &nums) : psum(nums.size()+1, 0) {// set psum[0]=0 as a sentinel
        partial_sum( nums.begin(), nums.end(), psum.begin()+1);
    }

    int sumRange(int i, int j) {
        return psum[j+1] - psum[i];
    }
private:
    vector<int> psum;    