
class Solution {
	public:
	    ListNode* removeNthFromEnd(ListNode* head, int n) {

			ListNode *dummy = new ListNode(0);
			ListNode *cur;
			ListNode *del_node
			int len;

			cur = head;

			while (cur) {
				cur = cur->next;
				len++;
			}

			cur = dummy;

			while (len - n > 0) {
				cur = cur->next;
				len--;
			}

			del_node = cur->next;
			cur->next = cur->next->next;
			cur = dummy->next;
			delete del_node;
			delete dummy;

			return cur;
		}
};
