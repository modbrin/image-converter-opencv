// image_converter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main(int argc, char *argv[])
{
	Converter conv{};
	if(argc >= 2)
	{
		//TODO: add command line argument passing support for filepath
	}
	conv.batch_process_png(true);
	return 0;
}


