
import numpy as np 
import cv2
cap = cv2.VideoCapture(0)

while(True):
    # Capture frame-by-frame
    ret, frame = cap.read()
    # Our operations on the frame come here
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY) 
    edges = cv2.Canny(gray,100,200)
# Display the resulting frame
    cv2.imshow('original', frame) 
    cv2.imshow('gray', gray) 
    cv2.imshow('edges', edges)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()

