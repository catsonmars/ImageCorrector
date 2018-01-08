#include"image.h"
Image::Image()
{

}


int Image::Read_Header(const char filename[])
{
	Open_File_ = fopen(filename, "rb");
	fread(read_header_, sizeof(unsigned char), 54, Open_File_);//first 54 bytes are part of the header
	int w = *(int*)&read_header_[18];
	int h = *(int*)&read_header_[22];

	int size_ = 3 * w*h;

	unsigned char *data = new unsigned char[size_];//size
	FILE *pFile = fopen("ImageCorrected.bmp", "wb");//need pointer pFile to read the image after 54 byte header
	fwrite(read_header_, 1, 54, pFile);

	for (int i = 0; i <h; i++)
	{

		fread(data, sizeof(unsigned char), 3 * w, Open_File_); //reads the width of the file
		for (int j = 0; j < w; j++)
		{
			for (int k = 0; k < 1; k++)//loops through 3 bytes and changes rgb values to 25,117,126 if that's not what's read
			{
				if (data[k] != 25)
				{
					data[k] = 25;

				}

				if (data[k + 1] != 117)
				{
					data[k + 1] = 117;
				}

				if (data[k + 2] != 126)
				{
					data[k + 2] = 126;
				}
				fwrite(data, sizeof(unsigned char), 3, pFile);
			}

		}

	}
	fclose(Open_File_);
	fclose(pFile);
	return size_;
}

Image::~Image()
{
	
}
