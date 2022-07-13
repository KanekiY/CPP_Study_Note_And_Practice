#pragma once
#include<iostream>
class FontHandle {
public:
	int y = 10;
};

class Fontx {
public:
	Fontx() {
		f.y = 5;
	}

	Fontx(Fontx& f) {
		this->f.y = 15;
	}

	operator FontHandle() const {
		return f;
	}
	int operator()() const {
		std::cout << "cout ()chongzai" << std::endl;
		return 1;
	}

	FontHandle f;
};


void changeFontSizeX(FontHandle f) {}

// ÒþÊ½×ª»»µÄcheck
void func3() {
	
	Fontx f1;
	
	std::cout << "f1 de f" << f1.f.y << std::endl;
	changeFontSizeX(f1);
	FontHandle f2 = f1;

	std::cout << "f2 de f" << f2.y << std::endl;
	FontHandle f3;
	std::cout << "f3 de f" << f3.y << std::endl;

	Fontx f4 = f1;
	std::cout << "f4 de f" << f4.f.y << std::endl;
}