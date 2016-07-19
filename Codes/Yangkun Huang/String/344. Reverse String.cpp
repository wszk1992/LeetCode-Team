      string reverseString(string s) {
        string::iterator head=s.begin(), tail=s.end()-1;
        int i=1;
        while(i<=s.size()/2){
            swap(*head, *tail);
            head++;
            tail--;
            i++;
        }
        return s;
    }
    
    string reverseString(string s) {
        string::iterator head=s.begin(), tail=s.end()-1;
        while(head<tail){
            swap(*head, *tail);
            head++;
            tail--;
        }
        return s;
    }    
    
