/*

Assignment: FlipVerticalImageEffect.h 
Description: This program flips the image vertically. 
Author: Rachel Tidwell 
HSU ID: 9492-53949
*/


#pragma once
#include "ImageEffect.h"
#include <vector>

#ifndef FLIP_VERTICAL_IMAGE_EFFECT
#define FLIP_VERTICAL_IMAGE_EFFECT


class FlipVerticalImageEffect : public ImageEffect
{
	vector <Pixel> the_vector;  
	 
    virtual void processImage(PpmDocument &doc)
    {
        for (int i = 0; i < doc.getHeight(); i++)
        {
        	 
			for (int j = 0; j < doc.getWidth(); j++)
            {
            	the_vector.push_back(doc.getPixel(i,j)); 
            }   
                
    	}
		int k = 0; 
		for (int i = 0; i < doc.getHeight(); i++)
        {
        	 
			for (int j = 0; j < doc.getWidth(); j++)
			{
				doc.setPixel((doc.getHeight() - 1 - i), j, the_vector[k]);
				k++; 
			}
	
		}
    }
      
	  
};

#endif 
