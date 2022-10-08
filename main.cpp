#include <iostream>

using namespace std; 

class Node {

private:
	int value = 0;
	Node* NextNode;
	friend class List;

public:  // Constructors

	Node(int v)
	{
		value = v;
		NextNode = NULL;
	}

	Node(int v, Node* newNextNode)
	{
		value = v;
		NextNode = newNextNode;
	}
	friend class Test;
};

typedef Node* PointerNode; //Alias

class List {

private:
	PointerNode head;
	PointerNode current;

public:
	List() { head = NULL; current = NULL; }
	//~List();

	void unshift(int v); // Insert at Beginning
	void push(int v); // Insert at End
	void splice(int v, int pos); // Insert at Index Position
	bool isEmpty() { return head == NULL; }
	void display();
	void next();
	void first();
	void last();
	Node* pop();
	void shift();
	void removeAtIndex(int pos);
	Node* getElementByIndex(int index);
	int length();
	bool searchElement(int element);

	friend class Test;
};
/*
List::~List()
{
	PointerNode aux;

	while (head) {
		aux = head;
		head = head->NextNode;
		delete aux;
	}

	head = NULL;
}
*/
int List::length() {
	int cont = 0;

	PointerNode aux = head;
	if (isEmpty()) {
		return cont;
	}
	else {
		while (aux != NULL) {
			aux = aux->NextNode;
			cont++;
		}
		return cont;
		cout << endl;
	}

}

void List::unshift(int v)
{
	if (isEmpty())
	{
		head = new Node(v);
	}
	else
	{
		head = new Node(v, head);
	}
}

void List::push(int v)
{
	if (isEmpty()) {
		head = new Node(v);
	}
	else
	{
		PointerNode aux = head;

		while (aux->NextNode != NULL) {
			aux = aux->NextNode;
		}
		aux->NextNode = new Node(v);
	}
}

void List::splice(int v, int pos)
{
	if (isEmpty()) {
		head = new Node(v);
	}
	else {
		if (pos <= 1)
		{
			unshift(v);
		}
		else {
			Node* aux = head;
			int i = 2;
			while ((i != pos) && (aux->NextNode != NULL)) {
				i++;
				aux = aux->NextNode;
			}
			PointerNode newNodeFirst = new Node(v);
			newNodeFirst->NextNode = aux->NextNode;
			aux->NextNode = newNodeFirst;
		}
	}
}

Node* List::pop()
{
	if (isEmpty()) {
		return NULL;
	}
	else {

		if (head->NextNode == NULL)
		{
			PointerNode temp = head;
			head = NULL;
			return temp;
		}
		else {

			PointerNode aux = head;
			while (aux->NextNode->NextNode != NULL) {
				aux = aux->NextNode;
			}

			PointerNode temp = aux->NextNode;
			aux->NextNode = NULL;

			return temp;
		}
	}
}

void List::shift()
{
	if (isEmpty()) {
		cout << "Empty List:" << endl;
	}
	else {
		if (head->NextNode == NULL)
		{
			PointerNode temp = head;
			head = NULL;
			delete temp;
		}
		else
		{
			PointerNode aux = head;
			head = head->NextNode;
			delete aux;
		}
	}
}

void List::removeAtIndex(int index) {
	if (isEmpty()) {
		cout << "Empty List" << endl;
	}
	else {
		if ((index > length()) || (index < 0)) {
			cout << "An Index should be greater than zero" << endl;
		}
		else {
			if (index == 1)
			{
				PointerNode temp = head;
				head = head->NextNode;
				delete temp;
			}
			else {
				int cont = 2;
				PointerNode aux = head;
				while (cont < index) {
					aux = aux->NextNode;
					cont++;
				}
				PointerNode temp = aux->NextNode;
				aux->NextNode = aux->NextNode->NextNode;
				delete temp;
			}
		}
	}
}

void List::display()
{
	Node* aux;
	if (head == NULL) {
		cout << "Empty List";
	}
	else
	{
		aux = head;
		while (aux)
		{
			if (aux->NextNode == NULL)
			{
				cout << aux->value;
			}
			else {
				cout << aux->value << ", ";
			}

			aux = aux->NextNode;
		}
		cout << endl;
	}
}

void List::next()
{
	if (current) current = current->NextNode;
}

void List::first()
{
	current = head;
}

void List::last()
{
	current = head;
	if (!isEmpty())
		while (current->NextNode) next();
}

bool List::searchElement(int element)
{
	bool searchElement = false;
	if (head != NULL) {
		Node* aux = head;
		while (aux)
		{
			if (aux->value == element)
			{
				searchElement = true;
			}
			aux = aux->NextNode;
		}
	}
	return searchElement;
}

Node* List::getElementByIndex(int index) 
{
	if (isEmpty()) {
		return NULL;
	}
	else {
		if ((index > length()) || (index < 0)) {
			cout << "An Index should be greater than zero" << endl;
		}
		else {
			if (index == 1)
			{
				PointerNode temp = head;
				head = head->NextNode;
				return temp;
			}
			else {
				int cont = 2;
				PointerNode aux = head;
				while (cont < index) {
					aux = aux->NextNode;
					cont++;
				}
				PointerNode temp = aux->NextNode;
				aux->NextNode = aux->NextNode->NextNode;
				return temp;
			}
		}
	}
}

class Test {
private:

public:
	Test(){ }
	void UNO(List* LBuscar, List* LTrabajo);
	void DOS();
	void TRES();
	void CUATRO();
};

//Exercise 1
void Test::UNO(List* LBuscar, List* LTrabajo)
{
	if (LBuscar->isEmpty() && LTrabajo->isEmpty())
	{
		cout << "Ambas Listas Estan Vacias" << endl;
	}
	else if (LBuscar->isEmpty() && !LTrabajo->isEmpty()) {
		LTrabajo->display();
	}
	else if (!LBuscar->isEmpty() && LTrabajo->isEmpty()) {
		cout << "Lista de Trabajo Esta Vacia" << endl;
	}
	else {
		List* output = new List();
		List* temp = LTrabajo;

		while (temp->length() != 0) {

			Node* currentNode = temp->pop();
			bool lBuscarHasElement = LBuscar->searchElement(currentNode->value);
			if (lBuscarHasElement)
			{

				output->unshift(currentNode->value);
				output->unshift(1);
				output->unshift(0);
				output->unshift(1);
			}
			else {
				output->unshift(-1);
			}
		}
		output->display();
	}
};

//Exercise 2
void Test::DOS()
{
	
};

//Exercise 3
void Test::TRES() {
	
};

//Exercise 4
void Test::CUATRO() {


};

int main()
{
	//Init Test
	Test test;

	cout << "***************************************************************************************" << endl;
	cout << "UNO" << "\n" << endl;
	List* ListaBuscar = new List();// Init as NULL
	ListaBuscar->push(4);
	ListaBuscar->push(5);
	ListaBuscar->push(7);
	ListaBuscar->push(9);
	ListaBuscar->push(12);
	ListaBuscar->push(23);
	ListaBuscar->push(34);

	List* ListaTrabajo = new List();
	ListaTrabajo->push(5);
	ListaTrabajo->push(8);
	ListaTrabajo->push(9);
	ListaTrabajo->push(23);
	ListaTrabajo->push(5);
	ListaTrabajo->push(7);
	ListaTrabajo->push(0);
	ListaTrabajo->push(14);

	test.UNO(ListaBuscar, ListaTrabajo);
	
	cout << endl;

	cout << "***************************************************************************************" << endl;
	//Lista.~List();
	cout << "DOS" << "\n" << endl;

	cout << endl;
	cout << "***************************************************************************************" << endl;
	//Lista.~List();
	cout << "TRES" << "\n" << endl; 
	
	cout << endl;
	cout << "***************************************************************************************" << endl;
	//Lista.~List();
    cout << "CUATRO" << "\n" << endl; 

	cout << endl;
	cout << "***************************************************************************************" << endl;
	//Lista.~List();
	cin.get();
	return 0;
}
