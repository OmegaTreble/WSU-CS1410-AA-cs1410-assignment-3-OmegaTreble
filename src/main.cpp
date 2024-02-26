#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

struct Item{
  double value;
  Item* next;
};

struct Stack{
  Item* top;
  int size;
};

void push(Stack* stack, double num){
  Item* item = new Item;
  item->value = num;
  item->next = stack->top;
  stack->size++;
  };
double top(Stack* stack){
  if (stack->top != nullptr){
    double topvalue = stack->top->value;
    return topvalue;
  }
  else {
    return HUGE_VAL;
  }
};
void pop(Stack* stack){
  if (stack->top == nullptr){
    cout << "List is empty. Can not delete an empty value." << endl;
  }
  else{
    Item* temp;
    temp = stack->top;
    stack->top=temp->next;
    delete temp;
    stack->size--;
  }
};
void print(Stack* stack){
  int i =1;
  cout << setw(20) << "-------------" << endl;
  while(stack->top != nullptr){
    if (i=1){
      cout << setw(30) << stack->top->value << setw(2) <<  "< TOP" << endl;
      stack->top = stack->top->next;
      i=2;
    };
    cout << setw(30) << stack->top->value << endl;
    stack->top = stack->top->next;
  }
  cout << setw(20) << "-------------" << endl;
  cout << setw(34) << stack->size << " Items" << endl;
};

int main(){
  int width;
  int i=0;
  double input;
  Stack* list = {0};
  cout << "Please enter the size of the list:  ";
  cin >> width;
  while (i < width) {
    cout << "Please enter the value" << endl;
    cin >> input;
    push(list, input);
    i++;
  }
  char pp = 'P';
  char prt = 'r';
  char tp = 't';
  char quit = 'q';
  char value;
  while (value != quit){
    cout << "Enter p to pop the top value out of the list." << endl;
    cout << "Enter r to print the entire list." << endl;
    cout << "Enter t to print the top value." << endl;
    cout << "enter q to quit." << endl;
    if (value == pp){
      pop(list);
    }
    else if (value == prt){
      print(list);
    }
    else if (value == tp){
      double topvalue=top(list);
      cout << "The top value is " << topvalue << endl;
    }
  }
  return 0;
}