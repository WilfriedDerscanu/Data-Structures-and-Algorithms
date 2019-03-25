#pragma once
#include <iostream>

//DT - data type
template<typename DT>
class List
{
public:
	List();

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
	
	~List();
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

template<typename DT>
inline List<DT>::List()
	:
	pVect(new DT[capacity])
{
}

template<typename DT>
inline void List<DT>::push_back(DT data)
{
	if (isFull())
		Resize();
	pVect[size++] = data;
}

template<typename DT>
inline void List<DT>::pop_back()
{
	if (!isEmpty())
		size--;
}

template<typename DT>
inline void List<DT>::add_front(DT data)
{
	if (isFull())
		Resize();
	for (uint64_t i = size; i > 0; i--)
		pVect[i] = pVect[i - 1];

	pVect[0] = data;
	size++;
}

template<typename DT>
inline void List<DT>::del_front()
{
	for (uint64_t i = 0; i < size - 1; i++)
		pVect[i] = pVect[i + 1];
	size--;
}

template<typename DT>
inline void List<DT>::erase(DT data, uint64_t pos)
{
	for (uint64_t i = pos; i < size - 1; i++)
		pVect[i] = pVect[i + 1];
	size--;
}

template<typename DT>
inline void List<DT>::insert(DT data, uint64_t pos)
{
	if (isFull())
		Resize();
	for (uint64_t i = size; i > pos; i--)
		pVect[i] = pVect[i - 1];
	pVect[pos] = data;
	size++;
}

template<typename DT>
inline DT List<DT>::front() const
{
	if (isEmpty())
		throw std::out_of_range("no element in the list");
	return pVect[0];
}

template<typename DT>
inline DT List<DT>::back() const
{
	if (isEmpty())
		throw std::out_of_range("no element in the list");
	return pVect[size - 1];
}

template<typename DT>
inline uint64_t List<DT>::getSize() const
{
	return size;
}

template<typename DT>
inline uint64_t List<DT>::getCapacity() const
{
	return capacity;
}

template<typename DT>
inline DT & List<DT>::operator[](uint64_t index)
{
	return pVect[index];
}

template<typename DT>
inline DT List<DT>::operator[](uint64_t index) const
{
	return pVect[index];
}

template<typename DT>
inline List<DT>::~List()
{
	delete[] pVect;
	pVect = nullptr;
}

template<typename DT>
inline bool List<DT>::isEmpty() const
{
	return size == 0;
}

template<typename DT>
inline bool List<DT>::isFull() const
{
	return size == capacity;
}

template<typename DT>
inline void List<DT>::Resize()
{
	capacity += incr;
	incr += Increment;
	T *p = new T[capacity];
	for (uint64_t i = 0; i < size; i++)
	{
		p[i] = pVect[i];
	}
	delete[] pVect;
	pVect = p;
	p = nullptr;
}
