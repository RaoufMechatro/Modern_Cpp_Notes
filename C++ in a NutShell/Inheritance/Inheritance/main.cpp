#include <iostream>




class Counter  /* Base Class */
{
protected:
	uint32_t count;
public:
	Counter() : count(0)
	{ }

	Counter(int c) : count(c)
	{ }

	uint32_t getCount() const
	{
		return count;
	}

	Counter operator ++ ()
	{
		return Counter(++count);
	}
};



class CountDn : public Counter  /* Derived Class */
{
	/*
	 *  Note:
	 * 		CountDn class inherits all the features of the Counter class.
	 *		CountDn doesn’t need a constructor or the get_count() or operator++() functions, because
	 *		these already exist in Counter.
	 *
	 */

public:
	Counter operator -- ()
	{
		return Counter(--count);
		/*
		 * member functions can access members of the base class if the members are public,
		 * or if they are protected. They can’t access private members.
		 *
		 */
	}

	CountDn() : Counter(0)
	{

	}

	CountDn(int a) : Counter(a)
	{

	}
};



int main(void)
{

	CountDn c1; //c1 of class CountDn
	CountDn c2(100);

	/*
	 *
	 *  There is no constructor in the CountDn class specifier, so what entity carries
	 * 	out the initialization? It turns out that—at least under certain circumstances—if you don’t specify
	 *	a constructor, the derived class will use an appropriate constructor from the base class
	 *
	 */

	std::cout << "\nc1=" << c1.getCount()<<std::endl; //display c1

	++c1;
	++c1;
	++c1; //increment c1, 3 times

	++c2;

	std::cout<<"\nc2="<<c2.getCount() <<std::endl; //display c2

	/*
	 *  The object c1 of the CountDn class also uses the operator++() and get_count() functions
	 *	from the Counter class. The first is used to increment c1.
	 */

	std::cout << "\nc1=" << c1.getCount(); //display it

	--c1; --c1; //decrement c1, twice
	std::cout << "\nc1=" << c1.getCount(); //display it

	std::cout << std::endl;


	return 0;
}






