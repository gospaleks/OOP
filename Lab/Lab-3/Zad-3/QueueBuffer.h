#pragma once
#include "Buffer.h"
class QueueBuffer : public Buffer
{
public:
	QueueBuffer(void);
	~QueueBuffer(void);
	QueueBuffer(int k)
		: Buffer(k){}
	virtual void push(int element);
	virtual void pop();


};

