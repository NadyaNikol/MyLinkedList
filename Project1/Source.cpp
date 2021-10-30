#include <iostream>
using namespace std;

struct node
{
	int data;
	node* next;
	node* prev;
};

class linked_list
{
private:
	node* head, * tail;
	int size = 0;
public:
	linked_list()
	{
		head = NULL;
		tail = NULL;
	}

	void push(int n) {

		node* tmp = new node;
		tmp->data = n;
		tmp->next = NULL;
		size++;

		if (head == NULL)
		{
			head = tmp;
			tail = tmp;
			tmp->prev = NULL;
		}
		else
		{
			tmp->prev = tail;
			tail->next = tmp;
			tail = tmp;
		}
	}

	void pushFirst(int n) {

		size++;
		node* tmp = new node;
		tmp->data = n;
		tmp->prev = NULL;

		if (head == NULL) {
			head = tmp;
			tail = tmp;
			tmp->next = NULL;
		}
		else
		{
			head->prev = tmp;
			tmp->next = head;
			head = tmp;
		}
	}

	void pop() {


		if (tail != NULL) {

			size--;
			node* tmp = tail;

			if (head == tail)
			{
				head = NULL;
				tail = NULL;
			}
			else
			{
				tail = tmp->prev;
				tail->next = NULL;
			}

			delete tmp;
		}
	}

	void popFirst()
	{
		if (head != NULL)
		{
			size--;
			node* tmp = head;

			if (head == tail)
			{
				head = NULL;
				tail = NULL;
			}
			else
			{
				head = head->next;
				head->prev = NULL;
			}

			delete tmp;
		}
	}

	bool popIndex(int index) {

		if (index == 0) popFirst();
		else if (index == size - 1) pop();

		if (index > 0 && index < size)
		{
			node* ptr = head;
			int count = 0;

			while (ptr != NULL)
			{
				if (count++ == index)
				{
					node* ptrPrev = ptr->prev;
					node* ptrNext = ptr->next;
					ptrPrev->next = ptrNext;
					ptrNext->prev = ptrPrev;

					delete ptr;
					size--;
					return true;
				}
				ptr = ptr->next;
			}
		}
		return false;
	}

	bool popElement(int element) {
		node* ptr = head;
		int count = 0;

		while (ptr != NULL)
		{
			if (ptr->data == element)
			{
				if (ptr == tail) pop();
				else if (ptr == head) popFirst();
				else
				{
					node* ptrPrev = ptr->prev;
					node* ptrNext = ptr->next;
					ptrPrev->next = ptrNext;
					ptrNext->prev = ptrPrev;
					delete ptr;
				}	

				size--;
				return true;
			}
			ptr = ptr->next;
		}
		return false;
	}

	void set(int index, int element)
	{
		if (index >= 0 && index < size)
		{
			node* ptr = head;
			int count = 0;

			while (ptr != NULL)
			{
				if (count++ == index)
				{
					ptr->data = element;
					break;
				}
				ptr = ptr->next;
			}
		}
	}

	void show() {
		node* ptr = head;

		while (ptr != NULL) {
			cout << ptr->data << " ";
			ptr = ptr->next;
		}
	}

	void show2() {
		node* ptr = tail;

		while (ptr != NULL) {
			cout << ptr->data << " ";
			ptr = ptr->prev;
		}
	}

};

int main()
{
	linked_list a;

	for (int i = 0; i < 10; i++) a.push(i + 1);
	
	a.pushFirst(100);

	for (int i = 0; i < 10; i++) a.pop();

	a.popFirst();


	a.push(64);
	a.push(7);

	a.pushFirst(10000);

	a.popIndex(0);
	/*cout << a.popElement(7) << endl;
	cout << a.popElement(64)<<endl;*/
	a.pushFirst(10000);

	a.set(0, 1);
	a.set(-1, 5);


	a.show();
	cout << endl;
	a.show2();

	return 0;
}

