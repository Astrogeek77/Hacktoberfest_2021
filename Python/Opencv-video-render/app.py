import cv2

import numpy as np


cap = cv2.VideoCapture('https://www.w3schools.com/html/mov_bbb.mp4')

while(cap.isOpened()):
    ret, frame = cap.read()
    if ret == True:
        cv2.imshow('video', frame)
        if cv2.waitKey(25) & 0xFF == ord('q'):
            break
    else:
        break

cap.release()

cv2.destroyAllWindows()