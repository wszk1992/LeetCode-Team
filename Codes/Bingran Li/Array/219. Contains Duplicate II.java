public class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        // solution 1: O(n2) time exceed
        /*
        for(int i=0;i<nums.length;i++){
            for(int j=i+1;(j<=i+k)&&(j<nums.length);j++){
                if(nums[i]==nums[j])
                    return true;
            }
        }
       return false; 
    }
    */
    // solution 2:
    HashMap<Integer, Integer> myMap = new HashMap<Integer, Integer>();
    for(int i=0;i<nums.length;i++){
        if((myMap.containsKey(nums[i]))&&(i<=k+myMap.get(nums[i])))
                return true;
        else
            myMap.put(nums[i],i);
    }
    return false;
    }
}