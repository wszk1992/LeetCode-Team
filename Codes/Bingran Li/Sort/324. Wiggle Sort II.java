public class Solution {
    public void wiggleSort(int[] nums) {
        // follow up: use quick selection and meet the time requirement
        
        // my thought: sort and then assign values of front part to 0th,2th....back part to 1th,3th-----> it is wrong
        // modified solution: put the middle apart--->at two ends
        
        Arrays.sort(nums); // static method, miss "Arrays"
        int l = nums.length;
        int temArray []= new int[l] ;
        for(int i=(l-1)/2,m=0;i>=0;i--,m=m+2){
            temArray[m] = nums[i]; // miss "*" 
        }
        for(int i=l-1,m=1;i>(l-1)/2;i--,m=m+2){
            temArray[m] = nums[i];
        }
        for(int i=0;i<l;i++){
            nums[i] = temArray[i];
        }
        
    }
}