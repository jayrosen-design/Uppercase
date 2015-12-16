#pragma once
//Jay Rosen
//COP2551.0M1
//This is the Filter class and Upper class header file
//These classes are used to transform data to UPPER CASE from input file to output file

#ifndef Filter_H
#define Filter_H
#include<iostream>
#include<fstream>

using namespace std;

// Filter class definition
class Filter
{
public:
	Filter();
	~Filter();
	virtual char transform(char ch) = 0;
	void doFilter(ifstream &in, ofstream &out);
};


/**************************************************************
*						Filter::Filter                        *
*             Default constructor for Filter class            *
**************************************************************/
Filter::Filter()
{

}

/**************************************************************
*						Filter::~Filter                        *
*             Default destructor for Filter class              *
**************************************************************/
Filter::~Filter()
{

}

/**************************************************************
*						Filter::doFilter                      *
*   Function that calls virtual function, reads input file,   *
*   and writes character transformations to output file.      *
**************************************************************/
void Filter::doFilter(ifstream &in, ofstream &out)
{
	char ch;
	char transCh;
	out.clear();
	in.clear();
	in.seekg(0L, ios::beg);
	in.get(ch);

	while (!in.fail())
	{
		transCh = transform(ch);
		out.put(transCh);
		in.get(ch);
	}
}


// Upper class definition
class Upper : public Filter
{
public:
	Upper();
	~Upper();
	char transform(char ch);
};

/**************************************************************
*						Upper::Upper                          *
*             Default constructor for Upper  class            *
**************************************************************/

Upper::Upper()
{

}

/**************************************************************
*						Upper::~Upper                          *
*             Default destructor for Upper  class              *
**************************************************************/
Upper::~Upper()
{

}

/**************************************************************
*						Upper::transform()                     *
*               Reads data  from input file and writes         *
*               uppercase character to output file.            *
**************************************************************/
char Upper::transform(char ch)
{
	return toupper(ch);
}

#endif