class Solution {
public:
    int longestMountain(vector<int>& arr) {
          int n = arr.size();
        int longestmou = 0;
         int count=0;
        for(int i=1;i<n-1;i++)
        {
          
            if(arr[i] > arr[i-1] and arr[i]>arr[i+1]){
                int j = i;
                count = 1;
                while(j>0 and arr[j]>arr[j-1]){
                    j--;
                    count++;
                }
                 j = i;
                while(j<n-1 and arr[j]>arr[j+1]){
                    j++;
                    count++;
                }
            }
            longestmou = max(longestmou,count);
            count = 0;
        }
        return longestmou;
    }
};