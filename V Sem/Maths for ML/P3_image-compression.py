#3a - 🍑
import numpy as np
import matplotlib.pyplot as plt
from sklearn.decomposition import PCA
img = plt.imread('D:\College Stuff\lab-programs\V Sem\Maths for ML\data\image(1).png')
img_2d = img.reshape(img.shape[0], img.shape[1] * img.shape[2])
pca = PCA(n_components=200)
img_pca = pca.fit_transform(img_2d)
img_reconstructed = pca.inverse_transform(img_pca)
plt.imshow(img_reconstructed.reshape(img.shape))
plt.title('Reconstructed Image')
plt.savefig('D:\College Stuff\lab-programs\V Sem\Maths for ML\data\P3_output(1).png')
plt.show()