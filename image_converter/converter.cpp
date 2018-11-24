#include "stdafx.h"

namespace fs = std::filesystem;


void Converter::png_to_bmp(const fs::path& filepath) const
{
	cv::Mat image = cv::imread(filepath.string(), -1);
	cv::Mat image_bmp;
	image.convertTo(image_bmp, CV_8UC3);
	fs::path write_path{ filepath };
	write_path.replace_extension(".bmp");
	imwrite(write_path.string(), image_bmp);
}

void Converter::batch_process_png(const bool& keep_original) const
{
	try {
		fs::path path = fs::current_path().append("imgs_test\\");
		for (auto & p : fs::recursive_directory_iterator(path))
		{
			if (p.path().extension().compare(".jpg") == 0)
			{
				this->png_to_bmp(p.path());
				std::cout << "Converted " << p.path() << std::endl;
				if (!keep_original)
				{
					fs::remove(p.path());
				}
			}
		}
	}
	catch (fs::filesystem_error e)
	{
		std::cout << e.what() << std::endl;
	}
	system("pause");
}

