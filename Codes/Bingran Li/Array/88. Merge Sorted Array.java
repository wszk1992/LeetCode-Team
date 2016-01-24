public class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        
        // solution 2: solving from the end to avoid extra moving
        int i=m-1,j=n-1;
        for(int k=m+n-1;k>=0;k--){
            
            if(i<0){
                for(;j>=0;j--){
                    nums1[k]=nums2[j];
                    k--;// miss this line--->bug
                }
                return;
            }
            if(j<0){
                return;
            }
            if(nums1[i]<=nums2[j]){
                nums1[k]=nums2[j];
                j--;
            }
            else{
                nums1[k]=nums1[i];
                i--;
            }
        }
        
        //solution 1: need a third nums, involving moving a lot
       /*
        int[] nums3 = new int[m+n];
        int i=0,j=0,k=0;
        while(k<m+n){
            if(i==m){
                for(;j<n;j++){
                    nums3[k]=nums2[j];
                    k++;
                }
                break;
            }
            if(j==n){ // error happends because of lacking check
                for(;i<m;i++){
                    nums3[k]=nums1[i];
                    k++;
                }
                break;
            }
            if(nums1[i]<=nums2[j]){
                nums3[k]=nums1[i];
                i++;
                k++;
            }
            if(nums1[i]>nums2[j]){// misspelling i--->1 
                nums3[k]=nums2[j];
                j++;
                k++;
            }
        }
        //copy element from array nums3 to nums1
        for(int p=0;p<m+n;p++){
            nums1[p]=nums3[p];
        }
        
      */  
    }
    
}