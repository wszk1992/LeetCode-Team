public class Solution {
    public boolean containsDuplicate(int[] nums) {
        /*
        // the input is array nums, output is a boolean
        boolean isDuplicate = false;
        // get the size of array 
        int count =nums.length;
        int i,j;
        // time complexity is n2
        for (i=0;i<count-1;i++)
          for (j=i+1;j<count;j++)
          {
            if(nums[i]==nums[j])
            {
                isDuplicate = true;
                return isDuplicate;
            }
          }
        return isDuplicate;
        */
        HashSet <Integer> numSet = new HashSet <Integer>();
        for (int i=0;i<nums.length;i++)
            if(!numSet.add(nums[i]))
            return true;
        return false;
    }
}