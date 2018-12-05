
import os

# import faceswap
# python faceswap.py convert -i C:\Users\kyu\Desktop\deepfake\DataA\model1 -o
# C:\Users\kyu\Desktop\deepfake\DataA -m C:\Users\kyu\Desktop\deepfake\model -mh  -b 10
#

os.system("cd C:/Users/kyu/Desktop/deepfake && python faceswap.py convert -i C:/Users/kyu/Desktop/deepfake/DataA/model1 -o C:/Users/kyu/Desktop/deepfake/result -m C:/Users/kyu/Desktop/deepfake/model -S -e 10 -sh gsharpen")

import imagetovideo
