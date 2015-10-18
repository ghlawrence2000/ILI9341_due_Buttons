/*
 *
 * UTFT_SmallFont Converted to GLCD format by GHLawrence2000
 *
 *
 * File Name           : SmallFont.h
 * Date                : 12 Oct 2015
 * Font size in bytes  : 1146
 * Font width          : 8
 * Font height         : 12
 * Font first char     : 32
 * Font last char      : 127
 * Font used chars     : 95
 *
 * The font data are defined as
 *
 * struct _FONT_ {
 *     uint16_t   font_Size_in_Bytes_over_all_included_Size_it_self;
 *     uint8_t    font_Width_in_Pixel_for_fixed_drawing;
 *     uint8_t    font_Height_in_Pixel_for_all_characters;
 *     unit8_t    font_First_Char;
 *     uint8_t    font_Char_Count;
 *
 *     uint8_t    font_Char_Widths[font_Last_Char - font_First_Char +1];
 *                  // for each character the separate width in pixels,
 *                  // characters < 128 have an implicit virtual right empty row
 *
 *     uint8_t    font_data[];
 *                  // bit field of all characters
 */

#include <inttypes.h>
#include <avr/pgmspace.h>

#ifndef SmallFont_H
#define SmallFont_H

#define SmallFont_WIDTH 8
#define SmallFont_HEIGHT 11

/*
 * added to allow fontname to match header file name. 
 * as well as keep the old name for backward compability
 */

//#define SystemFont5x7 System5x7

static const uint8_t SmallFont[] PROGMEM= {
    0x0, 0x0, // size of zero indicates fixed width font, actual length is width * height
    0x08, // width
    0x0F, // height
    0x20, // first char
    0x5F, // char count
    
    // Fixed width; char width table not used !!!!
    
    // font data
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // <space>
0x00,0x00,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00, // !
0x00,0x0C,0x02,0x0C,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // "
0x90,0xD0,0xBC,0xD0,0xBC,0x90,0x00,0x00,0x00,0x03,0x00,0x03,0x00,0x00,0x00,0x00, // #
0x18,0x24,0xFE,0x44,0x8C,0x00,0x00,0x00,0x03,0x02,0x07,0x02,0x01,0x00,0x00,0x00, // $
0x18,0x24,0xD8,0xB0,0x4C,0x80,0x00,0x00,0x00,0x03,0x00,0x01,0x02,0x01,0x00,0x00, // %
0xC0,0x38,0xE4,0x38,0xE0,0x00,0x00,0x00,0x01,0x02,0x02,0x01,0x02,0x02,0x00,0x00, // &
0x08,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // '
0x00,0x00,0x00,0xF8,0x04,0x02,0x00,0x00,0x00,0x00,0x00,0x01,0x02,0x04,0x00,0x00, // (
0x00,0x02,0x04,0xF8,0x00,0x00,0x00,0x00,0x00,0x04,0x02,0x01,0x00,0x00,0x00,0x00, // )
0x90,0x60,0xF8,0x60,0x90,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00, // *
0x20,0x20,0xFC,0x20,0x20,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00, // +
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x06,0x00,0x00,0x00,0x00,0x00,0x00, // ,
0x20,0x20,0x20,0x20,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // -
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00, // .
0x00,0x80,0x60,0x1C,0x02,0x00,0x00,0x00,0x04,0x03,0x00,0x00,0x00,0x00,0x00,0x00, // /
0xF8,0x04,0x04,0x04,0xF8,0x00,0x00,0x00,0x01,0x02,0x02,0x02,0x01,0x00,0x00,0x00, // 0
0x00,0x08,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x03,0x02,0x00,0x00,0x00,0x00, // 1
0x18,0x84,0x44,0x24,0x18,0x00,0x00,0x00,0x03,0x02,0x02,0x02,0x02,0x00,0x00,0x00, // 2
0x08,0x04,0x24,0x24,0xD8,0x00,0x00,0x00,0x01,0x02,0x02,0x02,0x01,0x00,0x00,0x00, // 3
0x40,0xB0,0x88,0xFC,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x02,0x00,0x00,0x00, // 4
0x3C,0x24,0x24,0x24,0xC4,0x00,0x00,0x00,0x01,0x02,0x02,0x02,0x01,0x00,0x00,0x00, // 5
0xF8,0x24,0x24,0x2C,0xC0,0x00,0x00,0x00,0x01,0x02,0x02,0x02,0x01,0x00,0x00,0x00, // 6
0x0C,0x04,0xE4,0x1C,0x04,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x00, // 7
0xD8,0x24,0x24,0x24,0xD8,0x00,0x00,0x00,0x01,0x02,0x02,0x02,0x01,0x00,0x00,0x00, // 8
0x38,0x44,0x44,0x44,0xF8,0x00,0x00,0x00,0x00,0x03,0x02,0x02,0x01,0x00,0x00,0x00, // 9
0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00, // :
0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x00,0x00,0x00,0x00,0x00, // ;
0x00,0x20,0x50,0x88,0x04,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x02,0x00,0x00, // <
0x90,0x90,0x90,0x90,0x90,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // =
0x00,0x02,0x04,0x88,0x50,0x20,0x00,0x00,0x00,0x02,0x01,0x00,0x00,0x00,0x00,0x00, // >
0x18,0x04,0xC4,0x24,0x18,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00, // ?
0xF8,0x04,0xE4,0x94,0xF8,0x00,0x00,0x00,0x01,0x02,0x02,0x02,0x02,0x00,0x00,0x00, // @
0x00,0xE0,0x9C,0xF0,0x80,0x00,0x00,0x00,0x02,0x03,0x00,0x00,0x03,0x02,0x00,0x00, // A
0x04,0xFC,0x24,0x24,0xD8,0x00,0x00,0x00,0x02,0x03,0x02,0x02,0x01,0x00,0x00,0x00, // B
0xF8,0x04,0x04,0x04,0x0C,0x00,0x00,0x00,0x01,0x02,0x02,0x02,0x01,0x00,0x00,0x00, // C
0x04,0xFC,0x04,0x04,0xF8,0x00,0x00,0x00,0x02,0x03,0x02,0x02,0x01,0x00,0x00,0x00, // D
0x04,0xFC,0x24,0x74,0x0C,0x00,0x00,0x00,0x02,0x03,0x02,0x02,0x03,0x00,0x00,0x00, // E
0x04,0xFC,0x24,0x74,0x0C,0x00,0x00,0x00,0x02,0x03,0x02,0x00,0x00,0x00,0x00,0x00, // F
0xF0,0x08,0x04,0x44,0xCC,0x40,0x00,0x00,0x00,0x01,0x02,0x02,0x01,0x00,0x00,0x00, // G
0x04,0xFC,0x20,0x20,0xFC,0x04,0x00,0x00,0x02,0x03,0x00,0x00,0x03,0x02,0x00,0x00, // H
0x04,0x04,0xFC,0x04,0x04,0x00,0x00,0x00,0x02,0x02,0x03,0x02,0x02,0x00,0x00,0x00, // I
0x00,0x04,0x04,0xFC,0x04,0x04,0x00,0x00,0x06,0x04,0x04,0x03,0x00,0x00,0x00,0x00, // J
0x04,0xFC,0x24,0xD0,0x0C,0x04,0x00,0x00,0x02,0x03,0x02,0x00,0x03,0x02,0x00,0x00, // K
0x04,0xFC,0x04,0x00,0x00,0x00,0x00,0x00,0x02,0x03,0x02,0x02,0x02,0x03,0x00,0x00, // L
0xFC,0x3C,0xC0,0x3C,0xFC,0x00,0x00,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x00,0x00, // M
0x04,0xFC,0x30,0xC4,0xFC,0x04,0x00,0x00,0x02,0x03,0x02,0x00,0x03,0x00,0x00,0x00, // N
0xF8,0x04,0x04,0x04,0xF8,0x00,0x00,0x00,0x01,0x02,0x02,0x02,0x01,0x00,0x00,0x00, // O
0x04,0xFC,0x24,0x24,0x18,0x00,0x00,0x00,0x02,0x03,0x02,0x00,0x00,0x00,0x00,0x00, // P
0xF8,0x84,0x84,0x04,0xF8,0x00,0x00,0x00,0x01,0x02,0x02,0x07,0x05,0x00,0x00,0x00, // Q
0x04,0xFC,0x24,0x64,0x98,0x00,0x00,0x00,0x02,0x03,0x02,0x00,0x03,0x02,0x00,0x00, // R
0x18,0x24,0x24,0x44,0x8C,0x00,0x00,0x00,0x03,0x02,0x02,0x02,0x01,0x00,0x00,0x00, // S
0x0C,0x04,0xFC,0x04,0x0C,0x00,0x00,0x00,0x00,0x02,0x03,0x02,0x00,0x00,0x00,0x00, // T
0x04,0xFC,0x00,0x00,0xFC,0x04,0x00,0x00,0x00,0x01,0x02,0x02,0x01,0x00,0x00,0x00, // U
0x04,0x7C,0x80,0xE0,0x1C,0x04,0x00,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x00, // V
0x1C,0xE0,0x3C,0xE0,0x1C,0x00,0x00,0x00,0x00,0x03,0x00,0x03,0x00,0x00,0x00,0x00, // W
0x04,0x9C,0x60,0x9C,0x04,0x00,0x00,0x00,0x02,0x03,0x00,0x03,0x02,0x00,0x00,0x00, // X
0x04,0x1C,0xE0,0x1C,0x04,0x00,0x00,0x00,0x00,0x02,0x03,0x02,0x00,0x00,0x00,0x00, // Y
0x0C,0x84,0x64,0x1C,0x04,0x00,0x00,0x00,0x02,0x03,0x02,0x02,0x03,0x00,0x00,0x00, // Z
0x00,0x00,0xFE,0x02,0x02,0x00,0x00,0x00,0x00,0x00,0x07,0x04,0x04,0x00,0x00,0x00, // [
0x00,0x0E,0x30,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x02,0x00,0x00,0x00, // <backslash>
0x00,0x02,0x02,0xFE,0x00,0x00,0x00,0x00,0x00,0x04,0x04,0x07,0x00,0x00,0x00,0x00, // ]
0x00,0x04,0x02,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ^
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x08,0x08,0x08,0x08,0x08,0x00,0x00, // _
0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // `
0x00,0x40,0xA0,0xA0,0xC0,0x00,0x00,0x00,0x00,0x01,0x02,0x02,0x03,0x02,0x00,0x00, // a
0x04,0xFC,0x20,0x20,0xC0,0x00,0x00,0x00,0x00,0x03,0x02,0x02,0x01,0x00,0x00,0x00, // b
0x00,0xC0,0x20,0x20,0x60,0x00,0x00,0x00,0x00,0x01,0x02,0x02,0x02,0x00,0x00,0x00, // c
0x00,0xC0,0x20,0x24,0xFC,0x00,0x00,0x00,0x00,0x01,0x02,0x02,0x03,0x02,0x00,0x00, // d
0x00,0xC0,0xA0,0xA0,0xC0,0x00,0x00,0x00,0x00,0x01,0x02,0x02,0x02,0x00,0x00,0x00, // e
0x00,0x20,0xF8,0x24,0x24,0x04,0x00,0x00,0x00,0x02,0x03,0x02,0x02,0x00,0x00,0x00, // f
0x00,0x40,0xA0,0xA0,0x60,0x20,0x00,0x00,0x00,0x07,0x0A,0x0A,0x0A,0x04,0x00,0x00, // g
0x04,0xFC,0x20,0x20,0xC0,0x00,0x00,0x00,0x02,0x03,0x02,0x00,0x03,0x02,0x00,0x00, // h
0x00,0x20,0xE4,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x03,0x02,0x00,0x00,0x00,0x00, // i
0x00,0x00,0x20,0xE4,0x00,0x00,0x00,0x00,0x08,0x08,0x08,0x07,0x00,0x00,0x00,0x00, // j
0x04,0xFC,0x80,0xE0,0x20,0x20,0x00,0x00,0x02,0x03,0x02,0x00,0x03,0x02,0x00,0x00, // k
0x04,0x04,0xFC,0x00,0x00,0x00,0x00,0x00,0x02,0x02,0x03,0x02,0x02,0x00,0x00,0x00, // l
0xE0,0x20,0xE0,0x20,0xC0,0x00,0x00,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x00,0x00, // m
0x20,0xE0,0x20,0x20,0xC0,0x00,0x00,0x00,0x02,0x03,0x02,0x00,0x03,0x02,0x00,0x00, // n
0x00,0xC0,0x20,0x20,0xC0,0x00,0x00,0x00,0x00,0x01,0x02,0x02,0x01,0x00,0x00,0x00, // o
0x20,0xE0,0x20,0x20,0xC0,0x00,0x00,0x00,0x08,0x0F,0x0A,0x02,0x01,0x00,0x00,0x00, // p
0x00,0xC0,0x20,0x20,0xE0,0x00,0x00,0x00,0x00,0x01,0x02,0x0A,0x0F,0x08,0x00,0x00, // q
0x20,0xE0,0x40,0x20,0x20,0x00,0x00,0x00,0x02,0x03,0x02,0x00,0x00,0x00,0x00,0x00, // r
0x00,0x60,0xA0,0xA0,0x20,0x00,0x00,0x00,0x00,0x02,0x02,0x02,0x03,0x00,0x00,0x00, // s
0x00,0x20,0xF8,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x02,0x02,0x00,0x00,0x00, // t
0x20,0xE0,0x00,0x20,0xE0,0x00,0x00,0x00,0x00,0x01,0x02,0x02,0x03,0x02,0x00,0x00, // u
0x20,0xE0,0x20,0x80,0x60,0x20,0x00,0x00,0x00,0x00,0x03,0x01,0x00,0x00,0x00,0x00, // v
0x60,0x80,0xE0,0x80,0x60,0x00,0x00,0x00,0x00,0x03,0x00,0x03,0x00,0x00,0x00,0x00, // w
0x20,0x60,0x80,0x60,0x20,0x00,0x00,0x00,0x02,0x03,0x00,0x03,0x02,0x00,0x00,0x00, // x
0x20,0xE0,0x20,0x80,0x60,0x20,0x00,0x00,0x08,0x08,0x07,0x01,0x00,0x00,0x00,0x00, // y
0x00,0x20,0xA0,0x60,0x20,0x00,0x00,0x00,0x00,0x02,0x03,0x02,0x02,0x00,0x00,0x00, // z
0x00,0x00,0x20,0xDE,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x04,0x00,0x00,0x00, // {
0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x00,0x00,0x00,0x00, // |
0x00,0x02,0xDE,0x20,0x00,0x00,0x00,0x00,0x00,0x04,0x07,0x00,0x00,0x00,0x00,0x00, // }
0x02,0x01,0x02,0x04,0x04,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ~


    
};

#endif