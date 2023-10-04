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
    ListNode* deleteMiddle(ListNode* head) {
        if (head->next == nullptr){
            head = nullptr;
            return head;
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

        if (count == 2){
            head->next = nullptr;
            return head;
        }

        cout << temp_v[int(count/2)] << endl;

        temp = head;
        for (int i = 1; i < count; i++){
            if (i != int(count/2)){
                temp->next = new ListNode(temp_v[i]);
                temp = temp->next;
            }
        }

        return head;
    }
};