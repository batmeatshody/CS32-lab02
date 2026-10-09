#include "student.h"
#include <string>
#include <cstring>

Student::Student(const char * const name, int perm) {
  this->perm = perm;
  this->name = nullptr;
  this->setName(name);
}

int Student::getPerm() const {
  return perm;
}

const char * const Student::getName() const {
  return name;
}

void Student::setPerm(const int permNumber) {
  perm = permNumber;
}

void Student::setName(const char * const newName) {
  if (newName == nullptr) {
    delete[] name;
    name = new char[1];
    name[0] = '\0';
    return;
  }

  char *copy = new char[strlen(newName) + 1];
  strcpy(copy, newName);

  delete[] name;
  name = copy;
}

Student::Student(const Student &orig) {
  this->perm = orig.perm;
  this->name = nullptr;
  this->setName(orig.name);
}

Student::~Student() {
  delete[] name;
  name = nullptr;
}

Student & Student::operator=(const Student &right) {
  if (&right == this)
    return (*this);

  perm = right.perm;
  setName(right.name);

  return (*this);
}

std::string Student::toString() const {
  std::string result = "[";
  result += name;
  result += ",";
  result += std::to_string(perm);
  result += "]";
  return result;
}

