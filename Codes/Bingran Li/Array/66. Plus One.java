public class Solution {
    public int[] plusOne(int[] digits) {
        // somebody's incisive thought
        for(int i=digits.length-1;i>-1;i--)
        {
            if(digits[i]!=9)
            {
                digits[i]++;
                return digits;
            }
            digits[i]=0;
        }
        int [] myDigits = new int[digits.length+1];
        myDigits[0]=1;
        return myDigits;
    }
}