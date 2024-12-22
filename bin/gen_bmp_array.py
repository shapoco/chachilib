#!/usr/bin/env python3

from PIL import Image

import sys
import numpy as np

import argparse

LIB_NAMESPCAE = 'nyna::graphics'

parser = argparse.ArgumentParser()
parser.add_argument('-s', '--src', required=True)
parser.add_argument('-n', '--name', required=True)
parser.add_argument('-o', '--outdir')
parser.add_argument('--cpp_outdir')
parser.add_argument('--hpp_outdir')
parser.add_argument('-i', '--incdir', default='nyna/graphics')
parser.add_argument('--out_namespace', default=LIB_NAMESPCAE)
args = parser.parse_args()

cpp_outdir = None
hpp_outdir = None

if args.outdir and (not args.cpp_outdir) and (not args.hpp_outdir):
    cpp_outdir = args.outdir
    hpp_outdir = args.outdir
elif (not args.outdir) and args.cpp_outdir and args.hpp_outdir:
    cpp_outdir = args.cpp_outdir
    hpp_outdir = args.hpp_outdir
else:
    raise Exception('Invalid output directory')

img = Image.open(args.src)
width, height = img.size
img_pixels = np.array([[img.getpixel((x,y)) for x in range(width)] for y in range(height)])

PIXELS_PER_BYTE = 8

stride = (width + PIXELS_PER_BYTE - 1) // PIXELS_PER_BYTE

buff: list[int] = []
for y in range(height):
    byte = 0
    for x in range(width):
        x_fine = x % PIXELS_PER_BYTE
        if x_fine == 0:
            byte = 0
        pixel = img_pixels[y, x]
        gray = (pixel[0] + pixel[1] + pixel[2]) / 3
        if gray >= 128:
            byte |= 1 << x_fine
        if x_fine == PIXELS_PER_BYTE - 1 or x == width - 1:
            buff.append(byte)

data_array_name = f'{args.name}_data'

index = 0
with open(f'{cpp_outdir}/{args.name}.cpp', 'w') as f:
    f.write('#include <stdint.h>\n\n')
    f.write(f'#include "{args.incdir}/bitmap1bpp.hpp"\n\n')
    f.write(f'namespace {args.out_namespace} {{\n\n')
    if args.out_namespace != LIB_NAMESPCAE:
        f.write(f'using namespace {LIB_NAMESPCAE};\n\n')
    f.write(f'static const uint8_t {data_array_name}[] = {{\n')
    
    sub_index = 0
    for byte in buff:
        if (sub_index % 16 == 0):
            f.write('    ')
        f.write('0x%02x, ' % byte)
        if ((sub_index + 1) % 16 == 0) or (sub_index + 1 == len(buff)):
            f.write('\n')
        sub_index += 1
        index += 1

    f.write('};\n\n')
    
    f.write(f'Bitmap1bpp {args.name}({width}, {height}, {stride}, (uint8_t *){data_array_name});\n\n')
    
    f.write('}\n')

with open(f'{hpp_outdir}/{args.name}.hpp', 'w') as f:
    f.write(f'#pragma once\n')
    f.write('\n')
    f.write(f'#include "{args.incdir}/bitmap1bpp.hpp"\n\n')
    f.write(f'namespace {args.out_namespace} {{\n\n')
    f.write(f'extern {LIB_NAMESPCAE}::Bitmap1bpp {args.name};\n\n')
    f.write('}\n')
