    int addDigits(int num) {
        return num ? num%9==0 ? 9 : num%9 : 0;
    }
