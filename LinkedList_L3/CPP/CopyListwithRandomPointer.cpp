/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }

        Node* ptr = head;
        while (ptr != nullptr) {
            Node* newNode = new Node(ptr->val);
            newNode->next = ptr->next;
            ptr->next = newNode;
            ptr = newNode->next;
        }

        ptr = head;
        while (ptr != nullptr) {
            if (ptr->random != nullptr) {
                ptr->next->random = ptr->random->next;
            }
            ptr = ptr->next->next;
        }

        Node* ptr_old_list = head;
        Node* ptr_new_list = head->next;
        Node* head_old = head->next;
        while (ptr_old_list != nullptr) {
            ptr_old_list->next = ptr_old_list->next->next;
            if (ptr_new_list->next != nullptr) {
                ptr_new_list->next = ptr_new_list->next->next;
            }
            ptr_old_list = ptr_old_list->next;
            ptr_new_list = ptr_new_list->next;
        }

        return head_old;
    }
};
