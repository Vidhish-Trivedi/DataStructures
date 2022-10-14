#include<iostream>
using namespace std;

class Node{
    private:
        long long int data;
        Node* next;
    
    public:
        Node(long long int d){
            this->data = d;
            this->next = NULL;
        }

        long long int getData(){
            return(this->data);
        }

        Node* getNext(){
            return(this->next);
        }

        void setData(long long int d){
            this->data = d;
            return;
        }

        void setNext(Node* n){
            this->next = n;
            return;
        }
};

class LinkedList{
    private:
        Node* head;

    public:
        LinkedList(){
            this->head = NULL;
        }

        void Print(){
            Node* temp = this->head;
            while(temp != NULL){
                cout << temp->getData() << " ";
                temp = temp->getNext();
            }
            cout << endl;
            return;
        }

        void AddToEnd(long long int v){
            Node* n = new Node(v);
            if(this->head == NULL){
                this->head = n;
                return;
            }
            
            Node* temp = this->head;
            while(temp->getNext() != NULL){
                temp = temp->getNext();
            }
            temp->setNext(n);
            return;
        }

        void AddToBeginning(long long int v){
            Node* temp = this->head;
            Node* n = new Node(v);
            n->setNext(temp);
            this->head = n;
            return;
        }

        int Search(long long int v){
            if(this->head == NULL){
                return(-1);  // Not Found.
            }
            Node* temp = this->head;
            while(temp != NULL){
                if(temp->getData() == v){
                    return(0);  // Found.
                }
                temp = temp->getNext();
            }
            return(-1);  // Not Found.
        }

        void Remove(long long int v){
            if(this->Search(v) == 0){
                Node* temp = this->head;
                Node* n = NULL;
                if(temp->getData() == v){
                    this->head = this->head->getNext();
                    return;
                }
                while(temp->getData() != v){
                    n = temp;
                    temp = temp->getNext();
                }
                n->setNext(temp->getNext());
                temp->setNext(NULL);
                return;
            }
            else{
                cout << "Value not in Linked List." << endl;
                return;
            }
        }
};

int main(){
    LinkedList* l = new LinkedList();

    // Simple Test.
    for(int i = 1; i <= 30; i++){
        l->AddToEnd(i);
    }

    l->Print();

    for(int i = -1; i >= -30; i--){
        l->AddToBeginning(i);
    }

    l->Print();

    cout << l->Search(13) << endl;
    cout << l->Search(0) << endl;

    l->Remove(13);
    cout << l->Search(13) << endl;
    l->Print();
    l->Remove(0);

    return(0);
}

