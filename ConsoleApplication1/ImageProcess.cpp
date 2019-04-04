#include "pch.h"
#include "ImageProcess.h"


ImageProcess::ImageProcess()
{
}

ImageProcess::ImageProcess(ImageProcess * prev)
{
	prevs.push_back(prev);
	prev->nexts.push_back(this);
}


ImageProcess::~ImageProcess()
{
}

IspProcess::IspProcess()
{
}

IspProcess::~IspProcess()
{
}

Scaler::Scaler()
{
}

Scaler::~Scaler()
{
}

DewarpProcess::DewarpProcess()
{
}

DewarpProcess::~DewarpProcess()
{
}
