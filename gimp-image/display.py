import Image
import numpy as np
import time

im = Image.open('gimp-image.png')
im = im.convert('RGBA')

data = np.array(im)   # "data" is a height x width x 4 numpy array
red, green, blue, alpha = data.T # Temporarily unpack the bands for readability

# Replace white with red... (leaves alpha values alone...)
white_areas = (red == 255) & (blue == 255) & (green == 255)
data[..., :-1][white_areas] = (255, 0, 0)

im2 = Image.fromarray(data)
im2.show()
im2.rotate(90).show()
