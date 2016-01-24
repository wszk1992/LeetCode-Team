public class Solution {
    public int removeDuplicates(int[] nums) {
      
      // somebody's idea: we only care about the new item
      int iterator=1;
      int currentIndex=0;
      for(;iterator<nums.length;iterator++)
      {
          if(nums[currentIndex]!=nums[iterator])
           {
               currentIndex++;
               nums[currentIndex]=nums[iterator];
           }
      }
      return currentIndex +1;
      // my solution
      /*
      int mark = nums[0]-1;
       int i=0;
       int sum=0;
       // mark all duplicated position
       while(i<nums.length)
       {
           int j=i+1;
           while(nums[j]==nums[i])
            {
                j++;
                nums[j]=mark;
                sum++;
            }
           i=j;
       }
      // move elements,trying to ..............but seems awkward
      
    
      // return length
        return nums.length-sum;
        */
    }
}