class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int mx = *max_element(arr1.begin(),arr1.end());
        vector<int>cnt(mx + 1,0);
        vector<int>ans;

        for(int i:arr1){
            cnt[i]++;
        }

        for(int i:arr2){
            ans.insert(ans.end(),cnt[i] , i);
            cnt[i] = 0;
        }

        for(int i = 0;i<=mx;i++){
            ans.insert(ans.end(),cnt[i] , i);
        }

        return ans;
    }
};