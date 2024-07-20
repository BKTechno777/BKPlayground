import numpy as np
import cv2

# Global variables
window_name = 'TrackBar'

def nothing(x):
    pass

img = np.zeros((640,480,3), dtype=np.uint8)
cv2.namedWindow(window_name, cv2.WINDOW_AUTOSIZE)

cv2.createTrackbar('R',window_name,0,255,nothing)
cv2.createTrackbar('G',window_name,0,255,nothing)
cv2.createTrackbar('B',window_name,0,255,nothing)


switch = '0 : OFF \n1 : ON'
cv2.createTrackbar(switch, window_name,0,1,nothing)

while True:
    cv2.imshow(window_name, img)
    if cv2.waitKey(1) & 0xFF == 27:
        break

    r = cv2.getTrackbarPos('R', window_name)
    g = cv2.getTrackbarPos('G', window_name)
    b = cv2.getTrackbarPos('B', window_name)
    s = cv2.getTrackbarPos(switch, window_name)

    if s == 0:
        img[:] = [0,0,0]
    else:
        img[:] = [b,g,r]

cv2.destroyAllWindows()