#include <iostream>

using namespace std;



// 1) creating the node that is the main key of the linked list
class node {
public:
    int data;
    node* next;
    node(){
        data = 0;
        next = NULL;
    }
};

// 2) creating the main the linked list and its main functions

class linkedlist{

public:
    node* head;
    linkedlist(){
        head = NULL;
    }

    // 3) check if list is empty or not and tells the user

    void isempty(){
        if(head == NULL)
            cout << "the list is empty" << endl;
        else
            cout << "the list isnot empty" << endl;
    }

    // 4) adding a value at the first node which the head points to

    void addatfirst(int value){
        node* temp = new node();
        temp->data = value;
        if(head == NULL){
            temp->next = NULL;
            head = temp;
        }
        else
            temp->next = head;
            head = temp;

    }

    // 5) adding a value at the last node which points to NULL
    void addatend(int value){
        node* ptr = head;
        node* temp = new node();
        temp->data = value;
        if(head == NULL){
            temp->next = NULL;
            head = temp;
        }
        else{
            while(ptr != NULL){
                ptr = ptr->next;
            }
            ptr->next = temp;
            temp->next = NULL;
        }
    }

    //  6)  checks if the value actually exists or not in the linked list
    bool check(int value){
                node* ptr = head;
                while(ptr != NULL){

                    if(ptr->data == value)
                        return true;
                    else {
                        ptr = ptr->next;
                    }
                }
                return false;

            }


    // 7) adding after specific value entered by the user that exists in the linked list

    void addafter(int previousspecificvalue , int value){
        if(check(previousspecificvalue)){
                node* ptr = head;
                node* temp = new node();
                temp->data = value;
                if(head == NULL){
                    temp->next = NULL;
                    head = temp;
                }
                else
                    while(ptr->data != previousspecificvalue){
                        ptr = ptr->next;
                    }
                    temp->next = ptr->next;
                    ptr->next = temp;
}
        else
                cout << "Value you entered does not exist in the linked list " << endl;

    }

    //  8) adding before specific value that exists in the linked list
    void addbefore(int upcomingspecificvalue , int value){
        if(check(upcomingspecificvalue)){
                node* ptr = head;
                node* temp = new node();
                temp->data = value;
                if(head == NULL){
                    temp->next = NULL;
                    head = temp;
                }
                else
                    while(ptr->next->data != upcomingspecificvalue){
                        ptr = ptr->next;
                    }
                    temp->next = ptr->next;
                    ptr->next = temp;
        }
        else
                cout << "Value you entered does not exist in the linked list " << endl;

    }

        // 8) displaying all of the linked list values

        int display(){
            node* ptr = head;
            while(ptr != NULL){
                cout << ptr->data << "  ";
                ptr = ptr->next;
            }
            cout << endl;
        }

        //  9)  return the index of the specific value entered as parameter in the function
        int position(int value){
            if(check(value)){
                    int position = 0;
                    node* ptr = head;
                    while(ptr != NULL){
                        if(ptr->data == value)
                            return position;
                        else{
                            ptr = ptr->next;
                            position++;
                    }}
                    return -1;
                }

            else
                    cout << "Value you entered does not exist in the linked list " << endl;


        }


        // 10) deletes a specific value entered by the user that exists in the linked list
            void deleteval(int value){
                if(check(value)){
                   node* ptr = head, *ptr2;
                   while(ptr->next->data != value){
                        ptr = ptr->next;
                   }
                   ptr2 = ptr->next;
                   ptr->next = ptr2->next;
                   delete ptr2;
            }
                else
                  cout << "Value you entered does not exist in the linked list " << endl;

            }

            // 11) reverse the whole list and display it

            int reversing(){

                    node *prev, *current, *next;
                    prev = NULL;
                    current = head;
                    while(current != NULL){
                        next = current->next;
                        current->next = prev;
                        prev = current;
                        current = next;
                    }
                    head = prev;

                    display();

            }

            void sortinasc(){

                node* current, *next, *ptr = new node();
                current = head;
                while(current != NULL){
                    next = current->next;
                    ptr->data = current->data;
                    if((current->data)  > (next->data)){
                        current->data = next->data;
                        next->data = ptr->data;
                    }
                    current = next;
                }
                display();
            }

};

int main()
{
    int x;
    linkedlist trial;
    trial.isempty();
    cout << "add the number that you need to add to the list " << endl;
    cin >> x;
    trial.addatfirst(x);
    cin >> x;
    trial.addatfirst(x);
    cin >> x;
    trial.addatfirst(x);
    cin >> x;
    trial.addatfirst(x);
    trial.isempty();
    trial.display();
    trial.reversing();

    trial.sortinasc();


    return 0;
}
