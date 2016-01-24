public class Solution {
    public List<String> summaryRanges(int[] nums) {
        
        /*
        
      List<String> list = new ArrayList<>();
      int n = nums.length;
      for(int i = 0, j = 1; j <= n; j++){
        if(j == n || nums[j] > nums[j-1] + 1){
          list.add(Integer.toString(nums[i]) + (i == j-1 ? "" : "->" + Integer.toString(nums[j-1])));
          i = j;
        }
      }
      return list;
        
        
        */
        
        List myList = new ArrayList();
        // then add new elements to myList
        int counter=0;
        int i=0;
        String myString;
        while(i<nums.length) // used to be true
        {
            // i moves to the end of the array
           if(i==nums.length-1)
           {
               if (counter == 0)
               {
                    myList.add(Integer.toString(nums[i]));
               }
               else
               {
                  myString = Integer.toString(nums[i]-counter) + "->" + Integer.toString(nums[i]);
                  myList.add(myString);
               }
               return myList; // used to be break; it work well on my pc ..... 
           }
           else if (nums[i]!=nums[i+1]-1) // here is the bug!!
           {
               // if there is only one element
              if (counter == 0)
              {
                  // add this element, first convert to string
                  myList.add(Integer.toString(nums[i]));
              }
              // there is more than one element
              else
              {
                  myString = Integer.toString(nums[i]-counter) + "->" + Integer.toString(nums[i]);
                  myList.add(myString);
              }
              counter = 0;
              i++;
           }
           //else just move i forward and add counter
           else
           {
            counter++;
             i++;   
           }
             
        }
        return myList;
    }
}