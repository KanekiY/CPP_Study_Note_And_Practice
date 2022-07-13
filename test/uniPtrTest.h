#pragma once
class BaseUnique {
public: 
	virtual void foo() = 0;
};

class DerivedUnique : public BaseUnique {
public:
	virtual  void foo() {
	}

};

