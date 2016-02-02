public class Solution {
    public String getHint(String secret, String guess) {
        
        // solution 1: algorithm is not good, did not figure out better way--->"DAN TENG"---24%
        
        // do NOT need HASHMAP, we can use ARRAY[10] to calculate the sum of numbers!!!!
       /*
        bulls = 0;
        int cows = 0;
        HashMap <Character, Integer> myMap = new HashMap <Character, Integer>();
        
        for(int i =0;i<secret.length();i++){
            if(secret.charAt(i)==guess.charAt(i)){
                bulls++;
            }
            else{
                if(myMap.containsKey(secret.charAt(i))){
                    myMap.put(secret.charAt(i),myMap.get(secret.charAt(i))+1);
                }
                else{
                    myMap.put(secret.charAt(i),1); // used to be 0
                }
               
            }
        }
        // check guess list
        for(int i =0;i<guess.length();i++){
            if(secret.charAt(i)==guess.charAt(i))
                continue;
            else if(myMap.containsKey(guess.charAt(i)) && myMap.get(guess.charAt(i))>0){
                cows++;
                myMap.put(guess.charAt(i),myMap.get(guess.charAt(i))-1); 
            }
        }
        
        String myString = Integer.toString(bulls)+"A"+Integer.toString(cows)+"B";
        return myString;
        
        */
        // solution 2: it is much clear and elegant
        
        int [] s= new int[10];
        int [] g= new int[10];
        int bulls=0;
        int cows=0;
        
        for(int i=0;i<secret.length();i++){
            if(secret.charAt(i)==guess.charAt(i))
                bulls++;
            else{
                s[secret.charAt(i)-'0']++;
                g[guess.charAt(i)-'0']++;
            }
        }
        for(int i=0;i<10;i++){
            cows+=Math.min(s[i],g[i]);
        }
        
        
        
        String myString = Integer.toString(bulls)+"A"+Integer.toString(cows)+"B";
        return myString;
    }
}