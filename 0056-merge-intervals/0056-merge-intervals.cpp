class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>>ans;

        sort(intervals.begin(),intervals.end());

        int end = intervals[0][1];
        int start = intervals[0][0];

        for(int i = 1;i<intervals.size();i++){

            int st = intervals[i][0];
            int en = intervals[i][1];
            
            if(st <= end){
                end = max(en,end);
            }

            else{
                ans.push_back({start,end});
                start = st;
                end = en;
            }

        }
        ans.push_back({start,end});

        return ans;
    }
};