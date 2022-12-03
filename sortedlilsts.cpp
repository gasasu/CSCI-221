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

class Node{
public:
    string value;
    Node* next;
    Node(string data){
    this->value = data;
    this-> next = NULL;}
    };



class SortedList{

public:
    Node* head = new Node("head");
    SortedList(){
        sort = 1;
        len = 0;
    }
    SortedList(int choice){
        sort = choice;
        len = 0;
    }
    void addNode(string data);
    bool isSortedByLength();
    bool isSortedByChar();
    int lengthOfList();
    void printlist();
    SortedList* copyll();
    int getsort();
    void setsort(int i);
    void removeElement(string input);
    void removeall();
    string* getlist();
    string getiposition(int i);
    void changesorttolength(SortedList lista);
    void changesorttochar(SortedList lista);

private:
    int len;
    int sort;
    void sortByLength(string data);
    void sortByChar(string data);
    };

int SortedList::lengthOfList(){
return len;}
int SortedList::getsort(){
return sort;}
bool SortedList::isSortedByLength(){
if (sort == 1){
    return true;
}
return false;}

bool SortedList::isSortedByChar(){
if (sort == 1){
    return false;
}
return true;}

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

void SortedList::addNode(string input){
if (sort==1){
    sortByLength(input);
}
else{
    sortByChar(input);
}
len++;
}

void SortedList::printlist(){
Node* tmp = head->next;
while (tmp != NULL){
    cout<<tmp->value<<endl;
    tmp = tmp->next;
}
}

SortedList* SortedList::copyll(){
    SortedList* newlist = new SortedList(this->getsort());
    Node* tmp = this->head->next;
    while (tmp != NULL){
        newlist->addNode(tmp->value);
        tmp = tmp->next;
    }
    return newlist;
}
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
void SortedList::removeall(){
Node* tmp = head;
while (tmp->next != NULL){
        Node* nextnode = tmp->next->next;
        delete tmp->next;
        tmp->next = nextnode;
        len--;
}
}
string* SortedList::getlist(){
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

string SortedList::getiposition(int i){
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
void SortedList::setsort(int i){
sort = i;}
void SortedList::changesorttochar(SortedList lista){
Node* tmp = head->next;
setsort(2);
head->next = NULL;
while (tmp != NULL){
    addNode(tmp->value);
    tmp = tmp->next;
}
}

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
    lista.addNode("sam");
    lista.addNode("bma");
    lista.addNode("mk");
    lista.addNode("mkere");
    lista.addNode("cma");
    lista.addNode("sma");
    lista.addNode("qma");
    lista.addNode("vma");
    lista.addNode("mk");
    lista.printlist();
    lista.changesorttolength(lista);
 lista.printlist();
return 0;}
