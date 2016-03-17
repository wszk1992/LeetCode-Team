vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // method 1
        // 先排序然后左右夹逼
        // time complexity O(n^3) space complexity O(1)
        vector<vector<int>> result;
        if (nums.size() < 4) 
        return result;
        sort(nums.begin(), nums.end());
        auto last = nums.end();
        for (auto a = nums.begin(); a < prev(last, 3); ++a) { // prev之前3个位置
            for (auto b = next(a); b < prev(last, 2); ++b) {  // next(b)b的下一个位置
                auto c = next(b);
                auto d = prev(last);                          // last前一个位置
                while (c < d) {
                    if (*a + *b + *c + *d < target) {
                        ++c;
                    } 
                    else if (*a + *b + *c + *d > target) 
                        --d;
                        else{
                        result.push_back({ *a, *b, *c, *d });
                        ++c;
                        --d;
                        }
                    }
                }
        }
        sort(result.begin(), result.end());   // vector排序?
        result.erase(unique(result.begin(), result.end()), result.end());  // unique()从输入序列中“删除”所有相邻的重复元素
        return result; // 把重复的元素移到后面去了，然后依然保存到了原数组中，然后 返回去重后最后一个元素的地址
        
  
  
  // method 2
  // average O(n^2)􅖌worst O(n^4) space O(n^2)
  vector<vector<int>> result;
  if (nums.size() < 4) return result;
  sort(nums.begin(), nums.end());
  unordered_multimap<int, pair<int, int>> cache;
  for (int i = 0; i + 1 < nums.size(); ++i)
	  for (int j = i + 1; j < nums.size(); ++j)
		  cache.insert(make_pair(nums[i] + nums[j], make_pair(i, j)));
  for (auto i = cache.begin(); i != cache.end(); ++i) {
	  int x = target - i->first;
	  auto range = cache.equal_range(x);
	  for (auto j = range.first; j != range.second; ++j) {
		  auto a = i->second.first;
		  auto b = i->second.second;
		  auto c = j->second.first;
		  auto d = j->second.second;
		  if (a != c && a != d && b != c && b != d) {       // a b c d 是序号
			  vector<int> vec = { nums[a], nums[b], nums[c], nums[d] };
			  sort(vec.begin(), vec.end());
			  result.push_back(vec);
		  }
	  }
  }
  sort(result.begin(), result.end());
  result.erase(unique(result.begin(), result.end()), result.end());
  return result;
}
