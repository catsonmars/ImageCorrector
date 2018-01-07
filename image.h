#pragma once
#include<iostream>
#include<stdio.h>
#include<fstream>
#include<sstream>
#include<string>

#pragma warning (disable : 4996)


#ifndef IMAGE_H
#define IMAGE_H
class Image {

public:
	Image();
	~Image();
	
	int Read_Header(const char filename[]);
	
	
	
private:
	FILE * Open_File_;
	unsigned char read_header_[54];
	int size_;



	
	
};

#endif
