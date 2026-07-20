#include <iostream>
using namespace std;

struct Node {

    int data;
    Node* next;

    Node(int value){
        data = value;
        next = nullptr;
    }
};


class Stack {

private:
    Node* top;


public:

    Stack(){
        top = nullptr;
    }


    void push(int value){

        Node* newNode = new Node(value);

        newNode->next = top;

        top = newNode;
    }


    void pop(){

        if(top == nullptr){

            cout<<"Stack Empty\n";
            return;
        }


        Node* temp = top;

        top = top->next;

        delete temp;
    }


    int peek(){

        if(top == nullptr)
            return -1;

        return top->data;
    }


    void display(){

        Node* current = top;

        while(current){

            cout<<current->data<<" ";

            current=current->next;
        }
    }
};


int main(){

    Stack s;


    s.push(10);
    s.push(20);
    s.push(30);


    cout<<"Stack: ";
    s.display();


    cout<<"\nTop: "
        <<s.peek();


    s.pop();


    cout<<"\nAfter pop: ";
    s.display();


    return 0;
}
