/*!
 * \file color.h
 * \author Copyright (C) 2008 ... 2009 by Bert Timmerman <bert.timmerman@xs4all.nl>.
 * \brief Definition of DXF color values.
 *
 * These definitions contain the following:\n
 * <ul>
 * <li>Colors mapping to standard pen widths.\n
 * <li>Colors according to the AutoCAD Color Index (ACI).\n
 * </ul>
 * <hr>
 * <h1><b>Copyright Notices.</b></h1>\n
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.\n
 * \n
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.\n
 * \n
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.\n
 * \n
 * Drawing eXchange Format (DXF) is a defacto industry standard for the
 * exchange of drawing files between various Computer Aided Drafting
 * programs.\n
 * DXF is an industry standard designed by Autodesk(TM).\n
 * For more details see http://www.autodesk.com.\n\n
 * <hr>
 */


/*!
 * \brief DXF color definitions mapping to standard pen widths.
 */
typedef enum
dxf_color
{
        DXF_COLOR_BYBLOCK = 0,
                /*!< color of the entity follows the color definition of the
                 * block in which it resides. */
        DXF_COLOR_RED = 1,
                /*!< 0.18 mm pen width. */
        DXF_COLOR_YELLOW = 2,
                /*!< 0.35 mm pen width. */
        DXF_COLOR_GREEN = 3,
                /*!< 0.50 mm pen width. */
        DXF_COLOR_CYAN = 4,
                /*!< 0.70 mm pen width. */
        DXF_COLOR_BLUE = 5,
                /*!< 1.00 mm pen width. */
        DXF_COLOR_MAGENTA = 6,
                /*!< 0.18 mm pen width. */
        DXF_COLOR_WHITE = 7,
                /*!< 0.25 mm pen width. */
        DXF_COLOR_GREY = 8,
                /*!< 0.15 mm pen width. */
        DXF_COLOR_BYLAYER = 256
                /*!< color of the entity follows the color definition of the
                 * layer on which it resides. */
} DxfColor;


/*
 * Googled and found a macro...
 *

#define RGB(R,G,B) {(R<<16)|(G<<8)|B,(R*65535)/255,(G*65535)/255,(B*65535)/255}

 *
 * I have tried it with a handful of rgb values and it works
 * (used gtk_widget_modify_bg to change the surface colour of some
 * dialogs), like:

GdkColor col = RGB(0,0,255);
gtk_widget_modify_bg ( dlg , GTK_STATE_NORMAL , &col );

 * A few changes were needed to my api.
 * For example, on Windows I returned colorrefs as int function values.
 * That is not possible for GdkColor structs, so I changed the api to
 * return a COLORREF parameter instead with:

typedef GdkColor COLORREF; // for Gtk
typedef int COLORREF; // for Windows

 * It works, but I still don't understand colours...
 *
 * Q1. the pixel component of the GdkColor struct is (R<<16)|(G<<8)|B,
 * but is the other way around in the Windows RGB macro R|(G<<16)|(B<<16).
 * I am puzzled by this.
 * I am also puzzled by the pixel value being 32 bits (r,g,b,alpha)
 * while the combined size of the r,g,b intensities is 48.
 * Why is this?
 *
 * Q2. while googling I came across this for GdkColor:
 * 'the programmer provides the r,g and b intensities and GDK fills in
 * the pixel component.'
 * When does GDK do this ?
 * By what functions ?
 *
 * Q3. I have tried reading about Colormaps and Colors in the GDK
 * reference manual, but I am getting stuck on the basics.
 * For example in the Description what does this mean:
 * 'A colormap is an object that contains the mapping between the color
 * values stored in memory and the RGB values that are used to display
 * color values.
 * In general, colormaps only contain significant information for
 * pseudo-color visuals, but even for other visual types, a colormap
 * object is required in some circumstances.'
 * Does it mean 'a colormap is a list of GdkColors like a palette' ?
 * Is the RGB value mentioned in the description the pixel component in
 * the GdkColor ?
 *
 * Q4. For GdkColor the manual says 'the GdkColor structure is used to
 * describe an allocated or unallocated color'.
 * What does allocated and unallocated color mean?
 *
 * Q5. The Colormaps and Colors Reference contains several functions,
 * but I did not use any of them.
 * It still worked with the colours coming out the way I expected.
 * When are these functions used/needed ?
 * Or are they becoming obsolete ?
 * 
 *
 * by Ken Resander [kresander@yahoo.com] 
 */

/*!
 * \brief Colors according to the AutoCAD Color Index (ACI).
 *
 * These colors are defined by:\n
 * \c dxf_ACI_color[index_number]: RGBColor (as in red value, green value, blue
 * value) and contain no alpha value.
 */
typedef enum
dxf_ACI_color
{
        dxf_ACI_color[00] = RGBColor (0,0,0),
        dxf_ACI_color[01] = RGBColor (255,0,0),
        dxf_ACI_color[02] = RGBColor (255,255,0),
        dxf_ACI_color[03] = RGBColor (0,255,0),
        dxf_ACI_color[04] = RGBColor (0,255,255),
        dxf_ACI_color[05] = RGBColor (0,0,255),
        dxf_ACI_color[06] = RGBColor (255,0,255),
        dxf_ACI_color[07] = RGBColor (255,255,255),
        dxf_ACI_color[08] = RGBColor (128,128,128),
        dxf_ACI_color[09] = RGBColor (192,192,192),
        dxf_ACI_color[10] = RGBColor (255,0,0),
        dxf_ACI_color[11] = RGBColor (255,127,127),
        dxf_ACI_color[12] = RGBColor (204,0,0),
        dxf_ACI_color[13] = RGBColor (204,102,102),
        dxf_ACI_color[14] = RGBColor (153,0,0),
        dxf_ACI_color[15] = RGBColor (153,76,76),
        dxf_ACI_color[16] = RGBColor (127,0,0),
        dxf_ACI_color[17] = RGBColor (127,63,63),
        dxf_ACI_color[18] = RGBColor (76,0,0),
        dxf_ACI_color[19] = RGBColor (76,38,38),
        dxf_ACI_color[20] = RGBColor (255,63,0),
        dxf_ACI_color[21] = RGBColor (255,159,127),
        dxf_ACI_color[22] = RGBColor (204,51,0),
        dxf_ACI_color[23] = RGBColor (204,127,102),
        dxf_ACI_color[24] = RGBColor (153,38,0),
        dxf_ACI_color[25] = RGBColor (153,95,76),
        dxf_ACI_color[26] = RGBColor (127,31,0),
        dxf_ACI_color[27] = RGBColor (127,79,63),
        dxf_ACI_color[28] = RGBColor (76,19,0),
        dxf_ACI_color[29] = RGBColor (76,47,38),
        dxf_ACI_color[30] = RGBColor (255,127,0),
        dxf_ACI_color[31] = RGBColor (255,191,127),
        dxf_ACI_color[32] = RGBColor (204,102,0),
        dxf_ACI_color[33] = RGBColor (204,153,102),
        dxf_ACI_color[34] = RGBColor (153,76,0),
        dxf_ACI_color[35] = RGBColor (153,114,76),
        dxf_ACI_color[36] = RGBColor (127,63,0),
        dxf_ACI_color[37] = RGBColor (127,95,63),
        dxf_ACI_color[38] = RGBColor (76,38,0),
        dxf_ACI_color[39] = RGBColor (76,57,38),
        dxf_ACI_color[40] = RGBColor (255,191,0),
        dxf_ACI_color[41] = RGBColor (255,223,127),
        dxf_ACI_color[42] = RGBColor (204,153,0),
        dxf_ACI_color[43] = RGBColor (204,178,102),
        dxf_ACI_color[44] = RGBColor (153,114,0),
        dxf_ACI_color[45] = RGBColor (153,133,76),
        dxf_ACI_color[46] = RGBColor (127,95,0),
        dxf_ACI_color[47] = RGBColor (127,111,63),
        dxf_ACI_color[48] = RGBColor (76,57,0),
        dxf_ACI_color[49] = RGBColor (76,66,38),
        dxf_ACI_color[50] = RGBColor (255,255,0),
        dxf_ACI_color[51] = RGBColor (255,255,127),
        dxf_ACI_color[52] = RGBColor (204,204,0),
        dxf_ACI_color[53] = RGBColor (204,204,102),
        dxf_ACI_color[54] = RGBColor (153,153,0),
        dxf_ACI_color[55] = RGBColor (153,153,76),
        dxf_ACI_color[56] = RGBColor (127,127,0),
        dxf_ACI_color[57] = RGBColor (127,127,63),
        dxf_ACI_color[58] = RGBColor (76,76,0),
        dxf_ACI_color[59] = RGBColor (76,76,38),
        dxf_ACI_color[60] = RGBColor (191,255,0),
        dxf_ACI_color[61] = RGBColor (223,255,127),
        dxf_ACI_color[62] = RGBColor (153,204,0),
        dxf_ACI_color[63] = RGBColor (178,204,102),
        dxf_ACI_color[64] = RGBColor (114,153,0),
        dxf_ACI_color[65] = RGBColor (133,153,76),
        dxf_ACI_color[66] = RGBColor (95,127,0),
        dxf_ACI_color[67] = RGBColor (111,127,63),
        dxf_ACI_color[68] = RGBColor (57,76,0),
        dxf_ACI_color[69] = RGBColor (66,76,38),
        dxf_ACI_color[70] = RGBColor (127,255,0),
        dxf_ACI_color[71] = RGBColor (191,255,127),
        dxf_ACI_color[72] = RGBColor (102,204,0),
        dxf_ACI_color[73] = RGBColor (153,204,102),
        dxf_ACI_color[74] = RGBColor (76,153,0),
        dxf_ACI_color[75] = RGBColor (114,153,76),
        dxf_ACI_color[76] = RGBColor (63,127,0),
        dxf_ACI_color[77] = RGBColor (95,127,63),
        dxf_ACI_color[78] = RGBColor (38,76,0),
        dxf_ACI_color[79] = RGBColor (57,76,38),
        dxf_ACI_color[80] = RGBColor (63,255,0),
        dxf_ACI_color[81] = RGBColor (159,255,127),
        dxf_ACI_color[82] = RGBColor (51,204,0),
        dxf_ACI_color[83] = RGBColor (127,204,102),
        dxf_ACI_color[84] = RGBColor (38,153,0),
        dxf_ACI_color[85] = RGBColor (95,153,76),
        dxf_ACI_color[86] = RGBColor (31,127,0),
        dxf_ACI_color[87] = RGBColor (79,127,63),
        dxf_ACI_color[88] = RGBColor (19,76,0),
        dxf_ACI_color[89] = RGBColor (47,76,38),
        dxf_ACI_color[90] = RGBColor (0,255,0),
        dxf_ACI_color[91] = RGBColor (127,255,127),
        dxf_ACI_color[92] = RGBColor (0,204,0),
        dxf_ACI_color[93] = RGBColor (102,204,102),
        dxf_ACI_color[94] = RGBColor (0,153,0),
        dxf_ACI_color[95] = RGBColor (76,153,76),
        dxf_ACI_color[96] = RGBColor (0,127,0),
        dxf_ACI_color[97] = RGBColor (63,127,63),
        dxf_ACI_color[98] = RGBColor (0,76,0),
        dxf_ACI_color[99] = RGBColor (38,76,38),
        dxf_ACI_color[100] = RGBColor (0,255,63),
        dxf_ACI_color[101] = RGBColor (127,255,159),
        dxf_ACI_color[102] = RGBColor (0,204,51),
        dxf_ACI_color[103] = RGBColor (102,204,127),
        dxf_ACI_color[104] = RGBColor (0,153,38),
        dxf_ACI_color[105] = RGBColor (76,153,95),
        dxf_ACI_color[106] = RGBColor (0,127,31),
        dxf_ACI_color[107] = RGBColor (63,127,79),
        dxf_ACI_color[108] = RGBColor (0,76,19),
        dxf_ACI_color[109] = RGBColor (38,76,47),
        dxf_ACI_color[110] = RGBColor (0,255,127),
        dxf_ACI_color[111] = RGBColor (127,255,191),
        dxf_ACI_color[112] = RGBColor (0,204,102),
        dxf_ACI_color[113] = RGBColor (102,204,153),
        dxf_ACI_color[114] = RGBColor (0,153,76),
        dxf_ACI_color[115] = RGBColor (76,153,114),
        dxf_ACI_color[116] = RGBColor (0,127,63),
        dxf_ACI_color[117] = RGBColor (63,127,95),
        dxf_ACI_color[118] = RGBColor (0,76,38),
        dxf_ACI_color[119] = RGBColor (38,76,57),
        dxf_ACI_color[120] = RGBColor (0,255,191),
        dxf_ACI_color[121] = RGBColor (127,255,223),
        dxf_ACI_color[122] = RGBColor (0,204,153),
        dxf_ACI_color[123] = RGBColor (102,204,178),
        dxf_ACI_color[124] = RGBColor (0,153,114),
        dxf_ACI_color[125] = RGBColor (76,153,133),
        dxf_ACI_color[126] = RGBColor (0,127,95),
        dxf_ACI_color[127] = RGBColor (63,127,111),
        dxf_ACI_color[128] = RGBColor (0,76,57),
        dxf_ACI_color[129] = RGBColor (38,76,66),
        dxf_ACI_color[130] = RGBColor (0,255,255),
        dxf_ACI_color[131] = RGBColor (127,255,255),
        dxf_ACI_color[132] = RGBColor (0,204,204),
        dxf_ACI_color[133] = RGBColor (102,204,204),
        dxf_ACI_color[134] = RGBColor (0,153,153),
        dxf_ACI_color[135] = RGBColor (76,153,153),
        dxf_ACI_color[136] = RGBColor (0,127,127),
        dxf_ACI_color[137] = RGBColor (63,127,127),
        dxf_ACI_color[138] = RGBColor (0,76,76),
        dxf_ACI_color[139] = RGBColor (38,76,76),
        dxf_ACI_color[140] = RGBColor (0,191,255),
        dxf_ACI_color[141] = RGBColor (127,223,255),
        dxf_ACI_color[142] = RGBColor (0,153,204),
        dxf_ACI_color[143] = RGBColor (102,178,204),
        dxf_ACI_color[144] = RGBColor (0,114,153),
        dxf_ACI_color[145] = RGBColor (76,133,153),
        dxf_ACI_color[146] = RGBColor (0,95,127),
        dxf_ACI_color[147] = RGBColor (63,111,127),
        dxf_ACI_color[148] = RGBColor (0,57,76),
        dxf_ACI_color[149] = RGBColor (38,66,76),
        dxf_ACI_color[150] = RGBColor (0,127,255),
        dxf_ACI_color[151] = RGBColor (127,191,255),
        dxf_ACI_color[152] = RGBColor (0,102,204),
        dxf_ACI_color[153] = RGBColor (102,153,204),
        dxf_ACI_color[154] = RGBColor (0,76,153),
        dxf_ACI_color[155] = RGBColor (76,114,153),
        dxf_ACI_color[156] = RGBColor (0,63,127),
        dxf_ACI_color[157] = RGBColor (63,95,127),
        dxf_ACI_color[158] = RGBColor (0,38,76),
        dxf_ACI_color[159] = RGBColor (38,57,76),
        dxf_ACI_color[160] = RGBColor (0,63,255),
        dxf_ACI_color[161] = RGBColor (127,159,255),
        dxf_ACI_color[162] = RGBColor (0,51,204),
        dxf_ACI_color[163] = RGBColor (102,127,204),
        dxf_ACI_color[164] = RGBColor (0,38,153),
        dxf_ACI_color[165] = RGBColor (76,95,153),
        dxf_ACI_color[166] = RGBColor (0,31,127),
        dxf_ACI_color[167] = RGBColor (63,79,127),
        dxf_ACI_color[168] = RGBColor (0,19,76),
        dxf_ACI_color[169] = RGBColor (38,47,76),
        dxf_ACI_color[255] = RGBColor (255,255,255)
}
DxfACIColor;


/*!
 * \brief Color names according to the Wikipedia List of Colors.
 *
 * These color names are defined by Wikipedia's
 * <a href="http://en.wikipedia.org/wiki/List_of_colors">
 * List of colors</a>\n
 * \c dxf_RGB_color_name[hex_triplet], where \c hex_triplet are the
 * hexadecimal values as in red value, green value, blue value
 * (0xRRGGBB) and this index contains no alpha values.
 */
typedef enum
dxf_RGB_color_name
{
        dxf_RGB_color_name[0xF0F8FF] = "Alice blue",
        dxf_RGB_color_name[0xE32636] = "Alizarin",
        dxf_RGB_color_name[0xE52B50] = "Amaranth",
        dxf_RGB_color_name[0xF19CBB] = "Amaranth Pink",
        dxf_RGB_color_name[0xFFBF00] = "Amber",
        dxf_RGB_color_name[0x9966CC] = "Amethyst",
        dxf_RGB_color_name[0xFBCEB1] = "Apricot",
        dxf_RGB_color_name[0x00FFFF] = "Aqua",
        dxf_RGB_color_name[0x7FFFD4] = "Aquamarine"
        dxf_RGB_color_name[0x4B5320] = "Aemy green",
        dxf_RGB_color_name[0x7BA05B] = "Asparagus",
        dxf_RGB_color_name[0xFF9966] = "Atomic tangerine",
        dxf_RGB_color_name[0x6D351A] = "Auburn",
        dxf_RGB_color_name[0x007FFF] = "Azure (color wheel)",
        dxf_RGB_color_name[0xF0FFFF] = "Azure (web)",
        dxf_RGB_color_name[0xE0FFFF] = "Baby blue",
        dxf_RGB_color_name[0xF5F5DC] = "Beige",
        dxf_RGB_color_name[0x3D2B1F] = "Bistre",
        dxf_RGB_color_name[0x000000] = "Black",
        dxf_RGB_color_name[0x0000FF] = "Blue",
        dxf_RGB_color_name[0x333399] = "Blue (pigment)",
        dxf_RGB_color_name[0x0247FE] = "Blue (RYB)",
        dxf_RGB_color_name[0x00DDDD] = "Blue-green",
        dxf_RGB_color_name[0x8A2BE2] = "Blue-violet",
        dxf_RGB_color_name[0x0095B6] = "Bondi blue",
        dxf_RGB_color_name[0xB5A642] = "Brass",
        dxf_RGB_color_name[0x66FF00] = "Bright green",
        dxf_RGB_color_name[0xFF007F] = "Bright pink",
        dxf_RGB_color_name[0x08E8DE] = "Bright turquoise",
        dxf_RGB_color_name[0xFF55A3] = "Brilliant rose",
        dxf_RGB_color_name[0xFB607F] = "Brink pink",
        dxf_RGB_color_name[0xCD7F32] = "Bronze",
        dxf_RGB_color_name[0x964B00] = "Brown",
        dxf_RGB_color_name[0xF0DC82] = "Buff",
        dxf_RGB_color_name[0x900020] = "Burgundy",
        dxf_RGB_color_name[0xCC5500] = "Burnt orange",
        dxf_RGB_color_name[0xE97451] = "Burnt sienna",
        dxf_RGB_color_name[0x8A3324] = "Burnt umber",
        dxf_RGB_color_name[0x78866B] = "Camouflage green",
        dxf_RGB_color_name[0x592720] = "Caput mortuum",
        dxf_RGB_color_name[0xC41E3A] = "Cardinal",
        dxf_RGB_color_name[0x960018] = "Carmine",
        dxf_RGB_color_name[0xEB4C42] = "Carmine Pink",
        dxf_RGB_color_name[0xFFA6C9] = "Carnation pink",
        dxf_RGB_color_name[0x99BADD] = "Carolina blue",
        dxf_RGB_color_name[0xED9121] = "Carrot orange",
        dxf_RGB_color_name[0xACE1AF] = "Celadon",
        dxf_RGB_color_name[0xDE3163] = "Cerise",
        dxf_RGB_color_name[0xEC3B83] = "Cerise Pink",
        dxf_RGB_color_name[0x007BA7] = "Cerulean",
        dxf_RGB_color_name[0x2A52BE] = "Cerulean blue",
        dxf_RGB_color_name[0xF7E7CE] = "Champagne",
        dxf_RGB_color_name[0x464646] = "Charcoal",
        dxf_RGB_color_name[0xDFFF00] = "Chartreuse (traditional)",
        dxf_RGB_color_name[0x7FFF00] = "Chartreuse (web)",
        dxf_RGB_color_name[0xFFB7C5] = "Cherry blossom pink",
        dxf_RGB_color_name[0xCD5C5C] = "Chestnut",
        dxf_RGB_color_name[0x7B3F00] = "Chocolate",
        dxf_RGB_color_name[0xE34234] = "Cinnabar",
        dxf_RGB_color_name[0xD2691E] = "Cinnamon",
        dxf_RGB_color_name[0x0047AB] = "Cobalt",
        dxf_RGB_color_name[0x9BDDFF] = "Columbia blue",
        dxf_RGB_color_name[0xB87333] = "Copper",
        dxf_RGB_color_name[0x996666] = "Copper rose",
        dxf_RGB_color_name[0xFF7F50] = "Coral",
        dxf_RGB_color_name[0xF88379] = "Coral pink",
        dxf_RGB_color_name[0xFF4040] = "Coral red",
        dxf_RGB_color_name[0xFBEC5D] = "Corn",
        dxf_RGB_color_name[0x6495ED] = "Cornflower blue",
        dxf_RGB_color_name[0xFFF8E7] = "Cosmic latte",
        dxf_RGB_color_name[0xFFFDD0] = "Cream",
        dxf_RGB_color_name[0xDC143C] = "Crimson",
        dxf_RGB_color_name[0x00FFFF] = "Cyan",
        dxf_RGB_color_name[0x00B7EB] = "Cyan (process)",
        dxf_RGB_color_name[0x00008B] = "Dark blue",
        dxf_RGB_color_name[0x654321] = "Dark brown",
        dxf_RGB_color_name[0x08457E] = "Dark cerulean",
        dxf_RGB_color_name[0x986960] = "Dark chestnut",
        dxf_RGB_color_name[0xCD5B45] = "Dark coral",
        dxf_RGB_color_name[0xB8860B] = "Dark goldenrod",
        dxf_RGB_color_name[0x013220] = "Dark green",
        dxf_RGB_color_name[0xBDB76B] = "Dark khaki",
        dxf_RGB_color_name[0x8B008B] = "Dark magenta",
        dxf_RGB_color_name[0x03C03C] = "Dark pastel green",
        dxf_RGB_color_name[0xE75480] = "Dark pink",
        dxf_RGB_color_name[0x560319] = "Dark scarlet",
        dxf_RGB_color_name[0xE9967A] = "Dark salmon",
        dxf_RGB_color_name[0x2F4F4F] = "Dark slate gray",
        dxf_RGB_color_name[0x177245] = "Dark spring green",
        dxf_RGB_color_name[0x918151] = "Dark tan",
        dxf_RGB_color_name[0x00CED1] = "Dark turquoise",
        dxf_RGB_color_name[0x9400D3] = "Dark violet",
        dxf_RGB_color_name[0xEF3038] = "Deep Carmine Pink",
        dxf_RGB_color_name[0xDA3287] = "Deep cerise",
        dxf_RGB_color_name[0xB94E48] = "Deep chestnut",
        dxf_RGB_color_name[0xC154C1] = "Deep fuchsia",
        dxf_RGB_color_name[0x9955BB] = "Deep lilac",
        dxf_RGB_color_name[0xCD00CC] = "Deep magenta",
        dxf_RGB_color_name[0xFFCBA4] = "Deep peach",
        dxf_RGB_color_name[0xFF1493] = "Deep pink",
        dxf_RGB_color_name[0x1560BD] = "Denim",
        dxf_RGB_color_name[0x1E90FF] = "Dodger blue",
        dxf_RGB_color_name[0xC2B280] = "Ecru",
        dxf_RGB_color_name[0x1034A6] = "Egyptian blue",
        dxf_RGB_color_name[0x7DF9FF] = "Electric blue",
        dxf_RGB_color_name[0x00FF00] = "Electric green (X11 green)",
        dxf_RGB_color_name[0x6600FF] = "Electric indigo",
        dxf_RGB_color_name[0xCCFF00] = "Electric lime",
        dxf_RGB_color_name[0xBF00FF] = "Electric purple",
        dxf_RGB_color_name[0x50C878] = "Emerald",
        dxf_RGB_color_name[0x614051] = "Eggplant",
        dxf_RGB_color_name[0x801818] = "Falu red",
        dxf_RGB_color_name[0x4F7942] = "Fern green",
        dxf_RGB_color_name[0xB22222] = "Firebrick",
        dxf_RGB_color_name[0xEEDC82] = "Flax",
        dxf_RGB_color_name[0x228B22] = "Forrest green",
        dxf_RGB_color_name[0xF64A8A] = "French Rose",
        dxf_RGB_color_name[0xFF00FF] = "Fuchsia",
        dxf_RGB_color_name[0xFF77FF] = "Fuchsia Pink",
        dxf_RGB_color_name[0xE49B0F] = "Gamboge",
        dxf_RGB_color_name[0xD4AF37] = "Gold (metallic)",
        dxf_RGB_color_name[0xFFD700] = "Gold (web) (Golden)",
        dxf_RGB_color_name[0x996515] = "Golden brown",
        dxf_RGB_color_name[0xFFDF00] = "Golden yellow",
        dxf_RGB_color_name[0xDAA520] = "Goldenrod",
        dxf_RGB_color_name[0x465945] = "Gray-asparagus",
        dxf_RGB_color_name[0x00FF00] = "Green (color wheel) (X11 green)",
        dxf_RGB_color_name[0x008000] = "Green (HTML/CSS green)",
        dxf_RGB_color_name[0x00A550] = "Green (pigment)",
        dxf_RGB_color_name[0x66B032] = "Green (RYB)",
        dxf_RGB_color_name[0xADFF2F] = "Green-yellow",
        dxf_RGB_color_name[0x808080] = "Gray",
        dxf_RGB_color_name[0x5218FA] = "Han Purple",
        dxf_RGB_color_name[0x3FFF00] = "Harlequin",
        dxf_RGB_color_name[0xDF73FF] = "Heliotrope",
        dxf_RGB_color_name[0xF400A1] = "Hollywood Cerise",
        dxf_RGB_color_name[0xFF00CC] = "Hot Magenta",
        dxf_RGB_color_name[0xFF69B4] = "Hot Pink",
        dxf_RGB_color_name[0x00416A] = "Indigo (dye)",
        dxf_RGB_color_name[0x4B0082] = "Indigo (web)",
        dxf_RGB_color_name[0x002FA7] = "International Klein Blue",
        dxf_RGB_color_name[0xFF4F00] = "International orange",
        dxf_RGB_color_name[0x009000] = "Islamic green",
        dxf_RGB_color_name[0xFFFFF0] = "Ivory",
        dxf_RGB_color_name[0x00A86B] = "Jade",
        dxf_RGB_color_name[0x4CBB17] = "Kelly green",
        dxf_RGB_color_name[0xC3B091] = "Khaki",
        dxf_RGB_color_name[0xF0E68C] = "Khaki (X11) (Light khaki)",
        dxf_RGB_color_name[0xB57EDC] = "Lavender (floral)",
        dxf_RGB_color_name[0xE6E6FA] = "Lavender (web)",
        dxf_RGB_color_name[0xCCCCFF] = "Lavender blue",
        dxf_RGB_color_name[0xFFF0F5] = "Lavender blush",
        dxf_RGB_color_name[0xC4C3D0] = "Lavender gray",
        dxf_RGB_color_name[0xEE82EE] = "Lavender magenta",
        dxf_RGB_color_name[0xFBAED2] = "Lavender pink",
        dxf_RGB_color_name[0x967BB6] = "Lavender purple",
        dxf_RGB_color_name[0xFBA0E3] = "Lavender rose",
        dxf_RGB_color_name[0x7CFC00] = "Lawn green",
        dxf_RGB_color_name[0xFDE910] = "Lemon",
        dxf_RGB_color_name[0xFFFACD] = "Lemon chifton",
        dxf_RGB_color_name[0xADD8E6] = "Light blue",
        dxf_RGB_color_name[0xFFB6C1] = "Light pink",
        dxf_RGB_color_name[0xC8A2C8] = "Lilac",
        dxf_RGB_color_name[0xBFFF00] = "Lime (color wheel)",
        dxf_RGB_color_name[0x00FF00] = "Lime (web) (X11 green)",
        dxf_RGB_color_name[0x32CD32] = "Lime green",
        dxf_RGB_color_name[0xFAF0E6] = "Linen",
        dxf_RGB_color_name[0xFF00FF] = "Magenta",
        dxf_RGB_color_name[0xCA1F7B] = "Magenta (dye)",
        dxf_RGB_color_name[0xFF0090] = "Magenta (process)",
        dxf_RGB_color_name[0xAAF0D1] = "Magic mint",
        dxf_RGB_color_name[0xF8F4FF] = "Magnolia",
        dxf_RGB_color_name[0x0BDA51] = "Malachite",
        dxf_RGB_color_name[0x800000] = "Maroon (HTML/CSS)",
        dxf_RGB_color_name[0xB03060] = "Maroon (X11)",
        dxf_RGB_color_name[0x73C2FB] = "Maya blue",
        dxf_RGB_color_name[0xE0B0FF] = "Mauve",
        dxf_RGB_color_name[0x915F6D] = "Mauve Taupe",
        dxf_RGB_color_name[0x0000CD] = "Medium blue",
        dxf_RGB_color_name[0xAF4035] = "Medium carmine",
        dxf_RGB_color_name[0xCC99CC] = "Medium lavender magenta",
        dxf_RGB_color_name[0x9370DB] = "Medium purple",
        dxf_RGB_color_name[0x00FA9A] = "Medium spring green",
        dxf_RGB_color_name[0x191970] = "Midnight Blue",
        dxf_RGB_color_name[0x004953] = "Midnight Green (Eagle Green)",
        dxf_RGB_color_name[0x98FF98] = "Mint green",
        dxf_RGB_color_name[0xFFE4E1] = "Misty rose",
        dxf_RGB_color_name[0xADDFAD] = "Moss green",
        dxf_RGB_color_name[0x997A8D] = "Mountbatten pink",
        dxf_RGB_color_name[0xFFDB58] = "Mustard",
        dxf_RGB_color_name[0x21421E] = "Myrtle",
        dxf_RGB_color_name[0x006633] = "MSU Green",
        dxf_RGB_color_name[0xFFDEAD] = "Navajo white",
        dxf_RGB_color_name[0x000080] = "Navy Blue",
        dxf_RGB_color_name[0xCC7722] = "Ochre",
        dxf_RGB_color_name[0x008000] = "Office green",
        dxf_RGB_color_name[0xCFB53B] = "Old Gold",
        dxf_RGB_color_name[0xFDF5E6] = "Old Lace",
        dxf_RGB_color_name[0x796878] = "Old Lavender",
        dxf_RGB_color_name[0xC08081] = "Old Rose",
        dxf_RGB_color_name[0x808000] = "Olive",
        dxf_RGB_color_name[0x6B8E23] = "Olive Drab",
        dxf_RGB_color_name[0x9AB973] = "Olivine",
        dxf_RGB_color_name[0xFF7F00] = "Orange (color wheel)",
        dxf_RGB_color_name[0xFB9902] = "Orange (RYB)",
        dxf_RGB_color_name[0xFFA500] = "Orange (web)",
        dxf_RGB_color_name[0xFFA000] = "Orange Peel",
        dxf_RGB_color_name[0xFF4500] = "Orange-Red",
        dxf_RGB_color_name[0xDA70D6] = "Orchid",
        dxf_RGB_color_name[0xAFEEEE] = "Pale blue",
        dxf_RGB_color_name[0x987654] = "Pale brown",
        dxf_RGB_color_name[0xAF4035] = "Pale carmine",
        dxf_RGB_color_name[0xDDADAF] = "Pale chestnut",
        dxf_RGB_color_name[0xABCDEF] = "Pale cornflower blue",
        dxf_RGB_color_name[0xF984E5] = "Pale magenta",
        dxf_RGB_color_name[0xFADADD] = "Pale pink",
        dxf_RGB_color_name[0xDB7093] = "Pale red-violet",
        dxf_RGB_color_name[0xBC987E] = "Pale taupe",
        dxf_RGB_color_name[0xFFEFD5] = "Papaya whip",
        dxf_RGB_color_name[0x77DD77] = "Pastel green",
        dxf_RGB_color_name[0xFFD1DC] = "Pastel pink",
        dxf_RGB_color_name[0x40404F] = "Payne's grey",
        dxf_RGB_color_name[0xFFE5B4] = "Peach",
        dxf_RGB_color_name[0xFFCC99] = "Peach-orange",
        dxf_RGB_color_name[0xFADFAD] = "Peach-yellow",
        dxf_RGB_color_name[0xD1E231] = "Pear",
        dxf_RGB_color_name[0xCCCCFF] = "Periwinkle",
        dxf_RGB_color_name[0x1C39BB] = "Persian blue",
        dxf_RGB_color_name[0x00A693] = "Persian green",
        dxf_RGB_color_name[0x32127A] = "Persian indigo",
        dxf_RGB_color_name[0xD99058] = "Persian orange",
        dxf_RGB_color_name[0xCC3333] = "Persian red",
        dxf_RGB_color_name[0xF77FBE] = "Persian pink",
        dxf_RGB_color_name[0xFE28A2] = "Persian rose",
        dxf_RGB_color_name[0xEC5800] = "Persimmon",
        dxf_RGB_color_name[0x01796F] = "Pine green",
        dxf_RGB_color_name[0xFFC0CB] = "Pink",
        dxf_RGB_color_name[0xFF9966] = "Pink-orange",
        dxf_RGB_color_name[0xE5E4E2] = "Platinum",
        dxf_RGB_color_name[0xCC99CC] = "Plum (web)",
        dxf_RGB_color_name[0xFF5A36] = "Portland Orange",
        dxf_RGB_color_name[0xB0E0E6] = "Powder blue (web)",
        dxf_RGB_color_name[0xCC8899] = "Puce",
        dxf_RGB_color_name[0x003153] = "Prusian blue",
        dxf_RGB_color_name[0xDD00FF] = "Psychedelic purple",
        dxf_RGB_color_name[0xFF7518] = "Pumpkin",
        dxf_RGB_color_name[0x7F007F] = "Purple (HTML/CSS)",
        dxf_RGB_color_name[0xA020F0] = "Purple (X11)",
        dxf_RGB_color_name[0x50404D] = "Purple Taupe",
        dxf_RGB_color_name[0xE30B5C] = "Raspberry",
        dxf_RGB_color_name[0x734A12] = "Raw umber",
        dxf_RGB_color_name[0xE3256B] = "Razzmatazz",
        dxf_RGB_color_name[0xFF0000] = "Red",
        dxf_RGB_color_name[0xED1C24] = "Red (pigment)",
        dxf_RGB_color_name[0xFE2712] = "Red (RYB)",
        dxf_RGB_color_name[0xC71585] = "Red-violet",
        dxf_RGB_color_name[0xD70040] = "Rich carmine",
        dxf_RGB_color_name[0x00CCCC] = "Robin egg blue",
        dxf_RGB_color_name[0xFF007F] = "Rose",
        dxf_RGB_color_name[0xE32636] = "Rose Madder",
        dxf_RGB_color_name[0xFF66CC] = "Rose pink",
        dxf_RGB_color_name[0xAA98A9] = "Rose quartz",
        dxf_RGB_color_name[0x905D5D] = "Rose Taupe",
        dxf_RGB_color_name[0x4169E1] = "Royal blue",
        dxf_RGB_color_name[0x6B3FA0] = "Royal purple",
        dxf_RGB_color_name[0xE0115F] = "Ruby",
        dxf_RGB_color_name[0x80461B] = "Russet",
        dxf_RGB_color_name[0xB7410E] = "Rust",
        dxf_RGB_color_name[0xFF6600] = "Safety orange (blaze orange)",
        dxf_RGB_color_name[0xF4C430] = "Saffron",
        dxf_RGB_color_name[0xFF8C69] = "Salmon",
        dxf_RGB_color_name[0xFF91A4] = "Salmon pink",
        dxf_RGB_color_name[0xF4A460] = "Sandy brown",
        dxf_RGB_color_name[0x92000A] = "Sangria",
        dxf_RGB_color_name[0x082567] = "Sapphire",
        dxf_RGB_color_name[0xFF2400] = "Scarlet",
        dxf_RGB_color_name[0xFFD800] = "School bus yellow",
        dxf_RGB_color_name[0x2E8B57] = "Sea green",
        dxf_RGB_color_name[0x321414] = "Seal brown",
        dxf_RGB_color_name[0xFFF5EE] = "Seashell",
        dxf_RGB_color_name[0xFFBA00] = "Selective yellow",
        dxf_RGB_color_name[0x704214] = "Sepia",
        dxf_RGB_color_name[0x009E60] = "Shamrock green",
        dxf_RGB_color_name[0xFC0FC0] = "Shocking pink",
        dxf_RGB_color_name[0xA0522D] = "Sienna",
        dxf_RGB_color_name[0xC0C0C0] = "Silver",
        dxf_RGB_color_name[0x87CEEB] = "Sky Blue",
        dxf_RGB_color_name[0x708090] = "Slate grey",
        dxf_RGB_color_name[0x003399] = "Smalt (Dark powder blue)",
        dxf_RGB_color_name[0xA7FC00] = "Spring bud",
        dxf_RGB_color_name[0x00FF7F] = "Spring green",
        dxf_RGB_color_name[0x4682B4] = "Steel blue",
        dxf_RGB_color_name[0xD2B48C] = "Tan",
        dxf_RGB_color_name[0xF28500] = "Tangerine",
        dxf_RGB_color_name[0xFFCC00] = "Tangerine yellow",
        dxf_RGB_color_name[0x483C32] = "Taupe",
        dxf_RGB_color_name[0x8B8589] = "Taupe gray",
        dxf_RGB_color_name[0xD0F0C0] = "Tea green",
        dxf_RGB_color_name[0xF88379] = "Tea rose (orange)",
        dxf_RGB_color_name[0xF4C2C2] = "Tea rose (rose)",
        dxf_RGB_color_name[0x008080] = "Teal",
        dxf_RGB_color_name[0xCD5700] = "Tenné (Tawny)",
        dxf_RGB_color_name[0xE2725B] = "Terra cotta",
        dxf_RGB_color_name[0xD8BFD8] = "Thistle",
        dxf_RGB_color_name[0xDE6FA1] = "Thullian pink",
        dxf_RGB_color_name[0xFF6347] = "Tomato",
        dxf_RGB_color_name[0x30D5C8] = "Turquoise",
        dxf_RGB_color_name[0x66023C] = "Tyrian Purple",
        dxf_RGB_color_name[0x120A8F] = "Ultramarine",
        dxf_RGB_color_name[0xFF6FFF] = "Ultra pink",
        dxf_RGB_color_name[0x5B92E5] = "United Nations blue",
        dxf_RGB_color_name[0xAE2029] = "Upsdell red",
        dxf_RGB_color_name[0xC5B358] = "Vegas Gold",
        dxf_RGB_color_name[0xC80815] = "Venetian red",
        dxf_RGB_color_name[0xE34234] = "Vermilion",
        dxf_RGB_color_name[0x8B00FF] = "Violet",
        dxf_RGB_color_name[0xEE82EE] = "Violet (web)",
        dxf_RGB_color_name[0x8601AF] = "Violet (RYB)",
        dxf_RGB_color_name[0x40826D] = "Viridian",
        dxf_RGB_color_name[0xF5DEB3] = "Wheat",
        dxf_RGB_color_name[0xFFFFFF] = "White",
        dxf_RGB_color_name[0xC9A0DC] = "Wisteria",
        dxf_RGB_color_name[0x738678] = "Xanadu",
        dxf_RGB_color_name[0x0F4D92] = "Yale Blue",
        dxf_RGB_color_name[0xFFFF00] = "Yellow",
        dxf_RGB_color_name[0xFFEF00] = "Yellow (process)",
        dxf_RGB_color_name[0xFEFE33] = "Yellow (RYB)",
        dxf_RGB_color_name[0x9ACD32] = "Yellow-green"
}
DxfRGBColorName;


/* EOF */
