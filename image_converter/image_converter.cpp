// image_converter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main(int argc, char *argv[])
{
	Converter conv{};
	cv::String folder_path = std::filesystem::current_path().string();
	
	if(argc >= 2)
	{
		folder_path = argv[1];

	}

	conv.batch_process_png(folder_path, true);
	return 0;
}


