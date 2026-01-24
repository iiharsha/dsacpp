#include "../template.h"

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode dummy{0};
    ListNode *curr = &dummy;

    while (l1 && l2) {

      if (l1->val <= l2->val) {
        curr->next = l1;
        l1 = l1->next;
      } else {
        curr->next = l2;
        l2 = l2->next;
      }

      curr = curr->next;
    }
    curr->next = l1 ? l1 : l2; // attach remaining lists

    return dummy.next;
  }
};

ListNode *buildList(const vector<int> &vals) {
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
      cout << "->";
    head = head->next;
  }
  cout << "\n";
}

void freeList(ListNode *head) {
  while (head) {
    ListNode *temp = head;
    head = head->next;
    delete temp;
  }
}

int main(void) {
  fast;

  vector<int> a = {1, 3, 5};
  vector<int> b = {2, 4, 6};

  ListNode *l1 = buildList(a);
  ListNode *l2 = buildList(b);

  Solution sol;
  ListNode *merged = sol.mergeTwoLists(l1, l2);

  printList(merged);
  freeList(merged);
  return 0;
}
