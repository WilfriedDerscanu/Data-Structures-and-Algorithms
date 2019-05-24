#pragma once
#include <exception>

template<typename T>
class Queue
{
private:
	struct Node
	{
		Node(T data, Node* next)
			:
			data(data),
			next(next)
		{}

		~Node()
		{
			if (next != nullptr)
			{
				delete next;
				next = nullptr;
			}
		}

		T data;
		Node* next;
	};
public:
	void Enque(T data)
	{
		if (tail == nullptr)
		{
			tail = head = new Node(data, nullptr);
		}
		else
		{
			tail->next = new Node(data, nullptr);
			tail = tail->next;
		}
	}
	T Deque()
	{
		if (isEmpty())
			throw std::exception();
		else
		{
			Node* temp = head;
			head = head->next;
			temp->next = nullptr;
			T data = temp->data;
			delete temp;
			return data;
		}
	}
	bool isEmpty() const
	{
		return head == nullptr;
	}
	~Queue()
	{
		delete head;
		head = nullptr;
	}
private:
	Node* head = nullptr;
	Node* tail = nullptr;

};
