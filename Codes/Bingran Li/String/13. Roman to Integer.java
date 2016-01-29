public class Solution {
    public int romanToInt(String s) {
        // solution 1----->69%
        char [] myChar = s.toCharArray();
        int sum=0;
        for(int i=0;i<myChar.length;i++){
            if(i==myChar.length-1){ // mis "="
                sum=sum+hash(myChar[i]);
                break;
            }
            if(hash(myChar[i])<hash(myChar[i+1])){
                sum = sum-hash(myChar[i]);
            }
            else{
                sum=sum+hash(myChar[i]);
            }
        }
        
        return sum;
    }
    
    public int hash(char myChar){
        if(myChar=='M')  return 1000;
        if(myChar=='D')  return 500;
        if(myChar=='C')  return 100;
        if(myChar=='L')  return 50;
        if(myChar=='X')  return 10;
        if(myChar=='V')  return 5;
        if(myChar=='I')  return 1;
        
        return 0;
    }
    
    
}