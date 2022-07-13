#pragma once
#include <iostream>




class Father {
public:
	int y = 10;
	int* pTest = nullptr;
	Father() {
		std::cout <<"created father" << std::endl;
	}

	Father(int&& i) {

		std::cout << "Father rvalue copy constructor" << std::endl;
	}
	Father(int& i) {

	}
	//Father(Father& f) {
	//	std::cout << "Father copy constructor"<<std::endl;

	//}

	////rvalue copy constructor
	//Father(Father&& f) noexcept
	//{
	//	std::cout << "Father rvalue created";

	//	//f.c[GLOOOO] = 0;
	//

	//}



	~Father() {
		std::cout << "Father destroyed" << std::endl;
	}
	
	void doIni() {
		ini();
	}
	
	
	void ini2(int i) {
		std::cout<<"no initialise number" << noInitialisez << std::endl;
		std::cout << &GLOOOO;
	}

	static int stcFunc() {
		static int i = 1;
		std::cout << "i zhi" << i << std::endl;
		return i++;
	}
	static void lookAddress() { 
		std::cout << &Father::GLOOOO;
	};

	 int printy() const {
		 int x = y;

		std::cout <<" const" << y << std::endl;
		return y;
	}

	 int printy()  {
		 std::cout << "non const" << y << std::endl;
		 return y;
	 }
	
	 static int staticValueT ;
private:
	int noInitialisez=1;
	static const int GLOOOO =10;
	const int a = 23;
	virtual  void ini(std::string str = "Father string");
	

	//this is to disable copy constructor
	//Father(const Father& f);
	
//	void operator = (const Father& dsd);
	//int c[GLOOOO];
};
  int Father::staticValueT = 2;

