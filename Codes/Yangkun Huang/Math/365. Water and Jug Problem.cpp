    // ax + by = d where d = gcd(x, y)
    // check if z%d==0
    bool canMeasureWater(int x, int y, int z) {
        return z == 0 || (z - x <= y && z % gcd(x, y) == 0);
    }
    int gcd(int a, int b){
        return a % b == 0 ? b : gcd(b, a % b);
    }
