/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head->next == nullptr){
            return;
        }

        //get length of the list and turn into temp vector
        vector<int> temp_v;
        int count = 1;
        auto temp = head;
        temp_v.push_back(temp->val);
        while (temp->next != nullptr){

            temp = temp->next;
            temp_v.push_back(temp->val);

            count++;
        }

        int merged_left = 1, merged_right = count - 1;
    
        auto temp2 = head->next;

        int total_in_place = 0;
        while (total_in_place < count - 1){
            if (total_in_place % 2 == 0){
                temp2->val = temp_v[merged_right];
                merged_right--;
                temp2 = temp2->next;
            }
            else{
                temp2->val = temp_v[merged_left];
                merged_left++;
                temp2 = temp2->next;
            }
            total_in_place++;
        }
    }
};