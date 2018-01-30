# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if l1 == None:
            return l2
        if l2 == None:
            return l1

        lists = None

        if l1.val <= l2.val:
            lists = ListNode(l1.val)
            l1 = l1.next
        else:
            lists = ListNode(l2.val)
            l2 = l2.next
        Head = lists

        while (l1 != None and l2 != None):
            if l1.val <= l2.val:
                lists.next = ListNode(l1.val)
                lists = lists.next
                l1 = l1.next
            else:
                lists.next = ListNode(l2.val)
                lists = lists.next
                l2 = l2.next

        while (l1 != None):
            lists.next = ListNode(l1.val)
            lists = lists.next
            l1 = l1.next
        while (l2 != None):
            lists.next = ListNode(l2.val)
            lists = lists.next
            l2 = l2.next

        return Head
