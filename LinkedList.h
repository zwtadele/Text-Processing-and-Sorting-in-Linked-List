#pragma once
#include <iostream>
#include <fstream>

using namespace std;

struct Node {
    string data = "";
    int count;
    Node* next;
};

class LinkedList {
private:
    Node* head;
    int size;

public:
    LinkedList();
    ~LinkedList();
    bool IsEmpty();
    int GetSize();
    void AddAtHead(string value);
    void AddAtPosition(string value, int position);
    void DeleteValue(string value);
    void Print(ostream &out);
    bool Search(string value);
    void Sorting();
};

LinkedList::LinkedList() {
    //cout << "constructor called" << endl;
    head = nullptr;
    size = 0;
}

LinkedList::~LinkedList() {
    //cout << "destructor called" << endl;
    Node* current = head;
    while(current != nullptr){
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

bool LinkedList::IsEmpty() {
    return head == nullptr;
}

int LinkedList::GetSize() {
    return size;
}

void LinkedList::AddAtHead(string value) {
    Node* temp = new Node();
    temp->data = value;
    temp->count = 1;
    temp->next = nullptr;
    
    if (head == nullptr) {
        head = temp;
    }
    else {
        temp->next = head;
        head = temp;
    }
    size++;
}

void LinkedList::AddAtPosition(string value, int position) {
    Node* temp = new Node();
    temp->data = value;
    temp->count = 1;
    temp->next = nullptr;

    if(head == nullptr) {
        head = temp;
    }
    else if(position <= 0) {
        temp->next = head;
        head = temp;
    }
    else {
        Node* previous = head;
        int count = 1;
        while(count < position && previous->next != nullptr) {
            previous = previous->next;
            count++;
        }
        temp->next = previous->next;
        previous->next = temp;
    }
  size++;
}

void LinkedList::DeleteValue(string value){
    if(head == nullptr){
        cout << "Empty List!" << endl;
    }
    else if(head->data == value){
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Target Eliminated!" << endl;
    }
    else {
        Node* previous = head;
        Node* current = head->next;
        while(current != nullptr) {
            if(current->data == value){
                previous->next = current->next;
                cout << "Found it!" << endl;
                delete current;
                return;
            }
            previous = current;
            current = current->next;
        }
    
        cout << "Didn't find it!" << endl;
    }
}

void LinkedList::Print(ostream &out) {
    Node* current = head;
    while(current != nullptr) {
        out << current-> count << " " << current->data << endl;
        current = current->next;
    }
}

bool LinkedList::Search(string value){
  if(IsEmpty()){
    return false;
  }
  Node* current = head;
  while(current != nullptr){
    if(current->data == value){
      current->count++;
      return true;
    
      }
    current = current -> next;
  }
  return false;
}

void LinkedList::Sorting(){
  Node* current = head;
  current = head;
  while (current != nullptr){
    Node* max = current; 
    Node* search = current;
      while (search != nullptr){ 
        /*if (search -> count > max -> count){
          max = search;
            }*/
        if(search->count > max->count || search->count == max->count && search->data < max->data){
          max = search; 
            }
          search = search -> next;
          }
          if(current != max){
            swap(max->data, current->data);
            swap(max->count, current->count);
        }
        current = current -> next;
      }
      }

  // see if whats being passed in is already in linked list
  // add count to node and creat boolean for true and false 

  // add to the count with the search 