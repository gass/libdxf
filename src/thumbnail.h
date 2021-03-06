/*!
 * \file thumbnail.h
 * \author Copyright (C) 2008, 2010 by Bert Timmerman <bert.timmerman@xs4all.nl>.
 * \brief Header file for DXF thumbnail (\c THUMBNAIL) functions.
 *
 * <hr>
 * <h1><b>Copyright Notices.</b></h1>\n
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License,
 * or (at your option) any later version.\n\n
 * This program is distributed in the hope that it will be useful, but
 * <b>WITHOUT ANY WARRANTY</b>; without even the implied warranty of
 * <b>MERCHANTABILITY</b> or <b>FITNESS FOR A PARTICULAR PURPOSE</b>.\n
 * See the GNU General Public License for more details.\n\n
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to:\n
 * Free Software Foundation, Inc.,\n
 * 59 Temple Place,\n
 * Suite 330,\n
 * Boston,\n
 * MA 02111 USA.\n
 * \n
 * Drawing eXchange Format (DXF) is a defacto industry standard for the
 * exchange of drawing files between various Computer Aided Drafting
 * programs.\n
 * DXF is an industry standard designed by Autodesk(TM).\n
 * For more details see http://www.autodesk.com.
 * <hr>
 */


#ifndef __THUMBNAIL_H_INCLUDED__
#define __THUMBNAIL_H_INCLUDED__


#include "global.h"


/*!
 * \brief DXF definition of a thumbnail.
 */
typedef struct
dxf_thumbnail
{
        int number_of_bytes;
                /*!< group code = 90\n
                 * The number of bytes in the image (and subsequent binary
                 * chunk records). */
        char *preview_image_data;
                /*!< group code = 310\n
                 * multiple lines (256 characters maximum per line). */
} DxfThumbnail;


int dxf_write_thumbnail (DxfThumbnail *dxf_thumbnail, int acad_version_number);


#endif /* __THUMBNAIL_H_INCLUDED__ */


/* EOF */
