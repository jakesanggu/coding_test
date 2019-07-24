#include <iostream>
#include <utility> //pair container
#include <string>


/*Syntax pair(data_type1 , data_type2) Pair_name */


int main(){


	std::pair <std::string, double > p1;

	//초기화
	std::pair <std::string, double > p2("Sanggu", 110.1);
	std::pair <std::string, double > p3(p2);
	std::pair <std::string, double > p4(std::make_pair(std::string("pica"),1.11));

	p1 = std::make_pair(std::string("hihi"),0.10);

	std::cout << "p1 first: " << p1.first << "p1.second: " << p1.second <<std::endl;

	p1.first = std::string("byebye");
	p1.second = 31.1;

	std::cout << "p1-new first: " << p1.first << "p1-new.second: " << p1.second <<std::endl;

	return 0;
}
