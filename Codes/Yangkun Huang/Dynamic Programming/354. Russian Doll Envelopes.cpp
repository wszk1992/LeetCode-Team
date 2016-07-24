    // the key is to sort envolopes by the first element of each pair
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int size = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [](pair<int, int> a, pair<int, int>b){
            return a.first<b.first || (a.first==b.first && a.second>b.second);
        });
        vector<int> collector;
        for(auto& i: envelopes){
            auto iter = lower_bound(collector.begin(), collector.end(), i.second);
            if(iter == collector.end()) // all elements in collector are smaller than i.second
                collector.push_back(i.second);
            else // if(*iter > i.second) still ac without this if clause
                *iter = i.second;
        }
        return collector.size();
    }
    
    int maxEnvelopes(vector<pair<int, int>>& envelopes) 
    {
        int size = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [](pair<int, int> a, pair<int, int>b){
            return a.first<b.first || (a.first==b.first && a.second>b.second);
        });
        for(auto j:envelopes)
            cout<<j.second<<endl;
        vector<int> collector;
        for(auto& pair: envelopes)
        {
            auto iter = lower_bound(collector.begin(), collector.end(), pair.second);
            if(iter == collector.end()) {cout<<" "<<pair.second<<" ff<"<<endl;
                collector.push_back(pair.second);}
            else {cout<<*iter<<" dd"<<endl;
                *iter = pair.second;}
        }
        for (auto i:collector)
            cout<<i<<endl;
        return collector.size();
    }
