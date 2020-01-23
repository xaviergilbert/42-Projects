from PIL import Image
import numpy as np

class ImageProcessor:
    # def __init__(self, image):
    #     self.image = image

    def load(self, path):
        """
            opens the .png file specified by the path argument and returns an array with the RGB values of the image pixels.
            It must display a message specifying the dimensions of the image (e.g. 340 x 500).
        """
        self.f = Image.open(path)
        array = np.array(self.f)
        print("The dimension of the image are : ", array.shape[0], "*", array.shape[1])
        return array
    
    def display(self, array):
        """
            takes a NumPy array as an argument and displays the corresponding RGB image.
        """
        self.f.show()

if __name__ == "__main__":
    imp = ImageProcessor()
    arr = imp.load("42AI.png")
    print(arr)
    imp.display(arr)