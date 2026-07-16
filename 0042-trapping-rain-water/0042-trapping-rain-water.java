class Solution {
    public int trap(int[] height) {
        int n = height.length;
        int trappedWater = 0;

        int[] lm = new int[n];
        int[] rm = new int[n];

        lm[0] = height[0];
        rm[n-1] = height[n-1];

        for(int i=1; i <n ; i++){
            lm[i] = Math.max(height[i],lm[i-1]);
        
        }

        for(int j = n-2;j>=0;j--){
            rm[j] = Math.max(height[j], rm[j+1]);
        }
        for(int i=0; i <n;i++){
            int waterHeight = Math.min(lm[i], rm[i]);
            trappedWater += (waterHeight-height[i]);
        }
        return trappedWater;
    }
}