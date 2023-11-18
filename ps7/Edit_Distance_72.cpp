class Solution {
public:
    int minDistance(string word1, string word2) {
        int x = word1.size() + 1;
        int y = word2.size() + 1;
        
        //matrix of size (x,y)
        vector<vector<int>> dp (x, vector<int>(y, 0)); 

        //initialize matrix
        for (int i = 1; i < x; i++){
            dp[i][0] = i;
        }
        for (int i = 1; i < y; i++){
            dp[0][i] = i;
        }

        // cout << "beginning "<< endl;
        // for (int i = 0; i < x; i++){
        //     for (int j = 0; j < y; j++){
        //         cout << dp[i][j] << "\t";
        //     }
        //     cout << "\n";
        // }

        for (int i = 1; i < x; i++){
            for (int j = 1; j < y; j++){
                //letter is in the same place in the old word as it is in the new, no action needed
                //cost doesn't increase
                if (word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{ 
                    //letter needs changed
                    int term1 = min(dp[i-1][j-1], dp[i][j-1]);
                    dp[i][j] = 1+ min(term1, dp[i-1][j]);
                }
            }
        }

        // cout << "\n" << " finished"<< endl;
        // for (int i = 0; i < x; i++){
        //     for (int j = 0; j < y; j++){
        //         cout << dp[i][j] << "\t";
        //     }
        //     cout << "\n";
        // }

        return dp[x-1][y-1];
    }
};