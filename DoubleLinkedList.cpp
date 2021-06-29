#include <iostream>
#include <cstdlib>
using namespace std;

class Node{                         // Declare the structure of Node
   public:
      Node* prev = NULL;
      int data;
      Node* next = NULL;

};
class LinkedList{
   private:
      Node* root=NULL;                             // declare root that points to the first element in the list
      Node* newNode(int data){
         Node* temp = new Node();
         temp->prev = NULL;
         temp->data = data;
         temp->next = NULL;
         return temp;
      }
   public:
      void display(){                           // Display function that display all the element present in the list
         Node* temp = root;
         while(temp){
            cout<<temp->data<<" ";
            temp = temp->next;
         }

      }
      void append(int data){                       // append the insert the element at last position
         Node* temp = root;
         if (root == NULL){
            root = newNode(data);
            return;
         }
         else{
            while(temp->next){
               temp = temp->next;
            }
            Node* new_Node = newNode(data);
            temp->next = new_Node;
            new_Node->prev = temp;
         }

      }
      int length(){                           // length function that return the no of element present in the list
         Node* temp = root;
         int len = 0;
         while(temp){
            temp = temp->next;
            len++;
         }
         return len;
      }
      void delete_by_index(int index){          // function that delete element by its index
         if (length() < index)
            return;
         else if (length() == index){
            Node* temp = root;
            while(temp->next)
               temp = temp->next;
            temp->prev->next = NULL;
            free(temp);
         }
         else if(index == 1){
            Node* temp = root;
            root = root->next;
            root->prev = NULL;
            free(temp);
         }
         else{
            Node* temp = root;

            for (int i=1; i<index; i++){
               temp = temp->next;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
         }
      }
      void delete_by_data(int data){            // function that remove element from list
         if (!Search(data))
            return;
         if (root->data == data){
            Node* temp = root;
            root = root->next;
            root->prev = NULL;
            free(temp);
         }
         else {
            Node* temp = root;
            while(temp){
               if (temp->data == data)
                  break;
               temp = temp->next;

            }
            if (temp->next){
               temp->prev->next = temp->next;
               temp->next->prev = temp->prev;

            }
            else if (temp->next == NULL){

               temp->prev->next = NULL;
               free(temp);
            }
         }
      }
      bool Search(int data){                  // function check if the element is present in the list or not
         Node* temp = root;
         while(temp){
            if (temp->data == data)
                return 1;
            temp = temp->next;
         }
         return 0;
      }
      void Insert(int data, int index){              // function that insert data at a given index
         if (index > length() + 2)
            return;

         if (index == 1){
            if (root){                              // for checking if Linked list is empty or not
               Node* new_Node = newNode(data);
               root->prev = new_Node;
               new_Node->next = root;
               root = new_Node;
            }
            else{
               root = newNode(data);
            }
            return;

         }
         else if (index == length() + 1){
            Node* temp = root;
            while(temp->next)
               temp = temp->next;
            temp->next = newNode(data);
         }
         else {
            Node* temp = root;
            for (int i=2; i<index; i++)
               temp = temp->next;
            Node* new_Node = newNode(data);
            temp->next->prev = new_Node;
            new_Node->next = temp->next;
            temp->next = new_Node;
            new_Node->prev = temp;
         }
      }
      void Clear(){                   // function that clear all data from the list
         root = NULL;
      }
};
int main()
{

    LinkedList list;
    list.append(3);
    list.append(1);
    list.append(4);
    list.append(2);
    list.append(5);
    list.append(6);
    list.Insert(25, 2);
    list.Insert(251, 5);
    list.append(10);
    list.display();
    cout<<"\nLength of linked list :"<<list.length()<<"\n";
    list.delete_by_data(6);
    list.delete_by_index(7);
    list.display();
    cout<<"\nLength of linked list :"<<list.length();
    if (list.Search(6))
      cout<<"\n6 is present in the list";
    list.Clear();
    return 0;
}
