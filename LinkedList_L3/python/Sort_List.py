class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def sortList(self, head):
        if not head or not head.next:
            return head
        mid = self.getMid(head)
        left = self.sortList(head)
        right = self.sortList(mid)
        return self.merge(left, right)

    def merge(self, list1, list2):
        dummy_head = ListNode()
        tail = dummy_head
        while list1 and list2:
            if list1.val < list2.val:
                tail.next = list1
                list1 = list1.next
            else:
                tail.next = list2
                list2 = list2.next
            tail = tail.next
        tail.next = list1 if list1 else list2
        return dummy_head.next

    def getMid(self, head):
        mid_prev = None
        while head and head.next:
            mid_prev = head if mid_prev is None else mid_prev.next
            head = head.next.next
        mid = mid_prev.next
        mid_prev.next = None
        return mid
