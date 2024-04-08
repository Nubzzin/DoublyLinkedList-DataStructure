#ifndef _DOUBLYLL_H_
#define _DOUBLYLL_H_

#include <iostream>

template <typename type>
class DoublyLinkedList {
public:
  struct Node {
    type value;
    Node *next{nullptr};
    Node *prev{nullptr};
  };

  Node *head;
  Node *tail;
  int length;

public:
  DoublyLinkedList(type value) {
    head = new Node;
    head->value = value;
    head->next = nullptr;
    head->prev = nullptr;
    tail = head;
    length = 1;
  }
  
  ~DoublyLinkedList() =default;
  
  void append(type value) {
    Node *newNode{ new Node };
    newNode->value = value;
    newNode->prev = tail;
    newNode->next = nullptr;
    tail->next = newNode;
    tail = newNode;
    length++;
  }

  void prepend(type value) {
    Node *newNode{ new Node };
    newNode->value = value;
    newNode->prev = nullptr;
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    length++;
  }

  void insert(int index, type value) {
    if (index <= 0) { prepend(value); return; }
    else if (index >= length) { append(value); return; }
    Node *pre{ head };
    for(int k{0}; k < index-1; k++) pre = pre->next;
    Node *aft{ pre->next };
    Node *newNode{ new Node };
    newNode->value = value;
    newNode->prev = pre;
    newNode->next = aft;
    pre->next = newNode;
    length++;
  }

  void remove(int index) {
    if (index == 0) {
      Node *tmp = head;
      head = head->next;
      head->prev = nullptr;
      delete tmp;
      length--;
      return;
    }
    if (index > length-1) {
      Node *pre = head;
      Node *tmp = head->next;
      while (tmp->next != nullptr){
        pre = pre->next;
        tmp = tmp->next;
      }
      pre->next = nullptr;
      pre->prev = tail;
      tail = pre;
      delete tmp;
      length--;
      return;
    }
    Node *pre{ head };
    for (int i{0}; i < index-1; i++) pre = pre->next;
    Node *del{ pre->next};
    Node *aft{ del->next};
    pre->next = aft;
    aft->prev = pre;
    delete del;
    length--;
  }

  void reverse() {
    if (head->next == nullptr) return;
    Node *first = head;
    Node *second = first->next;
    tail = head;
    while(second != nullptr) {
      Node *temp = second->next;
      second->next = first;
      first = second;
      second = temp;
    }
    head->next = nullptr;
    head = first;
  }

  void printList() {
    Node *currentNode = this->head;
    while(true) {
      std::cout << currentNode->value << " ";
      if (currentNode->next == nullptr) break;
      currentNode = currentNode->next;
    }
  }
};

#endif // _DOUBLYLL_H_