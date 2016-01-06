/* ----------------------------------------------------------------------------
 * ergoDOX layout : QWERTY (modified from the Kinesis layout)
 * ----------------------------------------------------------------------------
 * Copyright (c) 2015 Hugh Greene <hughg@tameter.org>, based on ...
 * Copyright (c) 2012 Ben Blazak <benblazak.dev@gmail.com>
 * Released under The MIT License (MIT) (see "license.md")
 * Project located at <https://github.com/benblazak/ergodox-firmware>
 * ------------------------------------------------------------------------- */


#include <stdint.h>
#include <stddef.h>
#include <avr/pgmspace.h>
#include "../../../lib/data-types/misc.h"
#include "../../../lib/usb/usage-page/keyboard--short-names.h"
#include "../../../lib/key-functions/public.h"
#include "../matrix.h"
#include "../layout.h"

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

/*
    The main ideas of this layout are as follows.

    1) Shift is a "sticky" key, so you can "shift once" with press-release, and
    "caps lock" with "press-release-press(-release)".

    2) On number keys, numbers and punctuation are swapped in terms of shift state,
    on the theory that punctuation will be used more often than numbers.

    3) There's a layer with one-press keys for cut, copy, paste, select all, save,
    and undo, because they're so common.

    It's based on http://stackoverflow.com/questions/2306423/an-ideal-keyboard-layout-for-programming which says

        I made the following changes to a standard QWERTY layout. (I don't use
        Dvorak, but there is a programmer Dvorak layout worth mentioning.)

            Swap numbers with symbols in the top row, because long or repeated
            literal numbers are typically replaced with named constants;

            Swap backquote with tilde, because backquotes are rare in many
            languages but destructors are common in C++;

            Swap minus with underscore, because underscores are common in
            identifiers;

            Swap curly braces with square brackets, because blocks are more
            common than subscripts; and

            Swap double quote with single quote, because strings are more common
            than character literals.
*/

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

const uint8_t PROGMEM _kb_layout[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {

	KB_MATRIX_LAYER(  // layout: layer 0: default
// unused
0,
// left hand
           4,     _1,         _2,      _3,      _4,    _5,       _bs,
         _bs,     _Q,         _W,      _E,      _R,    _T, _bracketL,
      _enter,     _A,         _S,      _D,      _F,    _G,
_application,     _Z,         _X,      _C,      _V,    _B,         1,
       _altR, _grave, _backslash,  _equal,   _dash,
                                                        2,     _guiL,
                                                0,      0,      _tab,
                                           _space, _ctrlL,     _altL,
// right haknd
      _bs, _6,      _7,      _8,      _9,         _0,            4,
_bracketR, _Y,      _U,      _I,      _O,         _P,          _bs,
           _H,      _J,      _K,      _L, _semicolon,       _enter,
        1, _N,      _M,  _comma, _period,    _arrowU, _application,
                _quote,  _slash, _arrowL,    _arrowD,      _arrowR,
_quote,      2,
  _tab,      0,      0,
 _altL, _ctrlL, _space ),

	KB_MATRIX_LAYER(  // layout: layer 1: shifted default
// unused
0,
// left hand
           3,     _1,         _2,      _3,      _4,    _5,       _bs,
         _bs,     _Q,         _W,      _E,      _R,    _T, _bracketL,
      _enter,     _A,         _S,      _D,      _F,    _G,
_application,     _Z,         _X,      _C,      _V,    _B,         1,
       _altR, _grave, _backslash,  _equal,   _dash,
                                                        2, _guiL,
                                                0,      0,  _tab,
                                           _space, _ctrlL, _altL,
// right hand
      _bs, _6,      _7,      _8,      _9,         _0,            3,
_bracketR, _Y,      _U,      _I,      _O,         _P,          _bs,
           _H,      _J,      _K,      _L, _semicolon,       _enter,
        1, _N,      _M,  _comma, _period,    _arrowU, _application,
                _quote,  _slash, _arrowL,    _arrowD,      _arrowR,
_quote,      2,
  _tab,      0,      0,
 _altL, _ctrlL, _space ),


	KB_MATRIX_LAYER(  // layout: layer 2: function keys
// unused
0,
// left hand
   0,  _F1,  _F2,  _F3,  _F4,  _F5, _del,
_del,    0,    0,    0,    0,    0,    0,
   0,    0,    0,    0,    0,    0,
   0,    0,    0,    0,    0,    0,    3,
   0,    0,    0,    0,    0,
                                 2, _print,
                          0,     0,_insert,
                          0, _altL, _ctrlL,
// right hand
   0,  _F6,  _F7,  _F8,  _F9,  _F10,    0,
_del,    0,    0,    0,    0,  _F11, _del,
         0,    0,    0,    0,  _F12,    0,
   3,    0,    0,    0,    0,_pageU,    0,
               0,    0,_home,_pageD, _end,
_sysReq,      2,
      0,      0,  0,
  _altL, _ctrlL,  0 ),


	KB_MATRIX_LAYER(  // layout: layer 3: shifted function keys
// unused
0,
// left hand
   0,  _F1,  _F2,  _F3,  _F4,  _F5,   _del,
_del,    0,    0,    0,    0,    0,      0,
   0,    0,    0,    0,    0,    0,
   0,    0,    0,    0,    0,    0,      3,
   0,    0,    0,    0,    0,
                                 2, _print,
                           0,    0,_insert,
                           0,    0,      0,
// right hand
   0,  _F6,  _F7,  _F8,  _F9, _F10,     0,
_del,    0,    0,    0,    0, _F11,  _del,
         0,    0,    0,    0, _F12,     0,
   3,    0,    0,    0,    0,_pageU,    0,
               0,    0,_home,_pageD, _end,
_sysReq,      2,
      0,      0,  0,
  _altL, _ctrlL,  0 ),


	KB_MATRIX_LAYER(  // layout: layer 4: shortcuts
// unused
0,
// left hand
_esc,  0,  0, 0, 0, 0, 0,
  _X,  0,  0, 0, 0, 0, 0,
  _C, _A, _S, 0, 0, 0,
  _V,  0,  0, 0, 0, 0, 0,
   0,  0, _Z, 0, 0,
                     0, 0,
                  0, 0, 0,
                  0, 0, 0,
// right hand
      0,  0,  0,  0,  0,  0, _esc,
      0,  0,  0,  0,  0,  0,   _X,
          0,  0,  0, _S, _A,   _C,
      0,  0,  0,  0,  0,  0,   _V,
              0,  0, _Z,  0,    0,
0, 0,
0, 0, 0,
0, 0, 0 ),

};

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

// aliases

// basic
#define  kprrel  &kbfun_press_release
#define  kprrelps &kbfun_press_release_preserve_sticky
#define  ktog    &kbfun_toggle
#define  ktrans  &kbfun_transparent
// --- layer push/pop functions
#define  lpush1   &kbfun_layer_push_1
#define  lpush2   &kbfun_layer_push_2
#define  lpush3   &kbfun_layer_push_3
#define  lpush4   &kbfun_layer_push_4
#define  lpush5   &kbfun_layer_push_5
#define  lpush6   &kbfun_layer_push_6
#define  lpush7   &kbfun_layer_push_7
#define  lpush8   &kbfun_layer_push_8
#define  lpush9   &kbfun_layer_push_9
#define  lpush10  &kbfun_layer_push_10
#define  lpop1    &kbfun_layer_pop_1
#define  lpop2    &kbfun_layer_pop_2
#define  lpop3    &kbfun_layer_pop_3
#define  lpop4    &kbfun_layer_pop_4
#define  lpop5    &kbfun_layer_pop_5
#define  lpop6    &kbfun_layer_pop_6
#define  lpop7    &kbfun_layer_pop_7
#define  lpop8    &kbfun_layer_pop_8
#define  lpop9    &kbfun_layer_pop_9
#define  lpop10   &kbfun_layer_pop_10
#define  lstck1   &kbfun_layer_sticky_1
#define  lstck2   &kbfun_layer_sticky_2
#define  lstck3   &kbfun_layer_sticky_3
#define  lstck4   &kbfun_layer_sticky_4
#define  lstck5   &kbfun_layer_sticky_5
#define  lstck6   &kbfun_layer_sticky_6
#define  lstck7   &kbfun_layer_sticky_7
#define  lstck8   &kbfun_layer_sticky_8
#define  lstck9   &kbfun_layer_sticky_9
#define  lstck10  &kbfun_layer_sticky_10
// ---

// device
#define  dbtldr  &kbfun_jump_to_bootloader

// special
#define  sshprre  &kbfun_shift_press_release
#define  sctprre  &kbfun_ctrl_press_release
#define  s2kcap   &kbfun_2_keys_capslock_press_release
#define  slpunum  &kbfun_layer_push_numpad
#define  slponum  &kbfun_layer_pop_numpad

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

const void_funptr_t PROGMEM _kb_layout_press[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {

	KB_MATRIX_LAYER(  // press: layer 0: default
// unused
NULL,
// left hand
 lstck4, sshprre, sshprre, sshprre, sshprre, sshprre,  kprrel,
 kprrel,  kprrel,  kprrel,  kprrel,  kprrel,  kprrel, sshprre,
 kprrel,  kprrel,  kprrel,  kprrel,  kprrel,  kprrel,
 kprrel,  kprrel,  kprrel,  kprrel,  kprrel,  kprrel, lstck1,
 kprrel, sshprre,  kprrel,  kprrel, sshprre,
                                                 lstck2, kprrel,
                                           NULL,   NULL, kprrel,
                                         kprrel, kprrel, kprrel,
// right hand
         kprrel, sshprre, sshprre, sshprre, sshprre, sshprre, lstck4,
        sshprre,  kprrel,  kprrel,  kprrel,  kprrel,  kprrel, kprrel,
                  kprrel,  kprrel,  kprrel,  kprrel,  kprrel, kprrel,
         lstck1,  kprrel,  kprrel,  kprrel,  kprrel,  kprrel, kprrel,
                          sshprre,  kprrel,  kprrel,  kprrel, kprrel,
 kprrel, lstck2,
 kprrel,   NULL,   NULL,
 kprrel, kprrel, kprrel ),


	KB_MATRIX_LAYER(  // press: layer 1: shifted default
// unused
NULL,
// left hand
 lstck4,  kprrel,  kprrel,  kprrel,  kprrel,  kprrel, sshprre,
sshprre, sshprre, sshprre, sshprre, sshprre, sshprre,  kprrel,
sshprre, sshprre, sshprre, sshprre, sshprre, sshprre,
 kprrel, sshprre, sshprre, sshprre, sshprre, sshprre,  ktrans,
 kprrel,  kprrel, sshprre, sshprre,  kprrel,
                                                 lstck3, sshprre,
                                           NULL,   NULL, sshprre,
                                     sshprre, kprrelps, kprrelps,
// right hand
       sshprre,  kprrel,  kprrel,  kprrel,  kprrel,  kprrel,  lstck4,
        kprrel, sshprre, sshprre, sshprre, sshprre, sshprre, sshprre,
                sshprre, sshprre, sshprre, sshprre, sshprre, sshprre,
        ktrans, sshprre, sshprre, sshprre, sshprre, sshprre,  kprrel,
                          kprrel, sshprre, sshprre, sshprre, sshprre,
sshprre,  lstck3,
sshprre,    NULL,      NULL,
kprrelps, kprrelps, sshprre ),


	KB_MATRIX_LAYER(  // press: layer 2: function keys
// unused
NULL,
// left hand
   NULL, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
   NULL,   NULL,   NULL,   NULL,   NULL,   NULL, lstck3,
 dbtldr,   NULL,   NULL,   NULL,   NULL,
                                                 lstck2, kprrel,
                                           NULL,   NULL, kprrel,
                                           NULL, kprrelps, kprrelps,
// right hand
        kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,   NULL,
          NULL,   NULL,   NULL,   NULL,   NULL, kprrel, kprrel,
                  NULL,   NULL,   NULL,   NULL, kprrel,   NULL,
        lstck3,   NULL,   NULL,   NULL,   NULL, kprrel,   NULL,
                          NULL,   NULL, kprrel, kprrel, kprrel,
 kprrel, lstck2,
   NULL,   NULL,     NULL,
 kprrelps, kprrelps, NULL ),


	KB_MATRIX_LAYER(  // press: layer 3: shifted function keys
// unused
NULL,
// left hand
   NULL, sshprre, sshprre, sshprre, sshprre, sshprre, sshprre,
sshprre,    NULL,    NULL,    NULL,    NULL,    NULL,    NULL,
   NULL,    NULL,    NULL,    NULL,    NULL,    NULL,
   NULL,    NULL,    NULL,    NULL,    NULL,    NULL,  lstck3,
   NULL,    NULL,    NULL,    NULL,    NULL,
                                              lstck2, sshprre,
                                        NULL,   NULL, sshprre,
                                        NULL,   NULL,    NULL,
// right hand
       sshprre, sshprre, sshprre, sshprre, sshprre, sshprre,    NULL,
          NULL,    NULL,    NULL,    NULL,    NULL, sshprre, sshprre,
                   NULL,    NULL,    NULL,    NULL, sshprre,    NULL,
        lstck3,    NULL,    NULL,    NULL,    NULL, sshprre,    NULL,
                            NULL,    NULL, sshprre, sshprre, sshprre,
sshprre, lstck2,
   NULL,   NULL,   NULL,
   NULL,   NULL,   NULL ),


	KB_MATRIX_LAYER(  // press: layer 4: shortcuts
// unused
NULL,
// left hand
 kprrel,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
 kprrel,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
 kprrel, kprrel, kprrel,   NULL,   NULL,   NULL,
 kprrel,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
   NULL,   NULL, kprrel,   NULL,   NULL,
                                                   NULL,   NULL,
                                           NULL,   NULL,   NULL,
                                           NULL,   NULL,   NULL,
// right hand
          NULL,   NULL,   NULL,   NULL,   NULL,   NULL, kprrel,
          NULL,   NULL,   NULL,   NULL,   NULL,   NULL, kprrel,
                  NULL,   NULL,   NULL, kprrel, kprrel, kprrel,
          NULL,   NULL,   NULL,   NULL,   NULL,   NULL, kprrel,
                          NULL,   NULL, kprrel,   NULL,   NULL,
   NULL,   NULL,
   NULL,   NULL,   NULL,
   NULL,   NULL,   NULL ),

};

// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------

const void_funptr_t PROGMEM _kb_layout_release[KB_LAYERS][KB_ROWS][KB_COLUMNS] = {

	KB_MATRIX_LAYER(  // release: layer 0: default
// unused
NULL,
// left hand
 lstck4, sshprre, sshprre, sshprre, sshprre, sshprre,  kprrel,
 kprrel,  kprrel,  kprrel,  kprrel,  kprrel,  kprrel, sshprre,
 kprrel,  kprrel,  kprrel,  kprrel,  kprrel,  kprrel,
 kprrel,  kprrel,  kprrel,  kprrel,  kprrel,  kprrel, lstck1,
 kprrel, sshprre,  kprrel,  kprrel, sshprre,
                                                 lstck2, kprrel,
                                           NULL,   NULL, kprrel,
                                         kprrel, kprrel, kprrel,
// right hand
         kprrel, sshprre, sshprre, sshprre, sshprre, sshprre, lstck4,
        sshprre,  kprrel,  kprrel,  kprrel,  kprrel,  kprrel, kprrel,
                  kprrel,  kprrel,  kprrel,  kprrel,  kprrel, kprrel,
         lstck1,  kprrel,  kprrel,  kprrel,  kprrel,  kprrel, kprrel,
                          sshprre,  kprrel,  kprrel,  kprrel, kprrel,
 kprrel, lstck2,
 kprrel,   NULL,   NULL,
 kprrel, kprrel, kprrel ),


	KB_MATRIX_LAYER(  // release: layer 1: shifted default
// unused
NULL,
// left hand
 lstck4,  kprrel,  kprrel,  kprrel,  kprrel,  kprrel, sshprre,
sshprre, sshprre, sshprre, sshprre, sshprre, sshprre,  kprrel,
sshprre, sshprre, sshprre, sshprre, sshprre, sshprre,
 kprrel, sshprre, sshprre, sshprre, sshprre, sshprre,  ktrans,
 kprrel,  kprrel, sshprre, sshprre,  kprrel,
                                                 lstck3, sshprre,
                                           NULL,   NULL, sshprre,
                                     sshprre, kprrelps, kprrelps,
// right hand
       sshprre,  kprrel,  kprrel,  kprrel,  kprrel,  kprrel,  lstck4,
        kprrel, sshprre, sshprre, sshprre, sshprre, sshprre, sshprre,
                sshprre, sshprre, sshprre, sshprre, sshprre, sshprre,
        ktrans, sshprre, sshprre, sshprre, sshprre, sshprre,  kprrel,
                          kprrel, sshprre, sshprre, sshprre, sshprre,
sshprre,  lstck3,
sshprre,    NULL,      NULL,
kprrelps, kprrelps, sshprre ),


	KB_MATRIX_LAYER(  // release: layer 2: function keys
// unused
NULL,
// left hand
   NULL, kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,
 kprrel,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
   NULL,   NULL,   NULL,   NULL,   NULL,   NULL, lstck3,
 dbtldr,   NULL,   NULL,   NULL,   NULL,
                                                 lstck2, kprrel,
                                           NULL,   NULL, kprrel,
                                           NULL, kprrelps, kprrelps,
// right hand
        kprrel, kprrel, kprrel, kprrel, kprrel, kprrel,   NULL,
          NULL,   NULL,   NULL,   NULL,   NULL, kprrel, kprrel,
                  NULL,   NULL,   NULL,   NULL, kprrel,   NULL,
        lstck3,   NULL,   NULL,   NULL,   NULL, kprrel,   NULL,
                          NULL,   NULL, kprrel, kprrel, kprrel,
 kprrel, lstck2,
   NULL,   NULL,     NULL,
 kprrelps, kprrelps, NULL ),


	KB_MATRIX_LAYER(  // release: layer 3: shifted function keys
// unused
NULL,
// left hand
   NULL, sshprre, sshprre, sshprre, sshprre, sshprre, sshprre,
sshprre,    NULL,    NULL,    NULL,    NULL,    NULL,    NULL,
   NULL,    NULL,    NULL,    NULL,    NULL,    NULL,
   NULL,    NULL,    NULL,    NULL,    NULL,    NULL,  lstck3,
   NULL,    NULL,    NULL,    NULL,    NULL,
                                              lstck2, sshprre,
                                        NULL,   NULL, sshprre,
                                        NULL,   NULL,    NULL,
// right hand
       sshprre, sshprre, sshprre, sshprre, sshprre, sshprre,    NULL,
          NULL,    NULL,    NULL,    NULL,    NULL, sshprre, sshprre,
                   NULL,    NULL,    NULL,    NULL, sshprre,    NULL,
        lstck3,    NULL,    NULL,    NULL,    NULL, sshprre,    NULL,
                            NULL,    NULL, sshprre, sshprre, sshprre,
sshprre, lstck2,
   NULL,   NULL,   NULL,
   NULL,   NULL,   NULL ),


	KB_MATRIX_LAYER(  // release: layer 4: shortcuts
// unused
NULL,
// left hand
 kprrel,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
 kprrel,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
 kprrel, kprrel, kprrel,   NULL,   NULL,   NULL,
 kprrel,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
   NULL,   NULL, kprrel,   NULL,   NULL,
                                                   NULL,   NULL,
                                           NULL,   NULL,   NULL,
                                           NULL,   NULL,   NULL,
// right hand
          NULL,   NULL,   NULL,   NULL,   NULL,   NULL, kprrel,
          NULL,   NULL,   NULL,   NULL,   NULL,   NULL, kprrel,
                  NULL,   NULL,   NULL, kprrel, kprrel, kprrel,
          NULL,   NULL,   NULL,   NULL,   NULL,   NULL, kprrel,
                          NULL,   NULL, kprrel,   NULL,   NULL,
   NULL,   NULL,
   NULL,   NULL,   NULL,
   NULL,   NULL,   NULL ),

	KB_MATRIX_LAYER(  // release: layer 5: nothing (just making sure unused
			  // functions don't get compiled out)
// unused
NULL,
// other
 kprrel, lpush8,  lpop8,   NULL,   NULL,   NULL,   NULL,   NULL,
   ktog, lpush9,  lpop9,   NULL,   NULL,   NULL,   NULL,   NULL,
 ktrans,lpush10, lpop10,   NULL,   NULL,   NULL,   NULL,   NULL,
 lpush1,  lpop1,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
 lpush2,  lpop2, dbtldr,   NULL,   NULL,   NULL,   NULL,   NULL,
 lpush3,  lpop3,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL,
 lpush4,  lpop4, s2kcap,   NULL,   NULL,   NULL,   NULL,   NULL,
 lpush5,  lpop5,slpunum,   NULL,   NULL,   NULL,   NULL,   NULL,
 lpush6,  lpop6,slponum,   NULL,   NULL,   NULL,   NULL,   NULL,
 lpush7,  lpop7,   NULL,   NULL,   NULL,   NULL,   NULL,   NULL )

};

