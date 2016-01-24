public class Solution {
    public void moveZeroes(int[] nums) {
        //solution 1: almost o(n2)
        /*
        for(int i=0;i<nums.length;i++){
            if(nums[i]==0){
                for(int j=i;j<nums.length;j++){
                    if(nums[j]!=0){
                        nums[i]=nums[j];
                        nums[j]=0;
                        break;
                    }
                    if((j==nums.length-1)&&(nums[j]==0)) // adding this makes time even longer.....
                      return;
                }
            }
        }
        */
      //solution 2:
      int j=0;
      for(int i=0;i<nums.length;i++){
          if(nums[i]!=0){
              nums[j]=nums[i];
              j++;
          }
      }
      for(;j<nums.length;j++){
          nums[j]=0;
      }
    }
}