#include<iostream>
using namespace std;
class node{
    public:
        int data;
        node *head, *next;

    node(){
        data = 0;
        head = NULL;
        next = NULL;
    }

    bool isEmpty() {
        if (head == NULL){
            return true;
        } else {
            return false;
        }
    }

    void insertBegin(int value){
        node *newNode = new node();
        newNode->data = value;
        if (isEmpty()) {
            head = newNode;
            newNode->next = NULL;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void insertOrder(int value){
        node *newNode = new node();
        newNode->data = value;
        if (isEmpty() || head->data >= value) {
            newNode->next = head;
            head = newNode;
            return;
        }
        node *temp = head;
        while (temp->next != NULL && temp->next->data < value) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void insertEnd(int value){
        node *newNode = new node();
        node *temp = head;
        newNode->data = value;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = NULL;
    }

    void deleteBegin(){
        if (isEmpty()) {
            cout<<"List is Empty"<<endl;
        } else {
            node *temp = head;
            head = temp->next;
            delete(temp);
        }
    }

    void deleteEnd(){
        if (isEmpty()) {
            cout<<"List is Empty"<<endl;
        } else {
            node *current = head;
            node *previous = NULL;
            while (current->next != NULL) {
                previous = current;
                current = current->next;
            }
            delete(current);
            previous->next = NULL;
        }
    }

    void deleteValue(int value){
        if (isEmpty()) {
            cout<<"List is Empty"<<endl;
        } else {
            node *current = head;
            node *previous = NULL;
            while (current->data != value) {
                previous = current;
                current = current->next;
            }
            if (current == NULL) {
                cout<<"Value not Found!";
                return;
            } else {
            previous->next = current->next;
            delete(current);
            }
        }
    }

    int size(){
        if (isEmpty()) {
            cout<<"List is Empty"<<endl;
            return -1;
        } else {
            int size = 0;
            node *temp = head;
            while (temp != NULL) {
                size++;
                temp = temp->next;
            }
            return size;
        }
    }

    int first(){
        if (isEmpty()) {
            cout<<"List is Empty"<<endl;
            return -1;
        } else {
            return head->data;
        }
    }

    void update(int oldValue, int newValue){
        if (isEmpty()) {
            cout<<"List is Empty"<<endl;
        } else {
            node *temp = head;
            while (temp->data != oldValue) {
                temp = temp->next;
            }
            temp->data = newValue;
        }
    }

    void display(){
        if (isEmpty()) {
            cout<<"List is Empty"<<endl;
        } else {
            node *temp = head;
            while (temp != NULL) {
                cout<<temp->data<<"\t";
                temp = temp->next;
            }
            cout<<endl;
        }
    }
};
int main(){
    node N = node();
    int choice, value, oldValue;
    
    while (true) {
        cout<<"1: insert at beginning"<<endl;
        cout<<"2: insert at the end"<<endl;
        cout<<"3: insert at a specific location"<<endl;
        cout<<"4: delete from beginning"<<endl;
        cout<<"5: delete from end"<<endl;
        cout<<"6: delete a specific value"<<endl;
        cout<<"7: display the list"<<endl;
        cout<<"8: size of list"<<endl;
        cout<<"9: first element"<<endl;
        cout<<"10: update a value"<<endl;
        cout<<"11: exit"<<endl;
        cout<<"Enter your choice:"<<endl;
        cin>>choice;

        switch (choice) {
        case 1:
            cout<<"Enter value:"<<endl;
            cin>>value;
            N.insertBegin(value);
            break;
        case 2:
            cout<<"Enter value:"<<endl;
            cin>>value;
            N.insertEnd(value);
            break;
        case 3:
            cout<<"Enter value:"<<endl;
            cin>>value;
            N.insertOrder(value);
            break;
        case 4:
            N.deleteBegin();
            break;
        case 5:
            N.deleteEnd();
            break;
        case 6:
            cout<<"Enter value:"<<endl;
            cin>>value;
            N.deleteValue(value);
            break;
        case 7:
            N.display();
            break;
        case 8:
            cout<<"Size is: "<<N.size()<<endl;
            break;
        case 9:
            cout<<N.first()<<endl;
            break;
        case 10:
            cout<<"Enter value Old:"<<endl;
            cin>>oldValue;
            cout<<"Enter value New:"<<endl;
            cin>>value;
            N.update(oldValue, value);
            break;
        case 11:
            return 0;
            break;
        
        default:
            cout<<"Invalid Chocie"<<endl;
            break;
        }
    }
    
    return 0;
}
