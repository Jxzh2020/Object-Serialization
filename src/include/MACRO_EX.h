#ifndef MACRO_EX_H
#define MACRO_EX_H
#include "Typefigure.h"


#define EXPAND_DEFINE(...) _EXPAND_DEFINE_0(__VA_ARGS__, , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , ,)

/*
#define _EXPAND_DEFINE_0(COUT,...) COUT; _EXPAND_DEFINE_1(__VA_ARGS__)
#define _EXPAND_DEFINE_1(_0,COUT,...) COUT; _EXPAND_DEFINE_2(__VA_ARGS__)
#define _EXPAND_DEFINE_2(_0,_1,COUT,...) COUT; _EXPAND_DEFINE_3(__VA_ARGS__)
#define _EXPAND_DEFINE_3(_0,_1,_2,COUT,...) COUT; _EXPAND_DEFINE_4(__VA_ARGS__)
#define _EXPAND_DEFINE_4(_0,_1,_2,_3,COUT,...) COUT; _EXPAND_DEFINE_5(__VA_ARGS__)
#define _EXPAND_DEFINE_5(_0,_1,_2,_3,_4,COUT,...) COUT; _EXPAND_DEFINE_6(__VA_ARGS__)
#define _EXPAND_DEFINE_6(_0,_1,_2,_3,_4,_5,COUT,...) COUT; _EXPAND_DEFINE_7(__VA_ARGS__)
#define _EXPAND_DEFINE_7(_0,_1,_2,_3,_4,_5,_6,COUT,...) COUT; _EXPAND_DEFINE_8(__VA_ARGS__)
#define _EXPAND_DEFINE_8(_0,_1,_2,_3,_4,_5,_6,_7,COUT,...) COUT; _EXPAND_DEFINE_9(__VA_ARGS__)
#define _EXPAND_DEFINE_9(_0,_1,_2,_3,_4,_5,_6,_7,_8,COUT,...) COUT; _EXPAND_DEFINE_10(__VA_ARGS__)
#define _EXPAND_DEFINE_10(_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,COUT,...) COUT; _EXPAND_DEFINE_11(__VA_ARGS__)
#define _EXPAND_DEFINE_11(_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,COUT,...) COUT; _EXPAND_DEFINE_12(__VA_ARGS__)
#define _EXPAND_DEFINE_12(_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,COUT,...) COUT; _EXPAND_DEFINE_13(__VA_ARGS__)
#define _EXPAND_DEFINE_13(_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,COUT,...) COUT; _EXPAND_DEFINE_14(__VA_ARGS__)
#define _EXPAND_DEFINE_14(_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13,COUT,...) COUT; _EXPAND_DEFINE_15(__VA_ARGS__)
#define _EXPAND_DEFINE_15(_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13_14,COUT,...) COUT; _EXPAND_DEFINE_16(__VA_ARGS__)
#define _EXPAND_DEFINE_16(_0,_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,_13_14,_15,COUT,...) COUT; _EXPAND_DEFINE_16(__VA_ARGS__)
*/
#define _EXPAND_DEFINE_0(COUT0,COUT1, ...)      COUT0 COUT1;       _EXPAND_DEFINE_1(__VA_ARGS__)
#define _EXPAND_DEFINE_1(COUT2,COUT3, ...)      COUT2 COUT3;       _EXPAND_DEFINE_2(__VA_ARGS__)
#define _EXPAND_DEFINE_2(COUT4,COUT5, ...)      COUT4 COUT5;       _EXPAND_DEFINE_3(__VA_ARGS__)
#define _EXPAND_DEFINE_3(COUT6,COUT7, ...)      COUT6 COUT7;       _EXPAND_DEFINE_4(__VA_ARGS__)
#define _EXPAND_DEFINE_4(COUT8,COUT9, ...)      COUT8 COUT9;       _EXPAND_DEFINE_5(__VA_ARGS__)
#define _EXPAND_DEFINE_5(COUT10,COUT11, ...)      COUT10 COUT11;       _EXPAND_DEFINE_6(__VA_ARGS__)
#define _EXPAND_DEFINE_6(COUT12,COUT13, ...)      COUT12 COUT13;       _EXPAND_DEFINE_7(__VA_ARGS__)
#define _EXPAND_DEFINE_7(COUT14,COUT15, ...)      COUT14 COUT15;       _EXPAND_DEFINE_8(__VA_ARGS__)
#define _EXPAND_DEFINE_8(COUT16,COUT17, ...)      COUT16 COUT17;       _EXPAND_DEFINE_9(__VA_ARGS__)
#define _EXPAND_DEFINE_9(COUT18,COUT19, ...)      COUT18 COUT19;       _EXPAND_DEFINE_10(__VA_ARGS__)
#define _EXPAND_DEFINE_10(COUT20,COUT21, ...)     COUT20 COUT21;       _EXPAND_DEFINE_11(__VA_ARGS__)
#define _EXPAND_DEFINE_11(COUT22,COUT23, ...)     COUT22 COUT23;       _EXPAND_DEFINE_12(__VA_ARGS__)
#define _EXPAND_DEFINE_12(COUT24,COUT26, ...)     COUT24 COUT26;       _EXPAND_DEFINE_13(__VA_ARGS__)
#define _EXPAND_DEFINE_13(COUT26,COUT27, ...)     COUT26 COUT27;       _EXPAND_DEFINE_14(__VA_ARGS__)
#define _EXPAND_DEFINE_14(COUT28,COUT29, ...)     COUT28 COUT29;       _EXPAND_DEFINE_15(__VA_ARGS__)
#define _EXPAND_DEFINE_15(COUT30,COUT31, ...)     COUT30 COUT31;



#define PUSH_FIELDS(...)            PUSH_FIELDS_0(__VA_ARGS__,_KEEP,_KEEP,_KEEP,_KEEP,_KEEP,_KEEP,_KEEP,                     \
                                    _KEEP,_KEEP,_KEEP,_KEEP,_KEEP,_KEEP,_KEEP,_KEEP,_KEEP,_KEEP,_KEEP,                       \
                                    _KEEP,_KEEP ,_KEEP ,_KEEP , _KEEP, _KEEP, _KEEP, _KEEP, _KEEP,_KEEP,                     \
                                    _KEEP,_KEEP,_KEEP,_KEEP,_KEEP)

#define PUSH_FIELDS_15(COUT30,COUT31, ...)        member_types.push_back(is_valid_type<COUT30>);
#define PUSH_FIELDS_14(COUT28,COUT29, ...)        member_types.push_back(is_valid_type<COUT28>);    PUSH_FIELDS_15(__VA_ARGS__)
#define PUSH_FIELDS_13(COUT26,COUT27, ...)        member_types.push_back(is_valid_type<COUT26>);    PUSH_FIELDS_14(__VA_ARGS__)
#define PUSH_FIELDS_12(COUT24,COUT25, ...)        member_types.push_back(is_valid_type<COUT24>);    PUSH_FIELDS_13(__VA_ARGS__)
#define PUSH_FIELDS_11(COUT22,COUT23, ...)        member_types.push_back(is_valid_type<COUT22>);    PUSH_FIELDS_12(__VA_ARGS__)
#define PUSH_FIELDS_10(COUT20,COUT21, ...)        member_types.push_back(is_valid_type<COUT20>);    PUSH_FIELDS_11(__VA_ARGS__)
#define PUSH_FIELDS_9(COUT18,COUT19, ...)         member_types.push_back(is_valid_type<COUT18>);    PUSH_FIELDS_10(__VA_ARGS__)
#define PUSH_FIELDS_8(COUT16,COUT17, ...)         member_types.push_back(is_valid_type<COUT16>);    PUSH_FIELDS_9(__VA_ARGS__)
#define PUSH_FIELDS_7(COUT14,COUT15, ...)         member_types.push_back(is_valid_type<COUT14>);    PUSH_FIELDS_8(__VA_ARGS__)
#define PUSH_FIELDS_6(COUT12,COUT13, ...)         member_types.push_back(is_valid_type<COUT12>);    PUSH_FIELDS_7(__VA_ARGS__)
#define PUSH_FIELDS_5(COUT10,COUT11, ...)         member_types.push_back(is_valid_type<COUT10>);    PUSH_FIELDS_6(__VA_ARGS__)
#define PUSH_FIELDS_4(COUT8,COUT9, ...)         member_types.push_back(is_valid_type<COUT8>);    PUSH_FIELDS_5(__VA_ARGS__)
#define PUSH_FIELDS_3(COUT6,COUT7, ...)         member_types.push_back(is_valid_type<COUT6>);    PUSH_FIELDS_4(__VA_ARGS__)
#define PUSH_FIELDS_2(COUT4,COUT5, ...)         member_types.push_back(is_valid_type<COUT4>);    PUSH_FIELDS_3(__VA_ARGS__)
#define PUSH_FIELDS_1(COUT2,COUT3, ...)         member_types.push_back(is_valid_type<COUT2>);    PUSH_FIELDS_2(__VA_ARGS__)
#define PUSH_FIELDS_0(COUT0,COUT1, ...)         member_types.push_back(is_valid_type<COUT0>);    PUSH_FIELDS_1(__VA_ARGS__)


#endif