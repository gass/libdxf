/*!
 * \file class.h
 * \author Copyright (C) 2009 by Bert Timmerman <bert.timmerman@xs4all.nl>.
 * \brief Defintion of a DXF class entity (\c CLASS).
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

#include "global.h"

/*!
 * \brief DXF definition of a class entity.
 */
typedef struct
dxf_class
{
        char *record_type;
                /*!< group code  = 0.\n
                 * Record type (CLASS).\n
                 * Identifies the beginning of a CLASS record. */
        char *record_name;
                /*!< group code = 1.\n
                 * Class DXF record name.\n
                 * hese should always be unique. */
        char *class_name;
                /*!< group code = 2.\n
                 * C++ class name.\n
                 * sed to bind with software that defines object class behavior.\n
                 * hese are always unique. */  
        char *app_name;
                /*!< group code = 3.\n
                 * Application name.\n
                 * Posted in Alert box when a class definition listed in this
                 * section is not currently loaded. */ 
        int proxy_cap_flag;
                /*!< group code = 90.\n
                 * Proxy capabilities flag.\n
                 * Bit coded value that indicates the capabilities of this object as a proxy.\n
                 * 0 = No operations allowed (0)\n
                 * 1 = Erase allowed (0x1)\n
                 * 2 = Transform allowed (0x2)\n
                 * 4 = Color change allowed (0x4)\n
                 * 8 = Layer change allowed (0x8)\n
                 * 16 = Linetype change allowed (0x10)\n
                 * 32 = Linetype scale change allowed (0x20)\n
                 * 64 = Visibility change allowed (0x40)\n
                 * 127 = All operations except cloning allowed (0x7F)\n
                 * 128 = Cloning allowed (0x80)\n
                 * 255 = All operations allowed (0xFF)\n
                 * 32768 = R13 format proxy (0x8000). */
        int was_a_proxy_flag;
                /*!< group code = 280.\n
                 * Was-a-proxy flag.\n
                 * Set to 1 if class was not loaded when this DXF file was
                 * created, and 0 otherwise. */
        int is_an_entity_flag;
                /*!< group code = 281.\n
                 * Is-an-entity flag.\n
                 * Set to 1 if class was derived from the AcDbEntity class and
                 * can reside in the BLOCKS or ENTITIES section.\n
                 * If 0, instances may appear only in the OBJECTS section. */
} DxfClass, * DxfClassPtr;

/* EOF */