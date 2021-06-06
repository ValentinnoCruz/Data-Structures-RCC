#ifndef QUEUE_H
#define QUEUE_H

#include <cstdlib>

using namespace std;

template <class T>
class Queue {
	private:
		struct Node{
                    T data;
                    Node *next;
		};
		Node *head;
		Node *tail;
		int size;
		void memError(){
			cout << "ERROR:Cannot allocate memory.\n";
			exit(EXIT_FAILURE);
		}
		void subError(){
			cout << "ERROR: Subscript out of range.\n";
			exit(EXIT_FAILURE);}
	public:
		Queue();
		virtual ~Queue();
		void push(T data);
		bool pop();
		T at(int index);
		T operator[](int index);
		void display();
		bool find(T data);
};

template <class T>
Queue<T>::Queue(){
	head = NULL;
	tail = NULL;
	size = 0;
}

template <class T>
Queue<T>::~Queue(){
	if (head) {                    // if head happens to be set 
		do {
			tail = head; // head to tail
			head = head->next; //head to be the old head link
			delete tail; 
		} while (head);
	}
}


//push to the back like a line

template <class T>
void Queue<T>::push(T data){
	if(!head){
		try{
			Node *temp = new Node;
			temp->next = NULL;
			temp->data = data;
			head = temp;
			tail = head;
			size++;
		} catch(bad_alloc) {
			memError();
		}
	} else {
		try{ 
			Node *temp = new Node;
			temp->data = data;
			temp->next = NULL;
			tail->next = temp;
			tail = temp;
			size++;
		} catch(bad_alloc) {
			memError();
		}
	}
}
template <class T>
bool Queue<T>::pop(){
	if(head){ 
		Node *newHead = head->next;
		head->next = NULL;
		delete head;
		head = newHead;
		return true;
	}
	return false;
}

template <class T>
T Queue<T>::at(int index) {
	if(index < 0 || index < size){
		Node *temp = head;
		for(int i = 0; i < index; i++){
			temp = temp->next;
		}
		return temp->data;
	} else {
		subError();
	}
}

template <class T>
T Queue<T>::operator [](int index){
	return at(index);
}

template <class T>
void Queue<T>::display(){
	Node *current = head;
	do{
		cout << current->data << ", ";
	} while((current = current->next));
	cout << endl;
}

template <class T>
bool Queue<T>::find(T data){
	Node *current = head;
	do{
		if(current->data == data) return true;
	} while((current = current->next));
	return false;
}


#endif /* QUEUE_H */