#include <iostream>
#include <vector>
#include <string>
#include <utility>


using namespace std;

int main(){


	vector<int> v;
	vector<int,string> g;


	v.reserve(8);	//8의 메모리 공간 할당

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(50);

	g.push_back(make_pair(30,"string2"));

	for( vector<int>:: size_type i = 0; i < v.size(); ++i){

		cout << v[i] <<endl;

	}

	cout << endl;


}
