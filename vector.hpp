#include <iostream>
using namespace std;

template<class T>
class vector
{
	public:
		size_t curr_len, cap_p;
		T *p;
	
		vector(){p=NULL; cap_p=1; curr_len=0;};
		vector(size_t size);
		size_t size() const;
		size_t capacity() const;
	
		void push_back(T x);
		T pop_back();
		void resize_to_fit();
		void clear();
		void print();
		
		vector& operator = (const vector&);
		vector operator + (const vector&) const;
		vector operator - (const vector&) const;
		vector operator * (float lambda) const;
		vector operator += (const vector&);
		vector operator -=  (const vector&);
		vector operator *= (float lambda);
		bool operator ==  (const vector&) const;
		bool operator != (const vector&) const;
		T& operator [] (int) const;
		
		~vector(){delete[] p;}
};


template<class T>
vector<T>::vector(size_t size)
{
	curr_len=0;
	
	for(cap_p=1;cap_p<=size;cap_p*=2);
	p=new T[cap_p];
}

template<class T>
size_t vector<T>::size() const
{
	return curr_len;
}

template<class T>
size_t vector<T>::capacity() const
{
	return cap_p;
}

template<class T>
void vector<T>::push_back(T x)
{
	if((curr_len+1)==cap_p)
	{
		cap_p*=2;

		T *n_p=new T[cap_p];
		for(int i=0;i<curr_len;i++)
			n_p[i]=p[i];
		delete[] p;
		p=n_p;
	}
	p[curr_len++]=x;
}

template<class T>
T vector<T>::pop_back()
{
	if((curr_len-1)==(cap_p/2))
    {
		cap_p/=2;
        
    	T *n_p=new T[cap_p];
		for(int i=0;i<cap_p;i++)
			n_p[i]=p[i];
		delete[] p;
		p=n_p;
	}
	return p[curr_len--];
}

template<class T>
void vector<T>::resize_to_fit()
{
	cap_p=curr_len;
    T *n_p=new T[cap_p];
	for(int i=0;i<cap_p;i++)
		n_p[i]=p[i];
	delete[] p;
	p=n_p;
}

template<class T>
void vector<T>::clear()
{
	cap_p=1;
    T *n_p=new T[cap_p];
	n_p[0]=0;
	delete[] p;
	p=n_p;
	curr_len=0;		
}

template<class T>
vector<T>& vector<T>::operator = (const vector &v)
{
	if(p!=NULL)
	{
		delete[] p;
		cap_p=1;
		curr_len=0;
	}
	
	p=new T[v.cap_p];
	cap_p=v.cap_p;
	curr_len=v.curr_len;
	for(int i=0;i<curr_len;i++)
		p[i]=v.p[i];
	return this;
}

template<class T>
vector<T> vector<T>::operator + (const vector &v) const
{
	vector temp(cap_p);
	temp.curr_len=curr_len;
	
	if(curr_len==v.curr_len)
	{
		for(int i=0;i<curr_len;i++)
			temp.p[i]=p[i]+v.p[i];
	}
	else
		cout<<"razlicite su duljine"<<endl;
	return temp;
}

template<class T>
vector<T> vector<T>::operator - (const vector &v) const
{
	vector temp(cap_p);
	temp.curr_len=curr_len;
	
	if(curr_len==v.curr_len)
	{
		for(int i=0;i<curr_len;i++)
			temp.p[i]=p[i]-v.p[i];
	}
	else
		cout<<"razlicite su duljine"<<endl;
	return temp;
}

template<class T>
vector<T> vector<T>::operator * (float lambda) const
{
	vector temp(cap_p);
	temp.curr_len=curr_len;
	
	for(int i=0;i<curr_len;i++)
		temp.p[i]=p[i]*lambda;
	return temp;
}

template<class T>
vector<T> vector<T>::operator += (const vector &v)
{
	for(int i=0;i<curr_len;i++)
		p[i]=p[i]+v.p[i];
	return *this;
}

template<class T>
vector<T> vector<T>::operator -= (const vector &v)
{
	for(int i=0;i<curr_len;i++)
		p[i]=p[i]-v.p[i];
	return *this;
}

template<class T>
bool vector<T>::operator == (const vector &v) const
{
	if(curr_len!=v.curr_len)
		return false;
		
	for(int i=0;i<curr_len;i++)
		if(p[i]!=v.p[i])
		return false;
	return true;
}

template<class T>
bool vector<T>::operator != (const vector &v) const
{
	if(curr_len!=v.curr_len)
		return true;
		
	for(int i=0;i<curr_len;i++)
		if(p[i]==v.p[i])
		return false;
	return true;
}
template<class T>
T& vector<T>:: operator [] (int dex) const
{
	return p[dex];
}

template<class T>
vector<T> vector<T>::operator *= (float lambda)
{
	for(int i=0;i<curr_len;i++)
		p[i]=p[i]*lambda;
	return *this;
}

template<class T>
void vector<T>::print()
{
	for(int i=0;i<curr_len;i++)
		cout << p[i] << "\t";
	cout << endl;
}