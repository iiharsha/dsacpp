#include "../template.h"

class Node {
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution {
public:
  Node *copyRandomList(Node *head) {
    if (head == NULL) {
      return NULL;
    }

    unordered_map<Node *, Node *> map;

    Node *newHead = new Node(head->val);
    Node *oldTemp = head->next;
    Node *newTemp = newHead;
    map[head] = newHead;

    while (oldTemp != NULL) {
      Node *copyNode = new Node(oldTemp->val);

      map[oldTemp] = copyNode;

      newTemp->next = copyNode;

      oldTemp = oldTemp->next;
      newTemp = newTemp->next;
    }

    oldTemp = head;
    newTemp = newHead;
    while (oldTemp != NULL) {
      newTemp->random = map[oldTemp->random];
      oldTemp = oldTemp->next;
      newTemp = newTemp->next;
    }

    return newHead;
  }
};

void printList(Node *head) {
  Node *temp = head;
  while (temp != NULL) {
    cout << "Val: " << temp->val << ", Random: ";

    if (temp->random) {
      cout << temp->random->val;
    } else {
      cout << "NULL";
    }

    cout << "\n";
    temp = temp->next;
  }
  cout << "---\n";
}

int main(void) {
  fast;

  // Create Nodes
  Node *n1 = new Node(1);
  Node *n2 = new Node(2);
  Node *n3 = new Node(3);

  n1->next = n2;
  n2->next = n3;

  // Link random pointers
  n1->random = n3; // 1 -> 3
  n2->random = n1; // 2 -> 1
  n3->random = n2; // 3 -> 2

  cout << "Original list:\n";
  printList(n1);

  Solution sol;
  Node *copiedHead = sol.copyRandomList(n1);

  cout << "Copied list:\n";
  printList(copiedHead);

  return 0;
}
