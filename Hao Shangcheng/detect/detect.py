
import numpy as np
import cv2 as cv

def cv_show(name, img, time):
  cv.imshow(name, img)
  cv.waitKey(time)
  cv.destroyAllWindows()
  
video = cv.VideoCapture('detect/armor.mp4')

width = int(video.get(cv.CAP_PROP_FRAME_WIDTH))
height = int(video.get(cv.CAP_PROP_FRAME_HEIGHT))
fps = video.get(cv.CAP_PROP_FPS)

# print("width = {}, height = {}".format(width, height))

fourcc = cv.VideoWriter.fourcc(*'MJPG')
writer = cv.VideoWriter('detect/detect_output.avi', fourcc, fps, (width, height), True)

while True:
  has, img = video.read()
  if has == False:
    break
  gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
  thresh, mask = cv.threshold(gray, 150, 255, cv.THRESH_BINARY)
  # cv_show("mask", mask, 0)
  
  contours, hierarchy = cv.findContours(mask, cv.RETR_EXTERNAL, cv.CHAIN_APPROX_SIMPLE)
  valid = []
  for contour in contours:
    rect = cv.boundingRect(contour)
    [x, y, w, h] = rect
    if h > 1.8 * w:
      valid.append(rect)
      # cv.rectangle(img, rect, (0, 0, 255), 2)
  
  for i, vi in enumerate(valid):
    for j, vj in enumerate(valid):
      if i < j:
        if abs(vi[0] - vj[0]) < 3 * abs(vi[3]) and abs(vi[1] - vj[1]) < 0.5 * abs(vi[3]):
          
          x_min = min(vi[0], vj[0])
          y_min = min(vi[1], vj[1])
          x_max = max(vi[0] + vi[2], vj[0] + vj[2])
          y_max = max(vi[1] + vi[3], vj[1] + vj[3])
          box = (x_min, y_min, x_max - x_min, y_max - y_min)
          
          # print('x: {}, {}; y: {}, {}'.format(x_min, x_max, y_min, y_max))
          
          cv.rectangle(img, box, (0, 255, 0), 2)
          cv.line(img, (box[0], box[1]), (box[0] + box[2], box[3] + box[1]), (255, 0, 0), 2)
          cv.line(img, (box[0] + box[2], box[1]), (box[0], box[3] + box[1]), (255, 0, 0), 2)
          mid_point = (box[0] + box[2] // 2, box[1] + box[3] // 2)
          cv.circle(img, mid_point, 5, (0, 0, 255), -1)
          
  writer.write(img)
  # cv_show("Proccess Frame", img, 0)

video.release()
writer.release()
cv.destroyAllWindows()
