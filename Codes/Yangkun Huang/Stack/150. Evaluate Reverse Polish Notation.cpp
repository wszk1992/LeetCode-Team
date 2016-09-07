    // difficulty is the negative number 
    // op2-op1 and op2/op1 not op1-op2
    int evalRPN(vector<string>& tokens) {
        stack<int> cal;
        int num1, num2;
        for(auto str:tokens){
            switch(str[str.size()-1]){  // check the last pos not the first to avoid negative number
                case '+':num1=cal.top();cal.pop();num2=cal.top();cal.pop();cal.push(num1+num2);break;
                case '-':num1=cal.top();cal.pop();num2=cal.top();cal.pop();cal.push(num2-num1);break;
                case '/':num1=cal.top();cal.pop();num2=cal.top();cal.pop();cal.push(num2/num1);break;
                case '*':num1=cal.top();cal.pop();num2=cal.top();cal.pop();cal.push(num1*num2);break;
                default:cal.push(stoi(str));
            }
        }
        return cal.top();
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int op1 , op2;
        for(int i = 0 ; i < tokens.size() ; i++){
            string tkn = tokens[i];
            if(tkn[tkn.size()-1]>='0' && tkn[tkn.size()-1]<='9')
                stk.push(stoi(tkn));
            else{
                op1 = stk.top();
                stk.pop();
                op2 = stk.top();
                stk.pop();
                switch(tkn[0]){
                    case '+':stk.push(op1 + op2);break;
                    case '-':stk.push(op2 - op1);break;
                    case '*':stk.push(op1 * op2);break;
                    case '/':stk.push(op2 / op1);break;
                    default:break;
                }
            }
        }
        return stk.top();
    }
