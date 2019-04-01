#pragma once
#include "BufferQueue.h"
#include "ImageProcess.h"

class WritePort : public ImageProcess,
	public BufferProductor
{
public:
	WritePort();
	virtual ~WritePort();
};

class ReadPort : public ImageProcess,
	public BufferConsumer
{
public:
	ReadPort();
	virtual ~ReadPort();
};


