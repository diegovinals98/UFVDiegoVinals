
import cv2
import numpy as np

img = cv2.imread("images/lena.png") 

height = img.shape[0] 
width = img.shape[1] 
channels = img.shape[2]
res = cv2.resize(img,(2*width, 2*height), interpolation = cv2.INTER_CUBIC)

cv2.imshow('img', img) 
cv2.imshow('res', res) 
cv2.waitKey(0) 
cv2.destroyAllWindows()