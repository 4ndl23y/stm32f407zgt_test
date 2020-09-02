//--------------------------------------------------------------
// File     : ub_Font_Arial_7x10.c
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
const uint16_t Arial_7x10_Table [] = {
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // Ascii = [ ]
0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x10,0x00,0x00, // Ascii = [!]
0x28,0x28,0x28,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // Ascii = ["]
0x24,0x24,0x7C,0x24,0x48,0x7C,0x48,0x48,0x00,0x00, // Ascii = [#]
0x38,0x54,0x50,0x38,0x14,0x54,0x54,0x38,0x10,0x00, // Ascii = [$]
0x20,0x54,0x58,0x30,0x28,0x54,0x14,0x08,0x00,0x00, // Ascii = [%]
0x10,0x28,0x28,0x10,0x34,0x48,0x48,0x34,0x00,0x00, // Ascii = [&]
0x10,0x10,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // Ascii = [']
0x08,0x10,0x20,0x20,0x20,0x20,0x20,0x20,0x10,0x08, // Ascii = [(]
0x20,0x10,0x08,0x08,0x08,0x08,0x08,0x08,0x10,0x20, // Ascii = [)]
0x10,0x38,0x10,0x28,0x00,0x00,0x00,0x00,0x00,0x00, // Ascii = [*]
0x00,0x00,0x10,0x10,0x7C,0x10,0x10,0x00,0x00,0x00, // Ascii = [+]
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x10,0x10, // Ascii = [,]
0x00,0x00,0x00,0x00,0x00,0x38,0x00,0x00,0x00,0x00, // Ascii = [-]
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00, // Ascii = [.]
0x08,0x08,0x10,0x10,0x10,0x10,0x20,0x20,0x00,0x00, // Ascii = [/]
0x38,0x44,0x44,0x54,0x44,0x44,0x44,0x38,0x00,0x00, // Ascii = [0]
0x10,0x30,0x50,0x10,0x10,0x10,0x10,0x10,0x00,0x00, // Ascii = [1]
0x38,0x44,0x44,0x04,0x08,0x10,0x20,0x7C,0x00,0x00, // Ascii = [2]
0x38,0x44,0x04,0x18,0x04,0x04,0x44,0x38,0x00,0x00, // Ascii = [3]
0x08,0x18,0x28,0x28,0x48,0x7C,0x08,0x08,0x00,0x00, // Ascii = [4]
0x7C,0x40,0x40,0x78,0x04,0x04,0x44,0x38,0x00,0x00, // Ascii = [5]
0x38,0x44,0x40,0x78,0x44,0x44,0x44,0x38,0x00,0x00, // Ascii = [6]
0x7C,0x04,0x08,0x10,0x10,0x20,0x20,0x20,0x00,0x00, // Ascii = [7]
0x38,0x44,0x44,0x38,0x44,0x44,0x44,0x38,0x00,0x00, // Ascii = [8]
0x38,0x44,0x44,0x44,0x3C,0x04,0x44,0x38,0x00,0x00, // Ascii = [9]
0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x10,0x00,0x00, // Ascii = [:]
0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x10,0x10,0x10, // Ascii = [;]
0x00,0x00,0x0C,0x30,0x40,0x30,0x0C,0x00,0x00,0x00, // Ascii = [<]
0x00,0x00,0x00,0x7C,0x00,0x7C,0x00,0x00,0x00,0x00, // Ascii = [=]
0x00,0x00,0x60,0x18,0x04,0x18,0x60,0x00,0x00,0x00, // Ascii = [>]
0x38,0x44,0x04,0x08,0x10,0x10,0x00,0x10,0x00,0x00, // Ascii = [?]
0x38,0x44,0x4C,0x54,0x5C,0x40,0x40,0x38,0x00,0x00, // Ascii = [@]
0x10,0x28,0x28,0x28,0x28,0x7C,0x44,0x44,0x00,0x00, // Ascii = [A]
0x78,0x44,0x44,0x78,0x44,0x44,0x44,0x78,0x00,0x00, // Ascii = [B]
0x38,0x44,0x40,0x40,0x40,0x40,0x44,0x38,0x00,0x00, // Ascii = [C]
0x70,0x48,0x44,0x44,0x44,0x44,0x48,0x70,0x00,0x00, // Ascii = [D]
0x7C,0x40,0x40,0x7C,0x40,0x40,0x40,0x7C,0x00,0x00, // Ascii = [E]
0x7C,0x40,0x40,0x78,0x40,0x40,0x40,0x40,0x00,0x00, // Ascii = [F]
0x38,0x44,0x40,0x40,0x5C,0x44,0x44,0x38,0x00,0x00, // Ascii = [G]
0x44,0x44,0x44,0x7C,0x44,0x44,0x44,0x44,0x00,0x00, // Ascii = [H]
0x38,0x10,0x10,0x10,0x10,0x10,0x10,0x38,0x00,0x00, // Ascii = [I]
0x04,0x04,0x04,0x04,0x04,0x04,0x44,0x38,0x00,0x00, // Ascii = [J]
0x44,0x48,0x50,0x60,0x50,0x48,0x48,0x44,0x00,0x00, // Ascii = [K]
0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x7C,0x00,0x00, // Ascii = [L]
0x44,0x6C,0x6C,0x54,0x44,0x44,0x44,0x44,0x00,0x00, // Ascii = [M]
0x44,0x64,0x64,0x54,0x54,0x4C,0x4C,0x44,0x00,0x00, // Ascii = [N]
0x38,0x44,0x44,0x44,0x44,0x44,0x44,0x38,0x00,0x00, // Ascii = [O]
0x78,0x44,0x44,0x44,0x78,0x40,0x40,0x40,0x00,0x00, // Ascii = [P]
0x38,0x44,0x44,0x44,0x44,0x44,0x54,0x38,0x04,0x00, // Ascii = [Q]
0x78,0x44,0x44,0x44,0x78,0x48,0x48,0x44,0x00,0x00, // Ascii = [R]
0x38,0x44,0x40,0x30,0x08,0x04,0x44,0x38,0x00,0x00, // Ascii = [S]
0x7C,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x00, // Ascii = [T]
0x44,0x44,0x44,0x44,0x44,0x44,0x44,0x38,0x00,0x00, // Ascii = [U]
0x44,0x44,0x44,0x28,0x28,0x28,0x10,0x10,0x00,0x00, // Ascii = [V]
0x44,0x44,0x54,0x54,0x54,0x6C,0x28,0x28,0x00,0x00, // Ascii = [W]
0x44,0x28,0x28,0x10,0x10,0x28,0x28,0x44,0x00,0x00, // Ascii = [X]
0x44,0x44,0x28,0x28,0x10,0x10,0x10,0x10,0x00,0x00, // Ascii = [Y]
0x7C,0x04,0x08,0x10,0x10,0x20,0x40,0x7C,0x00,0x00, // Ascii = [Z]
0x18,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x18, // Ascii = [[]
0x20,0x20,0x10,0x10,0x10,0x10,0x08,0x08,0x00,0x00, // Ascii = [\]
0x30,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x30, // Ascii = []]
0x10,0x28,0x28,0x44,0x00,0x00,0x00,0x00,0x00,0x00, // Ascii = [^]
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE, // Ascii = [_]
0x20,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // Ascii = [`]
0x00,0x00,0x38,0x44,0x3C,0x44,0x4C,0x34,0x00,0x00, // Ascii = [a]
0x40,0x40,0x58,0x64,0x44,0x44,0x64,0x58,0x00,0x00, // Ascii = [b]
0x00,0x00,0x38,0x44,0x40,0x40,0x44,0x38,0x00,0x00, // Ascii = [c]
0x04,0x04,0x34,0x4C,0x44,0x44,0x4C,0x34,0x00,0x00, // Ascii = [d]
0x00,0x00,0x38,0x44,0x7C,0x40,0x44,0x38,0x00,0x00, // Ascii = [e]
0x0C,0x10,0x7C,0x10,0x10,0x10,0x10,0x10,0x00,0x00, // Ascii = [f]
0x00,0x00,0x34,0x4C,0x44,0x44,0x4C,0x34,0x04,0x78, // Ascii = [g]
0x40,0x40,0x58,0x64,0x44,0x44,0x44,0x44,0x00,0x00, // Ascii = [h]
0x10,0x00,0x70,0x10,0x10,0x10,0x10,0x10,0x00,0x00, // Ascii = [i]
0x10,0x00,0x70,0x10,0x10,0x10,0x10,0x10,0x10,0xE0, // Ascii = [j]
0x40,0x40,0x48,0x50,0x60,0x50,0x48,0x44,0x00,0x00, // Ascii = [k]
0x70,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x00,0x00, // Ascii = [l]
0x00,0x00,0x78,0x54,0x54,0x54,0x54,0x54,0x00,0x00, // Ascii = [m]
0x00,0x00,0x58,0x64,0x44,0x44,0x44,0x44,0x00,0x00, // Ascii = [n]
0x00,0x00,0x38,0x44,0x44,0x44,0x44,0x38,0x00,0x00, // Ascii = [o]
0x00,0x00,0x58,0x64,0x44,0x44,0x64,0x58,0x40,0x40, // Ascii = [p]
0x00,0x00,0x34,0x4C,0x44,0x44,0x4C,0x34,0x04,0x04, // Ascii = [q]
0x00,0x00,0x58,0x64,0x40,0x40,0x40,0x40,0x00,0x00, // Ascii = [r]
0x00,0x00,0x38,0x44,0x30,0x08,0x44,0x38,0x00,0x00, // Ascii = [s]
0x20,0x20,0x78,0x20,0x20,0x20,0x20,0x18,0x00,0x00, // Ascii = [t]
0x00,0x00,0x44,0x44,0x44,0x44,0x4C,0x34,0x00,0x00, // Ascii = [u]
0x00,0x00,0x44,0x44,0x28,0x28,0x28,0x10,0x00,0x00, // Ascii = [v]
0x00,0x00,0x54,0x54,0x54,0x6C,0x28,0x28,0x00,0x00, // Ascii = [w]
0x00,0x00,0x44,0x28,0x10,0x10,0x28,0x44,0x00,0x00, // Ascii = [x]
0x00,0x00,0x44,0x44,0x28,0x28,0x10,0x10,0x10,0x60, // Ascii = [y]
0x00,0x00,0x7C,0x08,0x10,0x20,0x40,0x7C,0x00,0x00, // Ascii = [z]
0x18,0x10,0x10,0x10,0x20,0x20,0x10,0x10,0x10,0x18, // Ascii = [{]
0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10, // Ascii = [|]
0x30,0x10,0x10,0x10,0x08,0x08,0x10,0x10,0x10,0x30, // Ascii = [}]
0x00,0x00,0x00,0x74,0x4C,0x00,0x00,0x00,0x00,0x00, // Ascii = [~]
};


//--------------------------------------------------------------
// Font-Struktur
//--------------------------------------------------------------
UB_Font Arial_7x10 = {
  Arial_7x10_Table, // Font-Daten
  7,                // Breite eines Zeichens (in Pixel)
  10,               // Hoehe eines Zeichens  (in Pixel)
};



