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
// Name:Arial  /  Size:10  /  Style:[N]
// First-Ascii : 32
// Last-Ascii  : 126
//--------------------------------------------------------------
const uint16_t pArial_13_Table[] = {
0x04,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii:32 = [ ]
0x03,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0000,0x0002,0x0000,0x0000,0x0000, // Ascii:33 = [!]
0x05,0x000A,0x000A,0x000A,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii:34 = ["]
0x08,0x0012,0x0012,0x0022,0x00FF,0x0024,0x0024,0x00FF,0x0048,0x0048,0x0048,0x0000,0x0000,0x0000, // Ascii:35 = [#]
0x07,0x001C,0x002A,0x0028,0x0028,0x0038,0x000E,0x000A,0x002A,0x002A,0x001C,0x0008,0x0000,0x0000, // Ascii:36 = [$]
0x0C,0x0308,0x0490,0x0490,0x04A0,0x0320,0x004C,0x0052,0x0092,0x0092,0x010C,0x0000,0x0000,0x0000, // Ascii:37 = [%]
0x09,0x0030,0x0048,0x0048,0x0048,0x0030,0x0060,0x0092,0x008A,0x008C,0x0073,0x0000,0x0000,0x0000, // Ascii:38 = [&]
0x02,0x0001,0x0001,0x0001,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii:39 = [']
0x04,0x0001,0x0002,0x0002,0x0004,0x0004,0x0004,0x0004,0x0004,0x0004,0x0004,0x0002,0x0002,0x0001, // Ascii:40 = [(]
0x04,0x0008,0x0004,0x0004,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0004,0x0004,0x0008, // Ascii:41 = [)]
0x05,0x0004,0x001F,0x0004,0x000A,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii:42 = [*]
0x08,0x0000,0x0000,0x0008,0x0008,0x0008,0x007F,0x0008,0x0008,0x0008,0x0000,0x0000,0x0000,0x0000, // Ascii:43 = [+]
0x04,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0002,0x0002,0x0002,0x0000, // Ascii:44 = [,]
0x04,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x000E,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii:45 = [-]
0x04,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0004,0x0000,0x0000,0x0000, // Ascii:46 = [.]
0x04,0x0001,0x0001,0x0002,0x0002,0x0002,0x0004,0x0004,0x0004,0x0008,0x0008,0x0000,0x0000,0x0000, // Ascii:47 = [/]
0x07,0x003C,0x0042,0x0042,0x0042,0x0042,0x0042,0x0042,0x0042,0x0042,0x003C,0x0000,0x0000,0x0000, // Ascii:48 = [0]
0x07,0x0008,0x0018,0x0028,0x0008,0x0008,0x0008,0x0008,0x0008,0x0008,0x0008,0x0000,0x0000,0x0000, // Ascii:49 = [1]
0x07,0x003C,0x0042,0x0002,0x0002,0x0002,0x0004,0x0008,0x0010,0x0020,0x007E,0x0000,0x0000,0x0000, // Ascii:50 = [2]
0x07,0x003C,0x0042,0x0002,0x0002,0x001C,0x0002,0x0002,0x0002,0x0042,0x003C,0x0000,0x0000,0x0000, // Ascii:51 = [3]
0x07,0x0004,0x000C,0x000C,0x0014,0x0014,0x0024,0x0024,0x007E,0x0004,0x0004,0x0000,0x0000,0x0000, // Ascii:52 = [4]
0x07,0x003E,0x0020,0x0020,0x0040,0x007C,0x0042,0x0002,0x0002,0x0042,0x003C,0x0000,0x0000,0x0000, // Ascii:53 = [5]
0x07,0x003C,0x0042,0x0040,0x0040,0x005C,0x0062,0x0042,0x0042,0x0042,0x003C,0x0000,0x0000,0x0000, // Ascii:54 = [6]
0x07,0x007E,0x0004,0x0004,0x0008,0x0008,0x0010,0x0010,0x0020,0x0020,0x0020,0x0000,0x0000,0x0000, // Ascii:55 = [7]
0x07,0x003C,0x0042,0x0042,0x0042,0x003C,0x0042,0x0042,0x0042,0x0042,0x003C,0x0000,0x0000,0x0000, // Ascii:56 = [8]
0x07,0x003C,0x0042,0x0042,0x0042,0x0046,0x003A,0x0002,0x0002,0x0044,0x0038,0x0000,0x0000,0x0000, // Ascii:57 = [9]
0x04,0x0000,0x0000,0x0000,0x0004,0x0000,0x0000,0x0000,0x0000,0x0000,0x0004,0x0000,0x0000,0x0000, // Ascii:58 = [:]
0x04,0x0000,0x0000,0x0000,0x0004,0x0000,0x0000,0x0000,0x0000,0x0000,0x0004,0x0004,0x0004,0x0000, // Ascii:59 = [;]
0x08,0x0000,0x0000,0x0002,0x000C,0x0030,0x0040,0x0030,0x000C,0x0002,0x0000,0x0000,0x0000,0x0000, // Ascii:60 = [<]
0x08,0x0000,0x0000,0x0000,0x00FE,0x0000,0x0000,0x00FE,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii:61 = [=]
0x08,0x0000,0x0000,0x0040,0x0030,0x000C,0x0002,0x000C,0x0030,0x0040,0x0000,0x0000,0x0000,0x0000, // Ascii:62 = [>]
0x07,0x001C,0x0022,0x0022,0x0002,0x0004,0x0008,0x0010,0x0010,0x0000,0x0010,0x0000,0x0000,0x0000, // Ascii:63 = [?]
0x0D,0x01F0,0x0608,0x0804,0x09D2,0x1232,0x1412,0x1422,0x1424,0x1464,0x13B8,0x0802,0x040C,0x03F0, // Ascii:64 = [@]
0x09,0x0010,0x0028,0x0028,0x0028,0x0044,0x0044,0x00FE,0x0082,0x0101,0x0101,0x0000,0x0000,0x0000, // Ascii:65 = [A]
0x09,0x00FC,0x0082,0x0082,0x0082,0x00FC,0x0082,0x0082,0x0082,0x0082,0x00FC,0x0000,0x0000,0x0000, // Ascii:66 = [B]
0x09,0x0038,0x0044,0x0082,0x0080,0x0080,0x0080,0x0080,0x0082,0x0044,0x0038,0x0000,0x0000,0x0000, // Ascii:67 = [C]
0x09,0x00F8,0x0084,0x0082,0x0082,0x0082,0x0082,0x0082,0x0082,0x0084,0x00F8,0x0000,0x0000,0x0000, // Ascii:68 = [D]
0x09,0x00FE,0x0080,0x0080,0x0080,0x00FE,0x0080,0x0080,0x0080,0x0080,0x00FE,0x0000,0x0000,0x0000, // Ascii:69 = [E]
0x08,0x007E,0x0040,0x0040,0x0040,0x007C,0x0040,0x0040,0x0040,0x0040,0x0040,0x0000,0x0000,0x0000, // Ascii:70 = [F]
0x0A,0x0078,0x0084,0x0102,0x0100,0x0100,0x011E,0x0102,0x0102,0x0084,0x0078,0x0000,0x0000,0x0000, // Ascii:71 = [G]
0x09,0x0082,0x0082,0x0082,0x0082,0x00FE,0x0082,0x0082,0x0082,0x0082,0x0082,0x0000,0x0000,0x0000, // Ascii:72 = [H]
0x03,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0000,0x0000,0x0000, // Ascii:73 = [I]
0x06,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0022,0x0022,0x001C,0x0000,0x0000,0x0000, // Ascii:74 = [J]
0x09,0x0081,0x0082,0x0084,0x0088,0x0090,0x00B0,0x00C8,0x0084,0x0082,0x0081,0x0000,0x0000,0x0000, // Ascii:75 = [K]
0x07,0x0020,0x0020,0x0020,0x0020,0x0020,0x0020,0x0020,0x0020,0x0020,0x003F,0x0000,0x0000,0x0000, // Ascii:76 = [L]
0x0B,0x0202,0x0306,0x0306,0x028A,0x028A,0x0252,0x0252,0x0252,0x0222,0x0222,0x0000,0x0000,0x0000, // Ascii:77 = [M]
0x09,0x0082,0x00C2,0x00A2,0x00A2,0x0092,0x0092,0x008A,0x008A,0x0086,0x0082,0x0000,0x0000,0x0000, // Ascii:78 = [N]
0x0A,0x0078,0x0084,0x0102,0x0102,0x0102,0x0102,0x0102,0x0102,0x0084,0x0078,0x0000,0x0000,0x0000, // Ascii:79 = [O]
0x09,0x00FC,0x0082,0x0082,0x0082,0x0082,0x00FC,0x0080,0x0080,0x0080,0x0080,0x0000,0x0000,0x0000, // Ascii:80 = [P]
0x0A,0x0078,0x0084,0x0102,0x0102,0x0102,0x0102,0x0102,0x011A,0x0084,0x007A,0x0000,0x0000,0x0000, // Ascii:81 = [Q]
0x09,0x00FC,0x0082,0x0082,0x0082,0x0082,0x00FC,0x0088,0x0084,0x0084,0x0082,0x0000,0x0000,0x0000, // Ascii:82 = [R]
0x09,0x007C,0x0082,0x0082,0x0080,0x0070,0x000C,0x0002,0x0082,0x0082,0x007C,0x0000,0x0000,0x0000, // Ascii:83 = [S]
0x07,0x007F,0x0008,0x0008,0x0008,0x0008,0x0008,0x0008,0x0008,0x0008,0x0008,0x0000,0x0000,0x0000, // Ascii:84 = [T]
0x09,0x0082,0x0082,0x0082,0x0082,0x0082,0x0082,0x0082,0x0082,0x0044,0x0038,0x0000,0x0000,0x0000, // Ascii:85 = [U]
0x0A,0x0202,0x0202,0x0104,0x0104,0x0088,0x0088,0x0050,0x0050,0x0020,0x0020,0x0000,0x0000,0x0000, // Ascii:86 = [V]
0x0D,0x1041,0x10A1,0x08A2,0x08A2,0x08A2,0x0514,0x0514,0x0514,0x0208,0x0208,0x0000,0x0000,0x0000, // Ascii:87 = [W]
0x07,0x0041,0x0022,0x0022,0x0014,0x0008,0x0008,0x0014,0x0022,0x0022,0x0041,0x0000,0x0000,0x0000, // Ascii:88 = [X]
0x09,0x0082,0x0044,0x0044,0x0028,0x0028,0x0010,0x0010,0x0010,0x0010,0x0010,0x0000,0x0000,0x0000, // Ascii:89 = [Y]
0x07,0x003F,0x0002,0x0004,0x0004,0x0008,0x0008,0x0010,0x0010,0x0020,0x007F,0x0000,0x0000,0x0000, // Ascii:90 = [Z]
0x04,0x0006,0x0004,0x0004,0x0004,0x0004,0x0004,0x0004,0x0004,0x0004,0x0004,0x0004,0x0004,0x0006, // Ascii:91 = [[]
0x04,0x0008,0x0008,0x0004,0x0004,0x0004,0x0002,0x0002,0x0002,0x0001,0x0001,0x0000,0x0000,0x0000, // Ascii:92 = [\]
0x04,0x0006,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0006, // Ascii:93 = []]
0x05,0x0000,0x0004,0x000A,0x000A,0x000A,0x0011,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii:94 = [^]
0x07,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x007F, // Ascii:95 = [_]
0x04,0x0004,0x0002,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii:96 = [`]
0x07,0x0000,0x0000,0x0000,0x001C,0x0022,0x0002,0x001E,0x0022,0x0026,0x001A,0x0000,0x0000,0x0000, // Ascii:97 = [a]
0x07,0x0020,0x0020,0x0020,0x002C,0x0032,0x0022,0x0022,0x0022,0x0022,0x003C,0x0000,0x0000,0x0000, // Ascii:98 = [b]
0x07,0x0000,0x0000,0x0000,0x001C,0x0022,0x0020,0x0020,0x0020,0x0022,0x001C,0x0000,0x0000,0x0000, // Ascii:99 = [c]
0x07,0x0002,0x0002,0x0002,0x001A,0x0026,0x0022,0x0022,0x0022,0x0022,0x001E,0x0000,0x0000,0x0000, // Ascii:100 = [d]
0x07,0x0000,0x0000,0x0000,0x001C,0x0022,0x0022,0x003E,0x0020,0x0022,0x001C,0x0000,0x0000,0x0000, // Ascii:101 = [e]
0x04,0x0003,0x0004,0x0004,0x000E,0x0004,0x0004,0x0004,0x0004,0x0004,0x0004,0x0000,0x0000,0x0000, // Ascii:102 = [f]
0x07,0x0000,0x0000,0x0000,0x001A,0x0026,0x0022,0x0022,0x0022,0x0026,0x001A,0x0002,0x0022,0x001C, // Ascii:103 = [g]
0x07,0x0020,0x0020,0x0020,0x002C,0x0032,0x0022,0x0022,0x0022,0x0022,0x0022,0x0000,0x0000,0x0000, // Ascii:104 = [h]
0x03,0x0002,0x0000,0x0000,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0000,0x0000,0x0000, // Ascii:105 = [i]
0x03,0x0002,0x0000,0x0000,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0004, // Ascii:106 = [j]
0x07,0x0020,0x0020,0x0020,0x0022,0x0024,0x0028,0x0038,0x0024,0x0024,0x0022,0x0000,0x0000,0x0000, // Ascii:107 = [k]
0x03,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0000,0x0000,0x0000, // Ascii:108 = [l]
0x0B,0x0000,0x0000,0x0000,0x02CC,0x0332,0x0222,0x0222,0x0222,0x0222,0x0222,0x0000,0x0000,0x0000, // Ascii:109 = [m]
0x07,0x0000,0x0000,0x0000,0x002C,0x0032,0x0022,0x0022,0x0022,0x0022,0x0022,0x0000,0x0000,0x0000, // Ascii:110 = [n]
0x07,0x0000,0x0000,0x0000,0x001C,0x0022,0x0022,0x0022,0x0022,0x0022,0x001C,0x0000,0x0000,0x0000, // Ascii:111 = [o]
0x07,0x0000,0x0000,0x0000,0x002C,0x0032,0x0022,0x0022,0x0022,0x0032,0x002C,0x0020,0x0020,0x0020, // Ascii:112 = [p]
0x07,0x0000,0x0000,0x0000,0x001A,0x0026,0x0022,0x0022,0x0022,0x0026,0x001A,0x0002,0x0002,0x0002, // Ascii:113 = [q]
0x04,0x0000,0x0000,0x0000,0x0005,0x0006,0x0004,0x0004,0x0004,0x0004,0x0004,0x0000,0x0000,0x0000, // Ascii:114 = [r]
0x07,0x0000,0x0000,0x0000,0x001C,0x0022,0x0020,0x001C,0x0002,0x0022,0x001C,0x0000,0x0000,0x0000, // Ascii:115 = [s]
0x04,0x0000,0x0004,0x0004,0x000E,0x0004,0x0004,0x0004,0x0004,0x0004,0x0006,0x0000,0x0000,0x0000, // Ascii:116 = [t]
0x07,0x0000,0x0000,0x0000,0x0022,0x0022,0x0022,0x0022,0x0022,0x0022,0x001E,0x0000,0x0000,0x0000, // Ascii:117 = [u]
0x05,0x0000,0x0000,0x0000,0x0011,0x0011,0x000A,0x000A,0x000A,0x0004,0x0004,0x0000,0x0000,0x0000, // Ascii:118 = [v]
0x09,0x0000,0x0000,0x0000,0x0111,0x0111,0x00AA,0x00AA,0x00AA,0x0044,0x0044,0x0000,0x0000,0x0000, // Ascii:119 = [w]
0x07,0x0000,0x0000,0x0000,0x0022,0x0014,0x0014,0x0008,0x0014,0x0014,0x0022,0x0000,0x0000,0x0000, // Ascii:120 = [x]
0x07,0x0000,0x0000,0x0000,0x0022,0x0022,0x0014,0x0014,0x0014,0x0008,0x0008,0x0008,0x0008,0x0030, // Ascii:121 = [y]
0x07,0x0000,0x0000,0x0000,0x003E,0x0004,0x0004,0x0008,0x0010,0x0010,0x003E,0x0000,0x0000,0x0000, // Ascii:122 = [z]
0x04,0x0002,0x0004,0x0004,0x0004,0x0004,0x0004,0x0008,0x0004,0x0004,0x0004,0x0004,0x0004,0x0002, // Ascii:123 = [{]
0x03,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0002,0x0000, // Ascii:124 = [|]
0x04,0x0004,0x0002,0x0002,0x0002,0x0002,0x0002,0x0001,0x0002,0x0002,0x0002,0x0002,0x0002,0x0004, // Ascii:125 = [}]
0x08,0x0000,0x0000,0x0000,0x0000,0x0072,0x009E,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000, // Ascii:126 = [~]
};


//--------------------------------------------------------------
// Font-Struktur
//--------------------------------------------------------------
UB_pFont pArial_13 = {
  pArial_13_Table, // Font-Daten
  13,              // Hoehe eines Zeichens  (in Pixel)
  32,              // erstes Zeichen  (Ascii-Nr)
  126,              // letztes Zeichen (Ascii-Nr)
};

