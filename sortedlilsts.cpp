#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 (30 points) SortedLists. Write the code for a SortedList class. This class should contain a linked list
of strings in ascending sorted order. There are two possible ways the list can be sorted:
1. By string length.
2. By individual characters. Starting with the first, one character from each string is compared using
the numeric value of the ASCII encoding. If the strings have the same character, compare them on
the next.
Ties can be broken in any order.
Your class should have the following functionality

(a) (2 points) The ability to create new instances of the class that represent empty lists.
(b) (2 points) The ability to create (deep) copies of a SortedList.
(c) (2 points) The ability to create new instances of the class that specify which sorting method to use.
(d) (3 points) A method to add elements to the list in sorted order.
(e) (3 points) A method to remove all instances of an element from the list.
(f) (1 point) A method to remove all values from the list.
(g) (1 point) A method that returns whether or not the list is currently sorted by string length.
(h) (1 point) A method that returns whether or not the list is currently sorted by individual characters.
(i) (1 point) A method that returns the length of the list.
(j) (3 points) A method that returns an array containing the values in the list in current sorted order.
(k) (3 points) A method that returns the value in the ith position in current sorted order.
(l) (3 points) A method that changes the list to be sorted by string length.
(m) (3 points) A method that changes the list to be sorted by individual characters.
(n) (1 point) The class should not cause any memory leaks.
(o) (1 point) The class should have functions properly marked as constant.
*/
// class definition of a linked list node
class Node{
public:
    string value;
    Node* next;
    Node(string data){
    this->value = data;
    this-> next = NULL;}
    };


// class definition of our sorted list
// I used 1 to denote sorting by length and 2 for sorting by character
class SortedList{

public:
    Node* head = new Node("head");
    // constructor with no arguments
    SortedList(){
        sort = 1;
        len = 0;
    }
    // constructor specifying what sorting method to use.
    SortedList(int choice){
        sort = choice;
        len = 0;
    }
    // destructor to prevent memory leaks
    ~SortedList(){
    this->removeall();
    delete head;
    }
    void addNode(string data);
    bool isSortedByLength() const;
    bool isSortedByChar() const;
    int lengthOfList() const;
    void printlist() const;
    SortedList* copyll();
    int getsort() const;
    void setsort(int i);
    void removeElement(string input);
    void removeall();
    string* getlist() const;
    string getiposition(int i) const;
    void changesorttolength(SortedList lista);
    void changesorttochar(SortedList lista);

private:
    int len;
    int sort;
    void sortByLength(string data);
    void sortByChar(string data);
    };

// method to return length of list
int SortedList::lengthOfList() const{
return len;}
// method to return what sorting method is being used
int SortedList::getsort() const{
return sort;}
// method to return whether the list is sorted by length
bool SortedList::isSortedByLength() const{
if (sort == 1){
    return true;
}
return false;}
// method to return whether the list is sorted by char
bool SortedList::isSortedByChar() const{
if (sort == 1){
    return false;
}
return true;}
// private method to sort list by length
void SortedList::sortByLength(string input){
    int m = input.length();
Node* newnode = new Node(input);
Node* tmp = head;
while (tmp->next != NULL && m > tmp->next->value.length()){
    tmp = tmp->next;
}
newnode->next = tmp->next;
tmp->next = newnode;
}
// private method to sort list by character
void SortedList::sortByChar(string input){
    int m = input.length();
Node* newnode = new Node(input);
Node* tmp = head;
while (tmp->next != NULL && input > tmp->next->value){
    tmp = tmp->next;
}
newnode->next = tmp->next;
tmp->next = newnode;
}
// method to add elements to the list
void SortedList::addNode(string input){
if (sort==1){
    sortByLength(input);
}
else{
    sortByChar(input);
}
len++;
}
// method to print elements in the list. I created this for debugging
void SortedList::printlist() const{
Node* tmp = head->next;
while (tmp != NULL){
    cout<<tmp->value<<endl;
    tmp = tmp->next;
}
}
// method to deep copy of sorted list
SortedList* SortedList::copyll(){
    SortedList* newlist = new SortedList(this->getsort());
    Node* tmp = this->head->next;
    while (tmp != NULL){
        newlist->addNode(tmp->value);
        tmp = tmp->next;
    }
    return newlist;
}
// method to remove instances of a particular element in the list
void SortedList::removeElement(string input){
Node* tmp = head;
while (tmp->next != NULL){
    if (tmp->next->value == input){
        Node* nextnode = tmp->next->next;
        delete tmp->next;
        tmp->next = nextnode;
        len--;
    }
    else{
        tmp = tmp->next;
    }
}
}
// method to remove all elements in the list
void SortedList::removeall(){
Node* tmp = head;
while (tmp->next != NULL){
        Node* nextnode = tmp->next->next;
        delete tmp->next;
        tmp->next = nextnode;
        len--;
}
}
// method to return a list of elements in the sorted list
string* SortedList::getlist() const{
string* values = new string[len];
Node* tmp = head->next;
int i=0;
while (tmp != NULL){
    values[i] = tmp->value;
    tmp = tmp->next;
    i++;
}
return values;
}
// method to return value in the ith position
string SortedList::getiposition(int i)const{
int j = 0;
Node* tmp = head->next;
while (tmp != NULL){
    if (i==j){
        return tmp->value;
    }
    tmp = tmp->next;
    j++;
}
return "index invalid";
}
// method to change sorting method used
void SortedList::setsort(int i){
sort = i;}
// method that changes list to be sorted by character
void SortedList::changesorttochar(SortedList lista){
Node* tmp = head->next;
setsort(2);
head->next = NULL;
while (tmp != NULL){
    addNode(tmp->value);
    tmp = tmp->next;
}
}
// method that changes list to be sorted by length
void SortedList::changesorttolength(SortedList lista){
Node* tmp = head->next;
setsort(1);
head->next = NULL;
while (tmp != NULL){
    addNode(tmp->value);
    tmp = tmp->next;
}
}
int main(){
    SortedList lista(2);
    lista.addNode("him");
    lista.addNode("ahem");
    lista.addNode("mk");
    lista.printlist();
    lista.changesorttolength(lista);
 lista.printlist();
return 0;}
