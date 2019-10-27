#include <iostream>
#include<deque>
#include<stdio.h>
using namespace std;

template<class Y>
void zbroji(const deque<Y> &a, const deque<Y> &b, deque<Y> &rez)
{
    int ost=0;
    long int size=(a.size()>b.size())? a.size():b.size();
    
    for(long int i=0;i<size;i++)
    {
        rez.push_front(((a.size()>i)? (a[i]-'0'):0)+((b.size()>i)? (b[i]-'0'):0)+ost);
        
        if(rez.front()>9)
        {
            rez.front()-=10;
            ost=1;
        }
        else    ost=0;
    }
    if(ost) rez.push_front(1);
}

template<class Y>
void oduzmi(const deque<Y> &a, const deque<Y> &b, deque<Y> &rez)
{
    long int size=(a.size()>=b.size())?  a.size():b.size();
    int ost=0;
    bool flag=false;
    
    if(a.size()<b.size())   flag=true;
    else if(a.size()==b.size())
        for(long int i=size-1;i>=0;i--)
            if(a[i]<b[i])
            {
                flag=true;
                break;
            }
            else if(a[i]>b[i])
            {
                flag=false;
                break;
            }
            
    if(size==a.size() && flag==false)
        for(long int i=0;i<size;i++)
        {
            rez.push_front(((a.size()>i)? (a[i]-'0'):0)-((b.size()>i)? (b[i]-'0'):0)-ost);
            if(rez.front()<0)
            {
                rez.front()+=10;
                ost=1;
            }
            else ost=0;
        }
    else
        for(long int i=0;i<size;i++)
        {
            rez.push_front(((b.size()>i)? (b[i]-'0'):0)-((a.size()>i)? (a[i]-'0'):0)-ost);
            if(rez.front()<0)
            {
                rez.front()+=10;
                ost=1;
            }
                else ost=0;
        }
    while(!rez.front() && rez.size()>1) rez.pop_front();
    if(flag)    rez.front()=-rez.front();
}

template<class Y>
void mnoz(deque<Y> &a, deque<Y> &b, deque<Y> &rez)
{
    for(long int i=0;i<(a.size()+b.size());i++)  
	{
		rez.push_front(0);
		if(a.size()<i)	a[i]-='0';
		if(b.size()<i)	b[i]-='0';
	}
    
    for(long int i=0;i<a.size();i++)
        for(long int j=0;j<b.size();j++)
            rez[(a.size()-i-1)+(b.size()-j-1)+1]+=a[i]*b[j];
            
    for(long int i=rez.size()-1;i>=0;i--)
        if(rez[i]>9)
        {
            rez[i-1]+=rez[i]/10;
            rez[i]%=10;
        }
        
    while(!rez.front() && rez.size()>1) rez.pop_front();
}