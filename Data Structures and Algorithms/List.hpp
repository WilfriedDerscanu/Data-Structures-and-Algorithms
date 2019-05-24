#pragma once
#include <iostream>

template<typename DT>
class List
{
public:
	class Iterator
	{
	public:
		Iterator(DT* pData);
		Iterator operator++();
		Iterator operator++(int junk);
		DT& operator*();
		DT* operator->();
		bool operator==(const Iterator& lhs) const;
		bool operator!=(const Iterator& lhs) const;
	private:
		DT* pData;
	};
	class ConstIterator
	{
	public:
		ConstIterator(DT* pData);
		ConstIterator operator++();
		ConstIterator operator++(int junk);
		DT& operator*() const;
		DT* operator->() const;
		bool operator==(const ConstIterator& lhs) const;
		bool operator!=(const ConstIterator& lhs) const;
	private:
		DT* pData;
	};
public:
	List();
	List& operator=(const List& model);
	List(const List& model);
	List& operator=(List&& donor);
	List(List&& donor);
	~List();

	void push_back(DT data);
	void pop_back();

	void add_front(DT data);
	void del_front();

	void erase(DT data, uint64_t pos);
	void insert(DT data, uint64_t pos);

	DT front() const;
	DT back() const;

	uint64_t getSize() const;
	uint64_t getCapacity() const;

	DT& operator[](uint64_t index);
	DT operator[](uint64_t index) const;
	
	Iterator begin();
	Iterator end();
	ConstIterator begin() const;
	ConstIterator end() const;
private:
	bool isEmpty() const;
	bool isFull() const;
	void Resize();
private:
	friend std::ostream& operator<<(std::ostream& out, const List<DT>& lst)
	{
		for (uint64_t i = 0; i < lst.size; i++)
			out << lst[i] << ((i == lst.size - 1) ? "" : " ");
		return out;
	}
private:
	static constexpr uint8_t Start_size = 10;
	static constexpr uint8_t Increment = 5;
	uint64_t size = 0;
	uint64_t incr = Increment;
	uint64_t capacity = Start_size;

	DT* pVect;
};

#pragma region alloc and dealloc stuff
template<typename DT>
List<DT>::List()
	:
	pVect(new DT[capacity])
{
}

template<typename DT>
List<DT>::List(const List & model)
{
	*this = model;

}

template<typename DT>
List<DT>::List(List && donor)
{
	*this = std::move(donor);
}

template<typename DT>
List<DT> & List<DT>::operator=(const List<DT> & model)
{
	capacity = model.capacity;
	size = model.size;
	incr = model.incr;
	if (pVect != nullptr)
		delete[] pVect;
	pVect = new DT[capacity];
	for (uint64_t i = 0; i < size; i++)
	{
		pVect[i] = model.pVect[i];
	}
	return *this;
}

template<typename DT>
List<DT> & List<DT>::operator=(List<DT> && donor)
{
	capacity = model.capacity;
	size = model.size;
	incr = model.incr;
	if (pVect != nullptr)
		delete[] pVect;
	pVect = donor.pVect;
	donor.pVect = nullptr;
	donor.capacity = 0;
	donor.incr = 0;
	donor.size = 0;

	return *this;
}

template<typename DT>
List<DT>::~List()
{
	delete[] pVect;
	pVect = nullptr;
}
#pragma endregion

#pragma region Private Behaviour
template<typename DT>
bool List<DT>::isEmpty() const
{
	return size == 0;
}

template<typename DT>
bool List<DT>::isFull() const
{
	return size == capacity;
}

template<typename DT>
void List<DT>::Resize()
{
	capacity += incr;
	incr += Increment;
	DT *p = new DT[capacity];
	for (uint64_t i = 0; i < size; i++)
	{
		p[i] = pVect[i];
	}
	delete[] pVect;
	pVect = p;
	p = nullptr;
}
#pragma endregion

#pragma region Behaviour
template<typename DT>
void List<DT>::push_back(DT data)
{
	if (isFull())
		Resize();
	pVect[size++] = data;
}

template<typename DT>
void List<DT>::pop_back()
{
	if (!isEmpty())
		size--;
}

template<typename DT>
void List<DT>::add_front(DT data)
{
	if (isFull())
		Resize();
	for (uint64_t i = size; i > 0; i--)
		pVect[i] = pVect[i - 1];

	pVect[0] = data;
	size++;
}

template<typename DT>
void List<DT>::del_front()
{
	for (uint64_t i = 0; i < size - 1; i++)
		pVect[i] = pVect[i + 1];
	size--;
}

template<typename DT>
void List<DT>::erase(DT data, uint64_t pos)
{
	for (uint64_t i = pos; i < size - 1; i++)
		pVect[i] = pVect[i + 1];
	size--;
}

template<typename DT>
void List<DT>::insert(DT data, uint64_t pos)
{
	if (isFull())
		Resize();
	for (uint64_t i = size; i > pos; i--)
		pVect[i] = pVect[i - 1];
	pVect[pos] = data;
	size++;
}

template<typename DT>
DT List<DT>::front() const
{
	return pVect[0];
}

template<typename DT>
DT List<DT>::back() const
{
	return pVect[size - 1];
}
#pragma endregion

#pragma region Getters
template<typename DT>
uint64_t List<DT>::getSize() const
{
	return size;
}

template<typename DT>
uint64_t List<DT>::getCapacity() const
{
	return capacity;
}
#pragma endregion

#pragma region operators
template<typename DT>
DT & List<DT>::operator[](uint64_t index)
{
	return pVect[index];
}

template<typename DT>
DT List<DT>::operator[](uint64_t index) const
{
	return pVect[index];
}
#pragma endregion

#pragma region Iterators
template<typename DT>
typename List<DT>::Iterator List<DT>::begin()
{
	return Iterator(pVect);
}

template<typename DT>
typename List<DT>::Iterator List<DT>::end()
{
	return Iterator(pVect + size);
}

template<typename DT>
typename List<DT>::ConstIterator List<DT>::begin() const
{
	return ConstIterator(pVect);
}

template<typename DT>
typename List<DT>::ConstIterator List<DT>::end() const
{
	return ConstIterator(pVect + size);
}


template<typename DT>
List<DT>::Iterator::Iterator(DT * pData)
	:
	pData(pData)
{
}

template<typename DT>
typename List<DT>::Iterator List<DT>::Iterator::operator++()
{
	Iterator item = *this;
	pData++;
	return item;
}

template<typename DT>
typename List<DT>::Iterator List<DT>::Iterator::operator++(int junk)
{
	pData++;
	return *this;
}

template<typename DT>
DT & List<DT>::Iterator::operator*()
{
	return *pData;
}

template<typename DT>
DT* List<DT>::Iterator::operator->()
{
	return pData;
}

template<typename DT>
bool List<DT>::Iterator::operator==(const Iterator & lhs) const
{
	return pData == lhs.pData;
}

template<typename DT>
bool List<DT>::Iterator::operator!=(const Iterator & lhs) const
{
	return pData != lhs.pData;
}

template<typename DT>
List<DT>::ConstIterator::ConstIterator(DT * pData)
	:
	pData(pData)
{
}

template<typename DT>
typename List<DT>::ConstIterator List<DT>::ConstIterator::operator++()
{
	ConstIterator item = *this;
	pData++;
	return item;
}

template<typename DT>
typename List<DT>::ConstIterator List<DT>::ConstIterator::operator++(int junk)
{
	pData++;
	return *this;
}

template<typename DT>
DT & List<DT>::ConstIterator::operator*() const
{
	return *pData;
}

template<typename DT>
DT* List<DT>::ConstIterator::operator->() const
{
	return pData;
}

template<typename DT>
bool List<DT>::ConstIterator::operator==(const ConstIterator & lhs) const
{
	return pData == lhs.pData;
}

template<typename DT>
bool List<DT>::ConstIterator::operator!=(const ConstIterator & lhs) const
{
	return pData != lhs.pData;
}
#pragma endregion