public class Solution {
    public void sortColors(int[] nums) {
        // solution 1: two pass algorithm---counting sort!
        /*
        int count0=0,count1=0,count2=0;
        for(int i:nums){
            if(i==0) count0++;
            if(i==1) count1++;
            if(i==2) count2++;
        }
        for(int i=0;i<nums.length;i++){
            if(i<count0)     nums[i]=0;
            else if(i<count1+count0) nums[i] = 1;
            else nums[i]=2;
        }
        */
        // solution 2: one pass algorithm----trickey
        
        int second =nums.length-1;
        int zero = 0;
        for(int i=0;i<=second;i++){
             
            while(nums[i]==2 && i<second ){
                int tem = nums[second];
                nums[second] = 2;
                nums[i] = tem;
                second--;
            }
            while(nums[i]==0 && i>zero ){
                int tem=nums[zero];
                nums[zero]=0;
                nums[i]=tem;
                zero++;
            }
           
        }
            
        
        
    }
}