#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <algorithm>


/*
// Lambda Expression is used to replace functions which have few lines of code.
// There are two types of Lambda Expression -> Stateless, Stateful Lambda Expressions
// Stateless = [] "Empty capture lists".

// This means that the lambda has no knowledge of the integer x defined above and only knows about the
// value that was assigned to its parameter X when it was instantiated and called.

// Quick reminder: passing a parameter by reference is passing the location of that parameter
// So the formal parameter and the function body is an alias to the actual parameter.

// "auto" is usually used with lambda expressions to increase robustness, performance and usability.




// Using lambda expressions as function parameters:
	// #include <functional>

	auto l = [] (auto x) { std::cout<<x<<std::endl; };

                  //Return type, Parameter Type
	              //         |    |
	auto foo( std::function<void(int)> l, auto x ) //C++14
	{
		l(x);
	}


	auto foo( void(*l)(int)  ) //C++14
	{
		l(20);
	}


	void foo (auto l) { //C++20
		l(30.5);
	}



int main(void)
{
	// "auto" is usually used with lambda expressions to increase robustness, performance and usability.


	std::vector<int> test_scores1 {93, 88, 75, 70, 90};
	std::vector<float> test_scores2 {93, 88, 75, 70, 90};

	auto bonus = [] (auto& scores, int bonus_points)
	{
		for(auto &score: scores)
		{
			score += bonus_points;
		}
	};

	bonus(test_scores1, 10); //valid


	return 0;
}
*/






class Person{
	friend std::ostream &operator << (std::ostream &out, const Person& obj);

private:
	std::string name;
	int age;

public:
	Person(std::string Name, int Age) //parameterised constructor
	{
		name = Name;
		age  = Age;
	}

	Person(const Person& cpy) //cpy constructor
	{
		name = cpy.name;
		age = cpy.age;
	}

	~Person(){} //destructor

	//setters & getters:
	std::string get_name() const {return this->name;}
	void        set_name(std::string N) {this -> name = N;}
	int         get_age() const { return this->age; }
	void        set_age(int A) { this->age = A; }

};


std::ostream &operator << (std::ostream &out, const Person& obj)
{
	out<<obj.name<<" : "<<obj.age<<"yo"<<std::endl;

	return out;
}


int main(void)
{

	Person P1("Ahmed",18);

	std::cout<<P1<<std::endl;


	return 0;
}



