    // for the whole tree, the number of null nodes is always the number of actual nodes plus 1
    // if it were not the end of string, the number of '#' would have not exceed the number of nodes
    bool isValidSerialization(string preorder) {
        int nulls=0, nodes=0;
        auto iter=preorder.begin();
        for(;iter!=preorder.end();iter++)  // need to split string by ','
            if(*iter==','){
                *(iter-1)=='#' ? nulls++ : nodes++;
                if(nulls>nodes)
                    return false;
            }
        return nulls==nodes && *(iter-1)=='#';
    }
