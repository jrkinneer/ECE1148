#include <string>
#include <unordered_map>

class Solution {
public:

    vector<string> letterCombinations(string digits) {
        vector<string> temp;
        if (digits.size() == 0){
            return temp; //base case
        }


        unordered_map<char, string> dict;
        dict.insert( {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5',"jkl"},
        {'6',"mno"}, {'7',"pqrs"}, {'8', "tuv"}, {'9',"wxyz"}});
        
        string substr;
        comboHelper(temp, digits, 0, substr, dict);

        return temp;
    }

    void comboHelper(vector<string> &ret, string digits, int depth, string substr, unordered_map<char, string> dict){
        if (substr.size() == digits.size()){
            ret.push_back(substr);
            return;
        }

        char curr = digits[depth];
        string list = dict.find(curr)->second;
        cout << "list: " << list << endl;
        
        for (int i = 0; i < list.size(); i++){
            comboHelper(ret, digits, depth + 1, substr + list[i], dict);
        }

    }
};