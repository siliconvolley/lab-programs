import cv2

IMAGE_PATH = "./images/deeplink.jpg"

image = cv2.imread(IMAGE_PATH)

cv2.imshow("DeepLink FTW", image)

height, width, channels = image.shape

top_left = image[:height//2, : width//2]
top_right = image[: height//2, width//2:]
bottom_left = image[height//2:, : width//2]
bottom_right = image[height//2:, width//2:]

cv2.imshow("Top Left", top_left)
cv2.imshow("Top Right", top_right)
cv2.imshow("Bottom Left", bottom_left)
cv2.imshow("Bottom Right", bottom_right)

rotated_image = cv2.rotate(image, cv2.ROTATE_90_CLOCKWISE)

top_left_rotated = cv2.rotate(top_left, cv2.ROTATE_90_CLOCKWISE)
top_right_rotated = cv2.rotate(top_right, cv2.ROTATE_90_CLOCKWISE)
bottom_left_rotated = cv2.rotate(bottom_left, cv2.ROTATE_90_CLOCKWISE)
bottom_right_rotated = cv2.rotate(bottom_right, cv2.ROTATE_90_CLOCKWISE)

cv2.imshow("Image", rotated_image)

cv2.imshow("Top Left Rotated", top_left_rotated)
cv2.imshow("Top Right Rotated", top_right_rotated)
cv2.imshow("Bottom Left Rotated", bottom_left_rotated)
cv2.imshow("Bottom Right Rotated", bottom_right_rotated)

cv2.waitKey(0) # keeps the python kernal from crashing
