#include "../template.h"

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {};
  ListNode(int x) : val(x), next(nullptr) {};
  ListNode(int x, ListNode *next) : val(x), next(next) {};
};

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode dummyHead;

    int carry = 0;
    ListNode *current = &dummyHead;

    while (l1 != nullptr || l2 != nullptr || carry != 0) {
      int sum = 0;

      if (l1 != nullptr) {
        sum += l1->val;
        l1 = l1->next;
      }

      if (l2 != nullptr) {
        sum += l2->val;
        l2 = l2->next;
      }

      sum += carry;

      carry = sum / 10;
      current->next = new ListNode(sum % 10);
      current = current->next;
    }
    return dummyHead.next;
  }
};

/**
 * helper functions
 */
ListNode *createList(const vector<int> &vals) {
  ListNode dummy;
  ListNode *curr = &dummy;

  for (int v : vals) {
    curr->next = new ListNode(v);
    curr = curr->next;
  }
  return dummy.next;
}

void printList(ListNode *head) {
  while (head) {
    cout << head->val;
    if (head->next)
      cout << " -> ";
    head = head->next;
  }
  cout << "\n";
}

int main() {
  fast;

  vector<int> v1 = {2, 4, 3};
  vector<int> v2 = {5, 6, 4};

  ListNode *l1 = createList(v1);
  ListNode *l2 = createList(v2);

  cout << "List One: \n";
  printList(l1);

  cout << "List Two: \n";
  printList(l2);

  cout << "Result: \n";
  Solution sol;
  ListNode *result = sol.addTwoNumbers(l1, l2);
  printList(result);

  return 0;
}
