      // very classic problem
      int findMin(vector<int>& num) {
        int start=0,end=num.size()-1;
        while (start<end) {           
            if (num[start]<num[end])  // the key is: if rotated, the first element must be less than the last
                return num[start];
            
            int mid = (start+end)/2;
            
            if (num[mid]>=num[start])   // [start, mid] is increasing, minimum locates after mid
                start = mid+1;
            else 
                end = mid;              // [start, mid] is concave
        }
        
        return num[start];
    }
