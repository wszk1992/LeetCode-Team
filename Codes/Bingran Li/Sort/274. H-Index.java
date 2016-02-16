public class Solution {
    public int hIndex(int[] citations) {
        
         // solution 2: O(n) 
        
        int l = citations.length;
        // the core of preparation is similar, but this way is more clear and elegant
        int [] array = new int [l+1];
        for(int i=0;i<l;i++){
            if(citations[i]>=l) array[l]++;
            else array[citations[i]]++;
        }
        int max = 0;
        for(int i=array.length-1;i>=0;i--){
            max = max + array[i];
            if(max>=i) return i;
        }
        return 0;
        
        
        
        // solution 1: sort, then compare from the back---- O(nlgn),no extra space---slow
        /*
        if(citations.length==0) return 0;
        
        Arrays.sort(citations);
        
        for(int i=citations.length-1,lastNum=0;i>=0;i--){
     
            if(i==0 || citations[i]!=citations[i-1]){
                int num = citations.length-i;
                if(num>=citations[i]){
                     return Math.max(citations[i],lastNum);
                }
               lastNum = num;
            }
        }
        
        return citations.length;
        */
    }
}