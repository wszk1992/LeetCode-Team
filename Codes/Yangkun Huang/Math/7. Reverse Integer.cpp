    // m%(-n) is equal to m%n,  and (-m)%n is equal to -(m%n)
    // pow( ) return float or double
    // how to solve overflow
    // 1. use long long 2. compare old res and new res
    int reverse(int x) {
        int count=-1;
        int res=0;
        queue<int> q;
        while(x){
            q.push(x%10);
            x/=10;
            count++;
        }
        while(!q.empty()){
            int tmp=res;
            double d=q.front()*pow(10, count);
            res+=d;
            if(res-d!=tmp)
                return 0;
            q.pop();
            count--;
        }
        return res;
    }
    
    
    // a better solution
    int reverse(int x) {
        long long res = 0;
        while(x) {
            res = res*10 + x%10;
            x /= 10;
        }
        return (res<INT_MIN || res>INT_MAX) ? 0 : res;
    }
