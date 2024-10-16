
import numpy as np
import cv2 as cv

def cv_show(name, img, time):
  cv.imshow(name, img)
  cv.waitKey(time)
  cv.destroyAllWindows()

def quaternion_to_matrix(quat: np.array):
  w, x, y, z = quat
  return np.array([[1 - 2 * (y ** 2 + z ** 2), 2 * (x * y - z * w), 2 * (x * z + y * w)], 
                   [2 * (x * y + z * w), 1 - 2 * (x ** 2 + z ** 2), 2 * (y * z - x * w)], 
                   [2 * (x * z - y * w), 2 * (y * z + x * w), 1 - 2 * (x ** 2 + y ** 2)]])

K = np.array([[400, 0, 190],
              [0, 400, 160],
              [0,   0,   1]])
camera = np.array([2, 2, 2])
rotation = np.array([-0.5, 0.5, 0.5, -0.5])
R = quaternion_to_matrix(rotation)

def print_points(points, size = 2):
  img = np.zeros((1000, 1200, 3), dtype = np.uint8)
  for point in points:
    cv.circle(img, point, size, (255, 255, 0), -1)
  cv.imwrite('photograph/result.jpg', img)
  # cv_show('Projected points', img, 0)
  
points = []
with open('photograph/points.txt', 'r') as f:
  points = [list(map(float, f.readline().strip().split())) 
            for _ in range(int(f.readline().strip()))]

points = [K @ R.T @ (p - camera) for p in points]

print_points([(int(p[0] / p[2]), int(p[1] / p[2])) for p in points if p[2] > 0])
