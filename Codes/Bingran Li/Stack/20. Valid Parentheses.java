public class Solution {
    public boolean isValid(String s) {
        
       //  NOT NOT HAVE A GOOD IDEA ON HOW TO EXPRESS THAT CONDITION, ONLY WORKS SOMETIMES
       // somebody's solution-----> using stack
       
       char [] charArray = s.toCharArray();
       Stack <Character> myStack = new Stack<Character>();
       for(char myChar: charArray){
           if(myChar=='('||myChar=='['||myChar=='{'){
               myStack.push(myChar);
           }
           else{
               if(myStack.empty())  return false;
    
               if(myChar==')'&& myStack.pop()!='(') return false;
               if(myChar==']'&& myStack.pop()!='[') return false;
               if(myChar=='}'&& myStack.pop()!='{') return false;
                   
                   // I change some code and the operation time decrease from 2ms to 1ms
                   
                   /*
                   switch (myStack.pop()){
                   case '(': 
                       if(myChar!=')')
                            return false;
                        break; // ---------> miss break, it will execute following sentences
                   case '[':
                       if(myChar!=']')
                            return false;
                        break;
                   case '{':
                       if(myChar!='}')
                            return false;
                        break;
                   }
                   */
           } 
       }
       if(!myStack.empty()) // miss empty()
            return false;
        
        return true;
    } // miss }
}