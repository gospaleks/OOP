#pragma once
class Buffer
{
private:
	int* niz;
	int velicina;
	int brUpisanih;
public:
	Buffer();
	Buffer(int vel);
	Buffer(const Buffer& b);
	~Buffer();
	inline int vratiBrEl() { return brUpisanih; }
	void push(int podatak);
	int pop();
	void prikazi();
	void dupliraj();
	void izbaciPrazna();
};

