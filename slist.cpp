#include "slist.h"

//constructor
  SList::SList(){
    num = 0;
    head = nullptr;
  }
//destructor
  SList::~SList(){
  }
// add(value)				//Adds a new value to the end of this list.
  void SList::add(void* value){
    node *temp = new node;
    temp -> data = value;
    node *val = head;
    node *previous;
    if (head == nullptr) {
      head = temp;
    }
    else {
      do {
        previous = val;
        val = val -> next;
      }
      while(val != nullptr);
      previous -> next = temp;
    }
    num++;
  }
// clear()					//Removes all elements from this list.
  void SList::clear(){
    node *val = head;
    for (int i = 0; i < num; num--){
      for (int j = 1; j < num; j++){
        val = val -> next;
      }
      delete val;
    }
  }
// equals(list)				//Returns true if the two lists contain the same elements in the same order.
  bool SList::equals(SList x){
    if (x.num != num){
      return false;
    }
    else{
      node *val1 = head;
      node *val2 = x.head;
      for (int i = 0; i < num; i++){
        val1 = val1 -> next;
        val2 = val2 -> next;
        if (val1 != val2){
          return false;
        }
      }
    }
    return true;
  }
//get(index)				//Returns the element at the specified index in this list.
  void* SList::get(int index){
    node *val = head;
    for (int i = 0; i < index; i++){
      val = val -> next;
    }
    return val -> data;
  }
//insert(index, value)		//Inserts the element into this list before the specified index.
  void SList::insert(int index, void* value){
    node* temp = new node;
    temp -> data = value;
    node *val = head;
    for (int i = 0; i < index -1; i++){
      val = val -> next;
    }
    node *valpre = val;
    val = val -> next;
    temp -> next = val;
    valpre -> next = temp;
    num++;
  }
//exchg(index1, index2)		//Switches the payload data of specified indexex.
  void SList::exchg(int index1, int index2){
    node* val = head;
    node* val1;
    node* val2;
    for (int i = 0; i < num; i++){
      if (index1 == i){
        val1 = val;
      }
      if (index2 == i){
        val2 = val;
        break;
      }
      val = val -> next;
    }
    void* temp = val2 -> data;
    val2 -> data = val1 -> data;
    val1 -> data = temp;
  }
  //swap(index1,index2)		//Swaps node located at index1 with node at index2
  void SList::swap(int index1, int index2){
    node* val = head;
    node* val1;
    node* val2;
    int number = 0;
    for (int i = 0; i < num; i++){
      val = val -> next;
      if (index1-1 == i){
        val1 = val;
        number++;
        if (number == 2){
          break;
        }
      }
      if (index2-1 == i){
        val2 = val;
        number++;
        if (number == 2){
          break;
        }
      }
    }
    if (index1 + 1 == index2){
      
    }
    node* temp = val1 -> next -> next;      //swap what the two vals are originally pointing
    val1 -> next -> next = val2 -> next -> next;
    val2 -> next -> next = temp;
    temp = val1 -> next;
    val2 -> next = val1 -> next;
    val1 -> next = temp;
  }
  // isEmpty()				//Returns true if this list contains no elements.
  bool SList::isEmpty(){
    if (head -> next){
      return true;
    }
    return false;
  }
  // remove(index)			//Removes the element at the specified index from this list.
  void SList::remove(int index){
    node* val = head;
    node* val1;
    node* current;
    int number = 0;
    for (int i = 0; i < num; i++){
      val = val -> next;
      if (index-1 == i){
        val1 = val;
        number++;
        if (number == 2){
          break;
        }
      }
      if (index+1 == i){
        current = val;
        number++;
        if (number == 2){
          break;
        }
      }
    }
    val1 -> next = current;
    num--;
  }
  // set(index, value)		//Replaces the element at the specified index in this list with a new value.
  void SList::set(int index, void* value){
    node *enter = new node;
    enter -> data = value;
    node* val = head;
    node* val1;
    node* current;
    int number;
    for (int i = 0; i < num; i++){
      val = val -> next;
      if (index-1 == i){
        val1 = val;
        number++;
        if (number == 2){
          break;
        }
      }
      if (index+1 == i){
        current = val;
        number++;
        if (number == 2){
          break;
        }
      }
    }
    enter -> next = current;
    val1 -> next = enter;
  }
  // size()					//Returns the number of elements in this list.
  int SList::size(){
    return num;
  }

// DO NOT IMPLEMENT >>> subList(start, length)	//Returns a new list containing elements from a sub-range of this list.

// DO NOT IMPLEMENT >>> toString()				//Converts the list to a printable string representation.