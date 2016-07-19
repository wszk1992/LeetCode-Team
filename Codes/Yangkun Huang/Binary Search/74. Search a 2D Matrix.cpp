        // cheating method
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            if(!matrix.size()) // be careful with this
                return false;
            for(int i=0;i<matrix.size();i++){
                if(find(matrix[i].begin(), matrix[i].end(), target)!=matrix[i].end())
                    return true;
            }
            return false;
        }       
        
        // standard binary search method
            bool searchMatrix(vector<vector<int>>& matrix, int target) {
                int low=0, high=matrix.size()-1;  // here can be matrix.size()-1
                int row=0;
                while(low<=high){ // be careful here <=
                    int mid = (low+high)/2;
                    if(*(matrix[mid].end()-1)>=target){
                        if(*matrix[mid].begin()<=target){
                            row=mid;
                            break;
                        }
                        else
                            high=mid-1;
                    }
                    else
                        low=mid+1;
                }
                /* more common way
                while(low<high){ 
                    int mid = (low+high)/2;
                    if(*(matrix[mid].end()-1)>=target)
                        high=mid;
                    else
                        low=mid+1;
                }
                row=high; */
                
                // binary search matrix[row]
                low=0, high=matrix[row].size()-1;
                while(low<high){
                    int mid=(low+high)/2;
                    if(matrix[row][mid]>=target)
                        high=mid;
                    else
                        low=mid+1;
                }
                return matrix[row][high]==target;
            }        
