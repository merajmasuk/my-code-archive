#include<iostream>
using namespace std;

class Node{
    public:
        int data; Node *next;

        Node(int d){
            data = d;
            next = NULL;
        }
};

class LinkedList{
    public:
        Node* insert(Node *head, int data){
            if (head == NULL)
                return new Node(data);
            else if (head->next == NULL)
                head->next = new Node(data);
            else insert(head->next, data);
            return head;
        }

        void display(Node *head){
            Node *start = head;

            while (start){
                cout << start->data << " ";
                start = start->next;
            }
        }
};

int main(){
	Node* head = NULL;
  	LinkedList mylist;

    int T,data;
    cin >> T;

    while(T--){
        cin >> data;
        head = mylist.insert(head, data);
    }

	mylist.display(head);

	return 0;
}
