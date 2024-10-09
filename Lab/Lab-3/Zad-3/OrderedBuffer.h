#pragma once
#include "Buffer.h"
class OrderedBuffer : public Buffer
{
public:
	OrderedBuffer() { }
	OrderedBuffer(int k) :Buffer(k) { }
	virtual void clear();
	virtual void push(int element);
	virtual void pop();
};

