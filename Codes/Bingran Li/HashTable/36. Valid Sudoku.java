public class Solution {
    public boolean isValidSudoku(char[][] board) {
    
    // my solution -----92%
    boolean isValid=true;   
    // check row
    
    for(int i=0;i<9;i++){
        isValid = isValid(board[i]);
        if(!isValid)
            return false;
    }
    // check column
    for(int i=0;i<9;i++){
        char [] columnArray = new char[9];
        for(int j=0;j<9;j++){
            columnArray[j] = board[j][i];
        }
        isValid = isValid(columnArray);
        if(!isValid)
            return false;
    }
    
    // check subbox
     for(int i=0;i<9;i=i+3){
         for(int j=0;j<9;j=j+3){
             char [] subbox = new char[9];
             int num=0;
             for(int m=i;m<3+i;m++){
                 for(int n=j;n<3+j;n++){
                     subbox[num]=board[m][n];
                     num++;
                 }
             }
             isValid = isValid(subbox);
             if(!isValid)
                return false;
         }
     }  
       return true; // miss that 
    }
    public boolean isValid(char [] array){
        
        int [] count = new int[9];
        for(char ele:array){
            if(ele!='.')
                count[ele-'1']++; // start from 1
        }
        for(int i:count){
            if(i>1)
                return false;
        }
        return true;
    }
   
}