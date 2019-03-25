#pragma once
#include <iostream>

//DT - data type
template<typename DT>
class List
{
public:
	List();

	void push_back(DT data)
	void pop_back();

	void add_front(DT data);
	void del_front();

	void erase(T data, uint64_t pos);
	void insert(T data, uint64_t pos)

	DT front() const;
	DT back() const;

	uint64_t getSize() const;
	uint64_t getCapacity() const;

	T& operator[](uint64_t index);
	T operator[](uint64_t index) const
	
	~List();
private:
	bool isEmpty() const;
	bool isFull() const;
	void Resize();
private:
	friend std::ostream& operator<<(std::ostream& out, const List<T>& lst);
private:
	static constexpr uint8_t Start_size = 10;
	static constexpr uint8_t Increment = 5;
	uint64_t size = 0;
	uint64_t incr = Increment;
	uint64_t capacity = Start_size;

	DT* pVect;
};
