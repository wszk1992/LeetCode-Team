public class Solution {
    public int[] twoSum(int[] nums, int target) {
        // the value is the index of key
        HashMap<Integer, Integer> myMap = new HashMap<Integer,Integer>();
        int []result = new int[2];
        
        for(int i=0;i<nums.length;i++){
            if(myMap.containsKey(target-nums[i])){
                result[1]=i+1;
                result[0]=myMap.get(target-nums[i]);
                return result; // miss return, waste time
            }
            else
                myMap.put(nums[i],i+1);
        }
        return result;
    }
}