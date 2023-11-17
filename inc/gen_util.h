#ifndef _GEN_UTIL_H_
#define _GEN_UTIL_H_

#include "c.h"

/**
 * Compare (pre|suf)fix of string
 * 
 * @param str   String
 * @param fix   Prefix / Suffix
 * @param pre   0: Suffix, !0: Prefix
 * 
 * @return RET_OK, RET_FALSE, RET_INVAL
*/
r8 util_fix_cmp(cc *str, cc *fix, u8 pre);

/**
 * Split a string on a given character
 * 
 * @param str   Null terminated string (This will be modified in place)
 * @param split Char to split on
 * @param trim  Null terminated list of chars to trim from front/back of left/right
 * @param order 1 if the order of trim should be respected, 0 if not. (eg, if 1 & trim=" '". " 'this is a test ' " -> "this is test ")
 * @param left  Filled with pointer to the start of the lefthand string
 * @param right Filled with the pointer to the start of the righthand string
 * 
 * @return RET_OK, RET_FALSE, RET_INVAL
*/
r8 util_split_trim(ch *str, cc split, cc *trim, u8 order, cc **left, cc **right);

/**
 * Find the index of str in map
 * 
 * @param map   Null terminated list of strings, eg {"some", "values", 0}
 * @param str   Target string
 * @param mode  0: exact match, <0: prefix, >0: suffix
 * 
 * @return index into map, RET_FALSE, RET_INVAL
*/
r32 util_str_linmap(cc **map, cc *str, i8 fix);

#endif // _GEN_UTIL_H_
