    // recursive + random method
    int guessNumber(int n) {
        return guessNumber(1, n);
    }
    int guessNumber(int low, int high) {
        int range=high-low+1;
        int myGuess=(rand()%range)+low;
        if(guess(myGuess)==0)
            return myGuess;
        if(guess(myGuess)==-1)
            return guessNumber(low,myGuess-1);
        else
            return guessNumber(myGuess+1,high);
    }


    // standard binary search
    // initial value of low and high don't matter
    int guessNumber(int n) {
        int low = 1, high = n, mid = low;
        while (low < high){
            mid = low + (high - low)/2;
            if (guess(mid) == 0)
                return mid;
            if (guess(mid) == 1)
                low = mid+1;
            else
                high = mid-1;
        }
        return low; // return high also ok but cannot return mid
    }
    
    // merge > and =
    int guessNumber(int n) {
        int low = 0, high = n, mid = low;
        while (low < high){
            mid = low + rand()%(high - low);
            if (guess(mid) <= 0)
                high = mid;
            else
                low = mid+1;
            
        }
        return high;
    }
