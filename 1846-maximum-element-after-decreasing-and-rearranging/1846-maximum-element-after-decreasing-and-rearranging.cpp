class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int n = arr.size();

        if (n == 0)
            return 0;

        if (arr[0] != 1) {
            arr[0] = 1;
        }
        int i = 1;

        while (i < n) {

            if(arr[i] - arr[i-1] <= 1){
                i++;
                continue;
            }

            else{
                arr[i] = arr[i-1] + 1;
            }
            i++;
        }

        return arr[n-1];
    }
};