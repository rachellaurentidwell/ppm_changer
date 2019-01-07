/*

Assignment: HighContrastImageEffect.h
Description: This program makes the image high contrast.. 
Author: Rachel Tidwell 
HSU ID: 9492-53949
*/




#pragma once
#include "ImageEffect.h"
#ifndef HIGH_CONTRAST_IMAGE_EFFECT
#define HIGH_CONTRAST_IMAGE_EFFECT 




class HighContrastImageEffect : public ImageEffect
{
    virtual void processImage(PpmDocument &doc)
    {
         for (int i = 0; i < doc.getHeight(); i++)
        {
            for (int j = 0; j < doc.getWidth(); j++)
            {
                Pixel *p = &doc.getPixel(i, j);
               
                
                if(p->getRed() >= 128)
                {
                	p->setRed(255); 
 				}
 				else 
 				{
 					p->setRed(0); 
				}
				
				if(p->getBlue() >= 128)
                {
                	p->setBlue(255); 
 				}
 				else 
 			    {
 					p->setBlue(0); 
				}
				
				if(p->getGreen() >= 128)
                {
                	p->setGreen(255); 
 				}
 				else 
 				{
 					p->setGreen(0); 
				}
            }
        }
    }

};


#endif 
