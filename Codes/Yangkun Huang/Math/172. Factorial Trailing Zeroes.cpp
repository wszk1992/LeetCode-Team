      // all trailing 0 is from factors 5 * 2
      // and number of factor 2 is more than number of factor 5
      // calculate number of 5 and exponentials of 5 from 1 to n
      // use division rather than multyply can avoid overflow
      int trailingZeroes(int n) {
          return n < 5 ? 0 : n / 5 + trailingZeroes(n / 5);
      }
