        // method 1
        //bool isHappy(int n) {
        // vector<int> v;
        // int sum=n;
        // int count=0;                  // testcase ���ѭ������Ϊ7
        // for(int n=0;count<7;count++)  // �ֲ����������� ѭ������Ӧд�������
        // {
        //     if(sum==1)
        //     return true;
        //     else 
        //     {
        //         for(int i=sum;i>0;i/=10)
        //         v.push_back(i%10);
        //         for(sum=0;n<v.size();n++)
        //         sum=sum+(v[n]*v[n]);
        //     }
        // }
        // return false;
   }

     // method 2
    bool isHappy(int n) {
        int count=0;
        int *p=&count;
        return isHappy_recursion(n,p);    
    }
    
    bool isHappy_recursion(int n, int *p)
    {
        if(*p>=7)
        return false;
        if(n==1)
        return true;
        else
        {
            vector<int> v;
            int sum=0;
            for(int i=n;i>0;i/=10)
                v.push_back(i%10);
            for(int j=0;j<v.size();j++)
                sum=sum+(v[j]*v[j]);
            (*p)++;
            return isHappy_recursion(sum, p);
        }
    }