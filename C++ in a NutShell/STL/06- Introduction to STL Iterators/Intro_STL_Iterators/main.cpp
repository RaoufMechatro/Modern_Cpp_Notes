#include <iostream>
#include <vector>



// Declaring iterators:
// Iterators must be declared based on the container type they will iterate over
// Ex:
// std::vector<int>::iterator it1;

//initializing iterators:
// std::vector<int> vec {1,2,3}
// std::vector<int>::iterator it= vec.begin();
//or
// auto it = vec.begin();


int main(void)
{
	std::vector<int> vec{1, 2, 3};

	auto it = vec.begin();

	while(it != vec.end())
	{
		std::cout<<*it<<std::endl; //iterator is being treated as pointer in syntax only
		++it;
	}

	//Or:

	for( it = vec.begin(); it != vec.end(); ++it)
	{
		std::cout<<*it<<std::endl;
	}

	std::cout<<std::endl;

	//There is also a reverse iterator:
	//std::vector<int>::reverse_iterator revit;

	std::vector<int>::reverse_iterator revit = vec.rbegin();

	while( revit != vec.rend() )
	{
		std::cout<<*revit<<std::endl; //iterator is being treated as pointer
		++revit;
	}

	//Note:
	// iterators : vec.begin(), vec.end()
	// constant iterators : vec.cbegin(), vec.cend()
	// reverse iterators : vec.rbegin(), vec.rend()
	// constant reverse iterators : vec.crbegin(), vec.crend()


	return 0;
}


