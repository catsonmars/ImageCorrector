#include "image.h"
/*This is a file to demonstrate a simple algorithm I made to correct images in a 24-bit 252x252 bmp image. Enjoy.*/

int main()
{
	std::cout << "Enter in a filename of a BMP image that is 252x252\n";
	std::cout << "Don't forget to include the .bmp extension\n";
	char filename[25];
	std::cin >> filename;
	Image image;
	image.Read_Header(filename);

	

	return 0;
}
