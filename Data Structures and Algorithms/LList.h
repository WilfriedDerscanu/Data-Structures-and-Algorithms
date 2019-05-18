#pragma once
#include <exception>

template <typename T>
class LList
{
private:
	struct Node
	{
		Node(T data,Node* next = nullptr)
			:
			next(next),
			data(data)
		{
		}
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
	LList() = default;
	void PushLast(T data)
	{
		if (isEmpty())
		{
			first = last = new Node(data);
		}
		else
		{
			last->next = new Node(data);
		}
	}
	void PushFirst(T data)
	{
		if (isEmpty())
		{
			first = last = new Node(data);
		}
		else
		{
			first = new Node(data, first);
		}
	}

	T PopLast()
	{
		Node* index = first;
		if (isEmpty())
			throw(std::exception());
		else
		{
			if (index->next != nullptr)
			{
				while (index->next->next != nullptr)
				{
					index = index->next;
				}
				T data = index->next->data;
				last = index;
				delete index->next;
				index->next = nullptr;
				return data;
			}
			else
			{
				T data = last->data;
				delete last;
				last = first = nullptr;
				return data;
			}
		}
			
	}

	T PopFirst()
	{
		Node* temp = first;
		first = first->next;
		temp->next = nullptr;
		T data = temp->data;
		delete temp;
		return data;
	}

	T GetAt(unsigned pos) const
	{
		Node* index = first;
		for (int i = 0; i < pos; i++)
		{
			index = index->next;
			if (index == nullptr)
				throw(std::exception());
		}
		return index->data;
	}

	void SetAt(unsigned pos, T data)
	{
		Node* index = first;
		for (int i = 0; i < pos; i++)
		{
			index = index->next;
			if (index == nullptr)
				throw(std::exception());
		}
		index->data = data;
	}

	bool isEmpty() const
	{
		return first == nullptr;
	}

	~LList()
	{
		if (first != nullptr)
		{
			delete first;
			first = nullptr;
			last = nullptr;
		}
			
	}
private:
	Node* first = nullptr;
	Node* last = nullptr;
};