class Solution {
  public:
    int smallestSubWithSum(int x, vector<int>& arr) {
        int sum=0;
        int i=0,j=0;
        int minSubArrSize=INT_MAX;
        int n=arr.size();
        
        if(n==1 && arr[0]>x){
            return 1;
        } else if(n==1 && arr[0]<x){
            return 0;
        }
        
        while(i<n && j<n){
            if(arr[j]==x){
                return 1;
            }
            sum += arr[j];
        
            if(sum>x){
                int currSubArrSize = j-i+1;
                minSubArrSize = min(minSubArrSize, currSubArrSize);
                i++;
                sum=0;
                j=i;
            }
            else{
                j++;
            }
        }
        if((i>=n || j>=n) && minSubArrSize==INT_MAX) minSubArrSize=0;
        
        return minSubArrSize;
    }
};
