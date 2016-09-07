    // the idea is using the bits of a single variable to records the letters appeared in each string
    // solution 1 vector
    int maxProduct(vector<string>& words) {
        vector<int> mask(words.size());     // the key here is the index of string
        int result = 0;
        for (int i=0; i<words.size(); ++i) {
            for (char c : words[i])   
                mask[i] |= 1 << (c - 'a');  // mask[i] records what letters words[i] contains
            for (int j=0; j<i; ++j)     
                if (!(mask[i] & mask[j]))  // words[i] and words[j] contains no identical letters
                    result = max(result, int(words[i].size() * words[j].size()));   // no bit of both masks is 1 at the same time
        }
        return result;
    }
    
    // solution 2 map
    int maxProduct(vector<string>& words) {
        unordered_map<int,int> maxlen;      // the key here is the int number which represents what letters appeared
        int result = 0;
        for (string word : words) {
            int mask = 0;
            for (char c : word)
                mask |= 1 << (c - 'a');
            maxlen[mask] = max(maxlen[mask], (int) word.size());
            for (auto maskAndLen : maxlen)
                if (!(mask & maskAndLen.first))
                    result = max(result, (int) word.size() * maskAndLen.second);
        }
        return result;
    }
