#include "pch.h"
#include "BufferQueue.h"


BufferQueue::BufferQueue()
{
}


BufferQueue::~BufferQueue()
{
}

bool BufferQueue::addConsumer(BufferConsumer * consumer)
{
	if (std::find(consumers.begin(), consumers.end(), consumer) == consumers.end())
	{
		consumers.push_back(consumer);
		return true;
	}
	return false;
}

bool BufferQueue::addProductor(BufferProductor * productor)
{
	if (std::find(productors.begin(), productors.end(), productor) == productors.end()) 
	{
		productors.push_back(productor);
		return true;
	}
	return false;
}

bool BufferQueue::removeConsumer(BufferConsumer * consumer)
{
	if (std::find(consumers.begin(), consumers.end(), consumer) != consumers.end())
	{
		consumers.remove(consumer);
		return true;
	}
	return false;
}

bool BufferQueue::removeProductor(BufferProductor * productor)
{
	if (std::find(productors.begin(), productors.end(), productor) != productors.end())
	{
		productors.remove(productor);
		return true;
	}
	return false;
}

bool BufferQueue::onEmptyBufferAvailable(Buffer * buf)
{
	for(auto p : productors)
	{
		p->onEmptyBufferAvailable(buf);
	}
	return true;
}

bool BufferQueue::onFullBufferAvailable(Buffer * buf)
{
	for (auto c : consumers)
	{
		c->onFullBufferAvailable(buf);
	}
	return true;
}

void BufferConsumer::onFullBufferAvailable(Buffer * buf)
{
	bufs.push(buf);
}
