class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int max_window_size = 0;
        
        int start = 0;
        int current_window_size = 0, count_T = 0, count_F = 0;

        while (start < answerKey.size() - max_window_size){
            // cout << "\nsubstring: " << endl;
            for (int i = start; i < answerKey.size(); i++){
                // cout << answerKey[i] << " ";
                if (answerKey.at(i) == 'T'){
                    count_T++;
                }
                else{
                    count_F++;
                }

                if (count_F > k && count_T > k){
                    // cout << "violating k, current_window_size = " << current_window_size << endl;
                    if (current_window_size > max_window_size){
                        max_window_size = current_window_size;
                    }
                    current_window_size = 0;
                    count_F = 0;
                    count_T = 0;
                    start++;
                    break;
                }
                else{
                    // cout << "count_F = " << count_F << " count_T = " << count_T << endl;
                    current_window_size++;
                }

                if (i == answerKey.size() - 1){
                    if (current_window_size > max_window_size){
                        return current_window_size;
                    }
                }
            }
            
        }

        return max_window_size;
    }
};