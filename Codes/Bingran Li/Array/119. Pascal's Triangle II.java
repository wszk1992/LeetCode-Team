public class Solution {
    public List<Integer> getRow(int rowIndex) {
       
        /*
        1. you can use arrayList.set() to update value
        2. there is a formular
        row k of Pascal's Triangle: [C(k,0), C(k,1), ..., C(k, k-1), C(k, k)]
        and C[k,i] = C[k,i-1]*(k-i+1)/i
        3. your solution does not meet the space complexity requirement
        */
        ArrayList<Integer> myList = new ArrayList<Integer>();
        ArrayList<Integer> pList;
        int one = 1;
        myList.add(one);
        if(rowIndex==0){
            return myList;
        }
        myList.add(one);
        if(rowIndex==1){
            return myList;
        } 
        Solution mySolution = new Solution();
        pList = (ArrayList<Integer>)mySolution.getRow(rowIndex-1);
        myList.remove(1);
        for(int j=1;j<rowIndex;j++){
            int element;
            element = pList.get(j-1)+pList.get(j);
            myList.add(element);
        }
        myList.add(one);
        return myList;
    }
}