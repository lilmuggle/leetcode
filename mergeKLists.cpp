/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
     ListNode* mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(INT_MIN);
        ListNode *tail = &dummy;
        while(l1 && l2) {
            if(l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            }
            else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return nullptr;
        while(lists.size() > 1) {
            vector<ListNode*> next;
            for(int i =0; i < lists.size(); i += 2) {
                ListNode* p = (i == lists.size() - 1 ? nullptr : lists[i + 1]);
                ListNode* tmp = mergeTwoLists(lists[i], p);
                next.push_back(tmp);
            }
            lists.clear();
            lists = next;
        }
        return lists[0];
    }
};

//Another
static bool heapComp(ListNode* a, ListNode* b) {
        return a->val > b->val;
}
ListNode* mergeKLists(vector<ListNode*>& lists) { //make_heap
    ListNode head(0);
    ListNode *curNode = &head;
    vector<ListNode*> v;
    for(int i =0; i<lists.size(); i++){
        if(lists[i]) v.push_back(lists[i]);
    }
    make_heap(v.begin(), v.end(), heapComp); //vector -> heap data strcture

    while(v.size()>0){
        curNode->next=v.front();
        pop_heap(v.begin(), v.end(), heapComp);
        v.pop_back();
        curNode = curNode->next;
        if(curNode->next) {
            v.push_back(curNode->next);
            push_heap(v.begin(), v.end(), heapComp);
        }
    }
    return head.next;
}
