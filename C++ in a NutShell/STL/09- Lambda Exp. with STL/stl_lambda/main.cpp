#include <iostream>
#include <vector>
#include <map>
#include <algorithm>



void test1(void)
{
	std::vector<int> nums{10,20,30,40,50};

	std::for_each(nums.begin(), nums.end(), [](auto x){ std::cout<<x<<" "; });
	std::cout<<std::endl;
}



void test2(void)
{
	std::vector<int> nums{10,20,30,40,50};

	int modifier{5};

	std::transform(nums.begin(), nums.end(), nums.begin(), [modifier](auto x){ return x + modifier; });

	for(auto n:nums)
	{
		std::cout<<n<<" ";
	}
	std::cout<<std::endl;
}









int main(void)
{

	test1();

	test2();


	return 0;
}



