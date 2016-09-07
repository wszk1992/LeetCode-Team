    // Bulb i is switched in round d if and only if d divides i. 
    // So bulb i ends up on if and only if it has an odd number of divisors.
    // Divisors come in pairs, except when i is a square. 
    // So bulb i ends up on if and only if i is a square.
    // So just count the square numbers in the range [1,n]. 
    int bulbSwitch(int n) {
        return sqrt(n);
    }
