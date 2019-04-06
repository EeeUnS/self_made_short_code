#ifndef VECTOR__H
#define VECTOR__H

template<typename T>
struct Node
{
	Node* pre;
	T item;
	Node* next;
};

template<typename T>
class stack
{
public:
	stack(const stack<T> &b); //iterator�ʿ� �̱���
	stack();
	stack(const T &item);
	~stack();
	void push(const T &item);
	void pop();
	int size();
	bool empty();
	T top();
private:
	size_t size_type;
	Node<T>* end;
public:
	void swap(stack<T>& b);
	bool operator== (const stack<T>& rhs); //iterator�ʿ� �̱���
	bool operator!= (const stack<T>& rhs);//iterator�ʿ� �̱���
	bool operator< (const stack<T>& rhs);
	bool operator<= (const stack<T>& rhs);
	bool operator> (const stack<T>& rhs);
	bool operator>= (const stack<T>& rhs);

};

//
//
//template <class T, class Container>
//bool operator== (const stack<T, Container>& lhs, const stack<T, Container>& rhs);
//
//template <class T, class Container>
//bool operator!= (const stack<T, Container>& lhs, const stack<T, Container>& rhs);
//
//template <class T, class Container>
//bool operator<  (const stack<T, Container>& lhs, const stack<T, Container>& rhs);
//
//template <class T, class Container>
//bool operator<= (const stack<T, Container>& lhs, const stack<T, Container>& rhs);
//
//template <class T, class Container>
//bool operator>  (const stack<T, Container>& lhs, const stack<T, Container>& rhs);
//
//template <class T, class Container>
//bool operator>= (const stack<T, Container>& lhs, const stack<T, Container>& rhs);


#endif // !1