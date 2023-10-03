#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <cctype>
#include <algorithm>


class Person{
private:
	std::string name;
	int age;
public:
	Person() = default;

	Person(std::string Name, int Age)
	{
		name = Name;
		age = Age;
	}

	bool operator < (const Person& obj)
	{
		return (this->age < obj.age);
	}

	bool operator == (const Person& obj)
	{
		return ( (this->name == obj.name)&&(this->age == obj.age) );
	}

	friend std::ostream& operator << (std::ostream& os, const Person& obj)
	{
		os<<obj.name<<" "<<obj.age<<std::endl;
		return os;
	}

	~Person(){}

};




void find_test(void)
{

	std::vector<int> vec{1,2,31,4,5};
                 //The element we want to find = 31.
	auto loc = std::find(vec.begin(), vec.end(), 31);

	if(loc != vec.end()){
		std::cout<<"The element was found = "<<*loc<<std::endl;
	} else {
		std::cout<<"Element couldn't be found!"<<std::endl;
	}

	std::cout<<std::endl;

	std::list<Person> players{
		{"Larry",18},
		{"Harry",20},
		{"Potter",21},
	};

	auto loc1 = std::find(players.begin(), players.end(), Person{"Larry",18});
	// Note that the stl algorithm will use the operator "==" to find the required player

	if(loc1 != players.end()){
			std::cout<<"The player was found = "<<*loc1<<std::endl;
		} else {
			std::cout<<"Player couldn't be found!"<<std::endl;
		}


}


void count_test(void)
{
	std::vector<int> vec{1,2,3,4,1,6,1,7,8,1};
    //auto will always be int type
	auto num = std::count(vec.begin(), vec.end(), 1);
	std::cout<<"The number was repeated "<<num<<" times"<<std::endl;
}


void count_if_test(void)
{
	std::vector<int> vec{1,2,3,4,5,1,2,1,100};

	int num = std::count_if(vec.begin(), vec.end(), [](int x){return x%2 == 0;});
	std::cout<<"There are "<<num<<" even elements in that vector"<<std::endl;

	num = std::count_if(vec.begin(), vec.end(), [](int x){return x%2 != 0;});
	std::cout<<"There are "<<num<<" odd  elements in that vector"<<std::endl;
}


void replace_test(void)
{
	std::vector<int> vec {1,2,3,4,5,1,2};

	for(auto i : vec)
	{
		std::cout<<i<<" ";
	}
	std::cout<<std::endl;

	std::replace(vec.begin(), vec.end(), 1,100);
	for(auto i : vec)
	{
		std::cout<<i<<" ";
	}
	std::cout<<std::endl;

}


void all_of_test(void)
{
	std::vector<int> vec{11,12,13,14,28,56,89,99,69,87};

	if( std::all_of(vec.begin(), vec.end(), [](int x){ return x>10; }) )
	{
		printf("All elements are greater than 10");
	}
}


void transform_test(void) // transform algorithm is used mostly with strings
{
	std::string str1 = "This is a test";
	std::cout<<"String before transformation: "<<str1<<std::endl;
	std::transform(str1.begin(), str1.end(), str1.begin(), ::toupper); //transfrom to upper case, ::-> global scope
	//note that "toupper" can be changed with any other function we can make.
	std::cout<<"String after  transformation: "<<str1<<std::endl;
}




int main(void)
{
	// find_test();
	// count_test();
	// count_if_test();
	// replace_test();
	// all_of_test();
	// transform_test();

	return 0;
}






