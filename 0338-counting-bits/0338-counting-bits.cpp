class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int>arr(n+1,0);
        for(int i=0;i<=n;i++){
            
            int x=i;
            int count=0;
            while(x > 0){
                if(x%2!=0){
                    count++;
                }
                x=x/2;
            }
            arr[i]=count;
        }
        return arr;
    }
};