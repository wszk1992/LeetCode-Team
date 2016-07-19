    int hIndex(vector<int>& citations) {
        int n=citations.size();
        int low=0, high=n;
        while(low<high){
            int mid = (low+high)/2;
            if(citations[mid]>=n-mid) // n-mid means number of elements prior to [mid]
                high=mid;
            else
                low=mid+1;
        }
        return n-low;
    }
