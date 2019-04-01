#pragma once
#include "ImageProcess.h"
#include "Stream.h"

#include <list>
class Pipeline
{
public:
	Pipeline();
	virtual ~Pipeline();
	void buildPipeline(std::list<Stream*> streams);
	void initPipeline();
private:
	std::list<ImageProcess*> heads;
	IspProcess *isp;
	Scaler *ispscaler[2];
	DewarpProcess *dewarp[2];
	Scaler *backscaler[3];
};

