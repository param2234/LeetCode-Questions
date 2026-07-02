class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int mx1 = *max_element(students.begin(),students.end());
        int mx2 = *max_element(seats.begin(),seats.end());

        vector<int>sts(mx2 + 1,0);
        vector<int>studs(mx1 + 1,0);

        for(int i:seats){
            sts[i]++;
        }
        for(int i:students){
            studs[i]++;
        }

        int j = 0;
        for(int i = 0;i<=mx1;i++){
            int count = studs[i];

            while(count--){
                students[j++] = i;
            }
        }

        int k = 0;
        for(int i = 0;i<=mx2;i++){
            int count = sts[i];

            while(count--){
                seats[k++] = i;
            }
        }
        int ans= 0;
        for(int i = 0;i<students.size();i++){
            ans += abs(students[i] - seats[i]);
        }
        return ans;
    }
};