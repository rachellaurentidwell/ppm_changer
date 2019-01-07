
/*

Assignment: GrayscaleImageEffect.h 
Description: This program makes the image black and white  
Author: Rachel Tidwell 
HSU ID: 9492-53949
*/

#pragma once
#include "ImageEffect.h"
#ifndef GRAYSCALE_EFFECT
#define GRAYSCALE_EFFECT 



class GrayscaleImageEffect : public ImageEffect
{
    virtual void processImage(PpmDocument &doc)
    {
         for (int i = 0; i < doc.getHeight(); i++)
        {
            for (int j = 0; j < doc.getWidth(); j++)
            {
                Pixel *p = &doc.getPixel(i, j);
                
                int total_color; 
                float avg_color; 
                
                total_color = p->getRed() + p->getBlue() + p->getGreen(); 
                avg_color = total_color/3; 
                
                p->setRed(avg_color); 
                p->setBlue(avg_color);
                p->setGreen(avg_color); 
                
                
            }
        }
    }

};


#endif 
