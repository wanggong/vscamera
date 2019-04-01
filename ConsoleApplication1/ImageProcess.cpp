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
