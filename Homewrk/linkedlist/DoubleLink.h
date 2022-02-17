#ifndef DOUBLELINK_H
#define DOUBLELINK_H

#include <new>
#include <cstdlib>

using namespace std;

template <class T>
class DoubleLink {
	private:
		struct Node{
			T data;
			Node *prev;
			Node *next;
		};
		Node *head;
		Node *tail;
		int size;
		void memError();
		void subError();
	public:
		DoubleLink();
		virtual ~DoubleLink();
		void push(T data);
		bool pop();
		T at(int index);
		T operator[](int index);
		void display();
		bool find(T data);
};

template <class T>
DoubleLink<T>::DoubleLink(){
	head = NULL;
	tail = NULL;
	size = 0;
}

template <class T>
DoubleLink<T>::~DoubleLink(){
	if (head) {                   // if head happens to be set 
		do {
			tail = head; // head to tail 
			head = head->next; //head to be the old head link
			delete tail; 
		} while (head);
	}
}

template <class T>
void DoubleLink<T>::push(T data){
	if(!head){
		try{
			Node *temp = new Node;
			temp->prev = NULL;
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
			temp->prev = tail;
			tail->next = temp;
			tail = temp;
			size++;
		} catch(bad_alloc) {
			memError();
		}
	}
}

template <class T>
bool DoubleLink<T>::pop(){
	if(head){ 
		Node *newTail = tail->prev;
		newTail->next = NULL;
		delete tail;
		tail = newTail;
		size--;
		return true;
	} else {
		return false;
	}
}

template <class T>
T DoubleLink<T>::at(int index){
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
T DoubleLink<T>::operator [](int index) {
	return at(index);
}

template <class T>
void DoubleLink<T>::memError()
{
   cout << "Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}

template <class T>
void DoubleLink<T>::subError()
{
   cout << "Subscript is out of range.\n";
   exit(EXIT_FAILURE);
}

template <class T>
void DoubleLink<T>::display(){
	Node *current = head;
	do{
		cout << current->data << ", ";
	} while((current = current->next));
	cout << endl;
}

template <class T>
bool DoubleLink<T>::find(T data){
	Node *current = head;
	do{
		if(current->data == data) return true;
	} while((current = current->next));
	return false;
}
#endif /* DOUBLELINK_H */