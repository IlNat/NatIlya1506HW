#include <iostream>
#include <string.h>
#include <time.h>
#include "Windows.h"
using namespace std;

class Stack
{
	enum { EMPTY = -1, FULL = 20 }; // Нижняя и верхняя границы стека.
	char st[FULL + 1]; // Массив элементов стека.
	int top; // Индекс определяющий вершину стека.
public:

	// Конструктор.
	Stack();

	// Добавление элемента.
	void Push(char c);

	// Извлечение элемента.
	char Pop();

	// Проверка на отсутствие элементов в стеке.
	bool IsEmpty();

	// Проверка на переполнение стека.
	bool IsFull();

	// Количество элементов в стеке.
	int GetCount();
};

// Конструктор стека. Изначально стек пуст.
Stack::Stack()
{
	top = EMPTY;
}

// Проверка на отсутствие элементов в стеке.
bool Stack::IsEmpty()
{
	return top == EMPTY;
}

// Проверка на переполнение стека.
bool Stack::IsFull()
{
	return top == FULL;
}

// Возвращает количество присутствующих в стеке элементов.
int Stack::GetCount()
{
	return top + 1;
}

// Пока в стеке есть место увеличивает указатель на вершину и вставляет элемент. Иначе выводит сообщение.
void Stack::Push(char c)
{
	if (!IsFull())
	{
		st[++top] = c;
	}
	else
		cout << "Стек переполнен.\n";
}

// Возвращает верхний элемент и уменьшает указатель на вершину стека(если в стеке элементов нет, возвращает "0").
char Stack::Pop()
{
	if (!IsEmpty())
		return st[top--];
	else 
		return 0;
}


void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));

	Stack ST;
	int c;
	// Заполнение стека до конца.
	while (!ST.IsFull()) {
		c = rand() % 100;
		ST.Push(c);
	}

	// Пока стек не освободится.
	while (c = ST.Pop()) {
		cout << c << '\t' << ST.GetCount() << '\n';
	}
}
