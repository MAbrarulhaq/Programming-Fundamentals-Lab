// task 7
#include<iostream>
using namespace std;
class node{
    public:
        int info;
        node *next;
        node(int val){
            info=val;
            next=NULL;
        }     
};
class Queue{
    private:
        node* front;
        node* rear;
        int length;
    public:
        Queue(){
            front=rear=NULL;
            length=0;
        }

        void enqueue(int val){

            node *n = new node(val);

            if(front == NULL){
                
                front = n;
                rear = n; 
                length++;
            }
            
            rear->next =  n;
            rear = n;
            length++;
            
            
        }
        void dequeue(){
            // if(pos<1 || pos>length+1){
            //     return;
            // }
            node *curr=front;
                front=front->next;
                delete curr;
            
            // else{
            //     node *slow=NULL;
            //     for(int i=1;i<pos;i++){
            //         slow=curr;
            //         curr=curr->next;
            //     }
            //     slow->next=curr->next;
            //     delete curr;
            // }
            length--;

        }

        void duplicates(Queue &q2){
            node *curr=front;
            for(int j=0;j<length-1;j++){
             for(int i=0;i<curr->info;i++){
                q2.enqueue(curr->info);
            }
            curr=curr->next;
        }


        }



        bool isempty(){
            if(length==0){
                return true;
            }
            else{
                return false;
            }
        }
        void printing(){
            node *n=front;
            while(n!=NULL){
                cout<<n->info<<"\t";
                n=n->next;
            }
            cout<<endl;
            cout<<"-----------------------------------:"<<endl;
        }
        
};
int main(){
     Queue q1,q2;
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);
    q1.printing();

    // q1.dequeue();
    // q1.printing();

    // q1.isempty();

    q1.duplicates(q2);
    q2.printing();





    


}