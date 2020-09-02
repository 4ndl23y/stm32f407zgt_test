//--------------------------------------------------------------
// File     : ub_Font_Arial_11x18.c
// Datum    : 18.02.2013
// Version  : 1.0
// Autor    : UB
// EMail    : mc-4u(@)t-online.de
// Web      : www.mikrocontroller-4u.de
//
// Font-Settings : Monospace, Max-Width=16Pixel
// Ascii-Table   : First-Char = 32, Last-Char = 126
// Data-Layout   :
//        e.G. Ascii-'R'
//       "0x78,0x44,0x44,0x44,0x78,0x48,0x48,0x44,0x00,0x00"
//
//   0x78 = ".####..."
//   0x44 = ".#...#.."
//   0x44 = ".#...#.."
//   0x44 = ".#...#.."
//   0x78 = ".####..."
//   0x48 = ".#  #..."
//   0x48 = ".#  #..."
//   0x44 = ".#...#.."
//   0x00 = "........"
//   0x00 = "........"
//
//--------------------------------------------------------------

//--------------------------------------------------------------
// Includes
//--------------------------------------------------------------
#include "font.h"

//--------------------------------------------------------------
// Font-Daten
// erstellt von UB mit PixelFontGenerator 1.0
//--------------------------------------------------------------
const uint16_t Arial_11x18_Table [] = {
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [ ]
0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0000,0x0C00,0x0C00,0x0000,0x0000,0x0000,0x0000, // Ascii = [!]
0x1B00,0x1B00,0x1B00,0x1B00,0x1B00,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = ["]
0x1980,0x1980,0x1980,0x1980,0x7FC0,0x7FC0,0x1980,0x3300,0x7FC0,0x7FC0,0x3300,0x3300,0x3300,0x3300,0x0000,0x0000,0x0000,0x0000, // Ascii = [#]
0x1E00,0x3F00,0x7580,0x6580,0x7400,0x3C00,0x1E00,0x0700,0x0580,0x6580,0x6580,0x7580,0x3F00,0x1E00,0x0400,0x0400,0x0000,0x0000, // Ascii = [$]
0x7000,0xD800,0xD840,0xD8C0,0xD980,0x7300,0x0600,0x0C00,0x1B80,0x36C0,0x66C0,0x46C0,0x06C0,0x0380,0x0000,0x0000,0x0000,0x0000, // Ascii = [%]
0x1E00,0x3F00,0x3300,0x3300,0x3300,0x1E00,0x0C00,0x3CC0,0x66C0,0x6380,0x6180,0x6380,0x3EC0,0x1C80,0x0000,0x0000,0x0000,0x0000, // Ascii = [&]
0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [']
0x0080,0x0100,0x0300,0x0600,0x0600,0x0400,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0400,0x0600,0x0600,0x0300,0x0100,0x0080, // Ascii = [(]
0x2000,0x1000,0x1800,0x0C00,0x0C00,0x0400,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0400,0x0C00,0x0C00,0x1800,0x1000,0x2000, // Ascii = [)]
0x0C00,0x2D00,0x3F00,0x1E00,0x3300,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [*]
0x0000,0x0000,0x0C00,0x0C00,0x0C00,0x0C00,0xFFC0,0xFFC0,0x0C00,0x0C00,0x0C00,0x0C00,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [+]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0C00,0x0C00,0x0400,0x0400,0x0800,0x0000, // Ascii = [,]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x1E00,0x1E00,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [-]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0C00,0x0C00,0x0000,0x0000,0x0000,0x0000, // Ascii = [.]
0x0300,0x0300,0x0300,0x0600,0x0600,0x0600,0x0600,0x0C00,0x0C00,0x0C00,0x0C00,0x1800,0x1800,0x1800,0x0000,0x0000,0x0000,0x0000, // Ascii = [/]
0x1E00,0x3F00,0x3300,0x6180,0x6180,0x6180,0x6D80,0x6D80,0x6180,0x6180,0x6180,0x3300,0x3F00,0x1E00,0x0000,0x0000,0x0000,0x0000, // Ascii = [0]
0x0600,0x0E00,0x1E00,0x3600,0x2600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0000,0x0000,0x0000,0x0000, // Ascii = [1]
0x1E00,0x3F00,0x7380,0x6180,0x6180,0x0180,0x0300,0x0600,0x0C00,0x1800,0x3000,0x6000,0x7F80,0x7F80,0x0000,0x0000,0x0000,0x0000, // Ascii = [2]
0x1C00,0x3E00,0x6300,0x6300,0x0300,0x0E00,0x0E00,0x0300,0x0180,0x0180,0x6180,0x7380,0x3F00,0x1E00,0x0000,0x0000,0x0000,0x0000, // Ascii = [3]
0x0600,0x0E00,0x0E00,0x1E00,0x1E00,0x1600,0x3600,0x3600,0x6600,0x7F80,0x7F80,0x0600,0x0600,0x0600,0x0000,0x0000,0x0000,0x0000, // Ascii = [4]
0x7F00,0x7F00,0x6000,0x6000,0x6000,0x6E00,0x7F00,0x6380,0x0180,0x0180,0x6180,0x7380,0x3F00,0x1E00,0x0000,0x0000,0x0000,0x0000, // Ascii = [5]
0x1E00,0x3F00,0x3380,0x6180,0x6000,0x6E00,0x7F00,0x7380,0x6180,0x6180,0x6180,0x3380,0x3F00,0x1E00,0x0000,0x0000,0x0000,0x0000, // Ascii = [6]
0x7F80,0x7F80,0x0180,0x0300,0x0300,0x0600,0x0600,0x0C00,0x0C00,0x0C00,0x0800,0x1800,0x1800,0x1800,0x0000,0x0000,0x0000,0x0000, // Ascii = [7]
0x1E00,0x3F00,0x6380,0x6180,0x6180,0x2100,0x1E00,0x3F00,0x6180,0x6180,0x6180,0x6180,0x3F00,0x1E00,0x0000,0x0000,0x0000,0x0000, // Ascii = [8]
0x1E00,0x3F00,0x7300,0x6180,0x6180,0x6180,0x7380,0x3F80,0x1D80,0x0180,0x6180,0x7300,0x3F00,0x1E00,0x0000,0x0000,0x0000,0x0000, // Ascii = [9]
0x0000,0x0000,0x0000,0x0000,0x0C00,0x0C00,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0C00,0x0C00,0x0000,0x0000,0x0000,0x0000, // Ascii = [:]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0C00,0x0C00,0x0000,0x0000,0x0000,0x0000,0x0000,0x0C00,0x0C00,0x0400,0x0400,0x0800,0x0000, // Ascii = [;]
0x0000,0x0000,0x0000,0x0080,0x0380,0x0E00,0x3800,0x6000,0x3800,0x0E00,0x0380,0x0080,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [<]
0x0000,0x0000,0x0000,0x0000,0x7F80,0x7F80,0x0000,0x0000,0x7F80,0x7F80,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [=]
0x0000,0x0000,0x0000,0x4000,0x7000,0x1C00,0x0700,0x0180,0x0700,0x1C00,0x7000,0x4000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [>]
0x1F00,0x3F80,0x71C0,0x60C0,0x00C0,0x01C0,0x0380,0x0700,0x0E00,0x0C00,0x0C00,0x0000,0x0C00,0x0C00,0x0000,0x0000,0x0000,0x0000, // Ascii = [?]
0x1E00,0x3F00,0x3180,0x7180,0x6380,0x6F80,0x6D80,0x6D80,0x6F80,0x6780,0x6000,0x3200,0x3E00,0x1C00,0x0000,0x0000,0x0000,0x0000, // Ascii = [@]
0x0E00,0x0E00,0x1B00,0x1B00,0x1B00,0x1B00,0x3180,0x3180,0x3F80,0x3F80,0x3180,0x60C0,0x60C0,0x60C0,0x0000,0x0000,0x0000,0x0000, // Ascii = [A]
0x7C00,0x7E00,0x6300,0x6300,0x6300,0x6300,0x7E00,0x7E00,0x6300,0x6180,0x6180,0x6380,0x7F00,0x7E00,0x0000,0x0000,0x0000,0x0000, // Ascii = [B]
0x1E00,0x3F00,0x3180,0x6180,0x6000,0x6000,0x6000,0x6000,0x6000,0x6000,0x6180,0x3180,0x3F00,0x1E00,0x0000,0x0000,0x0000,0x0000, // Ascii = [C]
0x7C00,0x7F00,0x6300,0x6380,0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x6300,0x6300,0x7E00,0x7C00,0x0000,0x0000,0x0000,0x0000, // Ascii = [D]
0x7F80,0x7F80,0x6000,0x6000,0x6000,0x6000,0x7F00,0x7F00,0x6000,0x6000,0x6000,0x6000,0x7F80,0x7F80,0x0000,0x0000,0x0000,0x0000, // Ascii = [E]
0x7F80,0x7F80,0x6000,0x6000,0x6000,0x6000,0x7F00,0x7F00,0x6000,0x6000,0x6000,0x6000,0x6000,0x6000,0x0000,0x0000,0x0000,0x0000, // Ascii = [F]
0x1E00,0x3F00,0x3180,0x6180,0x6000,0x6000,0x6000,0x6380,0x6380,0x6180,0x6180,0x3180,0x3F80,0x1E00,0x0000,0x0000,0x0000,0x0000, // Ascii = [G]
0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x7F80,0x7F80,0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x0000,0x0000,0x0000,0x0000, // Ascii = [H]
0x3F00,0x3F00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x3F00,0x3F00,0x0000,0x0000,0x0000,0x0000, // Ascii = [I]
0x0180,0x0180,0x0180,0x0180,0x0180,0x0180,0x0180,0x0180,0x0180,0x6180,0x6180,0x7380,0x3F00,0x1E00,0x0000,0x0000,0x0000,0x0000, // Ascii = [J]
0x60C0,0x6180,0x6300,0x6600,0x6600,0x6C00,0x7800,0x7C00,0x6600,0x6600,0x6300,0x6180,0x6180,0x60C0,0x0000,0x0000,0x0000,0x0000, // Ascii = [K]
0x6000,0x6000,0x6000,0x6000,0x6000,0x6000,0x6000,0x6000,0x6000,0x6000,0x6000,0x6000,0x7F80,0x7F80,0x0000,0x0000,0x0000,0x0000, // Ascii = [L]
0x71C0,0x71C0,0x7BC0,0x7AC0,0x6AC0,0x6AC0,0x6EC0,0x64C0,0x60C0,0x60C0,0x60C0,0x60C0,0x60C0,0x60C0,0x0000,0x0000,0x0000,0x0000, // Ascii = [M]
0x7180,0x7180,0x7980,0x7980,0x7980,0x6D80,0x6D80,0x6D80,0x6580,0x6780,0x6780,0x6780,0x6380,0x6380,0x0000,0x0000,0x0000,0x0000, // Ascii = [N]
0x1E00,0x3F00,0x3300,0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x3300,0x3F00,0x1E00,0x0000,0x0000,0x0000,0x0000, // Ascii = [O]
0x7E00,0x7F00,0x6380,0x6180,0x6180,0x6180,0x6380,0x7F00,0x7E00,0x6000,0x6000,0x6000,0x6000,0x6000,0x0000,0x0000,0x0000,0x0000, // Ascii = [P]
0x1E00,0x3F00,0x3300,0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x6580,0x6780,0x3300,0x3F80,0x1E40,0x0000,0x0000,0x0000,0x0000, // Ascii = [Q]
0x7E00,0x7F00,0x6380,0x6180,0x6180,0x6380,0x7F00,0x7E00,0x6600,0x6300,0x6300,0x6180,0x6180,0x60C0,0x0000,0x0000,0x0000,0x0000, // Ascii = [R]
0x0E00,0x1F00,0x3180,0x3180,0x3000,0x3800,0x1E00,0x0700,0x0380,0x6180,0x6180,0x3180,0x3F00,0x1E00,0x0000,0x0000,0x0000,0x0000, // Ascii = [S]
0xFFC0,0xFFC0,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0000,0x0000,0x0000,0x0000, // Ascii = [T]
0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x7380,0x3F00,0x1E00,0x0000,0x0000,0x0000,0x0000, // Ascii = [U]
0x60C0,0x60C0,0x60C0,0x3180,0x3180,0x3180,0x1B00,0x1B00,0x1B00,0x1B00,0x0E00,0x0E00,0x0E00,0x0400,0x0000,0x0000,0x0000,0x0000, // Ascii = [V]
0xC0C0,0xC0C0,0xC0C0,0xC0C0,0xC0C0,0xCCC0,0x4C80,0x4C80,0x5E80,0x5280,0x5280,0x7380,0x6180,0x6180,0x0000,0x0000,0x0000,0x0000, // Ascii = [W]
0xC0C0,0x6080,0x6180,0x3300,0x3B00,0x1E00,0x0C00,0x0C00,0x1E00,0x1F00,0x3B00,0x7180,0x6180,0xC0C0,0x0000,0x0000,0x0000,0x0000, // Ascii = [X]
0xC0C0,0x6180,0x6180,0x3300,0x3300,0x1E00,0x1E00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0000,0x0000,0x0000,0x0000, // Ascii = [Y]
0x3F80,0x3F80,0x0180,0x0300,0x0300,0x0600,0x0C00,0x0C00,0x1800,0x1800,0x3000,0x6000,0x7F80,0x7F80,0x0000,0x0000,0x0000,0x0000, // Ascii = [Z]
0x0F00,0x0F00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0F00,0x0F00, // Ascii = [[]
0x1800,0x1800,0x1800,0x0C00,0x0C00,0x0C00,0x0C00,0x0600,0x0600,0x0600,0x0600,0x0300,0x0300,0x0300,0x0000,0x0000,0x0000,0x0000, // Ascii = [\]
0x1E00,0x1E00,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x1E00,0x1E00, // Ascii = []]
0x0C00,0x0C00,0x1E00,0x1200,0x3300,0x3300,0x6180,0x6180,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [^]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0xFFE0,0x0000,0x0000, // Ascii = [_]
0x3800,0x1800,0x0C00,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [`]
0x0000,0x0000,0x0000,0x0000,0x1F00,0x3F80,0x6180,0x0180,0x1F80,0x3F80,0x6180,0x6380,0x7F80,0x38C0,0x0000,0x0000,0x0000,0x0000, // Ascii = [a]
0x6000,0x6000,0x6000,0x6000,0x6E00,0x7F00,0x7380,0x6180,0x6180,0x6180,0x6180,0x7380,0x7F00,0x6E00,0x0000,0x0000,0x0000,0x0000, // Ascii = [b]
0x0000,0x0000,0x0000,0x0000,0x1E00,0x3F00,0x7380,0x6180,0x6000,0x6000,0x6180,0x7380,0x3F00,0x1E00,0x0000,0x0000,0x0000,0x0000, // Ascii = [c]
0x0180,0x0180,0x0180,0x0180,0x1D80,0x3F80,0x7380,0x6180,0x6180,0x6180,0x6180,0x7380,0x3F80,0x1D80,0x0000,0x0000,0x0000,0x0000, // Ascii = [d]
0x0000,0x0000,0x0000,0x0000,0x1E00,0x3F00,0x7300,0x6180,0x7F80,0x7F80,0x6000,0x7180,0x3F00,0x1E00,0x0000,0x0000,0x0000,0x0000, // Ascii = [e]
0x07C0,0x0FC0,0x0C00,0x0C00,0x7F80,0x7F80,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0000,0x0000,0x0000,0x0000, // Ascii = [f]
0x0000,0x0000,0x0000,0x0000,0x1D80,0x3F80,0x7380,0x6180,0x6180,0x6180,0x6180,0x7380,0x3F80,0x1D80,0x0180,0x6380,0x7F00,0x3E00, // Ascii = [g]
0x6000,0x6000,0x6000,0x6000,0x6F00,0x7F80,0x7180,0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x0000,0x0000,0x0000,0x0000, // Ascii = [h]
0x0600,0x0600,0x0000,0x0000,0x3E00,0x3E00,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0000,0x0000,0x0000,0x0000, // Ascii = [i]
0x0600,0x0600,0x0000,0x0000,0x3E00,0x3E00,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x4600,0x7E00,0x3C00, // Ascii = [j]
0x6000,0x6000,0x6000,0x6000,0x6180,0x6300,0x6600,0x6C00,0x7C00,0x7600,0x6300,0x6300,0x6180,0x60C0,0x0000,0x0000,0x0000,0x0000, // Ascii = [k]
0x3E00,0x3E00,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0000,0x0000,0x0000,0x0000, // Ascii = [l]
0x0000,0x0000,0x0000,0x0000,0xDD80,0xFFC0,0xCEC0,0xCCC0,0xCCC0,0xCCC0,0xCCC0,0xCCC0,0xCCC0,0xCCC0,0x0000,0x0000,0x0000,0x0000, // Ascii = [m]
0x0000,0x0000,0x0000,0x0000,0x6F00,0x7F80,0x7180,0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x0000,0x0000,0x0000,0x0000, // Ascii = [n]
0x0000,0x0000,0x0000,0x0000,0x1E00,0x3F00,0x7380,0x6180,0x6180,0x6180,0x6180,0x7380,0x3F00,0x1E00,0x0000,0x0000,0x0000,0x0000, // Ascii = [o]
0x0000,0x0000,0x0000,0x0000,0x6E00,0x7F00,0x7380,0x6180,0x6180,0x6180,0x6180,0x7380,0x7F00,0x6E00,0x6000,0x6000,0x6000,0x6000, // Ascii = [p]
0x0000,0x0000,0x0000,0x0000,0x1D80,0x3F80,0x7380,0x6180,0x6180,0x6180,0x6180,0x7380,0x3F80,0x1D80,0x0180,0x0180,0x0180,0x0180, // Ascii = [q]
0x0000,0x0000,0x0000,0x0000,0x6700,0x3F80,0x3900,0x3000,0x3000,0x3000,0x3000,0x3000,0x3000,0x3000,0x0000,0x0000,0x0000,0x0000, // Ascii = [r]
0x0000,0x0000,0x0000,0x0000,0x1E00,0x3F80,0x6180,0x6000,0x7F00,0x3F80,0x0180,0x6180,0x7F00,0x1E00,0x0000,0x0000,0x0000,0x0000, // Ascii = [s]
0x0000,0x0800,0x1800,0x1800,0x7F00,0x7F00,0x1800,0x1800,0x1800,0x1800,0x1800,0x1800,0x1F80,0x0F80,0x0000,0x0000,0x0000,0x0000, // Ascii = [t]
0x0000,0x0000,0x0000,0x0000,0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x6180,0x6380,0x7F80,0x3D80,0x0000,0x0000,0x0000,0x0000, // Ascii = [u]
0x0000,0x0000,0x0000,0x0000,0x60C0,0x3180,0x3180,0x3180,0x1B00,0x1B00,0x1B00,0x0E00,0x0E00,0x0600,0x0000,0x0000,0x0000,0x0000, // Ascii = [v]
0x0000,0x0000,0x0000,0x0000,0xDD80,0xDD80,0xDD80,0x5500,0x5500,0x5500,0x7700,0x7700,0x2200,0x2200,0x0000,0x0000,0x0000,0x0000, // Ascii = [w]
0x0000,0x0000,0x0000,0x0000,0x6180,0x3300,0x3300,0x1E00,0x0C00,0x0C00,0x1E00,0x3300,0x3300,0x6180,0x0000,0x0000,0x0000,0x0000, // Ascii = [x]
0x0000,0x0000,0x0000,0x0000,0x6180,0x6180,0x3180,0x3300,0x3300,0x1B00,0x1B00,0x1B00,0x0E00,0x0E00,0x0E00,0x1C00,0x7C00,0x7000, // Ascii = [y]
0x0000,0x0000,0x0000,0x0000,0x7FC0,0x7FC0,0x0180,0x0300,0x0600,0x0C00,0x1800,0x3000,0x7FC0,0x7FC0,0x0000,0x0000,0x0000,0x0000, // Ascii = [z]
0x0380,0x0780,0x0600,0x0600,0x0600,0x0600,0x0600,0x0E00,0x1C00,0x1C00,0x0E00,0x0600,0x0600,0x0600,0x0600,0x0600,0x0780,0x0380, // Ascii = [{]
0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600,0x0600, // Ascii = [|]
0x3800,0x3C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x0E00,0x0700,0x0700,0x0E00,0x0C00,0x0C00,0x0C00,0x0C00,0x0C00,0x3C00,0x3800, // Ascii = [}]
0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x3880,0x7F80,0x4700,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii = [~]
};


//--------------------------------------------------------------
// Font-Struktur
//--------------------------------------------------------------

UB_Font Arial_11x18 = {
  Arial_11x18_Table, // Font-Daten
  11,                // Breite eines Zeichens (in Pixel)
  18,                // Hoehe eines Zeichens  (in Pixel)
};
