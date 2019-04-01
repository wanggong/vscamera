#include "pch.h"
#include "Pipeline.h"


Pipeline::Pipeline()
{
}


Pipeline::~Pipeline()
{
}

void Pipeline::buildPipeline(std::list<Stream*> streams)
{

}

void Pipeline::initPipeline()
{
	isp = new IspProcess();
	ispscaler[0] = new Scaler();
	ispscaler[1] = new Scaler();
	backscaler[2] = new Scaler();
}
