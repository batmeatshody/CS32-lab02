#include <string>
#include "studentRoll.h"

StudentRoll::StudentRoll() {
  head = tail = NULL;
}

void StudentRoll::insertAtTail(const Student &s) {
  Node *newNode = new Node;
  newNode->s = new Student(s);
  newNode->next = NULL;

  if (head == NULL) {
    head = tail = newNode;
  } else {
    tail->next = newNode;
    tail = newNode;
  }
}

std::string StudentRoll::toString() const {
  std::string result = "[";
  Node *curr = head;

  while (curr != NULL) {
    if (curr != head) {
      result += ",";
    }
    result += curr->s->toString();
    curr = curr->next;
  }

  result += "]";
  return result;
}

StudentRoll::StudentRoll(const StudentRoll &orig) {
  head = tail = NULL;

  Node *curr = orig.head;
  while (curr != NULL) {
    insertAtTail(*(curr->s));
    curr = curr->next;
  }
}

StudentRoll::~StudentRoll() {
  Node *curr = head;
  while (curr != NULL) {
    Node *next = curr->next;
    delete curr->s;
    delete curr;
    curr = next;
  }
  head = tail = NULL;
}

StudentRoll & StudentRoll::operator =(const StudentRoll &right ) {
  if (&right == this)
    return (*this);

  Node *curr = head;
  while (curr != NULL) {
    Node *next = curr->next;
    delete curr->s;
    delete curr;
    curr = next;
  }
  head = tail = NULL;

  Node *rightCurr = right.head;
  while (rightCurr != NULL) {
    insertAtTail(*(rightCurr->s));
    rightCurr = rightCurr->next;
  }

  return (*this);
}

