import cv2
import numpy as np

cap = cv2.VideoCapture(0)

while True:
    _, frame = cap.read()

    frame = cv2.GaussianBlur(frame,(5,5), 0)
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    lower_blue = np.array([60,50,50])
    upper_blue = np.array([100,255,255])

    mask = cv2.inRange(hsv, lower_blue, upper_blue)

    res = cv2.bitwise_and(frame, frame, mask=mask)

    contours, hierarchy = cv2.findContours(mask, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

    # cv2.drawContours(frame, contours, -1, (0,255,0), 3)

    for contour in contours:
        if cv2.contourArea(contour) > 100:
            x,y,w,h = cv2.boundingRect(contour)
            cv2.rectangle(frame, (x,y), (x+w, y+h), (255,0,0), 2)

    cv2.imshow("Captured Image", frame)
    cv2.imshow("hsv",hsv)
    cv2.imshow("res", res)
    cv2.imshow("mask", mask)

    if cv2.waitKey(1) & 0xFF == 27:
        break

cv2.destroyAllWindows()