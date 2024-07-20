import os
import cv2
import numpy as np


img1 = cv2.imread('robo.jpg')
img2 = cv2.imread('OpenCV_logo_no_text.png')

assert img1 is not None, "File could not be loaded check with os.path.exists()"
assert img2 is not None, "File could not be loaded check with os.path.exists()"

img2 = cv2.resize(img2,(img1.shape[1], img1.shape[0]),interpolation = cv2.INTER_LINEAR)

rows,cols,channels = img2.shape


window_name = 'Arithmetic Operations'

output_image = cv2.addWeighted(img1, 0.3, img2, 0.8,0)

output_image = cv2.copyMakeBorder(output_image, 20,20,20,20, cv2.BORDER_CONSTANT, value=(0,0,255))

cv2.namedWindow(window_name, cv2.WINDOW_NORMAL)
cv2.imshow(window_name, output_image)
cv2.waitKey(0)