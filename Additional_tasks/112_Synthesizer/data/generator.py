import os
import wave
import struct

import math


def func(x, a=1, b=1, c=0, d=0):
    return a * math.sin(b * x + c) + d


# Audio duration = 0.45
# nchannels=1, sampwidth=2, framerate=44100, nframes=139392, comptype='NONE', compname='not compressed'
# b [0.1 : 1.5]

def main():
    for j in [1, 5, 10, 15]:
        for i in range(1, 15):
            b = i / 10
            file_name = f"data_{j}_{i}.wav"

            out = wave.open(file_name, mode="wb")
            out.setparams([1, 2, 44100, 139392, 'NONE', 'not compressed'])
            newdata = [int(round(func(x, a=j, b=b) * 1000)) for x in range(20_000)]
            newframes = struct.pack("<" + str(len(newdata)) + "h", *newdata)
            # записываем содержимое в преобразованный файл.
            out.writeframes(newframes)
            # source.close()
            out.close()
            os.system(f"aplay {file_name}")


if __name__ == '__main__':
    main()
