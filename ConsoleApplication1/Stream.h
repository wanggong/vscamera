#pragma once
#include<list>

class ImageProcess;
class Stream
{
public:
	Stream();
	virtual ~Stream();

private:
	std::list<ImageProcess*> processes;
};

