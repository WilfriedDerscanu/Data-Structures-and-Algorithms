#pragma once
#include <exception>

template<typename T>
class Stack
{
private:
	struct Node
	{
		Node(T data, Node* next)
			:
			data(data),
			next(next)
		{
		}
		T data;
		Node* next;
		~Node()
		{
			if (next != nullptr)
			{
				delete next;
				next = nullptr;
			}
		}
	};
public:
	void Push(T data)
	{
		if (isEmpty())
		{
			top = new Node(data, nullptr);
		}
		else
		{
			Node* newNode = new Node(data, top);
			top = newNode;
		}
	}

	T Pop()
	{
		if (isEmpty())
			throw(std::exception("Out of range"));
		else
		{
			Node* temp = top;
			T data = top->data;
			top = top->next;
			temp->next = nullptr;
			delete temp;
			return data;
		}
	}
	bool isEmpty()
	{
		return top == nullptr;
	}
	~Stack()
	{
		delete top;
		top = nullptr;
	}
private:
	Node* top = nullptr;
};