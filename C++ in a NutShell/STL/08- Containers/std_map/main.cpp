#include <iostream>
#include <algorithm>
#include <string>
#include <map>



// std::map:
// - Similar to dictionary.
// - Elements are stores as Key,Value pairs (std::pair).
// - Ordered by key.
// - No duplicated elements.
// - Direct element access using the key.
// - All iterators are available a nd invalidate when the corresponding element is deleted.



class Person{
private:
    int age;
    std::string name;

public:
    Person() = default;

    Person(std::string Name, int Age)
    {
        name = Name;
         age = Age;
    }

    friend std::ostream& operator << (std::ostream& os, const Person& obj)
    {
        os<<obj.name<<" is "<<obj.age<<" years old"<<std::endl;
        return os;
    }

    void operator = (const Person& obj)
    {
    	 age = obj.age;
    	name = obj.name;
    }

    bool operator < (const Person& obj) const
    {
         return( (this->age < obj.age)&&(this->name < obj.name) );
    }

    bool operator > (const Person& obj) const
    {
         return( (this->age > obj.age)&&(this->name > obj.name) );
    }


    bool operator == (const Person& obj) const
    {
         return( (this->age == obj.age)&&(this->name == obj.name) );
    }


    ~Person() {}

};





int main(void)
{
	Person P1{"Raouf",25}, P2{"Maghraby",26}, P3{"Mario",27}, P4{"Negm",28};

	std::map<std::string, Person> Players{
		{"Player1",P1},
		{"Player2",P2},
		{"Player3",P3},
		{"Player4",P4}
	};

	std::for_each(Players.begin(), Players.end(), [](auto x){std::cout<<x.second<<"  ";});
	std::cout<<std::endl;
	//Note that x.second means that we want to cout the value in that map.

	Players["Player5"] = Person{"Ramy",30};

	std::for_each(Players.begin(), Players.end(), [](auto x){std::cout<<x.second<<"  ";});
	std::cout<<std::endl;

	Players.at("Player3") = Person{"Islam",22}; //update value

	std::for_each(Players.begin(), Players.end(), [](auto x){std::cout<<x.second<<"  ";});
	std::cout<<std::endl;

	//Note that elements are updated according to their KEY


	auto it = Players.find("Player4");
	if(it != Players.end())
	{
		std::cout<<"===> "<<it->second<<std::endl;
		//Note that it->second means that we want to cout the value in that map.
	}


	return 0;
}





