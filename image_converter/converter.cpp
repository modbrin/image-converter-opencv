#include "stdafx.h"

namespace fs = std::filesystem;


void Converter::png_to_bmp(const fs::path& filepath) const
{
	cv::Mat image = cv::imread(filepath.string(), -1);
	cv::Mat image_bmp;
	image.convertTo(image_bmp, CV_32FC4);
	fs::path write_path{ filepath };
	write_path.replace_extension(".bmp");
	imwrite(write_path.string(), image_bmp);
}

void Converter::batch_process_png(const cv::String folder_path, const bool& keep_original) const
{
	int counter = 0;
	try {
		const fs::path path{folder_path};
		for (auto & p : fs::recursive_directory_iterator(path))
		{
			if (p.path().extension().compare(".png") == 0)
			{
				this->png_to_bmp(p.path());
				std::cout << "Converted " << p.path() << std::endl;
				if (!keep_original)
				{
					fs::remove(p.path());
				}
				++counter;
			}
		}
	}
	catch (fs::filesystem_error e)
	{
		std::cout << e.what() << std::endl;
		exit(1);
	}
	std::cout << "Total converted: " << counter << std::endl;
	system("pause");
}

