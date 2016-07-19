    string reverseVowels(string s) {
        string::iterator head=s.begin(), tail=s.end()-1;
        string vowels="aeiouAEIOU";
        while(head<tail){
            while(vowels.find(*head)==string::npos && head< tail)
                head++;
            while(vowels.find(*tail)==string::npos && head< tail)
                tail--;
            swap(*head, *tail);
            head++;
            tail--;
        }
        return s;
    }
