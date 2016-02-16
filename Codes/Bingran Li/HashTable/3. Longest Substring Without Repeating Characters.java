public class Solution {
    public int lengthOfLongestSubstring(String s) {
        
        // solution 1: divide & conque----> nlgn
        
        // solution 3: good dp
        if(s.length()<=1) return s.length();
        
        char [] myArray = s.toCharArray();
        int [] result = new int[myArray.length];
        int [] check = new int[128];
        int max;
        
        for(int i=0;i<check.length;i++){
            check[i]=-1;
        }
        
        result[0]=1;
        check[myArray[0]]=0;
        max=result[0];
        int back=0;
        
        for(int i=1;i<myArray.length;i++){
            int combine;
            if(check[myArray[i]]==-1){
                check[myArray[i]]=i;
                combine = i-back+1;
        
            }
            else{
                combine  = i-check[myArray[i]];
                int sameP = check[myArray[i]];
                for(int m=back;m<=sameP;m++){
                    check[myArray[m]]= -1;
                }
                check[myArray[i]]=i; //**bug** update the same element index
                back = sameP+1;
            }
            result[i]=Math.max(result[i-1],combine);
            if(result[i]>max) max=result[i];
        }
        
        return max;
        // solution 2: "bad" dp with hashmap, can't believe it works(76%), it think the worst case is n2
        /*
        if(s.length()<=1) return s.length();
        
        char [] myArray = s.toCharArray();
        int [] result = new int [myArray.length+1];
        result [1]=1;
        int max = result[1];
        for(int i=1;i<myArray.length;i++){
            boolean [] map = new boolean[128];
            int count=0;
            // if I use this part, no need to use dp
            for(int m=i;m>=0;m--){
                if(map[myArray[m]]==false) {
                    map[myArray[m]]=true;
                    count++;
                }
                else{
                    break;
                }
            }
            int hasLast = count;
            result[i+1]= Math.max(result[i],hasLast);
            if(result[i+1]>max) max=result[i+1];
        }
        return max;
        */
    }
    
}