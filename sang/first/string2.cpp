#include <iostream>
#include <string>

using namespace std;


int main(void){


string myString = "hello";
myString  += ", there ";	// 메모리 릭이 발생하지 않음. C에서는 금지된 행동, string 객체는 스택에서 생성
//메모리 크기변경과 할당이 여러번 일어나더라도 스코프에서 벗어나는 순간 소멸자가 호출되면서 모든 메모리가 정리
string myOtherString = myString;	//대입연산이 정상적으로 작동, 주소값이 아니라 문자열 자체가 복사

if( myString ==myOtherString ){ 	//같다 연산이 정상적으로 작동
	myOtherString[0] = 'H';
}

cout << myString <<endl;
cout << myOtherString << endl;


return 0;
}
