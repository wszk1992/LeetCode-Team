vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // method 1
        // ������Ȼ�����Ҽб�
        // time complexity O(n^3) space complexity O(1)
        vector<vector<int>> result;
        if (nums.size() < 4) 
        return result;
        sort(nums.begin(), nums.end());
        auto last = nums.end();
        for (auto a = nums.begin(); a < prev(last, 3); ++a) { // prev֮ǰ3��λ��
            for (auto b = next(a); b < prev(last, 2); ++b) {  // next(b)b����һ��λ��
                auto c = next(b);
                auto d = prev(last);                          // lastǰһ��λ��
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
        sort(result.begin(), result.end());   // vector����?
        result.erase(unique(result.begin(), result.end()), result.end());  // unique()�����������С�ɾ�����������ڵ��ظ�Ԫ��
        return result; // ���ظ���Ԫ���Ƶ�����ȥ�ˣ�Ȼ����Ȼ���浽��ԭ�����У�Ȼ�� ����ȥ�غ����һ��Ԫ�صĵ�ַ//
        }
  
  
  // method 2  
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
if (a != c && a != d && b != c && b != d) {
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