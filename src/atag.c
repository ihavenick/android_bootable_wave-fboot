/*
 ; This file is part of Badadroid project.
 ;
 ; Copyright (C) 2012 Rebellos, mijoma, b_kubica
 ;
 ;
 ; Badadroid is free software: you can redistribute it and/or modify
 ; it under the terms of the GNU General Public License as published by
 ; the Free Software Foundation, either version 3 of the License, or
 ; (at your option) any later version.
 ;
 ; Badadroid is distributed in the hope that it will be useful,
 ; but WITHOUT ANY WARRANTY; without even the implied warranty of
 ; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ; GNU General Public License for more details.
 ;
 ; You should have received a copy of the GNU General Public License
 ; along with Badadroid.  If not, see <http://www.gnu.org/licenses/>.
 ;
 ;
*/

#include "atag.h"
#include "string.h"

#define tag_next(t)     ((struct atag *)((unsigned long *)(t) + (t)->hdr.size))
#define tag_size(type)  ((sizeof(struct atag_header) + sizeof(struct type)) >> 2)
struct atag *params; /* used to point at the current tag */

void setup_core_tag(void * address)
{
    params = (struct atag *)address;         /* Initialise parameters to start at given address */

    params->hdr.tag = ATAG_CORE;            /* start with the core tag */
    params->hdr.size = tag_size(atag_core);  /* size tag */; /* size the tag */

    params = tag_next(params);              /* move pointer to next tag */
}

void setup_cmdline_tag(const char * line)
{
    int linelen = strlen(line);

    if(!linelen)
        return;                             /* do not insert a tag for an empty commandline */

    params->hdr.tag = ATAG_CMDLINE;         /* Commandline tag */
    params->hdr.size = (sizeof(struct atag_header) + linelen + 1 + 4) >> 2;

    strcpy(params->u.cmdline.cmdline,line); /* place commandline into tag */

    params = tag_next(params);              /* move pointer to next tag */
}

void setup_serial_tag(unsigned long low, unsigned long high )
{
    params->hdr.tag = ATAG_SERIAL;             /* Serial tag */
    params->hdr.size = tag_size(atag_serialnr);  /* size tag */

    params->u.serialnr.low = low;            /* low part of serial */
    params->u.serialnr.high = high;            /* high part of serial */

    params = tag_next(params);              /* move pointer to next tag */
}

void setup_rev_tag(unsigned long rev)
{
    params->hdr.tag = ATAG_REVISION;             /* Revision tag */
    params->hdr.size = tag_size(atag_revision);  /* size tag */

    params->u.revision.rev = rev;            /* revision of the board */

    params = tag_next(params);              /* move pointer to next tag */
}

void setup_end_tag(void)
{
    params->hdr.tag = ATAG_NONE;            /* Empty tag ends list */
    params->hdr.size = 0;                   /* zero length */
}
