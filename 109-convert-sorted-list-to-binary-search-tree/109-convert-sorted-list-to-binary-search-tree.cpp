class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) 
    {
        if(!head) return NULL;
        if(head->next == NULL) return new TreeNode(head->val);

        ListNode *slow = head, *fast = head;
        ListNode *prev = head;
        
        while(fast and fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        TreeNode *root = new TreeNode(slow->val);
        prev->next = NULL;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        
        return root;
    }
};