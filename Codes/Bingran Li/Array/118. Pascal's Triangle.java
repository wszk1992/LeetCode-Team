public class Solution {
    public List<List<Integer>> generate(int numRows) {
        // the idea is similar, but the expression is much simple
        /*
        List<List<Integer>> sol = new ArrayList<>();
        if (numRows == 0) return sol;

        List<Integer> row = new ArrayList<>();
        row.add(1);
        sol.add(row);

        for (int i = 1; i < numRows; i++) {
            List<Integer> r = new ArrayList<>();
            r.add(1);
            List<Integer> p = sol.get(i-1);    // get the previous line
            for (int j = 0; j < p.size()-1; j++) {
                r.add(p.get(j) + p.get(j+1));
            }
            r.add(1);
            sol.add(r);
        }        
        return sol;
        */
        
        
        ArrayList<List<Integer>> outerList = new ArrayList<List<Integer>>();
        ArrayList<Integer> innerList = new ArrayList<Integer>();
        if(numRows==0)
            return outerList;
        int one =1;
        innerList.add(one);// if i change innerList later, the value in outerList may change!! it may use pointer in add function, not copy the value(*****if it is an arrayList of list******)
        outerList.add(innerList);
        if(numRows==1){
            return outerList;
        }
        ArrayList<Integer> suckList = new ArrayList<Integer>();
        suckList.add(one);
        suckList.add(one);
        ArrayList<Integer> previousList;
        previousList = suckList;
        outerList.add(suckList);
        if(numRows==2){
            return outerList;
        }
        
        for(int i =3;i<=numRows;i++){
            ArrayList<Integer> currentList = new ArrayList<Integer>();
            currentList.add(one);
            for(int j=1;j<i-1;j++){
               int  element;
               element = previousList.get(j)+previousList.get(j-1);
               currentList.add(element);
            }
            currentList.add(one);
            previousList = currentList;
            outerList.add(currentList);
        }
        return outerList;
    }
}