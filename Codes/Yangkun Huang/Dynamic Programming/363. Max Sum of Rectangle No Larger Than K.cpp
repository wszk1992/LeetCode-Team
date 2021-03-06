  int maxSumSubmatrix(vector<vector<int>>& matrix, int k) 
  {
      if(matrix.empty()) return 0;
      int rowSize = matrix.size(), colSize = matrix[0].size();
      int ret = INT_MIN;
      for(int l = 0; l < colSize; ++l) //starting leftmost column;
      {
          vector<int> sums = vector<int>(rowSize, 0); //store the row pre-sums;
          for(int c = l; c < colSize; ++c) //try different ending columns;
          {
              for(int r = 0; r < rowSize; ++r) //sum them up in rows;
                  sums[r] += matrix[r][c];
              set<int> sums_set; //store the sums from the starting top-left;
              sums_set.insert(0); //as a sentinel;
              int maxSum = INT_MIN, sum = 0;
              for(auto i:sums)
              {
                  sum += i; //the sum from the starting top-left to current position;
                  auto iter = sums_set.lower_bound(sum-k); //check the possible sum candidates;
                  if(iter != sums_set.end()) maxSum = max(maxSum, sum-*iter); //found one, check it;
                  sums_set.insert(sum);
              }
              ret = max(ret, maxSum);
          }
        }
        return ret;
  }
