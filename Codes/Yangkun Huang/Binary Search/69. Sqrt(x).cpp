      // standard binary search method
      int mySqrt(int x) {
              if(!x)
                  return x;
              long i=1, j=0, k=0;
              while(i*i<x)  // here '=' or '<=' doesn't matter
                  i*=2;
              j=i/2;
              while(j<=i){    // the key here is '<=' not '<' need to set j<=i to check k and k+1
                  k=(i+j)/2;  
                  if(k*k==x)  // because if k*k>x next potential value could not be k+1, while k>x next potential value must be k+1
                      return k;
                  if(k*k>x)
                      i=k-1;
                  else
                      j=k+1;
              }
              return i;
      }
      
      // newton method
      int mySqrt(int x) {
          long r = x;
          while (r*r > x)
              r = (r + x/r) / 2;
          return r;
    }       
