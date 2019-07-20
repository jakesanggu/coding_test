#include <iostream>
#include <vector>
#include <string>

int main(void){

/* 다양한 종류의 벡터 선언 */

	std::vector<std::string> str_arr;
	std::vector<int>	 int_arr;
	std::vector< std::pair< int,int> > int_2_arr;
	std::vector< std::pair<std::string,double > > str_double_arr;
	std::vector< std::pair<std::string,double > > str_double_arr2;

/* 초기화 */

	std::cout << "초기화 코드" << std::endl;
	int len = 10;
	std::vector<int> int_arr_init(len,10);	// 길이 Len을 10으로 초기화

	for ( int x : int_arr_init)
		std::cout << x << " ";
	std::cout << std::endl;

/* 초기화2 */

	std::cout << "초기화 코드 2" << std::endl;
	std::vector <int> int_arr_init2 { 10,20,30};

	for ( int x : int_arr_init2 )
		std::cout << x << " ";

	std::cout << '\n';

/* 초기화3 */

	int temp_arr[] = {1,2,3,4,3,2,1};
	std::cout << "초기화 3" << std::endl;
//문제 O
	std::vector <int> int_arr_init3(temp_arr,temp_arr+7);
	std::vector <int> int_arr_init3(temp_arr,temp_arr+6);
//문제 X

	for( int y : int_arr_init3)
		std::cout << y;
	std::cout << std::endl;

/* 초기화 4 */
	std::cout << "초기화 4 " << std::endl;
	std::vector <int> int_arr_init4(int_arr_init3.begin(), int_arr_init3.end());

	for (int z : int_arr_init4)
		std::cout << z ;
	std::cout << std::endl;





/* 값 대입 */
	int_2_arr.push_back( std::make_pair( 3, 20 ) );
	int_arr.push_back( 30 );
	str_double_arr.push_back( std::make_pair("something",120.11) );


	//print Vector Element
	std::cout << int_arr[0] << std::endl;
	std::cout << int_2_arr[0].first << " " << int_2_arr[0].second <<std::endl;
	std::cout << str_double_arr[0].first << " " << str_double_arr[0].second << std::endl;

/* 여기서 문제 */






}
