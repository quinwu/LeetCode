# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        carry = 0
        head = p = ListNode(0)
        
        while l1 or l2 or carry:
            var1 = var2 = 0
            if l1:
                var1 = l1.val
                l1 = l1.next
            if l2:
                var2 = l2.val
                l2 = l2.next
            carry,val = divmod(var1 + var2 + carry , 10)
            p.next = ListNode(val)
            p = p.next
            
        return head.next