
import numpy as np
import cv2 as cv

def cv_show(name, img, time):
  cv.imshow(name, img)
  cv.waitKey(time)
  cv.destroyAllWindows()
  
img = cv.imread('apple/apple.png')
hsv_img = cv.cvtColor(img, cv.COLOR_BGR2HSV)

hsv_red_lower = cv.inRange(hsv_img, np.array([0, 90, 46]), np.array([23, 255, 255]))
hsv_red_upper = cv.inRange(hsv_img, np.array([156, 43, 56]), np.array([180, 255, 255]))
hsv_red = hsv_red_lower + hsv_red_upper
# cv_show('hsv red', hsv_red, 0)

res = cv.morphologyEx(hsv_red, cv.MORPH_ERODE, np.ones((3, 3), np.uint8))
res = cv.morphologyEx(res, cv.MORPH_OPEN, np.ones((25, 25), np.uint8))
res = cv.morphologyEx(res, cv.MORPH_CLOSE, np.ones((25, 25), np.uint8))
res = cv.morphologyEx(res, cv.MORPH_ERODE, np.ones((20, 20), np.uint8))
res = cv.morphologyEx(res, cv.MORPH_DILATE, np.ones((20, 20), np.uint8))

# cv_show('res', res, 0)

contours, hierarchy = cv.findContours(res, cv.RETR_TREE, cv.CHAIN_APPROX_SIMPLE)
bound_rect = cv.boundingRect(cv.Mat(contours[0]))

cv.rectangle(img, bound_rect, (255, 255, 255), 2)
cv_show("Result", img, 0)
cv.imwrite('apple/apple_output.png', img)
