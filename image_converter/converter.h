#pragma once
#include "stdafx.h"

class Converter
{
public:
	
	/**
	 * \brief Read png image by given path and create bmp copy next to it
	 * \param filepath Path to original image.
	 */
	void png_to_bmp(const std::filesystem::path& filepath) const;
	
	/**
	 * \brief Find all png files in given folder to be deleted.
	 * \param folder_path Path that will be scanned for images.
	 * \param keep_original Set true to disable deletion of original files.
	 */
	void batch_process_png(const cv::String folder_path, const bool& keep_original) const;
};
