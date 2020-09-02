//--------------------------------------------------------------
// Autor    : UB
// EMail    : mc-4u(@)t-online.de
// Web      : www.mikrocontroller-4u.de
//--------------------------------------------------------------


//--------------------------------------------------------------
// Font-Settings : Proportional, Max-Width=16Pixel
// Ascii-Table   : First-Char = 32, Last-Char = 126
// Data-Layout   :
//        e.G. Ascii-"R"
//       "0x06,0x3C,0x22,0x22,0x22,0x3C,0x24,0x24,0x22,0x00,0x00"
//
//  WIDTH = 6 Pixel
//    BIT = "543210"
//   0x3C = "####.."
//   0x22 = "#...#."
//   0x22 = "#...#."
//   0x22 = "#...#."
//   0x3C = "####.."
//   0x24 = "#  #.."
//   0x24 = "#  #.."
//   0x22 = "#...#."
//   0x00 = "......"
//   0x00 = "......"
//
//--------------------------------------------------------------


//--------------------------------------------------------------
// Includes
//--------------------------------------------------------------
#include "..\stm32_ub_font.h"


//--------------------------------------------------------------
// Font-Daten
// erstellt von UB mit PixelFontGenerator 1.6
// Source-Font :
// Name:Times New Roman  /  Size:8  /  Style:[N]
// First-Ascii : 32
// Last-Ascii  : 126
//--------------------------------------------------------------
const uint16_t pTimes_12_Table[] = {
0x03,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii:32 = [ ]
0x04,0x0000,0x0004,0x0004,0x0004,0x0004,0x0004,0x0004,0x0000,0x0004,0x0000,0x0000,0x0000, // Ascii:33 = [!]
0x05,0x0000,0x000A,0x000A,0x000A,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii:34 = ["]
0x06,0x0000,0x0009,0x0009,0x0012,0x003F,0x0012,0x003F,0x0024,0x0024,0x0000,0x0000,0x0000, // Ascii:35 = [#]
0x06,0x0008,0x001C,0x002A,0x0028,0x0018,0x000C,0x000A,0x002A,0x001C,0x0008,0x0000,0x0000, // Ascii:36 = [$]
0x09,0x0000,0x0082,0x0144,0x0148,0x0090,0x0012,0x0025,0x0045,0x0082,0x0000,0x0000,0x0000, // Ascii:37 = [%]
0x09,0x0000,0x0038,0x0048,0x0050,0x0066,0x01A4,0x0128,0x0112,0x00EC,0x0000,0x0000,0x0000, // Ascii:38 = [&]
0x02,0x0000,0x0002,0x0002,0x0002,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii:39 = [']
0x04,0x0000,0x0002,0x0004,0x0008,0x0008,0x0008,0x0008,0x0008,0x0008,0x0004,0x0002,0x0000, // Ascii:40 = [(]
0x04,0x0000,0x0008,0x0004,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0004,0x0008,0x0000, // Ascii:41 = [)]
0x06,0x0000,0x0008,0x002A,0x001C,0x002A,0x0008,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii:42 = [*]
0x06,0x0000,0x0000,0x0000,0x0008,0x0008,0x003E,0x0008,0x0008,0x0000,0x0000,0x0000,0x0000, // Ascii:43 = [+]
0x03,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0006,0x0002,0x0004,0x0000, // Ascii:44 = [,]
0x04,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x000E,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii:45 = [-]
0x03,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0002,0x0000,0x0000,0x0000, // Ascii:46 = [.]
0x03,0x0000,0x0001,0x0001,0x0002,0x0002,0x0002,0x0002,0x0004,0x0004,0x0000,0x0000,0x0000, // Ascii:47 = [/]
0x06,0x0000,0x001C,0x0022,0x0022,0x0022,0x0022,0x0022,0x0022,0x001C,0x0000,0x0000,0x0000, // Ascii:48 = [0]
0x06,0x0000,0x0018,0x0008,0x0008,0x0008,0x0008,0x0008,0x0008,0x001C,0x0000,0x0000,0x0000, // Ascii:49 = [1]
0x06,0x0000,0x001C,0x0022,0x0002,0x0002,0x0004,0x0008,0x0012,0x003E,0x0000,0x0000,0x0000, // Ascii:50 = [2]
0x06,0x0000,0x001C,0x0022,0x0002,0x000C,0x0002,0x0002,0x0002,0x003C,0x0000,0x0000,0x0000, // Ascii:51 = [3]
0x06,0x0000,0x0004,0x000C,0x0014,0x0014,0x0024,0x003E,0x0004,0x0004,0x0000,0x0000,0x0000, // Ascii:52 = [4]
0x06,0x0000,0x000E,0x0010,0x0018,0x0004,0x0002,0x0002,0x0002,0x003C,0x0000,0x0000,0x0000, // Ascii:53 = [5]
0x06,0x0000,0x0006,0x0018,0x0010,0x002C,0x0032,0x0022,0x0022,0x001C,0x0000,0x0000,0x0000, // Ascii:54 = [6]
0x06,0x0000,0x001E,0x0022,0x0002,0x0004,0x0004,0x0004,0x0008,0x0008,0x0000,0x0000,0x0000, // Ascii:55 = [7]
0x06,0x0000,0x001C,0x0022,0x0022,0x001C,0x0014,0x0022,0x0022,0x001C,0x0000,0x0000,0x0000, // Ascii:56 = [8]
0x06,0x0000,0x001C,0x0022,0x0022,0x0022,0x001E,0x0004,0x000C,0x0030,0x0000,0x0000,0x0000, // Ascii:57 = [9]
0x03,0x0000,0x0000,0x0000,0x0000,0x0002,0x0000,0x0000,0x0000,0x0002,0x0000,0x0000,0x0000, // Ascii:58 = [:]
0x03,0x0000,0x0000,0x0000,0x0000,0x0002,0x0000,0x0000,0x0000,0x0003,0x0001,0x0002,0x0000, // Ascii:59 = [;]
0x06,0x0000,0x0000,0x0000,0x0002,0x001C,0x0020,0x001C,0x0002,0x0000,0x0000,0x0000,0x0000, // Ascii:60 = [<]
0x06,0x0000,0x0000,0x0000,0x0000,0x003E,0x0000,0x003E,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii:61 = [=]
0x06,0x0000,0x0000,0x0000,0x0020,0x001C,0x0002,0x001C,0x0020,0x0000,0x0000,0x0000,0x0000, // Ascii:62 = [>]
0x05,0x0000,0x000C,0x0012,0x0002,0x0004,0x0008,0x0008,0x0000,0x0008,0x0000,0x0000,0x0000, // Ascii:63 = [?]
0x0A,0x0000,0x0078,0x0084,0x013A,0x024A,0x0292,0x0292,0x029C,0x0260,0x0102,0x0084,0x0078, // Ascii:64 = [@]
0x08,0x0000,0x0010,0x0010,0x0028,0x0028,0x0028,0x007C,0x0044,0x00EE,0x0000,0x0000,0x0000, // Ascii:65 = [A]
0x07,0x0000,0x007C,0x0022,0x0022,0x003C,0x0022,0x0022,0x0022,0x007C,0x0000,0x0000,0x0000, // Ascii:66 = [B]
0x07,0x0000,0x001E,0x0022,0x0040,0x0040,0x0040,0x0040,0x0022,0x001C,0x0000,0x0000,0x0000, // Ascii:67 = [C]
0x08,0x0000,0x00F8,0x0044,0x0042,0x0042,0x0042,0x0042,0x0044,0x00F8,0x0000,0x0000,0x0000, // Ascii:68 = [D]
0x07,0x0000,0x007E,0x0022,0x0028,0x0038,0x0028,0x0020,0x0022,0x007E,0x0000,0x0000,0x0000, // Ascii:69 = [E]
0x06,0x0000,0x003F,0x0011,0x0014,0x001C,0x0014,0x0010,0x0010,0x0038,0x0000,0x0000,0x0000, // Ascii:70 = [F]
0x07,0x0000,0x001E,0x0022,0x0040,0x0040,0x0047,0x0042,0x0022,0x001C,0x0000,0x0000,0x0000, // Ascii:71 = [G]
0x08,0x0000,0x00EE,0x0044,0x0044,0x007C,0x0044,0x0044,0x0044,0x00EE,0x0000,0x0000,0x0000, // Ascii:72 = [H]
0x04,0x0000,0x000E,0x0004,0x0004,0x0004,0x0004,0x0004,0x0004,0x000E,0x0000,0x0000,0x0000, // Ascii:73 = [I]
0x04,0x0000,0x0007,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x000C,0x0000,0x0000,0x0000, // Ascii:74 = [J]
0x08,0x0000,0x00EE,0x0048,0x0050,0x0060,0x0050,0x0048,0x0044,0x00EF,0x0000,0x0000,0x0000, // Ascii:75 = [K]
0x07,0x0000,0x0070,0x0020,0x0020,0x0020,0x0020,0x0020,0x0022,0x007E,0x0000,0x0000,0x0000, // Ascii:76 = [L]
0x0A,0x0000,0x038E,0x018C,0x018C,0x0154,0x0154,0x0154,0x0124,0x03AE,0x0000,0x0000,0x0000, // Ascii:77 = [M]
0x08,0x0000,0x00CE,0x0044,0x0064,0x0054,0x0054,0x004C,0x0044,0x00E4,0x0000,0x0000,0x0000, // Ascii:78 = [N]
0x08,0x0000,0x0038,0x0044,0x0082,0x0082,0x0082,0x0082,0x0044,0x0038,0x0000,0x0000,0x0000, // Ascii:79 = [O]
0x07,0x0000,0x007C,0x0022,0x0022,0x0022,0x003C,0x0020,0x0020,0x0070,0x0000,0x0000,0x0000, // Ascii:80 = [P]
0x08,0x0000,0x0038,0x0044,0x0082,0x0082,0x0082,0x0082,0x0044,0x0038,0x0008,0x0006,0x0000, // Ascii:81 = [Q]
0x07,0x0000,0x007C,0x0022,0x0022,0x003C,0x0028,0x0024,0x0024,0x0073,0x0000,0x0000,0x0000, // Ascii:82 = [R]
0x05,0x0000,0x000E,0x0012,0x0010,0x0008,0x0004,0x0002,0x0012,0x001C,0x0000,0x0000,0x0000, // Ascii:83 = [S]
0x08,0x0000,0x00FE,0x0092,0x0010,0x0010,0x0010,0x0010,0x0010,0x0038,0x0000,0x0000,0x0000, // Ascii:84 = [T]
0x08,0x0000,0x00EE,0x0044,0x0044,0x0044,0x0044,0x0044,0x0044,0x0038,0x0000,0x0000,0x0000, // Ascii:85 = [U]
0x07,0x0000,0x0077,0x0022,0x0022,0x0014,0x0014,0x0014,0x0008,0x0008,0x0000,0x0000,0x0000, // Ascii:86 = [V]
0x0B,0x0000,0x0777,0x0222,0x0222,0x0124,0x0154,0x0154,0x0088,0x0088,0x0000,0x0000,0x0000, // Ascii:87 = [W]
0x08,0x0000,0x00EE,0x0044,0x0028,0x0010,0x0010,0x0028,0x0044,0x00EE,0x0000,0x0000,0x0000, // Ascii:88 = [X]
0x08,0x0000,0x00EE,0x0044,0x0028,0x0028,0x0010,0x0010,0x0010,0x0038,0x0000,0x0000,0x0000, // Ascii:89 = [Y]
0x07,0x0000,0x007E,0x0044,0x0008,0x0010,0x0010,0x0020,0x0042,0x007E,0x0000,0x0000,0x0000, // Ascii:90 = [Z]
0x04,0x0000,0x0007,0x0004,0x0004,0x0004,0x0004,0x0004,0x0004,0x0004,0x0004,0x0007,0x0000, // Ascii:91 = [[]
0x03,0x0000,0x0004,0x0004,0x0002,0x0002,0x0002,0x0002,0x0001,0x0001,0x0000,0x0000,0x0000, // Ascii:92 = [\]
0x04,0x0000,0x000E,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x000E,0x0000, // Ascii:93 = []]
0x05,0x0000,0x000C,0x000C,0x0012,0x0012,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii:94 = [^]
0x06,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x003F,0x0000, // Ascii:95 = [_]
0x04,0x0000,0x0004,0x0002,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii:96 = [`]
0x05,0x0000,0x0000,0x0000,0x0000,0x000C,0x0002,0x000E,0x0012,0x000F,0x0000,0x0000,0x0000, // Ascii:97 = [a]
0x05,0x0000,0x0010,0x0010,0x0010,0x001C,0x0012,0x0012,0x0012,0x000C,0x0000,0x0000,0x0000, // Ascii:98 = [b]
0x05,0x0000,0x0000,0x0000,0x0000,0x000E,0x0012,0x0010,0x0010,0x000E,0x0000,0x0000,0x0000, // Ascii:99 = [c]
0x05,0x0000,0x0006,0x0002,0x0002,0x000E,0x0012,0x0012,0x0012,0x000F,0x0000,0x0000,0x0000, // Ascii:100 = [d]
0x05,0x0000,0x0000,0x0000,0x0000,0x000C,0x0012,0x001E,0x0010,0x000E,0x0000,0x0000,0x0000, // Ascii:101 = [e]
0x05,0x0000,0x0007,0x0009,0x0008,0x001C,0x0008,0x0008,0x0008,0x001C,0x0000,0x0000,0x0000, // Ascii:102 = [f]
0x05,0x0000,0x0000,0x0000,0x0000,0x000F,0x0012,0x000C,0x0010,0x001E,0x0011,0x000E,0x0000, // Ascii:103 = [g]
0x06,0x0000,0x0030,0x0010,0x0010,0x0016,0x001A,0x0012,0x0012,0x003B,0x0000,0x0000,0x0000, // Ascii:104 = [h]
0x03,0x0000,0x0002,0x0000,0x0000,0x0006,0x0002,0x0002,0x0002,0x0007,0x0000,0x0000,0x0000, // Ascii:105 = [i]
0x03,0x0000,0x0002,0x0000,0x0000,0x0006,0x0002,0x0002,0x0002,0x0002,0x0002,0x0004,0x0000, // Ascii:106 = [j]
0x06,0x0000,0x0030,0x0010,0x0010,0x0016,0x0014,0x0018,0x0014,0x0036,0x0000,0x0000,0x0000, // Ascii:107 = [k]
0x03,0x0000,0x0006,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0007,0x0000,0x0000,0x0000, // Ascii:108 = [l]
0x09,0x0000,0x0000,0x0000,0x0000,0x01B6,0x00DA,0x0092,0x0092,0x01DB,0x0000,0x0000,0x0000, // Ascii:109 = [m]
0x06,0x0000,0x0000,0x0000,0x0000,0x0036,0x001A,0x0012,0x0012,0x003B,0x0000,0x0000,0x0000, // Ascii:110 = [n]
0x06,0x0000,0x0000,0x0000,0x0000,0x001C,0x0022,0x0022,0x0022,0x001C,0x0000,0x0000,0x0000, // Ascii:111 = [o]
0x06,0x0000,0x0000,0x0000,0x0000,0x003C,0x0012,0x0012,0x0012,0x001C,0x0010,0x0038,0x0000, // Ascii:112 = [p]
0x05,0x0000,0x0000,0x0000,0x0000,0x000E,0x0012,0x0012,0x0012,0x000E,0x0002,0x0007,0x0000, // Ascii:113 = [q]
0x04,0x0000,0x0000,0x0000,0x0000,0x000D,0x0006,0x0004,0x0004,0x000E,0x0000,0x0000,0x0000, // Ascii:114 = [r]
0x04,0x0000,0x0000,0x0000,0x0000,0x0006,0x0008,0x0006,0x0002,0x000C,0x0000,0x0000,0x0000, // Ascii:115 = [s]
0x04,0x0000,0x0000,0x0004,0x0004,0x000E,0x0004,0x0004,0x0004,0x0006,0x0000,0x0000,0x0000, // Ascii:116 = [t]
0x05,0x0000,0x0000,0x0000,0x0000,0x0016,0x0012,0x0012,0x0012,0x000F,0x0000,0x0000,0x0000, // Ascii:117 = [u]
0x06,0x0000,0x0000,0x0000,0x0000,0x0037,0x0012,0x0014,0x0008,0x0008,0x0000,0x0000,0x0000, // Ascii:118 = [v]
0x07,0x0000,0x0000,0x0000,0x0000,0x005B,0x004A,0x005A,0x0024,0x0024,0x0000,0x0000,0x0000, // Ascii:119 = [w]
0x06,0x0000,0x0000,0x0000,0x0000,0x0036,0x0014,0x0008,0x0014,0x0036,0x0000,0x0000,0x0000, // Ascii:120 = [x]
0x06,0x0000,0x0000,0x0000,0x0000,0x0037,0x0012,0x0014,0x000C,0x0008,0x0008,0x0030,0x0000, // Ascii:121 = [y]
0x05,0x0000,0x0000,0x0000,0x0000,0x001F,0x0012,0x0004,0x0009,0x001F,0x0000,0x0000,0x0000, // Ascii:122 = [z]
0x05,0x0000,0x0004,0x0008,0x0008,0x0008,0x0010,0x0008,0x0008,0x0008,0x0008,0x0004,0x0000, // Ascii:123 = [{]
0x02,0x0000,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0000, // Ascii:124 = [|]
0x05,0x0000,0x0008,0x0004,0x0004,0x0004,0x0002,0x0004,0x0004,0x0004,0x0004,0x0008,0x0000, // Ascii:125 = [}]
0x06,0x0000,0x0000,0x0000,0x0000,0x0000,0x003A,0x002E,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii:126 = [~]
};


//--------------------------------------------------------------
// Font-Struktur
//--------------------------------------------------------------
UB_pFont pTimes_12 = {
  pTimes_12_Table, // Font-Daten
  12,              // Hoehe eines Zeichens  (in Pixel)
  32,              // erstes Zeichen  (Ascii-Nr)
  126,              // letztes Zeichen (Ascii-Nr)
};

