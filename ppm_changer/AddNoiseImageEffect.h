/*

Assignment: AddNoiseImageEffect.h 
Description: This program adds random noise to the picture. 
Author: Rachel Tidwell 
HSU ID: 9492-53949
*/


#pragma once
#include "ImageEffect.h"
#ifndef ADD_NOISE_IMAGE_EFFECT
#define ADD_NOISE_IMAGE_EFFECT 



class AddNoiseImageEffect : public ImageEffect
{
    virtual void processImage(PpmDocument &doc)
    {
         for (int i = 0; i < doc.getHeight(); i++)
        {
            for (int j = 0; j < doc.getWidth(); j++)
            {
                Pixel *p = &doc.getPixel(i, j);
                int pixel_random; 
                
                pixel_random = rand() % 21 + -10; 
                
			
				p->setRed(pixel_random + p->getRed());
				p->setBlue(pixel_random + p ->getBlue());
				p->setGreen(pixel_random + p->getGreen());
			
				if(p->getRed() < 0)
				{
					p->setRed(0); 
				};
				if(p->getRed() > 255)
				{
					p->setRed(255);
				};
			
				if(p->getBlue() < 0)
				{
					p->setBlue(0); 
				};
				if(p->getBlue() > 255)
				{
					p->setBlue(255);
				};
			
				if(p->getGreen() < 0)
				{
					p->setGreen(0); 
				};
				if(p->getGreen() > 255)
				{
					p->setGreen(255);
				};
            }
        }
    }

};



#endif 




