#include <iostream>
using namespace	std;

class TSteck
{
public:
	TSteck();
	TSteck(int len);
	TSteck(TSteck& TS);
	~TSteck();
	TSteck& operator=(TSteck& TS);
	bool operator ==(TSteck& TS);
	void push(double Elem);
	void top();
	double check();
	bool Full();
	bool Empty();

private:
	double* steck;
	int marker;
	int len_steck;
};
bool TSteck::operator==(TSteck& TS) {
	if (marker == TS.marker) {
		for (int i = marker; i > -1; i--) {
			if (steck[i] != TS.steck[i]) {
				return false;
			}
		}
	}
	else {
		return false;
	}
}
TSteck& TSteck::operator=(TSteck& TS) {
	if (TS.Empty()) {
		throw"TS is empty";
	}
	else {
	TSteck res(TS);
	return res;
	}
}

TSteck::TSteck(TSteck& TS) {
	marker = TS.marker;
	steck = new double[TS.len_steck];
	for (int i = 0; i < marker; i++) {
		this->steck[i] = TS.steck[i];
	}

}

double TSteck::check() {
	if (this->Empty()) {
		throw"steck is empty";
	}
	else {
		cout << "top element : " << steck[marker] << endl << "nomber of top element : " << marker << endl;
		double res = steck[marker];
		return res;
	}
}

bool TSteck::Full() {
	if (marker == len_steck) {
		return true;
	}
	else {
		return false;
	}
}
bool TSteck::Empty() {
	if (marker == -1) {
		return true;
	}
	else {
		return false;
	}

}

void TSteck::top() {
	if (this->Empty()) {
		cout << "steck is empty can`t top elem" << endl;
		throw "steck is empty";
	}
	else{
		steck[marker] = 0;
		marker--;
	}
}

void TSteck::push(double Elem) {
	if (this->Full()) {
		cout << "steck is full can`t push elem" << endl;
		throw"steck is full";

	}
	else {
		marker++;
		steck[marker] = Elem;
	}
}
TSteck::TSteck(int len) {
	marker = -1;
	steck = new double[len];
	for (int i = 0; i < len; i++) {
		steck[i] = 0;
	}
	len_steck = len;

}
TSteck::TSteck()
{
	marker = -1;
}


TSteck::~TSteck()
{
	delete[] steck;
	steck = nullptr;
}


int main()
{
	double c;
	TSteck p(10);
	TSteck g(5);
	p.push(4);
	c = p.check();
	p.push(7);
	c = p.check();
	p.top();
	c = p.check();
	for (int i = 1; i < 10; i++) {
		p.push((i+1));
		//p.check();
	}
	for (int i = 0; i < 5; i++) {
		g.push(i);
		g.check();
	}
	g.check();
	bool res;
	res = (p == g);
	cout << res << endl;
	g.check();
	p = g;
	res = (p == g);
	cout << res << endl;


}

