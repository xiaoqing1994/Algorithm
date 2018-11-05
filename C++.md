#C++ NOTE

##CONTENT
- [Override and Overload](#override-and-overload)
- [Class member](#class-member)
- [Pointer](#pointer)

##Override and Overload
Overloading function name means providing more than one declaration and definition using the same function name.

Overriding means

##Class member
###Accessor and Mutator function
Corresponding to get and set function.
###Utility Function(helper function)
The private function in the class which is used only in the class.

##Pointer
###New and delete
In C, we allocate and collect memory by using:
```c
int *p;
p = (int*)malloc(sizeof(int));
*p = 23;
free(p);
```
Using malloc is returning a block of size bytes of memory. Note this method will only return the memory but not perform object initialization and destruction.

New and delete are dynamic allocation operators.
```c++
int *p1;
int *p2;
p1 = new int;//new a single object
p2 = new int[5]; //new a array
delete p1;
delete []p2; //call the destruction of every elements.

t *p3;
p3 = new t(val); //new a object and initialize it
```
###This
Every object in C++ has access to its own address through **this** pointers. We always use it when we want to specify which parameters we refer to.
```c++
//Example 1
void Data::set(int year, int month, int day){
  /*pass the value of parameter month to its own private parameter month.*/
  this->month = month;  
  this->year = year;
  this->day = day;
}
//Example 2
Data& Data::set(int year){
  this->year = year;
  //this is a pointer, therefore * this is a reference of the object
  return * this;
}
```
##Friend Function and Friend Class
Friend functions are not members of a class, but can access private member variables of the class. It is declared using the keyword **friend** in the class definition.
```c++

```
