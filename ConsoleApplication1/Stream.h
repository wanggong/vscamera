#pragma once
#include<list>

#include "ImageProcess.h"
class Stream
{
public:
	Stream();
	virtual ~Stream();

private:
	std::list<ImageProcess*> processes;
};

