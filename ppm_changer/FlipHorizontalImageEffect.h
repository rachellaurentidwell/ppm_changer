
/*
Assignment: FlipHorizontalImageEffect.h
Description: This program flips the image horizontally.
Author: Rachel Tidwell
HSU ID: 9492-53949
*/

#pragma once
#include "ImageEffect.h"
#include <vector>

#ifndef FLIP_HORIZONTAL_IMAGE_EFFECT
#define FLIP_HORIZONTAL_IMAGE_EFFECT


class FlipHorizontalImageEffect : public ImageEffect
{
	vector <Pixel> the_vector;  // declaring vector 
	 
    virtual void processImage(PpmDocument &doc)
    {
        for (int i = 0; i < doc.getHeight(); i++)
        {
        	 
			for (int j = 0; j < doc.getWidth(); j++)
            {
            	
                
                the_vector.push_back(doc.getPixel(i,j)); // takes the values of each pixel and puts them into the vector 
                
			    
                
       		}   
                
    	}
		int k = 0; 
		for (int i = 0; i < doc.getHeight(); i++)
        {
        	 
			for (int j = 0; j < doc.getWidth(); j++)
			{
				doc.setPixel(i,(doc.getWidth() - 1 - j),the_vector[k]);
				k++; 
				
			}
	
		}
    }
      
	  
		
};

#endif 
