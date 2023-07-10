int maxArea(vector<int>& height) {
        int n = height.size();
        int l=0;
        int r = n-1;
        int max= 0;
        while(l<r){
            int lh = height[l];
            int rh= height[r];
            int area = (r-l)*min(lh,rh);
            if (area>max){
                max = area;
            }
            if (height[r]<height[l]){
                r--;
            }
            else{
                l++;
            }
        }
        return max;
    }