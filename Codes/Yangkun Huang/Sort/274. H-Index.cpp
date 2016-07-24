
  // O(nlogn)
  // suppose all papers match the requirement at first, then papre from low to high, h-index from high to low
  int hIndex(vector<int>& citations) {
        int count=0;
        int h_index=citations.size();
        sort(citations.begin(),citations.end());
        for(vector<int>::iterator i=citations.begin();i!=citations.end();i++)
          if(*i<h_index)   // can use binary search here
            h_index--;
          else
            break;
        return h_index;
    }

  // O(n)
  int hIndex(vector<int>& citations) {
      if(citations.empty())
          return 0;
      int n = citations.size();
      vector<int> hash(n + 1, 0);
      for(int i = 0; i < n; ++i){
          if(citations[i] >= n)
              hash[n]++;            // numbers of int larger than n
          else
              hash[citations[i]]++; // numbers of int larger than citations[i]
      }
      int cita_of_paper = 0;
      for(int paper = n; paper >= 0; --paper){    // largerst numbers of int 
          cita_of_paper += hash[paper];           // has[i] means the numbers of paper which has citations larger than i
          if(cita_of_paper >= paper)               
              return paper;
      }
  }
