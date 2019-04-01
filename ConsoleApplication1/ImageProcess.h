#pragma once
#include "BufferQueue.h"
#include "Stream.h"

#include <list>

class ImageProcess
{
public:
	ImageProcess();
	ImageProcess(ImageProcess *prev);
	virtual ~ImageProcess();

protected:
	std::list < Stream *> streams;
	std::list<ImageProcess*> prevs;
	std::list<ImageProcess*> nexts;
};

class IspProcess :
	public ImageProcess
{
public:
	IspProcess();
	~IspProcess();

};

class Scaler :
	public ImageProcess
{
public:
	Scaler();
	~Scaler();
};

class DewarpProcess :
	public ImageProcess
{
public:
	DewarpProcess();
	~DewarpProcess();
};

