#pragma once
//
//
//
//static int printTest();
 namespace Fon{
class FontHandle {

};

class Font {
public:
	operator FontHandle() const {
		return f;
	}

private:
	FontHandle f;
};


void changeFontSizeX(FontHandle f) {}

void func() {

	Font f1;

	changeFontSizeX(f1);
	FontHandle f2 = f1;

}

}