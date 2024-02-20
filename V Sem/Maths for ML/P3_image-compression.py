import cv2
import numpy as np

def compress_and_save_image(image_path, num_components, output_path, jpeg_quality=80):
    image = cv2.imread(image_path)

    h, w, _ = image.shape
    flattened_image = image.reshape((h * w, 3)).astype(np.float32)

    mean, eigenvectors = cv2.PCACompute(flattened_image, mean=None, maxComponents=num_components)

    compressed_image = cv2.PCAProject(flattened_image, mean, eigenvectors[:, :num_components])

    reconstructed_image = cv2.PCABackProject(compressed_image, mean, eigenvectors[:, :num_components])
    reconstructed_image = reconstructed_image.reshape((h, w, 3)).astype(np.uint8)

    cv2.imwrite(output_path, reconstructed_image, [int(cv2.IMWRITE_JPEG_QUALITY), jpeg_quality])

    print(f"Compressed image saved at: {output_path}")
if __name__ == "__main__":
    image_path = "./data/image.jpg"
    num_components = 3
    output_path = "./data/P3_compressed-image.jpg"
    jpeg_quality = 20

    compress_and_save_image(image_path, num_components, output_path, jpeg_quality)
