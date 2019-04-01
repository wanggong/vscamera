#pragma once
#include "Buffer.h"

#include <list>
#include <queue>
class BufferQueue
{
public:
	BufferQueue();
	virtual ~BufferQueue(); 
	bool addConsumer(BufferConsumer *consumer);
	bool addProductor(BufferProductor *productor);
	bool removeConsumer(BufferConsumer *consumer);
	bool removeProductor(BufferProductor *productor);
private:
	bool onEmptyBufferAvailable(Buffer *buf);
	bool onFullBufferAvailable(Buffer *buf);
private:
	std::list<Buffer*> empty_bufs;
	std::list<Buffer*> full_bufss;
	std::list<BufferConsumer*> consumers;
	std::list<BufferProductor*> productors;
};

class BufferUseBase
{
public:
		BufferUseBase();
		virtual ~BufferUseBase();
protected:
	std::queue<Buffer*> bufs;

};

class BufferConsumer : public BufferUseBase
{
public:
	BufferConsumer();
	virtual ~BufferConsumer();
	void onFullBufferAvailable(Buffer *buf);
};

class BufferProductor : public BufferUseBase
{
public:
	BufferProductor();
	virtual ~BufferProductor();
	virtual void onEmptyBufferAvailable(Buffer *buf);
};


