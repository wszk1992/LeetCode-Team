	// method 1 O(m+n)
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int m = matrix.size();
		if (m == 0) return false;
		int n = matrix[0].size();
		// keep there is always one way to move
		// first find which row, then find which column
		int i = 0, j = n - 1;
		while (i < m && j >= 0) {
			if (matrix[i][j] < target)
				i++;
			else if (matrix[i][j] > target)
				j--;
			else
				return true;
		}
		return false;
	}
	
	
	// method 2 O(mlogn)
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		return searchMatrix(matrix, target, 0, matrix.size() - 1);
	}
	
	bool searchMatrix(vector<vector<int>>& matrix, int target, int top, int bottom) {
		if (top > bottom)
		    return false;
		
		int mid = top + (bottom - top) / 2;
		if (matrix[mid].front() <= target && target <= matrix[mid].back()) // equal to "if (v[mid] == target)"
		    if (searchVector(matrix[mid], target)) return true;
		
		if (searchMatrix(matrix, target, top, mid - 1)) return true; 	// equal to "left = mid + 1;"
		if (searchMatrix(matrix, target, mid + 1, bottom)) return true;	// equal to "right = mid - 1;"
		
		return false;
	}
	
	bool searchVector(vector<int>& v, int target) {
		int left = 0, right = v.size() - 1;
		
		while (left <= right) {
		    int mid = left + (right - left) / 2;
		    if (v[mid] == target)
		        return true;
		    if (v[mid] < target)
		        left = mid + 1;
		    else
		        right = mid - 1;
		}
		
		return false;
	}
