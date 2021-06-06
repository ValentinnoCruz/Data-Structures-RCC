#ifndef PRIORITYLIST_H
#define PRIORITYLIST_H

#include <cstdlib>

using namespace std;

template <class T>
class PriorityList {
	public:
		PriorityList();
		virtual ~PriorityList();
		void push(T data);
		bool pop();
		T at(int index);
		T operator[](int index);
		void display();
		bool find(T data);
		
	private:
		struct Node{
			T data;
			Node *next;
		};
		Node *head;
		Node *tail;
		int size;
		void memError();
		void subError();
};

template <class T>
PriorityList<T>::PriorityList(){
	head = NULL;
	tail = NULL;
	size = 0;
}

template <class T>
PriorityList<T>::~PriorityList(){
	if (head) {                     // if head happens to be set 
		do {
			tail = head;  //  head to tail
			head = head->next; //head to be the old head link
			delete tail; 
		} while (head);
	}
}

template <class T>
void PriorityList<T>::push(T data) {
	if(!this->head){
		try {
			Node *temp = new Node;
			temp->data = data;
			temp->next = NULL;
			head = temp;
			tail = head;
			size++;
		} catch(bad_alloc){
			this->memError();
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
			this->memError();
		}
	}
}

template <class T>
bool PriorityList<T>::pop(){
	if(head){
		Node *current = head;
		do{
			if(current->next->next == NULL){
				break;
			}
			current = current->next;
		} while(true);
		current->next = NULL;
		delete tail;
		tail = current;
		size--;
	}
}

template <class T>
T PriorityList<T>::at(int index){
	if(index < 0 || index < size){
		Node *temp = head;
		for(int i = 0; i < index; i++){
			temp = temp->next;
		}
		return temp->data;
	}
	return 0;
}

template <class T>
T PriorityList<T>::operator [](int index) {
	return at(index);
}


//Display error message and terminate program with mem allocation failure

template <class T>
void PriorityList<T>::memError() {
   cout << "ERROR:Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}


// show error message and terminate when subscript is not within range

template <class T>
void PriorityList<T>::subError() {
   cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}

template <class T>
void PriorityList<T>::display(){
	Node *current = head;
	do{
		cout << current->data << ", ";
	} while((current = current->next));
	cout << endl;
}

/**
 * find the index that the data is at
 * @param data
 * @return 
 */


template <class T>
bool PriorityList<T>::find(T data){
	Node *current = head;
	do{
		if(current->data == data){
			//move  to the front
			//find the previous one
			if(current != head){ // if it is already head do nothing
				Node *prev = head;
				do{
					if(prev->next == current){
						break;
					}
				} while((prev = prev->next));
				prev->next = current->next;
				if(current == tail){
					tail = prev;
				}
				current->next = head;
				head = current;
				
			}
			return true;
		}
	} while((current = current->next));
	return false;
}
#endif /* PRIORITYLIST_H */