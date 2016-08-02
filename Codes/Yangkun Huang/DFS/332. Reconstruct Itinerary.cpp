    // how to represent the graph
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        map<string, multiset<string>> graph;
        vector<string> route;        
        for(auto t:tickets)
            graph[t.first].insert(t.second); // second -> first
        findItinerary(route, graph, "JFK");
        reverse(route.begin(), route.end());
        return route;
    }
    
    void findItinerary(vector<string>& route, map<string, multiset<string>>& graph, string depart){
        while(graph[depart].size()){
            string next=*graph[depart].begin(); // since multiset has already been ordered, begin() is the string with smallest lexical order
            graph[depart].erase(graph[depart].begin());   // erase from multiset -- remove edge
            findItinerary(route, graph, next);
        }
        route.push_back(depart);// route.push_back(next);
    }
    
    // string findSmallestLexical(multiset<string>& arrive){   // useless since multiset has already been ordered
    //     if(!arrive.empty()){
    //         string smallestLexical=*arrive.begin();
    //         for(auto iter:arrive){
    //             for(int i=0;i<3;i++)
    //                 if(smallestLexical[i]>iter[i])
    //                     smallestLexical=iter;
    //                 else
    //                     break;
    //         }
    //         return smallestLexical;
    //     }
    //     return "";
    // }
