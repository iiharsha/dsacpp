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
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    if (lists.empty()) {
      return nullptr;
    }

    struct Compare {
      bool operator()(const ListNode *a, const ListNode *b) {
        return a->val > b->val;
      }
    };

    priority_queue<ListNode *, vector<ListNode *>, Compare> min_heap;
    for (const auto &n : lists) {
      if (n) {
        min_heap.emplace(n);
      }
    }

    ListNode dummy;
    ListNode *curr = &dummy;

    while (!min_heap.empty()) {
      auto node = min_heap.top();
      min_heap.pop();
      curr->next = node;
      curr = curr->next;
      if (node->next) {
        min_heap.emplace(node->next);
      }
    }

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
  return 0;
}
