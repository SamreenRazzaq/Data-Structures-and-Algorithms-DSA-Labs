# include <iostream>
#define size 5
using namespace std;
class Queue{
int array[size],front,rear;
public:
Queue(){
	front=-1;
	rear=-1;
}
bool isfull(){
	if (front==-1 && rear==size-1){
		return true;
    }
    if (front==rear+1){
    	return true;
	}
		return false;
	}
bool isempty(){
	if (front==-1)
		return true;
	else
	return false;
	}
void enqueue(int element){
	if (isfull()){
		cout<<"QUEUE IS FULL..."  <<endl;
	}     
	else{
	if (front==-1)
	front=0;
	rear=(rear+1)%size;
	array[rear]=element;
	cout<<"ADD: "  <<endl<<element<<endl;
	}
}
int dequeue(){
	int element;
	if (isempty()){
		cout<<"QUEUE IS EMPTY..."<<endl;
		return(-1);
	}
	else{
		element=array[front];
		if (front==rear){
			front=-1;
			rear=-1;
		}
		else{
			front=(front+1)%size;
		}
		return(element);
	}
}
void display(){
	int i;
	if (isempty()){
		cout<<"EMPTY QUEUE..."<<endl;
		}
		else{
			cout<<"FRONT="<<front<<endl<<"ARRAY=";
			for (i=front;i!=rear;i=(i+1)%size)
			cout<<array[i];
			cout<<array[i] <<endl<<"REAR= "<<rear<<endl;
		}
}
};
int main(){
	Queue q;
	q.dequeue();
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.enqueue(6);
	q.display();

int num=q.dequeue();
if (num!=-1)
cout<<"DELETE ELEMENT IS: "<<num<<endl;
q.display();
q.enqueue(7);
q.display();
q.enqueue(8);
return 0;
}	

