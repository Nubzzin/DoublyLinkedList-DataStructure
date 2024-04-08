#include <iostream>
#include "DoublyLL.h"

int main() {
  DoublyLinkedList<int> *DLL = new DoublyLinkedList(10);
  DLL->append(20);
  DLL->append(30);
  DLL->prepend(0);
  DLL->insert(2,15);

  DLL->printList(); std::cout << "\n";

  DLL->remove(15);

  DLL->printList(); std::cout << "\n";

  DLL->reverse();

  DLL->printList(); std::cout << "\n";

  delete DLL;
  
  return 0;
}