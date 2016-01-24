public class Solution {
    public void rotate(int[] nums, int k) {
        // solution 1: use another array 
        // int [] temArray = new int[nums.length]();// compile error
        int [] temArray = new int[nums.length];
        for(int i =0;i<nums.length;i++)
        {
            temArray[(i+k)%nums.length]=nums[i];
        }
        for(int i=0;i<nums.length;i++)
        {
            nums[i]=temArray[i];
        }
        //return nums; // there is no return value
        //solution 2: somebody use api
        /*
        int n = nums.length;
        int[] newList = new int[n];
        if (n > 1) {
            k = k % n;
            System.arraycopy(nums, n - k, newList, 0, k);
            System.arraycopy(nums, 0, newList, k, n - k);
            System.arraycopy(newList, 0, nums, 0, n);
        */
    }
}