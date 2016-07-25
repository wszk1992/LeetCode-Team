    // solution 1
    string getPermutation(int n, int k) {
        string ans = "";
        int product = 1;
        for (int i = 1; i <= n; i++){
            product = i * product;
            ans += to_string(i);
        }
        for (int i = 0; i < n; i++){ 
            product /= n - i;
            int m=(k-1)/product+i, tmp=ans[m];  // if k<product, m=i
            for(int j=m;j>i;j--)
                ans[j]=ans[j-1];
            ans[i]=tmp;
            k= k%product ? k%product : product;
        }
        return ans;
    }
    
    // solution 2
    string getPermutation(int n, int k) {
        string ans = "";
        int i, j, t, sum, jie;
        jie = 1;
        for (i = 1; i <= n; i++){
            jie = i * jie;
            ans += to_string(i);
        }
        for (i = 0; i < n; i++){
            jie /= n - i;
            for (sum = 0, j = 1; j <= n; j++){
                if (sum + jie >= k) break;
                sum += jie;
                swap(ans[i], ans[i + j]);
            }
            k -= sum;
        }
        return ans;
    }
