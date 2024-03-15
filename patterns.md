# Standard patterns

## Comment style

//! todo, see chat with leslie

## sudo-namespaces

//! todo

## Common function specification (eg callbacks)

```c
// caveat: IntelliSense picks up block above define, not around declaration or implementation

/// Single definition of signature
/**
 * Callback on shortcut keys pressed
 * 
 * @param cst   Current core keyboard hook state
 * @param key   Shortcut keycode
 * @param mods  Mask of modifer keys
 * 
 * @return RET_OK, RET_FALSE
 *  
 */
#define short_fn(name) r8(name)(state * cst, u8 key, u16 mods)

/// Typedef, intended for use as short_fn*
typedef short_fn(short_fn);

/// Declaration
short_fn(someFunctionName);

/// Definition
short_fn(someFunctionName);
{
    // impl here
}

/// fn* example
void someOtherFunction(short_fn* callback);

```