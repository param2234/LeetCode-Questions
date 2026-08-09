class Solution {
public:

    bool can_finish(vector<int>& piles, int h,int k){

        int count = 0;
        for(int x:piles){
            
            int num = (x + k - 1)/k;

            count += num;

            if(count > h)return false;

        }

        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int maxi = *max_element(piles.begin(),piles.end());

        int st = 1;
        int end = maxi;
        int ans = INT_MAX;
        int mid;
        
        while(st<end){

            mid = st + (end - st)/2;

            if(can_finish(piles,h,mid)){
                end = mid;
            }

            else{
                st = mid + 1;
            }
        }

        return st;
    }
};