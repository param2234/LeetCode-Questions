class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> dupl = arr;

        sort(dupl.begin(), dupl.end());

        unordered_map<int, int> rank;

        int r = 1;

        for(int i = 0; i < dupl.size(); i++) {
            if(rank.find(dupl[i]) == rank.end()) {
                rank[dupl[i]] = r;
                r++;
            }
        }

        for(int i = 0; i < arr.size(); i++) {
            arr[i] = rank[arr[i]];
        }

        return arr;
    }
};