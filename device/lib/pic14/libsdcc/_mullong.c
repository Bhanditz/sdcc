/* ---------------------------------------------------------------------------
   _mullong.c - routine for 32 bit multiplication

   Copyright (C) 2005, Raphael Neider <rneider AT web.de>

   This library is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by the
   Free Software Foundation; either version 2.1, or (at your option) any
   later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License 
   along with this library; see the file COPYING. If not, write to the
   Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston,
   MA 02110-1301, USA.

   As a special exception, if you link this library with other files,
   some of which are compiled with SDCC, to produce an executable,
   this library does not by itself cause the resulting executable to
   be covered by the GNU General Public License. This exception does
   not however invalidate any other reasons why the executable file
   might be covered by the GNU General Public License.
-------------------------------------------------------------------------*/

#pragma save
#pragma disable_warning 126 /* unreachable code */
#pragma disable_warning 116 /* left shifting more than size of object */
long
_mullong (long a, long b)
{
  long result = 0;
  unsigned char i;

  /* check all bits in a byte */
  for (i = 0; i < 8u; i++) {
    /* check all bytes in operand (generic code, optimized by the compiler) */
    if (a & 0x0001u) result += b;
    if (sizeof (a) > 1 && (a & 0x00000100ul)) result += (b << 8u);
    if (sizeof (a) > 2 && (a & 0x00010000ul)) result += (b << 16u);
    if (sizeof (a) > 3 && (a & 0x01000000ul)) result += (b << 24u);
    a = ((unsigned long)a) >> 1u;
    b <<= 1u;
  } // for i

  return result;
}
#pragma restore
