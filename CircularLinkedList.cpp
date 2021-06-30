#include <iostream>

using namespace std;

class Node{         // Declare the structure of Node
public:
   int data;
   Node* next;
};
class CircularLinkedList{
private:
   Node* root = NULL;                        // declare root that points to the first element in the list
   Node* newNode(int data){                 // function to create a single node
         Node* temp= new Node();
         temp->data=data;
         temp->next=NULL;
         return temp;
      }
public:                        
   void append(int data){                          // append the insert the element at last position
      if (root==NULL){
         root = newNode(data);;
         root->next = root;
         return;
      }
      Node* temp = root;
      while(temp->next != root)
         temp = temp->next;

      Node* new_Node = newNode(data);
      temp->next = new_Node;
      new_Node->next = root;
   }
   void display(){                                      // Display function that display all the element present in the list
      Node* temp = root;
      while(temp->next != root){
         cout<< temp->data <<" ";
         temp = temp->next;
      }
      cout<<temp->data;
   }
   bool Search(int data){                              // function check if the element is present in the list or not
      Node* temp = root;
      while(temp->next != root){
         if (temp->data == data)
            return true;
         temp = temp->next;
      }
      if (temp->data == data)
            return true;
      return false;
   }
   int length(){                                 // length function that return the no of element present in the list
      int len = 0;
      if (!root)
         return 0;
      Node* temp = root;
      while(temp->next != root){
         temp = temp->next;
         len++;
      }
      return len + 1;
   }
   void delete_by_value(int data){                  // function that remove element from list
      if (!Search(data))
         return;
      Node* temp =  root;

      while(temp->next != root){
         if (temp->next->data == data)
            break;
         temp = temp->next;

      }
      if (temp->next == root){
         temp->next = root->next;
         root = root->next;
         return;

      }
      temp->next = temp->next->next;
   }
   void delete_by_index(int index){               // function that delete element by its index
      Node* temp = root;

      if (index > length())
         return;

      if (index == 1){
         while(temp->next != root)
            temp = temp->next;
         temp->next = root->next;
         root = root->next;
         return;
      }

      int i = 2;

      while(i < index){
         temp = temp->next;
         i++;
      }

      if (temp->next == root){
         temp->next = root->next;
         root = root->next;
         return;
      }

      temp->next = temp->next->next;
   }
   void Insert(int data, int index){               // function that insert data at a given index
      Node* temp = root;

      if (index > length() + 1)
         return;

      if (index == 1){
         while(temp->next != root)
            temp = temp->next;

         Node* new_Node = newNode(data);

         new_Node->next = temp->next;
         temp->next = new_Node;
         root = new_Node;

         return;
      }

      int i = 2;
      while(i < index){
         temp = temp->next;
         i++;
      }
      Node* new_Node = newNode(data);

      new_Node->next = temp->next;
      temp->next = new_Node;

   }
   void Clear(){                                   // function that clear all data from the list
      root = NULL;
   }

};
int main()
{
    cout << "Hello world!" << endl;
    CircularLinkedList lis;
    lis.append(10);
    lis.append(20);
    lis.append(30);
    lis.append(40);
    lis.append(50);
    lis.display();
    if (lis.Search(40))
      cout<<"\n40 is Present in the list.";
    cout<<"\nLength of list : "<<lis.length();
    lis.delete_by_index(2);
    lis.Insert(25, 3);
    lis.delete_by_value(40);
    lis.Insert(35, 1);
    cout<<"\n";
    lis.display();
    lis.Clear();
    return 0;
}
