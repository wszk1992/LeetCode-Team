public class Solution {
    public String addBinary(String a, String b) {
        
        // solution 1 : beat 91%
        String A = "0" + a;
        String B = "0" + b;
        char [] shortArray; 
        char [] longArray;
        int maxLength;
        if(A.length()<B.length()){
            shortArray =  A.toCharArray();
            longArray = B.toCharArray();
            maxLength = B.length();
        }
        else{
            shortArray =  B.toCharArray();
            longArray = A.toCharArray();
            maxLength = A.length();
        }
        
        char [] myArray = new char[maxLength];
        int i = shortArray.length-1;
        int j = longArray.length-1;
        int m = longArray.length-1;
        while(j>-1){
            
            if(shortArray[i]+longArray[j] == 96){ // ASCII code, there are char
                myArray[m]= '0';
            }
            else if(shortArray[i]+longArray[j] == 97){
                myArray[m]='1';
            }
            else if(shortArray[i]+longArray[j] == 98){
                myArray[m]='0';
                longArray[j-1]++;
            }
            else{
                myArray[m]='1';
                longArray[j-1]++;
            }
            m--;
            j--;
            // if the short come to an end
            if(i!=0){
                i--;
            }
            
        }
        
        String myString = new String(myArray);
        if(myArray[0]=='0'){
            return myString.substring(1);
        }
        else{
            return myString;
        }
        
        
    }
}