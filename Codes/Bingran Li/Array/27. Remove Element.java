public class Solution {
    public int removeElement(int[] nums, int val) {
        
        // solution 2: this guy's thought is a little similar with my original thought, but much simpler
        // changing the rear makes me confusing
        int lastIndex = nums.length - 1;
        for(int i =0;i<lastIndex+1;i++)
        {
            if(nums[i]==val)
            {
                nums[i]=nums[lastIndex];
                lastIndex--;
                i--;
            }
        }
        return lastIndex+1;
  
        // solution 1: transfer it to arrayList--waste too much time
       
       /* ArrayList<Integer> myList = new ArrayList<Integer>();
        for(int i = 0;i<nums.length;i++)
        {
            myList.add(nums[i]);
        }
        for(int i=0;i<myList.size();)
        {
            if((int)myList.get(i)==val)
            {
                myList.remove(i);
            }
            else
            i++;
        }
       for(int i=0;i<myList.size();i++)
       {
           nums[i]=(int)myList.get(i);
       }
        return myList.size();
        */
        
    }
}