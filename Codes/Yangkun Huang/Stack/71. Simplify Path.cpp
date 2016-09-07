    // 1. c++ can use stringstream and getline as string split in java and python
    // 2. stack and queue can only be traversed once
    // solution 1
    string simplifyPath(string path) {
        deque<string> stk;
        string res, tmp;
        stringstream ss(path);
        while(getline(ss,tmp,'/')) {
            if (tmp == "" or tmp == ".") continue;
            if (tmp == ".." and !stk.empty()) stk.pop_back();
            else if (tmp != "..") stk.push_back(tmp);
        }
        while(!stk.empty()){  
            res += "/"+stk.front();
            stk.pop_front();
        }
        return res.empty() ? "/" : res;
    }
    
    // solution 2 O(1) space
    // relative pos of i and j
    string simplifyPath(string path) {
        int i = 0;
        for (int j = 1; j < path.length(); j++){
            if (path[i] != '/'){    // i is searching for a '/' and stop to check the following chars
                path[++i] = path[j];
            }
            else if (path[j] != '.'){   // j keeps one or two steps further than i
                if (path[j] != '/')
                    path[++i] = path[j];
            }
            else if (j + 1 == path.length() || path[j + 1] == '/'){ // path[j]=='.' skip '/.'
                j++;
            }
            else if (path[j + 1] == '.' && (j + 2 == path.length() || path[j + 2] == '/')){ // path[j, j+1, j+2]=='../'
                if (i)
                    i = path.rfind('/', i - 1);     // if meet '/..' go back and skip substr after last '/'
                j += 2;
            }
            else{   // no '/' and '.' just copy
                path[++i] = path[j];
            }
        }
        if (path[i] != '/' || i == 0)       // i should reach path.size()
            i++;
        return path.substr(0, i);
    }
