class Solution {
public:
    struct compare{
        bool operator()(ListNode* a,ListNode* b){
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare> pq;

        for(ListNode* node : lists){
            if(node) pq.push(node);
        }

        ListNode* head = NULL;
        ListNode* tail = NULL;

        while(!pq.empty()){
            ListNode* curr = pq.top();
            pq.pop();

            if(head == NULL){
                head = curr;
                tail = curr;
            }
            else{
                tail->next = curr;
                tail = curr;
            }

            if(curr->next){
                pq.push(curr->next);
            }
        }
        return head;
    }
};