public class Solution {
    public int majorityElement(int[] nums) {
        // no good idea,my original idea is using quicksort 
        // but there is an api for sorting
        // solution 1: somebody's idea------>38% (not very fast)
        /*
        Arrays.sort(nums);
        return nums[nums.length/2];
        */
        // solution 2: hashmap---------> it is more slower
        /*
        HashMap<Integer, Integer> myMap = new HashMap<Integer, Integer>();
        for(int num:nums){
            if(myMap.get(num)==null){
                myMap.put(num,1);
            }
            else{
                myMap.put(num,myMap.get(num)+1);
            }
            if(myMap.get(num)>nums.length/2){
                return num;
            }
        }
        return 0;
      */
      // solution 3: morre voting algorithm
      int majCandi=nums[0],count=1;
      for(int i=1;i<nums.length;i++){
          if(nums[i]==majCandi)
            count++;
          else
            count--;
          if(count==0){
              majCandi=nums[i+1];
              i++;
              count=1;
          }
      }
      // omit checking part
      return majCandi;
      
      
    }
}