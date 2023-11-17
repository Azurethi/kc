#include "gen_util.h"

#include <string.h>

r8 util_fix_cmp(cc *str, cc *fix, u8 pre)
{
    if (!str || !fix)
        return RET_INVAL;
    
    sz len = strlen(str);
    sz len2 = strlen(fix);
    if (len2 > len)
        return RET_INVAL;

    if (strncmp(str + (len - len2) * !pre, fix, len2))
        return RET_FALSE;

    return RET_OK;
}

r8 util_split_trim(ch *str, cc split, cc *trim, u8 order, cc **left, cc **right)
{
    if(!str || !split || !left || !right)   //~ Allow left/right optional?
        return RET_INVAL;

    ch *sp = strchr(str, split);
    if (!sp)
        return RET_FALSE;

    ch *end = str + strlen(str);

    *sp = 0;
    *left = str;
    *right = sp+1;
    if(!trim)
        return RET_OK;

    end--;
    sp--;
    
    if (order)
    {
        i32 n = strlen(trim);
        for (int i = 0; i<n; i++)
        {
            ch rem = trim[i];
            while(**left == rem) *left += 1;
            while(**right == rem) *right += 1;
            while(*sp == rem)
            {
                *sp = 0;
                sp--;
            }
            while(*end == rem)
            {
                *end = 0;
                end--;
            }
        }
    }
    else
    {
        while(strchr(trim, **left) && *++*left != 0);
        while(strchr(trim, **right) && *++*right != 0);
        
        sp--;
        while(strchr(trim, *sp) && sp > *left)
        {
            *sp = 0;
            sp--;
        }

        while(strchr(trim, *end) && end > *right)
        {
            *end = 0;
            end--;
        }
    }

    return RET_OK;
}

r32 util_str_linmap(cc **map, cc *str, i8 fix)
{
    if (!map || !str)
        return RET_INVAL;

    i32 idx = 0;
    if (fix == 0)
    {
        while(*map)
        {
            if (!strcmp(str, *map)) 
                return idx;
            map++;
            idx++;
        }

    }
    else
    {
        while(*map)
        {
            if (!util_fix_cmp(str, *map, fix<0)) 
                return idx;
            map++;
            idx++;
        }
    }

    return RET_FALSE;
}
