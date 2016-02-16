public class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        
        // my thought: O(n3),which is n2*n ----time limit exceed---use small trick to reduce some time, it really works(67%)
        Arrays.sort(nums);
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        HashSet <List<Integer>>mySet = new HashSet<List<Integer>>();
        int length = nums.length;
        
        for(int i=0;i<length-3;i++){
            if(nums[i]*4>target) // trick one
                break;
            for(int j=i+1;j<length-2;j++){
                int newTarget = target -nums[i]-nums[j];
                 List<List<Integer>> temResult = twoSum(nums,j+1,newTarget);
                 // fill the front part
                 while(!temResult.isEmpty()){// may use iterator
                     (temResult.get(0)).add(0,nums[j]);
                     (temResult.get(0)).add(0,nums[i]);
                      boolean b = mySet.add(temResult.get(0));
                    // result.add(temResult.get(0));
                     temResult.remove(0);
                 }
            }
        }
        Iterator <List<Integer>>myIter = mySet.iterator();
        while(myIter.hasNext()){
            result.add(myIter.next());
        }
        return result;
        
    }
    public List<List<Integer>> twoSum(int []nums,int startPoint,int target){
        
        HashMap <Integer,Integer> myMap = new HashMap <Integer,Integer> ();
        List<List<Integer>> temResult = new ArrayList<List<Integer>>();
        
        
        for(int i=startPoint;i<nums.length;i++){
            if(nums[nums.length-1]*2<target) break; // trick two
            if(nums[startPoint]*2>target) break;   
            int val = target - nums[i];
            if(myMap.containsKey(val)){
                List <Integer> myList = new ArrayList<Integer>();
                myList.add(val);
                myList.add(nums[i]);
                temResult.add(myList);
            }
           if(!myMap.containsKey(nums[i])) 
                myMap.put(nums[i],1);
           
                
        }   
         return temResult;
    }
    
    
}