// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : first(nullptr), countOp(0) {}

void Train::addCar(bool light) {
  Car* newCar = new Car{ light, nullptr, nullptr };

  if (first == nullptr) {
    newCar->next = newCar;
    newCar->prev = newCar;
    first = newCar;
  } else {
    Car* lastCar = first->prev;
    newCar->next = first;
    newCar->prev = lastCar;
    lastCar->next = newCar;
    first->prev = newCar;
  }
}

int Train::getLength() {
  countOp = 0;
  if (first == nullptr) return 0;
  Car* current = first;
  current->light = true;
  while (true) {
    int countSteps = 0;
    do {
      current = current->next;
      countSteps++;
      countOp++;
    } while (!current->light);
    current->light = false;
    for (int i = 0; i < countSteps; i++) {
      current = current->prev;
      countOp++;
    }
    if (!current->light) return countSteps;
  }
}

int Train::getOpCount() {
  return countOp;
}
