#include <cstdlib>
#include <iostream>

using namespace std;

#include "DoubleLink.h"
#include "SortedList.h"
#include "PriorityList.h"
#include "Queue.h"

int main(int argc, char** argv) {
	cout << "\nDouble Link List\n";
	DoubleLink<int> dubLink;
        dubLink.push(2);
	dubLink.push(3);
	dubLink.push(5);
	dubLink.push(7);
	dubLink.push(11);
        cout << "Push: ";
	dubLink.display();
	dubLink.pop();
        cout << "Pop: ";
	dubLink.display();
        
        cout << "\nSorted List\n";
	SortedList<int> sortedLink;
	sortedLink.push(2);
	sortedLink.push(3);
	sortedLink.push(5);
	sortedLink.push(7);
	sortedLink.push(11);
        cout << "Push: ";
	sortedLink.display();
	sortedLink.pop();
        cout << "Pop: ";
	sortedLink.display();

	cout << "\nPriority List\n";
	PriorityList<int> priorList;
	priorList.push(2);
	priorList.push(3);
	priorList.push(5);
	priorList.push(7);
	priorList.push(11);
        cout << "Push: ";
	priorList.display();
	priorList.pop();
        cout << "Pop: ";
	priorList.display();
	priorList.find(7);
        cout << "Reorganized: ";
	priorList.display();
        
        	cout << "\nQueue List\n";
	Queue<int> queueLink;
	queueLink.push(2);
	queueLink.push(3);
	queueLink.push(5);
	queueLink.push(7);
	queueLink.push(11);
        cout << "Push: ";
	queueLink.display();
	queueLink.pop();
        cout << "Pop: ";
	queueLink.display();
}