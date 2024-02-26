// CS1410 - Assignment 03 - Du Mars
#include <iostream>
#include <iomanip>  
#include <cmath>
using namespace std;

//TODO 1: ShapeKind Enumeration goes here
enum class ShapeKind {CIRCLE, RECTANGLE, SQUARE};
//TODO 2: Shape Structure goes here
struct Shape {
  ShapeKind kind;
  int length;
  int width;
};

// Function prototypes and definitions
double area(Shape s);
//TODO 3: area() definition goes here
double area(Shape s) {
  if (s.kind == ShapeKind::CIRCLE) {
    double radius = s.length / 2;
    double area = ((radius * radius) * 3.14);
    return area;
  }
  else if (s.kind == ShapeKind::RECTANGLE) {
    double area = s.length * s.width;
    return area;
  }
  else if (s.kind == ShapeKind::SQUARE) {
    double area = s.length * s.length;
    return area;
  }
  else {return 0;}
}

double perimeter(Shape s);
//TODO 4: perimeter() definition goes here
double perimeter(Shape s) {
  if (s.kind == ShapeKind::CIRCLE) {
    double perimeter = s.length * 3.14;
    return perimeter;
  }
  if (s.kind == ShapeKind::RECTANGLE) {
    double perimeter = (s.length * 2) + (s.width * 2);
    return perimeter;
  }
  if (s.kind == ShapeKind::SQUARE) {
    double perimeter = 4 * s.length;
    return perimeter;
  }
  else {
    return 0;
  }
}

string nameOf(Shape s);
//TODO 5: nameOf() definition goes here
string nameOf(Shape s) {
  switch(s.kind){
    case ShapeKind::CIRCLE: return "Circle";
    case ShapeKind::RECTANGLE: return "Rectangle";
    case ShapeKind::SQUARE: return "Square";
  }
  return 0;
}

void promptAndReadInputFor(Shape& s);
//TODO 6: promptAndReadInputFor() definition goes here
void promptAndReadInputFor(Shape& s){
  if (s.kind == ShapeKind::CIRCLE) {
    cout << "What is the diameter of the circle: ";
    cin >> s.length;
    s.width=s.length;
  }
  if (s.kind == ShapeKind::SQUARE) {
    cout << "What is the length of the square:  ";
    cin >> s.length;
    s.width=s.length;
  }
  if (s.kind == ShapeKind::RECTANGLE) {
    cout << "What is the length and the width of the rectangle:  ";
    cin >> s.length >> s.width;
  }
}

// The main function
int main() {
  // Shape objects
  Shape CIRCLE = {ShapeKind::CIRCLE, 0, 0};
  //TODO 7: define two more shape objects: a square and and a rectangle 
  Shape RECTANGLE = {ShapeKind::RECTANGLE, 0, 0};
  Shape SQUARE = {ShapeKind::SQUARE, 0, 0};

  //TODO 8: Call the promptAndReadInputFor() function on each of the above three shapes
  promptAndReadInputFor(CIRCLE);
  promptAndReadInputFor(SQUARE);
  promptAndReadInputFor(RECTANGLE);
  
  //TODO 9: Print a out a report of these shapes in a table-like format
  cout << setw(10) << "Shape" << setw(10) << "Width" << setw(10) << "Length" << setw(10) << "Perimeter" << setw(10) << "Area" << endl;
  cout << "---------------------------------------------------------------------------" << endl;
  cout << setw(10) << nameOf(CIRCLE) << setw(10) << CIRCLE.width << setw(10) << CIRCLE.length << setw(10) << perimeter(CIRCLE) << setw(10) << area(CIRCLE) << endl;
  cout << setw(10) << nameOf(SQUARE) << setw(10) << SQUARE.width << setw(10) << SQUARE.length << setw(10) << perimeter(SQUARE) << setw(10) << area(SQUARE) << endl;
  cout << setw(10) << nameOf(RECTANGLE) << setw(10) << RECTANGLE.width << setw(10) << RECTANGLE.length << setw(10) << perimeter(RECTANGLE) << setw(10) << area(RECTANGLE) << endl;
  return 0;
}