#pragma once
class Buffer
{
public:
	Buffer();
	virtual ~Buffer();
};

template<typename T>
class BufferCallback
{
public:
	virtual ~BufferCallback();
	virtual void onBufferAvailable(T *t);
};
