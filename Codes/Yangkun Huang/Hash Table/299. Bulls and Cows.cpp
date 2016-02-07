string getHint(string secret, string guess) {
          int cntA = 0, cntB = 0;
          unordered_map<char, int> hash;
        vector<bool> tag(secret.size(), false);
         for (auto a : secret) {
            ++hash[a];
          };
         for (int i = 0; i < secret.size(); ++i) {
             if (secret[i] == guess[i]) {
                 ++cntA;
                --hash[secret[i]];
                tag[i] = true;
            }
         }
        for (int i = 0; i < guess.size(); ++i) {
            if (!tag[i] && hash[guess[i]] > 0) {
                ++cntB;
                --hash[guess[i]];
             }
         }
         return to_string(cntA) + "A" + to_string(cntB) + "B";
     } 