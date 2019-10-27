#include <iostream>
#include <cstdlib>
using namespace std;

template<class T>
class node
{
	public:
		T value;
		node<T>* _prev;
		node<T>* _next;

		node(){}
		node(T val, node<T>* prev, node<T>* next){value=val; prev=_prev; next=_next;}

		T key() const {return value;}
		node<T>* next() {return _next; }
		node<T>* prev() {return _prev; }
};

template<class T>
class list
{
	public:
		node<T> *head;
		node<T> *tail;
		
		list(){head=NULL; tail=NULL;}
		list(const list&);

		node<T>* front(); 
		node<T>* back();
		void print(); 

		void push_front(node<T> x);
		node<T>* pop_front(); 
		void push_back(node<T> x);
		node<T>* pop_back(); 

		void insert(node<T>* prev, node<T>* x); 
		void erase(node<T>* x);
		void clear(); 
		node<T>* search(node<T>* x);

		void sort(); 
		void reverse();
		
		~list();
};

template<class T>
node<T>* list<T>::front()
{
	node<T> *n=head;
	
	while((n->_prev)!=NULL)
	{
		n=head->_prev;
	}
	return n;
}

template<class T>
node<T>* list<T>::back()
{
	node<T> *n=tail;
	
	while((n->_next)!=NULL)
	{
		n=head->_next;
	}
	return n;
}

template<class T>
void list<T>::print()
{
	node<T> *temp=head;
		
	while(temp!=NULL)
	{
		cout << temp->value << " ---- ";
		temp=temp->_next;
	}
	cout<<" NULL"<<endl;
}

template<class T>
node<T>* list<T>::pop_front()
{
	node<T>* n=front();
	head=head->_next;
	head->_prev=NULL;
	delete n;
	return head;
}

template<class T>
node<T>* list<T>::pop_back()
{
	node<T>* n=back();
	tail=tail->_prev;
	tail->_next=NULL;
	delete n;
	return tail;
}

template<class T>
void list<T>::push_front(node<T> x)
{
	node<T>* n=new node<T>(x.key(),x.prev(),x.next());
	
	if(head==NULL)
	{
		head=n;
		tail=n;
		tail->_next=NULL;
	}
	else
	{
		head->_prev=n;
		n->_next=head;
		n->_prev=NULL;
		head=n;
	}
}

template<class T>
void list<T>::push_back(node<T> x)
{
	node<T>* n=new node<T>(x.key(),x.prev(),x.next());
	
	if(tail==NULL)
	{
		head=n;
		head->_prev=NULL;
		tail=n;
	}
	else
	{
		tail->_next=n;
		n->_prev=tail;
		n->_next=NULL;
		tail=n;
	}
}

template<class T>
void list<T>::insert(node<T>* prev, node<T>* x)
{
	node<T>* temp=search(prev);
	
	x->_next=temp->_next;
	(temp->_next)->_prev=x;
	temp->_next=x;
	x->_prev=temp;
}

template<class T>
node<T>* list<T>::search(node<T>* x)
{
	head=front();
	node<T>* i;
	
	for(i=head;i!=NULL;i=i->_next)
		if(i->value == x->value)
			break;
			
	return i;
}

template<class T>
void list<T>::erase(node<T>* x)
{
	node<T>* temp=search(x);
    
    if(temp->_next==NULL)
		(temp->_prev)->_next=NULL;
    else if(temp->_prev==NULL)   
        (temp->_next)->_prev=NULL;
    else
    {     
		(temp->_prev)->_next=temp->_next;
		(temp->_next)->_prev=temp->_prev;
    }
	delete temp;
}

template<class T>
void list<T>::clear()
{
	head=front();
	
	while((head->_next)!=NULL)
	{
		node<T>* temp=head;
		delete	head;
		head=temp->_next;
	}
	head=tail=NULL;
}

template<class T>
void list<T>::sort()
{
	head=front();
	node<T> *i,*j;
	T temp;
	
	for(i=head;i!=NULL;i=i->_next)
		for(j=i;j!=NULL;j=j->_next)
			if(i->value > j->value)
			{
				temp=i->value;
				i->value=j->value;
				j->value=temp;
			}
}

template<class T>
void list<T>::reverse()
{
	head=front();
	node<T> *prvi, *drugi;
	
	prvi=head;
	drugi=prvi->_next;
	prvi->_next=NULL;
	prvi->_prev=drugi;
	
	while(drugi!=NULL)
	{
		drugi->_prev=drugi->_next;
		drugi->_next=prvi;
		prvi=drugi;
		drugi=drugi->_prev;
	}
	
	head=prvi;
}

template<class T>
list<T>::~list()
{
	node<T> *curr=head;
	
	while(curr!=NULL)
	{
		node<T>* temp=curr;
		curr=temp->_next;
		delete temp;
	}
	
	head=NULL;
	tail=NULL;
}

template<class T>
list<T>::list(const list &l)
{
	head=l.head;
	tail=l.tail;
}