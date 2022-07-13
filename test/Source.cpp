#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <iostream>
#include <math.h>
#include <stack>
#include <type_traits>
#include <bitset>
#include<unordered_map>
#include<vector>
#include "Father.h"
#include "Header.h"
#include "Constructor_Type_Impilicit_Conversion.h"
#include "uniPtrTest.h"
#include<memory>
//#include "staticHea.cpp"
#include "etnCheck.h"
extern int printTest();
using namespace std;






//const int Father::GLOOOO;



void incrementAndPrint()
{
	static float s_value{ 4.0 }; // static duration via static keyword.  This initializer is only executed once.
	++s_value;
	std::cout << s_value << '\n';
}

//static 
const int& print(const Father& f)  {
	
	f.printy();
	return f.y;
	
}
void print( Father& f) {
	f.printy();

}

//explicit conversion
class Child:public Father  {
	
	
	
public:
	
	string x="sayonara";

	Child();

	using Father::Father;
	 Child(int i,Father& f):Father(5) {
		 
		
		 x = "this is child construct";
		 cout << x<<endl;
	 }

	 //copy constructor是可以继承的
	 Child(Child& c) {


		
		 cout << "Child copy constructor" << endl;
	 }

	 Child(const string& str , int i=0 ) :x(str) {
		 cout << "Child override constructor" << endl;
	 }

	 ~Child() {
	 
		 cout << "Child  destructor" << endl;
	 }

	 /*default value的传参必须放在最后*/
	 //Child(const string& str="sd", int i = 10) :x(str) {}

	 static void lookAddress() {
		 std::cout << "child";}
	 const string& ini(Child& c);
};

Child::Child() :Father(4) {
	y = 5;

	pTest = new int(3);
	cout << "Child default constructor" << endl;
}

class Son : public Father {
public:
	Son() {
	}
	int i = 1;
	
	void ini(std::string str = "son string") ;
};

void Father::ini(std::string str) {
	std::cout << "This is father func";
	std::cout << str << endl;
	cout << GLOOOO;
}


//impilicit test
 const string& Child::ini(Child& c ) {
	std::cout << "This is Child ini func"<<endl;

	return x;
	
}

void Son::ini(std::string str) {
	
	std::cout << "This is Son func"<<endl;
	std::cout << str << endl;
}

class Base {
public:
	 void f1()  {
		std::cout << 1;
		f2();
		
	}
	 void f2() {
		std::cout << 2;
	}

};

class Derived :public Base {
public:
	void f1() {
		std::cout << 3;
		Base::f2();
	}
	virtual void f2() {
		std::cout << 4;
	}


};
//
//class FOO {
//	explicit FOO(int i);
//	int opreator()(int x) const{}
//
//};

class PrivateTest {
public:
	
	PrivateTest() {
	
		cout << "private mem" << endl;
	}
};

class PublicTest {
public:

	PublicTest() {

		cout << "public mem" << endl;
	}
};

class Tt {



public:

	void testPrivAccess(Tt& T) {
		p4 = T.p4;
		cout << "    swap    " ;
	}
	
private:
	
	PublicTest p4;
};


void doSth(int arr[], int s) {
	
	int* pEle = nullptr;// no need to allocate the space of the array
	int size = sizeof(arr) / sizeof(int);
	for (int i = 0; i <= size; i++) {
		pEle = &arr[i];
		//*&arr[i] = 6;
		*pEle = 10;
	}

	//delete pEle;// not necessary

}

void variousArr() {
	int array[6] = { 1,1,1,1,1,1 };




	//for (int i : array) {// i is the value of the array
	//	array[i] = i;
	//}


	//int(*arr2)[6];
	int* arr2[6];
	
	for (int i = 0; i <= 5; i++) {

		//*arr2[i] = 1;
		arr2[i] = new int(8);//comments
	}
	int j = 0;
	for (int*& i : arr2) {//
		std::cout << "before" << '\n';
		std::cout << arr2[j] << '\n';
		*i = 1;
		std::cout << "after" << '\n';
		std::cout << &i << '\n';

		std::cout << "value" << '\n';
		std::cout << *i << '\n';
		j++;
	}

	for (int* i : arr2) {//
		std::cout << "before" << '\n';
		std::cout << arr2[j] << '\n';
		*i = 1;
		std::cout << "after" << '\n';
		std::cout << &i << '\n';

		std::cout << "value" << '\n';
		std::cout << *i << '\n';
		j++;
	}


	//int* arr3=new int[6]();
	//int** arr4 = new int* [3]();

	//doSth(array, array[3]);
}

void polymorphismTest() {
	/*
//polymorphism
	Child* child = new Son();
	child->ini();




	Derived* d = new Derived();
	Base& b = *d;
	b.f1();
	b.f2();
*/
}

bool bitWiseBase(int a, int b) {

	
	int c = a & b;
	std::cout << c << std::endl;
	if (log2(c) == 0.0) { 
		
		std::cout << " the power of 2";
		return true; 
	}

	return false;

}

int calcBits(int number) {
	int count = 0;
	//calculate the total bits in a number
	while (number) {
		count++;
		//std::cout<< number<<std::endl;
		number >>= 1;
	}
	return count;
}
void  printInBinary(int number) {
	 int i;
	 for ( i = 1 << 7; i >0; i=i/2) {
		 //std::cout << i << std::endl;
		(number & i) ? std::cout << "1" : std::cout << "0"<<endl;
		
	}
	std::cout << std::endl;
}


//various constructor
class copyTest {

public:
	
	std::string myStr;
		int length;
	copyTest() :myStr("my string"),length(myStr.size()) {


		std::cout << "This is a constructor"<<std::endl;
		
	}
	copyTest(const copyTest& cpy ):myStr(cpy.myStr),length(cpy.length) {
		std::cout << myStr << std::endl;
		std::cout << "This is a copy constructor" << std::endl;
		std::cout << "---------------------" << std::endl;
	}
	//是否传引用是有区别的
	copyTest& operator= (const copyTest & cpy) {
		this->myStr = cpy.myStr;
		this->length = cpy.length;
		std::cout << "This is a = constructor" << std::endl;
		std::cout << "---------------------" << std::endl;
		return *this;
	}
	
};


bool stackTest(std::string ultma) {

	std::stack <char> s;

	for (char i:ultma) {

		if (i== '{' || i == '(' || i == '<' || i == '[') {
			s.push(i);
		}

		else if (i == '}' || i == ')' || i == '>' || i == ']') {
			
			if ((s.top() == '{'&& i=='}')|| (s.top() == '(' && i == ')')||(s.top() == '<' && i == '>')|| (s.top() == '[' && i == ']')) {
				



				s.pop(); 
			}

		}
	}

	if (s.empty()==true) { 
		cout << "balanced";
		return true; 
	}

	
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
	cout << "unbalanced";
		return false;


}
int lonelyinteger(vector<int> a) {

	unordered_map<int, int> map;

	for (auto i = a.begin(); i != a.end(); i++) {


		auto x = map.find(*i);
		if (x == map.end()) {

			//int key = *i;
			//map[key] = 1;
			map.insert({ *i,1 });
			//	map.insert(key, 1);

		}
		else {
			map.erase(*i);
			cout << "erased" << *i << endl;
		}


	}
	
		unordered_map<int, int>::iterator s = map.begin();
		int result = s->first;
	

	
	return result;
}

int diagonalDifference(vector<vector<int>> arr) {
	int size = arr.size();
	int ltrD = 0;
	int rtlD = 0;
	for(int i=0;i<arr.size();i++){
		int j=size-i-1;
		ltrD+=arr[i][i];
		rtlD+=arr[i][j];

	}
	
	return abs(ltrD - rtlD);
}


int testMain() {
	



	// bitWiseBase(13, 11);

	//printInBinary(3);
	//stackTest("[{<(<<(){()}>>)>}][]");
	int i = 0;
	float s[] = { 0.f,0.2f,0.3f,0.4f,4,4,5,5,6.f};
	cout <<sizeof(s)/sizeof(float) << endl;
	float sum=0;

	float* x = s;
	int size =sizeof(s) / sizeof(float);

	cout << endl;
	
	
	for (int j=0; j <= size;j++) {
		sum += *x;
		x++;
		
	//	cout<<is_same<decltype(s[1]), decltype(*x)>::value;
		

			//	typeid(s).name();
	}



	/*...pointer array*/
	/*
	int* xx = new int[2];
	int**yy = new int*[1];

	*xx = 1;
	*(xx + 1) = 2;
	yy[0] = (xx+1);
	cout << typeid(*xx).name()<<endl;
	cout << xx+1<< endl;
	cout << typeid(*yy).name() << endl;
	cout << **yy << endl;
	*/

	/*
	Father* f=new Child();
	const Father* ff = new Father();

	int zzz = print(*ff);
	zzz = 2;

	cout << "zzz" << zzz<<endl;
	Child* c = dynamic_cast<Child*>(new Father());
	c->ini2(4);
	


	print(*f);
	print( *ff);
	cout <<"size of father"<<sizeof(f) << endl;
	Father::lookAddress();
	Child::lookAddress();
	string xyz = "sds";
	int iii = 0;
	//c.ini(xyz);
	*/





	//Child child(4, f);
	//	void (*pIncre)() = incrementAndPrint;
	//incrementAndPrint();
	//char* pCHar = (char*)pIncre;
	//cout << *(pCHar);
	
	return 0;
}





extern void RotateInplace(int preViousindex, int cToReplace, int ioStr[], int n, int& iterator, int& round, int size);

void RotateString(int ioStr[], int n, int direction,int size)
{
	int round = 0;
	int iterator = 0;
	
	cout << "ssssize" << size << endl;
	//if (direction == 0) n = sizeof(ioStr) - n;

	RotateInplace(0, ioStr[0],ioStr,n, iterator, round,size);


}

void RotateInplace(int preViousindex, int cToReplace, int ioStr[], int n, int& iterator, int& round, int size) {
	if (iterator == 6) return;
	int index;
	char cr;


	if ((preViousindex + n) <= (size - 1)) {
		index = preViousindex + n;
		cr = ioStr[preViousindex + n];
		ioStr[index] = cToReplace;



	}

	else {
		index = ((preViousindex + n) % size);
		cout << "index" << index << endl;
		cr = ioStr[index];
		cout << "value" << cr << endl;
		cout << "pre value" << cToReplace << endl;
		ioStr[index] = cToReplace;


		if ((size % n == 0) && (round < n - 1) && (index == round)) {
			round++;
			index = round;
			cr = ioStr[index];
		}

	}
	iterator++;

	RotateInplace(index, cr, ioStr, n, iterator, round, size);

}

void childUniTest(Child* c) {
	cout << "Child uniptr get works" << endl;
}
	
	

	// Your code here


// Perform an in-place "rotation" of the characters in ioStr

// Where "rotation" means shift the characters left or right and those which drop
// off the end of the string are added to the vacated character positions at the other end
// n: the number of places to rotate
// direction: 0 = rotate left, 1 = rotate right
// e.g. RotateString( "ABCDE", 1, 1 ) -> "EABCD"
// e.g. RotateString( "ABCDE", 2, 1 ) -> "DEABC"
// e.g. RotateString( "ABCDEF", 4, 0 ) -> "EFABCD"
template<class T> class B {};   // 主模板


	template<class T>
	void swap(B<T>& a, B<T>& B) {
		cout << "cout" << endl ;
	}


	class SizeTest {

		char a[11];
	//	double x;
	};


int main(int argc, char* const argv[])
{
	int* pInt = new int(1);
	cout << pInt << endl;
	cout << &pInt<<endl;
	int str[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int size = sizeof(str) / 4;
	//char* c = &str[2];
	//*c = 's';
	cout << "before ";
	for  (auto &i:str) {
		cout << i;
	}
	cout << endl;

	RotateString(str, 6, 1,size);
	cout << "after ";
	for (auto& i : str) {
		cout << i<<endl;
	}
	cout << endl;
	printf(" siez: %d\n", sizeof(str));

	printTest();

	
	
	 vector<int> vec = { 1,2,3,4,5,6 };

	 int& int_to = vec.back();
	 cout << &int_to << endl;
	 cout << "--------------------------before" << endl;
	 vec.push_back(7);

	 cout << int_to << endl;

	 cout << "--------------------------end" << endl;
	 cout << &int_to << endl;
	//cout <<"size :" << sizeof(c) << endl;


	//
	////构建顺序，override 以及隐式转换的本质
	//Father tes;
	//unique_ptr<Child> unique = make_unique<Child>(1,tes);
	//
	//childUniTest(unique.get());

	//unique->ini(*unique);



	//free(str);
	
    
	return 0;
}