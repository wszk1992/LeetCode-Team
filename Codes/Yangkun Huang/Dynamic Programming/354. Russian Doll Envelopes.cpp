    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        vector<pair<int, int>>::iterator iter;
        pair<int, int> j;
        int product=0, index=0;
        for(int i=0;i<envelopes.size();i++){
            int p=envelopes[i].first*envelopes[i].second;
            if(p>product){
                product=p;
                index=i;
            }
        }
        cout<<index<<endl;
        // for auto does not use iterator, use same basic type
        // for(auto i:envelopes){
        //     int p=i.first*i.second;
        //     if(product<i.first*i.second){
        //         product=i.first*i.second;
        //         // iter=i;
        //         j=i;
        //     }    
        // }
        return product;
    }
