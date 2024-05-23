# -*- coding: utf-8 -*-
"""
Created on Mon Oct 21 12:01:00 2019

@author: javier.morales.escud
"""

import cv2 as cv
flags = [i for i in dir(cv) if i.startswith('COLOR_')]
print( flags )