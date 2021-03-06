/*!
 * \file insert.h
 * \author Copyright (C) 2008, 2010 by Bert Timmerman <bert.timmerman@xs4all.nl>.
 * \brief Header file for a DXF insert entity (\c INSERT).
 *
 * A DXF \c INSERT entity is an insertion for a (external) \c BLOCK entity.\n
 * Whilst a \c BLOCK only resides in the block table only once as a
 * definition, an \c INSERT entity can insert blocks as singlular entities
 * and also as [rectanglar, polar] arrays in the drawing.
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


#ifndef _INSERT_H
#define _INSERT_H


#include "global.h"
#include "entity.h"


/*!
 * \brief DXF definition of an AutoCAD block or external reference insert
 * entity.
 */
typedef struct
dxf_insert
{
        DxfEntity common;
                /*!< common properties for DXF entities. */
        char *block_name;
                /*!< group code = 2. */
        double x0;
                /*!< group code = 10\n
                 * base point. */
        double y0;
                /*!< group code = 20\n
                 * base point. */
        double z0;
                /*!< group code = 30\n
                 * base point. */
        double rel_x_scale;
                /*!< group code = 41\n
                 * optional, defaults to 1.0. */
        double rel_y_scale;
                /*!< group code = 42\n
                 * optional, defaults to 1.0. */
        double rel_z_scale;
                /*!< group code = 43\n
                 * optional, defaults to 1.0. */
        double column_spacing;
                /*!< group code = 44\n
                 * optional, defaults to 0.0. */
        double row_spacing;
                /*!< group code = 45\n
                 * optional, defaults to 0.0. */
        double rot_angle;
                /*!< group code = 50\n
                 * optional, defaults to 0.0. */
        int attributes_follow;
                /*!< group code = 66\n
                 * optional, defaults to 0\n
                 * If the value of the "Attributes follow" flag is 1,
                 * a series of Attribute (Attrib) entities is expected to
                 * follow the Insert, terminated by a sequence end (Seqend)
                 * entity. */
        int columns;
                /*!< group code = 70\n
                 * optional, defaults to 1. */
        int rows;
                /*!< group code = 71\n
                 * optional, defaults to 1. */
        double extr_x0;
                /*!< X-value of the extrusion vector.\n
                 * Defaults to 0.0 if ommitted in the DXF file.\n
                 * Group code = 210. */
        double extr_y0;
                /*!< Y-value of the extrusion vector.\n
                 * Defaults to 0.0 if ommitted in the DXF file.\n
                 * Group code = 220. */
        double extr_z0;
                /*!< Z-value of the extrusion vector.\n
                 * Defaults to 1.0 if ommitted in the DXF file.\n
                 * Group code = 230. */
} DxfInsert, * DxfInsertPtr;


DxfInsert *
dxf_insert_new ();
DxfInsert *
dxf_insert_init
(
        DxfInsert *dxf_insert
);
int
dxf_insert_read
(
        char *filename,
        FILE *fp,
        int *line_number,
        DxfInsert *dxf_insert,
        int acad_version_number
);
int
dxf_insert_write_lowlevel
(
        FILE *fp,
        int id_code,
        char *block_name,
        char *linetype,
        char *layer,
        double x0,
        double y0,
        double z0,
        double thickness,
        double rel_x_scale,
        double rel_y_scale,
        double rel_z_scale,
        double column_spacing,
        double row_spacing,
        double rot_angle,
        int color,
        int attribute_follows,
        int paperspace,
        int columns,
        int rows
);
int
dxf_insert_write
(
        FILE *fp,
        DxfInsert dxf_insert
);


#endif /* _INSERT_H */


/* EOF */
