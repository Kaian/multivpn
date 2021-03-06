/*

	multivpn - Multiprotocol VPN tool 

	Copyright (C) 2004  Gorka Gorrotxategi - zgor; Jose Ignacio Sanchez Martin - Topo[LB]

	This program is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2, or (at your option)
	any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software Foundation,
	Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  

	---------

	debug.c: debug information manager
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <ctype.h>


#include "globals.h"
#include "debug.h"


inline void debug(int level,char *formatString, ...){
	va_list ap;
	if (global_v.debug > level)
	{
		printf("Debug INFO:  ");
		va_start(ap,formatString);
		vfprintf(stdout, formatString, ap);
		va_end(ap);
		fprintf(stdout, "\n");
		fflush(stdout);
	}
}

inline void debug_error(char *formatString, ...)
{
  	 va_list ap;
   	 fprintf(stderr,"Error:  ");
         va_start(ap,formatString);
         vfprintf(stderr, formatString, ap);
         va_end(ap);
         fprintf(stderr, "\n");
         fflush(stderr);
												
}
