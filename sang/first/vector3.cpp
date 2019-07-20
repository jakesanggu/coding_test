
#include <vector>
#include <iostream>

using namespace std;


int main(void){

	vector < pair <int , int > > vec;

	int arr[] = {10,20,5,40};
	int arr1[] = { 30 ,60 ,20, 50 };
	int n = sizeof(arr)/ sizeof(arr[0]);

	for(int i=0; i < n ; i ++ )
		vec.push_back( make_pair(arr[i],arr1[i]));

	for(int i =0; i < n ; i++){
		cout << vec[i].first << "  "
		<< vec[i].second <<endl;
	}



return 0;


}
