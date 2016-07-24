    // (4^n-1) = (4-1) (4^(n-1) + 4^(n-2) + 4^(n-3) + ..... + 4 + 1) which is divisible by 3
    bool isPowerOfFour(int num) {
        return num > 0 && (num & (num - 1)) == 0 && (num - 1) % 3 == 0;
    }
