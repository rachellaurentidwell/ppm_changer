#pragma once
#include "Pixel.h"
#include <string>
using namespace std;

class PpmDocument
{
private:
	string _doc_type;
	int _width;
	int _height;
	int _max_rgb;

	//2D array of Pixel objects
	Pixel **_pixels = nullptr;

public:
	PpmDocument(string doc_type = "",
		int width = 1,
		int height = 1,
		int max_rgb = 255)
	{
		_doc_type = doc_type;
		_width = width;
		_height = height;
		_max_rgb = max_rgb;

		//dynamically allocate space for our 2D array
		_pixels = new Pixel*[_height];
		for (int i = 0; i < _height; i++)
		{
			//allocate sub array
			_pixels[i] = new Pixel[_width];
		}
	}

    //copy constructor
    PpmDocument(const PpmDocument &other) : 
        PpmDocument(other._doc_type, other._width, other._height, other._max_rgb)
    {
        for (int row = 0; row < _height; row++)
        {
            for (int col = 0; col < _width; col++)
            {
                _pixels[row][col] = other._pixels[row][col];
            }
        }
    }

    //copy move operator
    PpmDocument& operator=(const PpmDocument &other)
    {
        if (this->_pixels != nullptr)
        {
            for (int i = 0; i < _height; i++)
            {
                //remove sub array
                delete[] _pixels[i];
            }

            //remove the outer array
            delete[] _pixels;
        }
        _doc_type = other._doc_type;
        _width = other._width;
        _height = other._height;
        _max_rgb = other._max_rgb;

        //dynamically allocate space for our 2D array
        _pixels = new Pixel*[_height];
        for (int i = 0; i < _height; i++)
        {
            //allocate sub array
            _pixels[i] = new Pixel[_width];
        }
        return *this;
    } 

	//because we've dynamically allocated memory,
	//we need a destructor to delete said memory.
	~PpmDocument()
	{
		for (int i = 0; i < _height; i++)
		{
			//remove sub array
			delete[] _pixels[i];
		}

		//remove the outer array
		delete[] _pixels;
	}

	Pixel &getPixel(int row, int col)
	{
		return _pixels[row][col];
	}

	void setPixel(int row, int col, Pixel p)
	{
		_pixels[row][col] = p;
	}

	int getWidth()
	{
		return _width;
	}

    void setWidth(int w)
    {
        _width = w;
    }

	int getHeight()
	{
		return _height;
	}

    void setHeight(int h)
    {
        _height = h;
    }

    string getDocType()
    {
        return _doc_type;
    }

    void setDocType(string dt)
    {
        _doc_type = dt;
    }

    int getMaxRgb()
    {
        return _max_rgb;
    }

    void setMaxRgb(int rgb)
    {
        _max_rgb = rgb;
    }

    
};