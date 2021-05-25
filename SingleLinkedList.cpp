#include <iostream>

using namespace std;
// declaring the class structure of a Node;
class Node{
   public:
      int data;
      Node *next;
};

// declaring the linked List class.
class linkedlist{
   private:
      Node* root=NULL;
      Node* newNode(int data){                 // function to create a single node
         Node* temp= new Node();
         temp->data=data;
         temp->next=NULL;
         return temp;
      }

   public:
      void append(int data){                   // function to append list
         Node* temp=root;
         if(root==NULL){
            root=newNode(data);
            return;
         }
         else{
            while(temp->next){
               temp = temp->next;
            }
            temp->next=newNode(data);
         }
      }

      void display(){                      // function to display all node in list.
         Node* temp = root;
         if (root == NULL)
            cout<<"\nList is empty !!!";
         else{
            while(temp){
               cout<<temp->data<<" -> ";
               temp = temp->next;
            }
         }

      }
      int length(){                        // function to find length of linked list
         int len = 0;
         Node* temp = root;
         while(temp){
           temp = temp->next;
           len++;
         }
         return len;
      }
      void insert(int data, int position){   // function to insert data at given position
         Node* temp = root;
         if (length() < position){
            cout<<"\nInvalid position !!!";
         }
         else{
            while(position > 2){
               temp = temp->next;
               position--;
            }
            Node* value = newNode(data);
            value->next = temp->next;
            temp->next = value;
         }
      }
      void Remove(int data){               // function to remove the data from linked list
         Node* temp = root;
         if (temp->data == data){
               root = temp->next;
               return;
         }

         while(temp){
            if (temp->next->data == data)
               break;
            temp = temp->next;
         }
         temp->next = temp->next->next;
      }


      void ClearList(){                   // function to clear all nodes from linked list
         root = NULL;
      }


      void delete_by_index(int index){    // function to delete a node by its index value
         Node* temp = root;
         while(index > 1){
            index--;
            temp = temp->next;
         }
         Remove(temp->data);
      }


      bool Search(int data){             // function to search if the element is present or not in the linked list
         Node* temp = root;
         while(temp){
            if (temp->data == data)
               return true;
            temp = temp->next;
         }
         return false;
      }

};



int main()
{
    linkedlist l;   // declaring l as linked list
    l.append(1);
    l.append(2);
    l.append(3);
    l.append(4);
    l.append(6);
    l.insert(5, 5);
    l.Remove(5);
    l.insert(5, 5);
    l.delete_by_index(1);
    cout<<"\nLength of list : "<<l.length()<<"\n";
    l.display();
    cout<<"\n";
    cout<<l.Search(6);
    l.ClearList();
    l.display();
    return 0;
}
