
import numpy as np
import cv2 as cv
import matplotlib.pyplot as plt
import random

def cv_show(name, img, time):
  cv.imshow(name, img)
  cv.waitKey(time)
  cv.destroyAllWindows()

def quaternion_to_matrix(quat: np.array):
  w, x, y, z = quat
  return np.array([[1 - 2 * (y ** 2 + z ** 2), 2 * (x * y - z * w), 2 * (x * z + y * w)], 
                   [2 * (x * y + z * w), 1 - 2 * (x ** 2 + z ** 2), 2 * (y * z - x * w)], 
                   [2 * (x * z - y * w), 2 * (y * z + x * w), 1 - 2 * (x ** 2 + y ** 2)]])

logo = cv.imread('logo/logo.jpg')
height, width = logo.shape[0], logo.shape[1]
hsv_img = cv.cvtColor(logo, cv.COLOR_BGR2HSV)
hsv_cyan = cv.inRange(hsv_img, np.array([78, 43, 46]), np.array([99, 255, 255]))
hsv_cyan = cv.morphologyEx(hsv_cyan, cv.MORPH_CLOSE, np.ones((5, 5), np.uint8))
hsv_cyan = cv.morphologyEx(hsv_cyan, cv.MORPH_OPEN, np.ones((6, 6), np.uint8))
# cv_show('hsv_cyan', hsv_cyan, 0)

contours, hierarchy = cv.findContours(hsv_cyan, cv.RETR_TREE, cv.CHAIN_APPROX_SIMPLE)
bound_rect = cv.boundingRect(cv.Mat(contours[0]))

N, tps, fps, D = 15000, 200, 30, 1
points, depth = [], []
for i in range(N):
  ci = random.randint(0, len(contours) - 1)
  cj = random.randint(0, len(contours[ci]) - 1)
  points.append(contours[ci][cj] + [random.randint(-D, D), random.randint(-D, D)])
  depth.append(np.array([random.randint(0, width), random.randint(0, height)]))

fourcc = cv.VideoWriter.fourcc(*'MJPG')
writer = cv.VideoWriter('logo/logo_output.avi', fourcc, fps, (width, height), True)

for t in range(tps):
  frame = np.zeros((height, width), np.uint8)
  theta = t / tps
  for point, dep in zip(points, depth):
    cur = (1 - theta) * dep + theta * point
    x, y = map(int, cur[0])
    if x >= 0 and x < width and y >= 0 and y < height:
      frame[y][x] = 255

  frame = cv.cvtColor(frame, cv.COLOR_GRAY2BGR)
  writer.write(frame)
  if t == tps - 1:
    seconds = 1
    for j in range(fps):
      writer.write(frame)
  # cv_show('frame', frame, 0)

writer.release()
cv.destroyAllWindows()
