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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        if(lists.size() == 1) return lists[0];
        int numberOfLists = lists.size();
        while(numberOfLists > 1){
            for(int i = 0; i < numberOfLists / 2; i++){
                lists[i] = mergeTwoLists(lists[i], lists[numberOfLists - 1 - i]);
            }
            numberOfLists = numberOfLists - numberOfLists/2;
        }
        return lists[0];
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){ //this func is destructive to list1 and list2. at the very end this would be O(n) because it's comparing the entire to the new value?
        ListNode* result = new ListNode(0); // false head. 
        ListNode* head = result;
        while(nullptr != list1 && nullptr !=list2){
            if(list1->val < list2->val){
                 result->next = list1;
                 list1 = list1->next;
            }
            else{
                result->next = list2;
                list2 = list2->next;
            }
            result = result->next; //incrementate to next node. 
        }
        //extra. 
        while(nullptr!= list1){
            result->next = new ListNode(list1->val);
            list1 = list1->next;
            result = result->next;
        }
        while(nullptr!= list2){
            result->next = new ListNode(list2->val);
            list2 = list2->next;
            result = result->next;
        }
        return head->next;
    }
};
