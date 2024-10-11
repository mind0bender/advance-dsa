#include <iostream>

using namespace std;

template <typename data_t>
class Node {
 private:
  Node* next;
  Node* prev;
  data_t data;

 public:
  Node(data_t val) : data(val), next(nullptr), prev(nullptr) {}
  void setData(data_t val) { data = val; }
  data_t getData() { return data; }
  void setNext(Node* val) { next = val; }
  Node* getNext() { return next; }
  void setPrev(Node* val) { prev = val; }
  Node* getPrev() { return prev; }

  void display() {
    cout << "data: " << data << endl;
    cout << "next: " << next << endl;
    cout << "prev: " << prev << endl;
  }
};

template <typename data_t>
void display(data_t val) {
  cout << val << endl;
}

template <typename data_t>
class LinkedList {
 private:
  Node<data_t>* head;
  Node<data_t>* getTail() {
    Node<data_t>* tail = head;
    while (tail && tail->getNext()) {
      tail = tail->getNext();
    }
    return tail;
  }

 public:
  LinkedList() : head(nullptr) {}
  void insertNode(data_t val, bool fromBeg = true) {
    Node<data_t>* node = new Node<data_t>(val);
    if (fromBeg) {
      node->setNext(head);
      if (head) {
        head->setPrev(node);  //
      }
      head = node;
    } else {
      Node<data_t>* tail = getTail();
      if (tail) {
        tail->setNext(node);
        node->setPrev(tail);  //
      } else {
        node->setPrev(head);  //
        head = node;
      }
    }
  }
  void traverse(void (*cb)(data_t), bool reverse = false) {
    if (!reverse) {
      Node<data_t>* temp = head;
      while (temp) {
        (*cb)(temp->getData());
        temp = temp->getNext();
      }
    } else {
      Node<data_t>* temp = getTail();
      while (temp) {
        (*cb)(temp->getData());
        temp = temp->getPrev();
      }
    }
  }
  void deleteNode(bool fromBeg = true) {
    if (fromBeg) {
      if (head) {
        Node<data_t>* firstEle = head;
        head = head->getNext();
        head->setPrev(nullptr);
        delete firstEle;
      } else {
        cout << "Underflow" << endl;
      }
    } else {
      Node<data_t>* tail = head;
      Node<data_t>* prevTail = head;
      while (tail && tail->getNext()) {
        prevTail = tail;
        tail = tail->getNext();
      }
      if (prevTail) {
        Node<data_t>* tail = prevTail->getNext();
        prevTail->setNext(nullptr);

        delete tail;
      }
    }
  }

  void search(data_t val) {
    auto check = [val](data_t ele) -> bool {
      if (ele == val) {
        return true;
      } else {
        return false;
      }
    };
    Node<data_t>* temp = head;
    while (temp) {
      if (check(temp->getData())) {
        cout << "Element found" << endl;
        return;
      }
      temp = temp->getNext();
    }
    cout << "Element not found" << endl;
  }
};

int main() {
  LinkedList<int> ll;
  ll.insertNode(31);
  ll.insertNode(11);
  // delete from beginning
  ll.deleteNode();
  ll.insertNode(7, false);  // from end
  // delete from end
  // ll.deleteNode(false);

  // display w\. lambda fn\.
  ll.traverse([](int val) { cout << val << '\t'; });
  cout << endl;
  // in reverse
  ll.traverse([](int val) { cout << val << '\t'; }, true);
  cout << endl;
  ll.search(11);

  cout << "Yash Gupta\t23BCS11317" << endl;
  return 0;
}