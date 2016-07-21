      int trap(vector<int>& height) {
          // each bar contains water as the lower side of left and right
          // also think is it slow/fast or forward/backward?
          // this is a sum problem not a maximum problem
          
          // Keep track of the already safe level and the total water so far
          // In each step, process and discard the lower one of the leftmost or rightmost elevation.
          int water = 0;
          for (int l = 0, r = height.size()-1, level = 0; l < r;) {
              int lower = height[height[l] < height[r] ? l++ : r--];
              level = max(level, lower);
              water += level - lower;
          }
          return water;
      }
