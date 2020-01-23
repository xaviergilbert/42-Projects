from PIL import Image
import numpy as np
from matplotlib import pyplot as PLT

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
        # self.f.show()
        PLT.imshow(array)
        PLT.show()

class ScrapBooker:

    def crop(self, array, dimensions, position = (0, 0)):
        """
            crop the image as a rectangle with the given dimensions 
            (meaning, the new height and width for the image), 
            whose top left corner is given by the position argument. 
            The position should be (0,0) by default. 
            You have to consider it an error (and handle said error) 
            if dimensions is larger than the current image size.
        """
        if dimensions[0] > array.shape[0] or dimensions[1] > array.shape[1]:
            print(error)
            exit()
        img = array[position[0]:dimensions[0] + position[0],position[1]:dimensions[1] + position[1]]
        return img

    def thin(self, array, n, axis):
        """
            delete every n-th pixel row along the specified axis (0 vertical, 1 horizontal), example below.
        """
        obj = 0
        count = 0
        while obj < array.shape[axis]:
            if (obj + count + 1) % n == 0:
                array = np.delete(array, obj, axis)
                count += 1
            obj += 1
        return array

    def juxtapose(self, array, n, axis):
        """
            juxtapose n copies of the image along the specified axis (0 vertical, 1 horizontal).
        """
        arr = array
        while n - 1 > 0:
            array = np.concatenate((array, arr), axis)
            n -= 1
        return array

    def mosaic(self, array, dimensions):
        """
            make a grid with multiple copies of the array. 
            The dimensions argument specifies the dimensions (meaning the height and width) of the grid (e.g. 2x3).
        """
        array = self.juxtapose(array, dimensions[0], 0)
        array = self.juxtapose(array, dimensions[1], 1)
        return array

if __name__ == "__main__":
    imp = ImageProcessor()
    arr = imp.load("../ex01/42AI.png")
    # imp.display(arr)
    
    img = ScrapBooker()
    # img = img.crop(arr, (50, 50), (50, 50))
    # imp = ImageProcessor()
    # imp.display(img)

    # img = img.thin(arr, 3, 0)
    # imp = ImageProcessor()
    # imp.display(img)

    # img = img.juxtapose(arr, 3, 1)
    # imp = ImageProcessor()
    # imp.display(img)

    img = img.mosaic(arr, (3, 2))
    imp = ImageProcessor()
    imp.display(img)