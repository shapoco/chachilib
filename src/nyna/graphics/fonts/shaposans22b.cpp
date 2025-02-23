#include <stdint.h>

#include "nyna/graphics/tiny_font.hpp"

namespace nyna::graphics::fonts {

using namespace nyna::graphics;

static const uint8_t shaposans22b_data[] = {
    // (BLANK) ' ' (0x20) : index=0, w=6
    0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x0f, 0x0f, 0x0f, // '!' (0x21) : index=0, w=4
    0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0xef, 0x01, 0xef, 0x01, 0xef, 0x01, 0xef, 0x01, 0x8c, 0x01, 0x8c, 0x01, 0xc6, 0x00, 0x00, 0x00, // '"' (0x22) : index=22, w=9
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x9c, 0x03, 0x9c, 0x03, 0x9c, 0x03, 0xff, 0x07, 0xff, 0x07, 0xff, 0x07, 0x9c, 0x03, // '#' (0x23) : index=66, w=11
    0x9c, 0x03, 0xce, 0x01, 0xce, 0x01, 0xff, 0x07, 0xff, 0x07, 0xff, 0x07, 0xce, 0x01, 0xce, 0x01, 
    0xce, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x70, 0x00, 0xfc, 0x01, 0xfe, 0x03, 0x77, 0x07, 0x77, 0x07, 0x77, 0x00, 0x7e, 0x00, // '$' (0x24) : index=110, w=11
    0x7c, 0x00, 0xf0, 0x01, 0xf0, 0x03, 0x70, 0x07, 0x77, 0x07, 0x77, 0x07, 0xfe, 0x03, 0xfc, 0x01, 
    0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x3c, 0x1c, 0x7e, 0x1c, 0xe7, 0x0e, 0xe7, 0x0e, 0xe7, 0x07, 0x7e, 0x07, 0xbc, 0x03, // '%' (0x25) : index=154, w=16
    0x80, 0x03, 0xc0, 0x01, 0xc0, 0x3d, 0xe0, 0x7e, 0xe0, 0xe7, 0x70, 0xe7, 0x70, 0xe7, 0x38, 0x7e, 
    0x38, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x38, 0x00, 0xfe, 0x00, 0xfe, 0x00, 0xef, 0x01, 0xc7, 0x01, 0xef, 0x01, 0xfe, 0x00, // '&' (0x26) : index=198, w=12
    0x7c, 0x00, 0xfc, 0x0c, 0xfe, 0x0f, 0xef, 0x0f, 0xc7, 0x07, 0xc7, 0x07, 0xff, 0x0f, 0xfe, 0x0e, 
    0x7c, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x0f, 0x0f, 0x0f, 0x0f, 0x0c, 0x0c, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ''' (0x27) : index=242, w=4
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x1c, 0x0e, 0x0e, 0x0e, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x0e, 0x0e, // '(' (0x28) : index=264, w=5
    0x0e, 0x1c, 0x00, 0x00, 0x00, 0x00, 
    0x07, 0x0e, 0x0e, 0x0e, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x0e, 0x0e, // ')' (0x29) : index=286, w=5
    0x0e, 0x07, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x70, 0x00, 0x73, 0x06, 0xff, 0x07, 0xff, 0x07, // '*' (0x2a) : index=308, w=11
    0xfc, 0x01, 0x70, 0x00, 0xfc, 0x01, 0xff, 0x07, 0xff, 0x07, 0x73, 0x06, 0x70, 0x00, 0x70, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x70, 0x00, 0x70, 0x00, 0x70, 0x00, // '+' (0x2b) : index=352, w=11
    0xff, 0x07, 0xff, 0x07, 0xff, 0x07, 0x70, 0x00, 0x70, 0x00, 0x70, 0x00, 0x70, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, // ',' (0x2c) : index=396, w=4
    0x0f, 0x0c, 0x0c, 0x06, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // '-' (0x2d) : index=418, w=9
    0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, // '.' (0x2e) : index=462, w=4
    0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0xc0, 0x01, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0x70, 0x00, 0x70, 0x00, 0x70, 0x00, 0x38, 0x00, // '/' (0x2f) : index=484, w=9
    0x38, 0x00, 0x38, 0x00, 0x38, 0x00, 0x1c, 0x00, 0x1c, 0x00, 0x1c, 0x00, 0x0e, 0x00, 0x0e, 0x00, 
    0x0e, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x7c, 0x00, 0xfe, 0x00, 0xfe, 0x00, 0xef, 0x01, 0xc7, 0x01, 0xc7, 0x01, 0xe7, 0x01, // '0' (0x30) : index=528, w=9
    0xf7, 0x01, 0xdf, 0x01, 0xcf, 0x01, 0xc7, 0x01, 0xc7, 0x01, 0xef, 0x01, 0xfe, 0x00, 0xfe, 0x00, 
    0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x70, 0x00, 0x78, 0x00, 0x7c, 0x00, 0x7e, 0x00, 0x74, 0x00, 0x70, 0x00, 0x70, 0x00, // '1' (0x31) : index=572, w=9
    0x70, 0x00, 0x70, 0x00, 0x70, 0x00, 0x70, 0x00, 0x70, 0x00, 0x70, 0x00, 0x70, 0x00, 0x70, 0x00, 
    0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x7c, 0x00, 0xfe, 0x00, 0xff, 0x01, 0xe6, 0x01, 0xc0, 0x01, 0xc0, 0x01, 0xe0, 0x00, // '2' (0x32) : index=616, w=9
    0xf0, 0x00, 0x78, 0x00, 0x3c, 0x00, 0x1e, 0x00, 0x0e, 0x00, 0x0f, 0x00, 0xff, 0x01, 0xff, 0x01, 
    0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0xfe, 0x01, 0xfe, 0x01, 0xfe, 0x01, 0xf0, 0x00, 0x78, 0x00, 0x3c, 0x00, 0x1e, 0x00, // '3' (0x33) : index=660, w=9
    0x7e, 0x00, 0xfe, 0x00, 0xe0, 0x01, 0xc0, 0x01, 0xc0, 0x01, 0xe6, 0x01, 0xff, 0x01, 0xfe, 0x00, 
    0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x1c, 0x00, 0x1c, 0x00, 0x1c, 0x00, 0x0e, 0x00, 0x0e, 0x00, 0xee, 0x00, 0xee, 0x00, // '4' (0x34) : index=704, w=9
    0xe7, 0x00, 0xe7, 0x00, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 
    0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0xfe, 0x01, 0xfe, 0x01, 0xfe, 0x01, 0x0e, 0x00, 0x0e, 0x00, 0x7f, 0x00, 0xff, 0x00, // '5' (0x35) : index=748, w=9
    0xff, 0x01, 0xe7, 0x01, 0xc0, 0x01, 0xc0, 0x01, 0xc0, 0x01, 0xe6, 0x01, 0xff, 0x01, 0xfe, 0x00, 
    0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x3c, 0x00, 0x1c, 0x00, 0x1c, 0x00, 0x1e, 0x00, 0x0e, 0x00, 0x7e, 0x00, 0xff, 0x00, // '6' (0x36) : index=792, w=9
    0xff, 0x01, 0xef, 0x01, 0xc7, 0x01, 0xc7, 0x01, 0xc7, 0x01, 0xef, 0x01, 0xff, 0x01, 0xfe, 0x00, 
    0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xc7, 0x01, 0xe7, 0x01, 0xe0, 0x00, 0xe0, 0x00, // '7' (0x37) : index=836, w=9
    0xf0, 0x00, 0x70, 0x00, 0x70, 0x00, 0x70, 0x00, 0x78, 0x00, 0x38, 0x00, 0x38, 0x00, 0x38, 0x00, 
    0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x7c, 0x00, 0xfe, 0x00, 0xef, 0x01, 0xc7, 0x01, 0xc7, 0x01, 0xef, 0x01, 0xfe, 0x00, // '8' (0x38) : index=880, w=9
    0x7c, 0x00, 0xfe, 0x00, 0xef, 0x01, 0xc7, 0x01, 0xc7, 0x01, 0xc7, 0x01, 0xef, 0x01, 0xfe, 0x00, 
    0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x7c, 0x00, 0xfe, 0x00, 0xff, 0x01, 0xef, 0x01, 0xc7, 0x01, 0xc7, 0x01, 0xc7, 0x01, // '9' (0x39) : index=924, w=9
    0xef, 0x01, 0xff, 0x01, 0xfe, 0x00, 0xfc, 0x00, 0xe0, 0x00, 0xf0, 0x00, 0x70, 0x00, 0x70, 0x00, 
    0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, // ':' (0x3a) : index=968, w=4
    0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0f, // ';' (0x3b) : index=990, w=4
    0x0f, 0x0c, 0x0c, 0x06, 0x00, 0x00, 
    0x00, 0x00, 0x40, 0xe0, 0xf0, 0x78, 0x3c, 0x1e, 0x0f, 0x0f, 0x1e, 0x3c, 0x78, 0xf0, 0xe0, 0x40, // '<' (0x3c) : index=1012, w=8
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, // '=' (0x3d) : index=1034, w=9
    0x00, 0x00, 0x00, 0x00, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x02, 0x07, 0x0f, 0x1e, 0x3c, 0x78, 0xf0, 0xf0, 0x78, 0x3c, 0x1e, 0x0f, 0x07, 0x02, // '>' (0x3e) : index=1078, w=8
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x78, 0x00, 0xfe, 0x01, 0xfe, 0x01, 0xcf, 0x03, 0x87, 0x03, 0x87, 0x03, 0xc0, 0x03, // '?' (0x3f) : index=1100, w=10
    0xe0, 0x01, 0xf0, 0x00, 0x70, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x70, 0x00, 
    0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0xf8, 0x07, 0xfe, 0x1f, 0x0e, 0x1c, 0x07, 0x38, 0xe3, 0x31, 0xf3, 0x33, 0x33, 0x33, // '@' (0x40) : index=1144, w=14
    0x33, 0x33, 0x33, 0x33, 0x33, 0x3b, 0xf3, 0x1f, 0xe3, 0x0c, 0x07, 0x00, 0x0e, 0x10, 0xfe, 0x1f, 
    0xf8, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0xe0, 0x00, 0xf0, 0x01, 0xf0, 0x01, 0xf0, 0x01, 0xb8, 0x03, 0xb8, 0x03, 0xb8, 0x03, // 'A' (0x41) : index=1188, w=13
    0x1c, 0x07, 0x1c, 0x07, 0x1c, 0x07, 0xfe, 0x0f, 0xfe, 0x0f, 0xfe, 0x0f, 0x07, 0x1c, 0x07, 0x1c, 
    0x07, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0xff, 0x00, 0xff, 0x03, 0xff, 0x03, 0x87, 0x07, 0x07, 0x07, 0x87, 0x07, 0xff, 0x03, // 'B' (0x42) : index=1232, w=12
    0xff, 0x01, 0xff, 0x07, 0x07, 0x07, 0x07, 0x0e, 0x07, 0x0e, 0x07, 0x0f, 0xff, 0x07, 0xff, 0x07, 
    0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0xf0, 0x01, 0xfc, 0x07, 0xfe, 0x0f, 0x1e, 0x0e, 0x0f, 0x04, 0x07, 0x00, 0x07, 0x00, // 'C' (0x43) : index=1276, w=12
    0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x0f, 0x04, 0x1e, 0x0e, 0xfe, 0x0f, 0xfc, 0x07, 
    0xf0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0xff, 0x00, 0xff, 0x03, 0xff, 0x07, 0x87, 0x07, 0x07, 0x0f, 0x07, 0x0e, 0x07, 0x0e, // 'D' (0x44) : index=1320, w=12
    0x07, 0x0e, 0x07, 0x0e, 0x07, 0x0e, 0x07, 0x0e, 0x07, 0x0f, 0x87, 0x07, 0xff, 0x07, 0xff, 0x03, 
    0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0xff, 0x03, 0xff, 0x03, 0xff, 0x03, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0xff, 0x01, // 'E' (0x45) : index=1364, w=10
    0xff, 0x01, 0xff, 0x01, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0xff, 0x03, 0xff, 0x03, 
    0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0xff, 0x03, 0xff, 0x03, 0xff, 0x03, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, // 'F' (0x46) : index=1408, w=10
    0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 
    0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0xf0, 0x03, 0xfc, 0x07, 0xfe, 0x0f, 0x1e, 0x0e, 0x0f, 0x04, 0x07, 0x00, 0x07, 0x00, // 'G' (0x47) : index=1452, w=13
    0x87, 0x1f, 0x87, 0x1f, 0x87, 0x1f, 0x07, 0x1c, 0x0f, 0x1c, 0x1e, 0x1e, 0xfe, 0x1f, 0xfc, 0x1f, 
    0xf0, 0x1d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x07, 0x0e, 0x07, 0x0e, 0x07, 0x0e, 0x07, 0x0e, 0x07, 0x0e, 0x07, 0x0e, 0xff, 0x0f, // 'H' (0x48) : index=1496, w=12
    0xff, 0x0f, 0xff, 0x0f, 0x07, 0x0e, 0x07, 0x0e, 0x07, 0x0e, 0x07, 0x0e, 0x07, 0x0e, 0x07, 0x0e, 
    0x07, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x1f, 0x1f, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x1f, // 'I' (0x49) : index=1540, w=5
    0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x0e, 0x00, 0x0e, 0x00, 0x0e, 0x00, 0x0e, 0x00, 0x0e, 0x00, 0x0e, 0x00, 0x0e, // 'J' (0x4a) : index=1562, w=12
    0x00, 0x0e, 0x00, 0x0e, 0x00, 0x0e, 0x00, 0x0e, 0x02, 0x0f, 0x8f, 0x07, 0xff, 0x07, 0xfe, 0x03, 
    0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x07, 0x0e, 0x07, 0x0f, 0x87, 0x07, 0xc7, 0x03, 0xe7, 0x01, 0xf7, 0x00, 0x7f, 0x00, // 'K' (0x4b) : index=1606, w=12
    0x3f, 0x00, 0x3f, 0x00, 0x7f, 0x00, 0xf7, 0x00, 0xe7, 0x01, 0xc7, 0x03, 0x87, 0x07, 0x07, 0x0f, 
    0x07, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, // 'L' (0x4c) : index=1650, w=10
    0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0xff, 0x03, 0xff, 0x03, 
    0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x0f, 0x78, 0x0f, 0x78, 0x1f, 0x7c, 0x1f, 0x7c, 0x3f, 0x7e, 0x3f, 0x7e, 0x7f, 0x7f, // 'M' (0x4d) : index=1694, w=15
    0x77, 0x77, 0xf7, 0x77, 0xe7, 0x73, 0xe7, 0x73, 0xc7, 0x71, 0xc7, 0x71, 0x07, 0x70, 0x07, 0x70, 
    0x07, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x1f, 0x1c, 0x1f, 0x1c, 0x3f, 0x1c, 0x3f, 0x1c, 0x7f, 0x1c, 0x7f, 0x1c, 0xf7, 0x1c, // 'N' (0x4e) : index=1738, w=13
    0xf7, 0x1c, 0xe7, 0x1d, 0xe7, 0x1d, 0xc7, 0x1f, 0xc7, 0x1f, 0x87, 0x1f, 0x87, 0x1f, 0x07, 0x1f, 
    0x07, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0xf0, 0x03, 0xfc, 0x0f, 0xfe, 0x1f, 0x1e, 0x1e, 0x0f, 0x3c, 0x07, 0x38, 0x07, 0x38, // 'O' (0x4f) : index=1782, w=14
    0x07, 0x38, 0x07, 0x38, 0x07, 0x38, 0x07, 0x38, 0x0f, 0x3c, 0x1e, 0x1e, 0xfe, 0x1f, 0xfc, 0x0f, 
    0xf0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0xff, 0x01, 0xff, 0x07, 0xff, 0x07, 0x07, 0x0f, 0x07, 0x0e, 0x07, 0x0e, 0x07, 0x0f, // 'P' (0x50) : index=1826, w=12
    0xff, 0x07, 0xff, 0x07, 0xff, 0x01, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 
    0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0xf0, 0x03, 0xfc, 0x0f, 0xfe, 0x1f, 0x1e, 0x1e, 0x0f, 0x3c, 0x07, 0x38, 0x07, 0x38, // 'Q' (0x51) : index=1870, w=14
    0x07, 0x38, 0xc7, 0x38, 0xe7, 0x39, 0xc7, 0x3b, 0x8f, 0x3f, 0x1e, 0x1f, 0xfe, 0x1f, 0xfc, 0x3f, 
    0xf0, 0x39, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0xff, 0x01, 0xff, 0x07, 0xff, 0x07, 0x07, 0x0f, 0x07, 0x0e, 0x07, 0x0e, 0x07, 0x0f, // 'R' (0x52) : index=1914, w=12
    0xff, 0x07, 0xff, 0x07, 0xff, 0x03, 0x87, 0x03, 0x87, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x0e, 
    0x07, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0xf8, 0x01, 0xfe, 0x07, 0xfe, 0x0f, 0x0f, 0x0e, 0x07, 0x04, 0x0f, 0x00, 0x7e, 0x00, // 'S' (0x53) : index=1958, w=12
    0xfe, 0x01, 0xf8, 0x07, 0xc0, 0x07, 0x00, 0x0f, 0x02, 0x0e, 0x07, 0x0f, 0xff, 0x07, 0xfe, 0x07, 
    0xf8, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0xff, 0x1f, 0xff, 0x1f, 0xff, 0x1f, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, // 'T' (0x54) : index=2002, w=13
    0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 
    0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x07, 0x1c, 0x07, 0x1c, 0x07, 0x1c, 0x07, 0x1c, 0x07, 0x1c, 0x07, 0x1c, 0x07, 0x1c, // 'U' (0x55) : index=2046, w=13
    0x07, 0x1c, 0x07, 0x1c, 0x07, 0x1c, 0x07, 0x1c, 0x0f, 0x1e, 0x1e, 0x0f, 0xfe, 0x0f, 0xfc, 0x07, 
    0xf0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x07, 0x1c, 0x07, 0x1c, 0x07, 0x1c, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x1c, 0x07, // 'V' (0x56) : index=2090, w=13
    0x1c, 0x07, 0x1c, 0x07, 0xb8, 0x03, 0xb8, 0x03, 0xb8, 0x03, 0xf0, 0x01, 0xf0, 0x01, 0xf0, 0x01, 
    0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x07, 0x70, 0x07, 0x70, 0x07, 0x70, 0x07, 0x70, 0xc7, 0x71, 0xce, 0x39, 0xce, 0x39, // 'W' (0x57) : index=2134, w=15
    0xee, 0x3b, 0xee, 0x3b, 0xee, 0x3b, 0x7e, 0x3f, 0x7c, 0x1f, 0x7c, 0x1f, 0x3c, 0x1e, 0x3c, 0x1e, 
    0x3c, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x0f, 0x1e, 0x0e, 0x0e, 0x1e, 0x0f, 0x1c, 0x07, 0xbc, 0x07, 0xb8, 0x03, 0xf8, 0x03, // 'X' (0x58) : index=2178, w=13
    0xf0, 0x01, 0xf0, 0x01, 0xf8, 0x03, 0xb8, 0x03, 0xbc, 0x07, 0x1c, 0x07, 0x1e, 0x0f, 0x0e, 0x0e, 
    0x0f, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x07, 0x1c, 0x0e, 0x0e, 0x0e, 0x0e, 0x1c, 0x07, 0x1c, 0x07, 0xb8, 0x03, 0xb8, 0x03, // 'Y' (0x59) : index=2222, w=13
    0xf0, 0x01, 0xf0, 0x01, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 0xe0, 0x00, 
    0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0xff, 0x0f, 0xff, 0x0f, 0xff, 0x0f, 0x80, 0x07, 0xc0, 0x03, 0xc0, 0x03, 0xe0, 0x01, // 'Z' (0x5a) : index=2266, w=12
    0xf0, 0x00, 0xf0, 0x00, 0x78, 0x00, 0x3c, 0x00, 0x3c, 0x00, 0x1e, 0x00, 0xff, 0x0f, 0xff, 0x0f, 
    0xff, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x1f, 0x1f, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, // '[' (0x5b) : index=2310, w=5
    0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 
    0x07, 0x00, 0x0e, 0x00, 0x0e, 0x00, 0x0e, 0x00, 0x1c, 0x00, 0x1c, 0x00, 0x1c, 0x00, 0x38, 0x00, // '\' (0x5c) : index=2332, w=9
    0x38, 0x00, 0x38, 0x00, 0x38, 0x00, 0x70, 0x00, 0x70, 0x00, 0x70, 0x00, 0xe0, 0x00, 0xe0, 0x00, 
    0xe0, 0x00, 0xc0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x1f, 0x1f, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, // ']' (0x5d) : index=2376, w=5
    0x1f, 0x1f, 0x00, 0x00, 0x00, 0x00, 
    0x18, 0x3c, 0x7e, 0xff, 0xe7, 0xc3, 0x81, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // '^' (0x5e) : index=2398, w=8
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // '_' (0x5f) : index=2420, w=14
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x01, 0xff, 0x01, 
    0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x07, 0x07, 0x0f, 0x0e, 0x1c, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // '`' (0x60) : index=2464, w=5
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x00, 0xfe, 0x01, // 'a' (0x61) : index=2486, w=10
    0xfe, 0x03, 0x82, 0x03, 0xf8, 0x03, 0xfe, 0x03, 0x8e, 0x03, 0x87, 0x03, 0xff, 0x03, 0xfe, 0x03, 
    0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x77, 0x00, 0xff, 0x01, // 'b' (0x62) : index=2530, w=10
    0xff, 0x01, 0xcf, 0x03, 0x87, 0x03, 0x87, 0x03, 0x87, 0x03, 0xcf, 0x03, 0xff, 0x01, 0xff, 0x01, 
    0x77, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0xfe, 0x01, // 'c' (0x63) : index=2574, w=10
    0xfe, 0x03, 0x8f, 0x03, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x8f, 0x03, 0xfe, 0x03, 0xfe, 0x01, 
    0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x80, 0x03, 0x80, 0x03, 0x80, 0x03, 0x80, 0x03, 0x80, 0x03, 0xb8, 0x03, 0xfe, 0x03, // 'd' (0x64) : index=2618, w=10
    0xfe, 0x03, 0xcf, 0x03, 0x87, 0x03, 0x87, 0x03, 0x87, 0x03, 0xcf, 0x03, 0xfe, 0x03, 0xfe, 0x03, 
    0xb8, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x00, 0xfe, 0x03, // 'e' (0x65) : index=2662, w=11
    0xfe, 0x03, 0x8f, 0x07, 0x07, 0x07, 0xff, 0x07, 0xff, 0x07, 0x07, 0x00, 0xfe, 0x03, 0xfe, 0x03, 
    0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x78, 0x7c, 0x7e, 0x0e, 0x0e, 0x7f, 0x7f, 0x7f, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, // 'f' (0x66) : index=2706, w=7
    0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x03, 0xfe, 0x03, // 'g' (0x67) : index=2728, w=10
    0xfe, 0x03, 0xcf, 0x03, 0x87, 0x03, 0x87, 0x03, 0xcf, 0x03, 0xfe, 0x03, 0xfe, 0x03, 0xbc, 0x03, 
    0x80, 0x03, 0xc2, 0x03, 0xfe, 0x01, 0xfe, 0x01, 0x7c, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x77, 0x00, 0xff, 0x01, // 'h' (0x68) : index=2772, w=10
    0xff, 0x01, 0xcf, 0x03, 0x87, 0x03, 0x87, 0x03, 0x87, 0x03, 0x87, 0x03, 0x87, 0x03, 0x87, 0x03, 
    0x87, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x0e, 0x0e, 0x0e, 0x00, 0x00, 0x0f, 0x0f, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, // 'i' (0x69) : index=2816, w=4
    0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x1c, 0x1c, 0x1c, 0x00, 0x00, 0x1e, 0x1e, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, // 'j' (0x6a) : index=2838, w=5
    0x1c, 0x1c, 0x1e, 0x0f, 0x07, 0x00, 
    0x00, 0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0xc7, 0x03, 0xe7, 0x01, // 'k' (0x6b) : index=2860, w=10
    0xf7, 0x00, 0x7f, 0x00, 0x3f, 0x00, 0x1f, 0x00, 0x3f, 0x00, 0x7f, 0x00, 0xf7, 0x00, 0xe7, 0x01, 
    0xc7, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x0f, 0x0f, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, // 'l' (0x6c) : index=2904, w=4
    0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x37, 0x06, 0x7f, 0x0f, // 'm' (0x6d) : index=2926, w=13
    0xff, 0x1f, 0xef, 0x1d, 0xe7, 0x1c, 0xe7, 0x1c, 0xe7, 0x1c, 0xe7, 0x1c, 0xe7, 0x1c, 0xe7, 0x1c, 
    0xe7, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x77, 0x00, 0xff, 0x01, // 'n' (0x6e) : index=2970, w=10
    0xff, 0x01, 0xcf, 0x03, 0x87, 0x03, 0x87, 0x03, 0x87, 0x03, 0x87, 0x03, 0x87, 0x03, 0x87, 0x03, 
    0x87, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x00, 0xfe, 0x03, // 'o' (0x6f) : index=3014, w=11
    0xfe, 0x03, 0x8f, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x8f, 0x07, 0xfe, 0x03, 0xfe, 0x03, 
    0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x77, 0x00, 0xff, 0x01, // 'p' (0x70) : index=3058, w=10
    0xff, 0x01, 0xcf, 0x03, 0x87, 0x03, 0x87, 0x03, 0x87, 0x03, 0xcf, 0x03, 0xff, 0x01, 0xff, 0x01, 
    0x77, 0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb8, 0x03, 0xfe, 0x03, // 'q' (0x71) : index=3102, w=10
    0xfe, 0x03, 0xcf, 0x03, 0x87, 0x03, 0x87, 0x03, 0x87, 0x03, 0xcf, 0x03, 0xfe, 0x03, 0xfe, 0x03, 
    0xb8, 0x03, 0x80, 0x03, 0x80, 0x03, 0x80, 0x03, 0x80, 0x03, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x77, 0x7f, 0x7f, 0x0f, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, // 'r' (0x72) : index=3146, w=7
    0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x01, 0xfe, 0x07, // 's' (0x73) : index=3168, w=11
    0xff, 0x07, 0x07, 0x06, 0x7f, 0x00, 0xfe, 0x03, 0xf0, 0x07, 0x03, 0x07, 0xff, 0x07, 0xff, 0x03, 
    0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x0e, 0x0e, 0x0e, 0x7f, 0x7f, 0x7f, 0x0e, 0x0e, 0x0e, 0x0e, 0x1e, 0x7e, 0x7c, // 't' (0x74) : index=3212, w=7
    0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x87, 0x03, 0x87, 0x03, // 'u' (0x75) : index=3234, w=10
    0x87, 0x03, 0x87, 0x03, 0x87, 0x03, 0x87, 0x03, 0x87, 0x03, 0xcf, 0x03, 0xfe, 0x03, 0xfe, 0x03, 
    0x78, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x07, 0x07, // 'v' (0x76) : index=3278, w=11
    0x8f, 0x07, 0x8e, 0x03, 0xde, 0x03, 0xdc, 0x01, 0xfc, 0x01, 0xf8, 0x00, 0xf8, 0x00, 0x70, 0x00, 
    0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x1c, 0xe7, 0x1c, // 'w' (0x77) : index=3322, w=13
    0xe7, 0x1c, 0xf7, 0x1d, 0xf7, 0x1d, 0xfe, 0x0f, 0xfe, 0x0f, 0xbe, 0x0f, 0xbc, 0x07, 0x1c, 0x07, 
    0x1c, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x8f, 0x07, 0x8e, 0x03, // 'x' (0x78) : index=3366, w=11
    0xde, 0x03, 0xdc, 0x01, 0xfc, 0x01, 0xf8, 0x00, 0xfc, 0x01, 0xdc, 0x01, 0xde, 0x03, 0x8e, 0x03, 
    0x8f, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x07, 0x07, // 'y' (0x79) : index=3410, w=11
    0x8e, 0x03, 0x8e, 0x03, 0x8e, 0x03, 0xdc, 0x01, 0xdc, 0x01, 0xfc, 0x01, 0xf8, 0x00, 0xf8, 0x00, 
    0xf8, 0x00, 0x70, 0x00, 0x7e, 0x00, 0x7e, 0x00, 0x3e, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x03, 0xff, 0x03, // 'z' (0x7a) : index=3454, w=10
    0xff, 0x03, 0xe0, 0x01, 0xf0, 0x00, 0x78, 0x00, 0x3c, 0x00, 0x1e, 0x00, 0xff, 0x03, 0xff, 0x03, 
    0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x3c, 0x3e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0f, 0x07, 0x0f, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, // '{' (0x7b) : index=3498, w=6
    0x3e, 0x3c, 0x00, 0x00, 0x00, 0x00, 
    0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, // '|' (0x7c) : index=3520, w=3
    0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 
    0x0f, 0x1f, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x3c, 0x38, 0x3c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, // '}' (0x7d) : index=3542, w=6
    0x1f, 0x0f, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0xf1, 0x01, // '~' (0x7e) : index=3564, w=9
    0xff, 0x01, 0x1f, 0x01, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
};

static const TinyFontGlyph shaposans22b_index[] = {
    TinyFontGlyph(0, 6, TinyFontGlyph::BLANK), 
    TinyFontGlyph(0, 4), 
    TinyFontGlyph(22, 9), 
    TinyFontGlyph(66, 11), 
    TinyFontGlyph(110, 11), 
    TinyFontGlyph(154, 16), 
    TinyFontGlyph(198, 12), 
    TinyFontGlyph(242, 4), 
    TinyFontGlyph(264, 5), 
    TinyFontGlyph(286, 5), 
    TinyFontGlyph(308, 11), 
    TinyFontGlyph(352, 11), 
    TinyFontGlyph(396, 4), 
    TinyFontGlyph(418, 9), 
    TinyFontGlyph(462, 4), 
    TinyFontGlyph(484, 9), 
    TinyFontGlyph(528, 9), 
    TinyFontGlyph(572, 9), 
    TinyFontGlyph(616, 9), 
    TinyFontGlyph(660, 9), 
    TinyFontGlyph(704, 9), 
    TinyFontGlyph(748, 9), 
    TinyFontGlyph(792, 9), 
    TinyFontGlyph(836, 9), 
    TinyFontGlyph(880, 9), 
    TinyFontGlyph(924, 9), 
    TinyFontGlyph(968, 4), 
    TinyFontGlyph(990, 4), 
    TinyFontGlyph(1012, 8), 
    TinyFontGlyph(1034, 9), 
    TinyFontGlyph(1078, 8), 
    TinyFontGlyph(1100, 10), 
    TinyFontGlyph(1144, 14), 
    TinyFontGlyph(1188, 13), 
    TinyFontGlyph(1232, 12), 
    TinyFontGlyph(1276, 12), 
    TinyFontGlyph(1320, 12), 
    TinyFontGlyph(1364, 10), 
    TinyFontGlyph(1408, 10), 
    TinyFontGlyph(1452, 13), 
    TinyFontGlyph(1496, 12), 
    TinyFontGlyph(1540, 5), 
    TinyFontGlyph(1562, 12), 
    TinyFontGlyph(1606, 12), 
    TinyFontGlyph(1650, 10), 
    TinyFontGlyph(1694, 15), 
    TinyFontGlyph(1738, 13), 
    TinyFontGlyph(1782, 14), 
    TinyFontGlyph(1826, 12), 
    TinyFontGlyph(1870, 14), 
    TinyFontGlyph(1914, 12), 
    TinyFontGlyph(1958, 12), 
    TinyFontGlyph(2002, 13), 
    TinyFontGlyph(2046, 13), 
    TinyFontGlyph(2090, 13), 
    TinyFontGlyph(2134, 15), 
    TinyFontGlyph(2178, 13), 
    TinyFontGlyph(2222, 13), 
    TinyFontGlyph(2266, 12), 
    TinyFontGlyph(2310, 5), 
    TinyFontGlyph(2332, 9), 
    TinyFontGlyph(2376, 5), 
    TinyFontGlyph(2398, 8), 
    TinyFontGlyph(2420, 14), 
    TinyFontGlyph(2464, 5), 
    TinyFontGlyph(2486, 10), 
    TinyFontGlyph(2530, 10), 
    TinyFontGlyph(2574, 10), 
    TinyFontGlyph(2618, 10), 
    TinyFontGlyph(2662, 11), 
    TinyFontGlyph(2706, 7), 
    TinyFontGlyph(2728, 10), 
    TinyFontGlyph(2772, 10), 
    TinyFontGlyph(2816, 4), 
    TinyFontGlyph(2838, 5), 
    TinyFontGlyph(2860, 10), 
    TinyFontGlyph(2904, 4), 
    TinyFontGlyph(2926, 13), 
    TinyFontGlyph(2970, 10), 
    TinyFontGlyph(3014, 11), 
    TinyFontGlyph(3058, 10), 
    TinyFontGlyph(3102, 10), 
    TinyFontGlyph(3146, 7), 
    TinyFontGlyph(3168, 11), 
    TinyFontGlyph(3212, 7), 
    TinyFontGlyph(3234, 10), 
    TinyFontGlyph(3278, 11), 
    TinyFontGlyph(3322, 13), 
    TinyFontGlyph(3366, 11), 
    TinyFontGlyph(3410, 11), 
    TinyFontGlyph(3454, 10), 
    TinyFontGlyph(3498, 6), 
    TinyFontGlyph(3520, 3), 
    TinyFontGlyph(3542, 6), 
    TinyFontGlyph(3564, 9), 
};

TinyFont shaposans22b(22, 32, 95, 2, shaposans22b_data, shaposans22b_index);

}
