#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(void){


map <string,int> m; // <key,value>

m.insert(make_pair("a",1));
m.insert(make_pair("b",2));
m.insert(make_pair("c",3));
m.insert(make_pair("d",4));
m["f"] = 6 ; //이것도 가능

//사용 법

//출력
cout <<  m.find("a")-> second << endl;
cout <<  m.find("a")-> first << endl;

//사이즈 체크
cout << "is empty? " <<m.empty() << endl;
cout << "size: " << m.size() <<endl;

// traverse print

/* 주의 점은 i는 정수가 아님.. */
for (auto i = m.begin() ; m.end() != i ; i++ ){
	cout << i->first << " " << i->second <<endl;
}



return 0;
}
