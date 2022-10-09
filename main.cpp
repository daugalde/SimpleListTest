#include <iostream>
#include <string>
using namespace std; 

class Node {

private:
	int value = 0;
	string val = "";
	Node* NextNode;

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
	Node(string v)
	{
		this->val = v;
		NextNode = NULL;
	}

	Node(string v, Node* newNextNode)
	{
		this->val = v;
		NextNode = newNextNode;
	}
	friend class List;

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
	void unshift(string v); // Insert at Beginning
	void push(string v); // Insert at End
	void unshift(int v); // Insert at Beginning
	void push(int v); // Insert at End
	void splice(int v, int pos); // Insert at Index Position
	bool isEmpty() { return head == NULL; }
	void display();
	void displayVal();
	void next();
	void first();
	void last();
	Node* pop();
	void shift();
	void removeAtIndex(int pos);
	int length();
	bool searchElement(int element);
	List* splitNumbers(int number);
	int readElementByIndex(int index);

	friend class Test;
};

List* List::splitNumbers(int num)
{
	List* result = new List();
	if (num > 0)
	{
		while (num != 0)
		{
			int temp = num % 10;
			result->unshift(temp);
			num = num / 10;
		}
	}
	return result;
}

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

void List::unshift(string v)
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

void List::push(string v)
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

void List::displayVal()
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
				cout << aux->val;
			}
			else {
				cout << aux->val << ", ";
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

int List::readElementByIndex(int index)
{
	Node* aux;
	if (head == NULL) {
		return -1;
	}
	else
	{
		int count = 0;
		aux = head;
		while (aux)
		{
			if (count == index)
			{
				return aux->value;
			}
			count++;
			aux = aux->NextNode;
		}
	}
}

class Test {
private:

public:
	Test(){ }
	void UNO(List* LBuscar, List* LTrabajo);
	void DOS(int num1, int num2);
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
void Test::DOS(int num1, int num2)
{
	if (num1 <= 0 || num2 <= 0)
	{
		cout << "Ambos Numeros tienen que ser positivos" << endl;
		return;
	}

	List* numL1 = (new List())->splitNumbers(num1);

	List* numL2 = (new List())->splitNumbers(num2);

	if (numL1->length() % 2 == 0 || numL2->length() % 2 == 0)
	{
		cout << "Ambos Numeros no son impares y no son validos" << endl;
		return;
	}

	if (numL1->length() != numL2->length())
	{
		cout << "Ambos Numeros no son del mismo largo y no son validos" << endl;
		return;
	}

	if (numL1->length() < 2 || numL2->length() < 2)
	{
		cout << "Algun numero es menos de 3 digitos y no son validos" << endl;
		return;
	}

	List* output = new List();

	int cont = 0;

	bool isListTwo = true;

	int length = (numL1->length() - 1);
	
	int centerIndexL1 = (numL1->length() / 2) ;

	int centerIndexL2 = (numL2->length() / 2);

	int leftIndex = centerIndexL1 - 1;

	int rightIndex = centerIndexL1 + 1;

	bool isSecondList = true;
	
	while (cont < length) {
		if (isSecondList)
		{
			output->push(to_string(numL2->readElementByIndex(centerIndexL2)) + " + " +
				to_string(numL1->readElementByIndex(leftIndex)) + " - " +
				to_string(numL1->readElementByIndex(rightIndex)) + ", " +
				to_string(numL2->readElementByIndex(centerIndexL2)) + " + " +
				to_string(numL1->readElementByIndex(rightIndex)) + " - " +
				to_string(numL1->readElementByIndex(leftIndex))
			);
			isSecondList = false;
		}
		else {
			output->push(to_string(numL1->readElementByIndex(centerIndexL1)) + " + " +
				to_string(numL2->readElementByIndex(rightIndex)) + " - " +
				to_string(numL2->readElementByIndex(leftIndex)) + ", " +
				to_string(numL1->readElementByIndex(centerIndexL2)) + " + " +
				to_string(numL2->readElementByIndex(leftIndex)) + " - " +
				to_string(numL2->readElementByIndex(rightIndex))
			);
			isSecondList = true;
			leftIndex--;
			rightIndex++;
		}
		cont++;
	}

	output->displayVal();

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
	cout << "DOS" << "\n" << endl;
	test.DOS(65234, 89107);
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
