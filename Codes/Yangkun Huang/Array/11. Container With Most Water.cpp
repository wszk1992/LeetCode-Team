        // compare with no.84
        // is this a dp problem?
        // when meet two pointer problem, think whether it is slow/fast pts or forward/backward pts
        int maxArea(vector<int>& height) {
            int water=0, mini=0;
            for(int i=0, j=height.size()-1;i<j;){
                mini=min(height[i], height[j]);
                water=max(water, mini*(j-i));
                // the key here is to update the lower line and make it higher
                while(height[i] <= mini && i<j)
                    i++;
                while(height[j] <= mini && i<j)
                    j--;
            }
            return water;
        }
