    // solution 1 heap
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> res;
        priority_queue<pair<int, int>> liveBlg;
        int cur=0, leftpos=0, height=0, len=buildings.size();
        while(cur<len || !liveBlg.empty()){
            if(liveBlg.empty() || cur<len && buildings[cur][0]<=liveBlg.top().second){
                leftpos=buildings[cur][0];
                while(cur<len && buildings[cur][0]==leftpos){
                    liveBlg.push(make_pair(buildings[cur][2], buildings[cur][1]));
                    cur++;
                }
            }
            else{
                leftpos=liveBlg.top().second;
                while(!liveBlg.empty() && liveBlg.top().second<=leftpos)
                    liveBlg.pop();
            }
            height= liveBlg.empty() ? 0 : liveBlg.top().first;
            if(res.empty() || height!=res.back().second)
                res.push_back(make_pair(leftpos, height));
        }
        return res;
    }
