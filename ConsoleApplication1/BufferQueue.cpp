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
	std::lock_guard<std::mutex> lockg(lock);
	if (std::find(consumers.begin(), consumers.end(), consumer) == consumers.end())
	{
		consumers.push_back(consumer);
		return true;
	}
	return false;
}

bool BufferQueue::addProductor(BufferProductor * productor)
{
	std::lock_guard<std::mutex> lockg(lock);
	if (std::find(productors.begin(), productors.end(), productor) == productors.end()) 
	{
		productors.push_back(productor);
		return true;
	}
	return false;
}

bool BufferQueue::removeConsumer(BufferConsumer * consumer)
{
	std::lock_guard<std::mutex> lockg(lock);
	if (std::find(consumers.begin(), consumers.end(), consumer) != consumers.end())
	{
		consumers.remove(consumer);
		return true;
	}
	return false;
}

bool BufferQueue::removeProductor(BufferProductor * productor)
{
	std::lock_guard<std::mutex> lockg(lock);
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

BufferConsumer::BufferConsumer()
{
}

BufferConsumer::~BufferConsumer()
{
}

void BufferConsumer::onFullBufferAvailable(Buffer * buf)
{
	bufs.push(buf);
}

BufferUseBase::BufferUseBase()
{
}

BufferUseBase::~BufferUseBase()
{
}

BufferProductor::BufferProductor()
{
}
BufferProductor::~BufferProductor()
{
}
void BufferProductor::onEmptyBufferAvailable(Buffer *buf)
{
}
