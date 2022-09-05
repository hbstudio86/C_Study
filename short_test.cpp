#include <iostream>

using namespace std;

class tClass {
private:
	int k;
	char* n;
public:
	tClass() :k(0), n(NULL) {};
	tClass(int ik) { k = ik; n = NULL; }
	tClass(int ik,const char* is) { k = ik; n = (char*)is; }
	~tClass() {};

	void outStr(void) { cout << n << endl; }
};

int main(void) {

	tClass t1;
	tClass t2(1);
	tClass t3(1, "hello");

	t3.outStr();

	return 0;
}