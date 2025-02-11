// ASU CSE310 Linked List Sample Code
// Description: This program displays a simple LinkedList with nodes.
//              Study this sample code to learn basic operations on linked list.

#include <iostream>

using namespace std;

//A LinkedList Node contains a data and a pointer that points to the next Node
struct Node
{
    int data;
    Node *next;
};

//A simple LinkedList class demo
class LinkedList
{
    private:
        Node* head;     //always points to the first Node of the list. Do NOT remove it.

    public:
        //constructor. Initialize an empty linked list
        LinkedList()
        {
            head = NULL;
        }

        //LinkedList insertion demo. This function will always insert a new
        //Node at the head of the linked list
        void insertNodeAtFront(int n)
        {
            //create a new Node
            Node *aNewNode = new Node;
            aNewNode->data = n;
            aNewNode->next = NULL;

            //if it is an empty linked list, insert it as the first node
            if(head == NULL)
               head = aNewNode;
            else
            {
                aNewNode->next = head;
                head = aNewNode;
            }
        } //end of insertNodeAtFront

        //LinkedList deletion demo. This function will delete the last node
        void deleteLastNode()
        {
            //if it is an empty linked list, cannot delete
            if(head == NULL)
                cout << "Empty linked list, deletion error" << endl;
            else if (head->next == NULL)    //linked list contains only one node
            {
                delete head;
                head = NULL;
            }
            else
            {
                //we will use two pointers for the deletion
                Node* current = head;
                Node* previous = NULL;

                //traverse through the linked list to the end
                while(current->next != NULL)
                {
                    previous = current;
                    current = current->next;
                }
                //after above while loop, current points to the last node
                delete current;
                previous->next = NULL;
                current = previous;
            }
        } //end of deleteLastNode()

        //this function prints Linked list contents from head to tail
        void printList()
        {
            Node* temp = head;
            if (head == NULL)
                cout << "Empty linked list" << endl;
            else
            {
                while(temp != NULL)
                {
                    cout << temp->data << ", ";
                    temp = temp->next;
                }
                cout << endl;
            }
        } //end of printList
}; //end of class LinkedList definition

//driver function used to test/check above linked list
int main()
{
    LinkedList sampleList;  //create an LinkedList object

    int num;

    //sentinel value controlled while loop that allows user to continue
    //inserting a Node until 0 is entered
    cout << "Enter an integer (enter 0 to stop): ";
    cin >> num;

    while (num != 0)
    {
        sampleList.insertNodeAtFront(num);
        cout << "\nEnter an integer (enter 0 to stop): ";
        cin >> num;
    }
    sampleList.printList();
    sampleList.deleteLastNode();
    sampleList.deleteLastNode();
    sampleList.printList();
}
