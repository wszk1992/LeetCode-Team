class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if(edges.empty()) {
            return vector<int>(1, 0);
        }
        vector<int> res;
        int minHeight = n;
        vector<vector<int>> next(n, vector<int>());
        for(auto edge : edges) {
            next[edge.first].push_back(edge.second);
            next[edge.second].push_back(edge.first);
        }
        unordered_set<int> set;
        vector<int> maxTrace;
        vector<int> trace(1, 0);
        int maxLen = 0;
        set.insert(0);
        dfs(next, maxTrace, trace, set, maxLen, 0);
        trace = vector<int>(1, maxTrace.back());
        set.clear();
        set.insert(maxTrace.back());
        dfs(next, maxTrace, trace, set, maxLen, maxTrace.back());
        if(maxTrace.size() % 2 == 0) {
            res.push_back(maxTrace[maxTrace.size() / 2 - 1]);
        }
        res.push_back(maxTrace[maxTrace.size() / 2]);
        return res;
    }
    
    void dfs(vector<vector<int>>& next, vector<int>& maxTrace, vector<int>& trace, unordered_set<int>& set, int& maxLen, int label) {
        int num = 0;
        for(auto nextLabel : next[label]) {
            if(!set.count(nextLabel)) {
                num++;
                set.insert(nextLabel);
                trace.push_back(nextLabel);
                dfs(next, maxTrace, trace, set, maxLen, nextLabel);
                trace.pop_back();
                set.erase(nextLabel);
            }
        }
        if(num == 0 && trace.size() > maxLen) {
            maxLen = trace.size();
            maxTrace = trace;
        }
    }
};