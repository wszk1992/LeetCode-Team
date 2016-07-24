    // first version
    // O(n) time 
    string convert(string s, int numRows) {
        vector<vector<char>> v(numRows);
        bool isEven=false;
        for(int i=0;i<s.size();){
            if(!isEven){
                for(int j=0;j<numRows && i<s.size();j++)
                    v[j].push_back(s[i++]);
            }
            else{
                for(int j=numRows-2;j>0 && i<s.size();j--)
                    v[j].push_back(s[i++]);
            }
            isEven=!isEven;
        }
        string res;
        for(auto c:v){
            for(auto a:c)
                res+=a;
        }
        return res;
    }
    
    // second version 
    // O(n) time
    string convert(string s, int numRows) {
        vector<string> v(numRows);
        bool isEven=false;
        for(int i=0;i<s.size();){
            if(!isEven){
                for(int j=0;j<numRows && i<s.size();j++)
                    v[j]+=s[i++];
            }
            else{
                for(int j=numRows-2;j>0 && i<s.size();j--)
                    v[j]+=s[i++];
            }
            isEven=!isEven;
        }
        string res;
        for(auto c:v){
            res+=c;
        }
        return res;
    }
    
    // fastest version
    // O(n) time
    string convert(string s, int numRows) {
        string result = "";
        
        // simple cases that could be inferred easily
        if (s.size() <= numRows || numRows == 1) return s;
        
        // colIndex represents the "straight column" index (PAY or ALI in the example)
        int colIndex = 0;
        
        // append result row by row
        for (int i = 0; i < numRows; i++) {
            
            // for each row, the first character is in the ith position of s;
            result += s[i];
            
            // 2*numRows - 2 is the increment amount between two straight columns
            // i is the current location in this column
            // so colIndex is now the position of character of the same position in the next "straight column"
            colIndex = i + 2*numRows - 2;
            
            // 2*numRows - 2 - i is the position of the character in the "tilted column" (P or S or I in the example)
            // use colIndex - 2 * i (same value) because we need to increment this value every time
            // while there is still character in the "tilted column":
            while (colIndex - 2 * i < s.size()) {
                
                // if it is the first or the last row, tilted column overlaps the straight column, ignore!
                if (i != 0 && i != numRows - 1) {
                    // first: append the character in the tilted column
                    result += s[colIndex - 2 * i];
                }
                // in the first line and the last line, neighbor element differ in 2*numRows-2 positions
                // while in other line neighbor elements differ in colIndex-3i(to left) and 2i(to right)
                
                // second: append the character in the straight column in the same row only if this position exists
                if (colIndex < s.size()) {
                    result += s[colIndex];
                }
                
                // increment colIndex to the next column
                colIndex += 2*numRows - 2;
            }
        }
        return result;
    }
