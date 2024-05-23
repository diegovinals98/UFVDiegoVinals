# -*- coding: utf-8 -*-
"""
Created on Mon Oct 21 12:02:09 2019

@author: javier.morales.escud
"""
import numpy as np
import cv2 as cv

color = np.uint8([[[34,132,125 ]]])
hsv_color = cv.cvtColor(color,cv.COLOR_BGR2HSV)
print( hsv_color )