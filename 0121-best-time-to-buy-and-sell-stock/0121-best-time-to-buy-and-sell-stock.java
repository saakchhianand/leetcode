class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int minSF = prices[0];
        int maxP = 0;

        for(int i=1; i<n;i++){
            int profit = prices[i] - minSF;

            maxP = Math.max(maxP, profit);

            minSF = Math.min(minSF, prices[i]);
        }
        return maxP;
    }
}