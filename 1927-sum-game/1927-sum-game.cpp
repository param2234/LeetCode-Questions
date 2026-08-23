class Solution {
public:
    bool sumGame(string num) {
        
        int n = num.size();

        int f_half = 0;
        int s_half = 0;
        int i = 0;
        int j = n/2;

        for(;i<n/2 && j<n;i++,j++){
            if(num[i] != '?'){
                f_half += num[i] - '0';
            }
            else{
                num[i] = '9';
            }

            if(num[j] != '?'){
                s_half += num[j] - '0';
            }

            else{
                num[j] = '9';
            }
        }

        i = 0;
        j = n/2;

        for(;i<n/2 && j<n;i++,j++){
            
            f_half += num[i] - '0';
                                   
            s_half += num[j] - '0';
            
        }

        if(f_half == s_half)return false;

        return true;


    }
};