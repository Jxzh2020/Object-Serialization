#ifndef MACRO_EX_H
#define MACRO_EX_H
#include "Typefigure.h"

/*
template <typename T>
T Checks(T& src){return src; }

int Checks() {return 0; }
*/

int _GLOBALD = 0;
#define Checks(...) _Checks(temp,##__VA_ARGS__,_GLOBALD)
#define _Checks(T,K, ...) K
#define CHECKS(...) _CHECKS(int,##__VA_ARGS__,int)
#define _CHECKS(T, K, ...) K

#define EXPAND_DEFINE(...) _EXPAND_DEFINE_0(__VA_ARGS__, , , , , , , , , , , , , , , , , , , , , , , , , , , , , , , ,)

#define _EXPAND_DEFINE_0(COUT0,COUT1, ...)        COUT0 COUT1;        CHECKS(COUT0)&  _FUN0() {int temp = 0;return Checks(COUT1);} _EXPAND_DEFINE_1(__VA_ARGS__)
#define _EXPAND_DEFINE_1(COUT2,COUT3, ...)        COUT2 COUT3;        CHECKS(COUT2)&  _FUN1() {int temp = 0;return Checks(COUT3);} _EXPAND_DEFINE_2(__VA_ARGS__)
#define _EXPAND_DEFINE_2(COUT4,COUT5, ...)        COUT4 COUT5;        CHECKS(COUT4)&  _FUN2() {int temp = 0;return Checks(COUT5);} _EXPAND_DEFINE_3(__VA_ARGS__)
#define _EXPAND_DEFINE_3(COUT6,COUT7, ...)        COUT6 COUT7;        CHECKS(COUT6)&  _FUN3() {int temp = 0;return Checks(COUT7);} _EXPAND_DEFINE_4(__VA_ARGS__)
#define _EXPAND_DEFINE_4(COUT8,COUT9, ...)        COUT8 COUT9;        CHECKS(COUT8)&  _FUN4() {int temp = 0;return Checks(COUT9);} _EXPAND_DEFINE_5(__VA_ARGS__)
#define _EXPAND_DEFINE_5(COUT10,COUT11, ...)      COUT10 COUT11;      CHECKS(COUT10)&  _FUN5() {int temp = 0;return Checks(COUT11);} _EXPAND_DEFINE_6(__VA_ARGS__)
#define _EXPAND_DEFINE_6(COUT12,COUT13, ...)      COUT12 COUT13;      CHECKS(COUT12)&  _FUN6() {int temp = 0;return Checks(COUT13);} _EXPAND_DEFINE_7(__VA_ARGS__)
#define _EXPAND_DEFINE_7(COUT14,COUT15, ...)      COUT14 COUT15;      CHECKS(COUT14)&  _FUN7() {int temp = 0;return Checks(COUT15);} _EXPAND_DEFINE_8(__VA_ARGS__)
#define _EXPAND_DEFINE_8(COUT16,COUT17, ...)      COUT16 COUT17;      CHECKS(COUT16)&  _FUN8() {int temp = 0;return Checks(COUT17);} _EXPAND_DEFINE_9(__VA_ARGS__)
#define _EXPAND_DEFINE_9(COUT18,COUT19, ...)      COUT18 COUT19;      CHECKS(COUT18)&  _FUN9() {int temp = 0;return Checks(COUT19);} _EXPAND_DEFINE_10(__VA_ARGS__)
#define _EXPAND_DEFINE_10(COUT20,COUT21, ...)     COUT20 COUT21;      CHECKS(COUT20)&  _FUN10() {int temp = 0;return Checks(COUT21);} _EXPAND_DEFINE_11(__VA_ARGS__)
#define _EXPAND_DEFINE_11(COUT22,COUT23, ...)     COUT22 COUT23;      CHECKS(COUT22)&  _FUN11() {int temp = 0;return Checks(COUT23);} _EXPAND_DEFINE_12(__VA_ARGS__)
#define _EXPAND_DEFINE_12(COUT24,COUT25, ...)     COUT24 COUT25;      CHECKS(COUT24)&  _FUN12() {int temp = 0;return Checks(COUT25);} _EXPAND_DEFINE_13(__VA_ARGS__)
#define _EXPAND_DEFINE_13(COUT26,COUT27, ...)     COUT26 COUT27;      CHECKS(COUT26)&  _FUN13() {int temp = 0;return Checks(COUT27);} _EXPAND_DEFINE_14(__VA_ARGS__)
#define _EXPAND_DEFINE_14(COUT28,COUT29, ...)     COUT28 COUT29;      CHECKS(COUT28)&  _FUN14() {int temp = 0;return Checks(COUT29);} _EXPAND_DEFINE_15(__VA_ARGS__)
#define _EXPAND_DEFINE_15(COUT30,COUT31, ...)     COUT30 COUT31;      CHECKS(COUT30)&  _FUN15() {int temp = 0;return Checks(COUT31);}

#define FUN(i) _FUN##i()




#define PUSH_FIELDS(...)            PUSH_FIELDS_16(__VA_ARGS__,_KEEP,_KEEP,_KEEP,_KEEP,_KEEP,_KEEP,_KEEP,                    \
                                    _KEEP,_KEEP,_KEEP,_KEEP,_KEEP,_KEEP,_KEEP,_KEEP,_KEEP,_KEEP,_KEEP,                       \
                                    _KEEP,_KEEP ,_KEEP ,_KEEP , _KEEP, _KEEP, _KEEP, _KEEP, _KEEP,_KEEP,                     \
                                    _KEEP,_KEEP,_KEEP,_KEEP,_KEEP)

#define PUSH_FIELDS_16(COUT30,COUT31, ...)        temp.member_types.push_back(is_valid_type<COUT30>);    temp.member_names.push_back(#COUT31);  temp.offset.push_back(offset);   offset+=is_valid_type_offset<COUT30>;     PUSH_FIELDS_15(__VA_ARGS__)
#define PUSH_FIELDS_15(COUT28,COUT29, ...)        temp.member_types.push_back(is_valid_type<COUT28>);    temp.member_names.push_back(#COUT29);  temp.offset.push_back(offset);   offset+=is_valid_type_offset<COUT28>;     PUSH_FIELDS_14(__VA_ARGS__)
#define PUSH_FIELDS_14(COUT26,COUT27, ...)        temp.member_types.push_back(is_valid_type<COUT26>);    temp.member_names.push_back(#COUT27);  temp.offset.push_back(offset);   offset+=is_valid_type_offset<COUT26>;     PUSH_FIELDS_13(__VA_ARGS__)
#define PUSH_FIELDS_13(COUT24,COUT25, ...)        temp.member_types.push_back(is_valid_type<COUT24>);    temp.member_names.push_back(#COUT25);  temp.offset.push_back(offset);   offset+=is_valid_type_offset<COUT24>;     PUSH_FIELDS_12(__VA_ARGS__)
#define PUSH_FIELDS_12(COUT22,COUT23, ...)        temp.member_types.push_back(is_valid_type<COUT22>);    temp.member_names.push_back(#COUT23);  temp.offset.push_back(offset);   offset+=is_valid_type_offset<COUT22>;     PUSH_FIELDS_11(__VA_ARGS__)
#define PUSH_FIELDS_11(COUT20,COUT21, ...)        temp.member_types.push_back(is_valid_type<COUT20>);    temp.member_names.push_back(#COUT21);  temp.offset.push_back(offset);   offset+=is_valid_type_offset<COUT20>;     PUSH_FIELDS_10(__VA_ARGS__)
#define PUSH_FIELDS_10(COUT18,COUT19, ...)        temp.member_types.push_back(is_valid_type<COUT18>);    temp.member_names.push_back(#COUT19);  temp.offset.push_back(offset);   offset+=is_valid_type_offset<COUT18>;     PUSH_FIELDS_9(__VA_ARGS__)
#define PUSH_FIELDS_9(COUT16,COUT17, ...)         temp.member_types.push_back(is_valid_type<COUT16>);    temp.member_names.push_back(#COUT17);  temp.offset.push_back(offset);   offset+=is_valid_type_offset<COUT16>;     PUSH_FIELDS_8(__VA_ARGS__)
#define PUSH_FIELDS_8(COUT14,COUT15, ...)         temp.member_types.push_back(is_valid_type<COUT14>);    temp.member_names.push_back(#COUT15);  temp.offset.push_back(offset);   offset+=is_valid_type_offset<COUT14>;     PUSH_FIELDS_7(__VA_ARGS__)
#define PUSH_FIELDS_7(COUT12,COUT13, ...)         temp.member_types.push_back(is_valid_type<COUT12>);    temp.member_names.push_back(#COUT13);  temp.offset.push_back(offset);   offset+=is_valid_type_offset<COUT12>;     PUSH_FIELDS_6(__VA_ARGS__)
#define PUSH_FIELDS_6(COUT10,COUT11, ...)         temp.member_types.push_back(is_valid_type<COUT10>);    temp.member_names.push_back(#COUT11);  temp.offset.push_back(offset);   offset+=is_valid_type_offset<COUT10>;     PUSH_FIELDS_5(__VA_ARGS__)
#define PUSH_FIELDS_5(COUT8,COUT9, ...)           temp.member_types.push_back(is_valid_type<COUT8>);     temp.member_names.push_back(#COUT9);   temp.offset.push_back(offset);   offset+=is_valid_type_offset<COUT8>;     PUSH_FIELDS_4(__VA_ARGS__)
#define PUSH_FIELDS_4(COUT6,COUT7, ...)           temp.member_types.push_back(is_valid_type<COUT6>);     temp.member_names.push_back(#COUT7);   temp.offset.push_back(offset);   offset+=is_valid_type_offset<COUT6>;     PUSH_FIELDS_3(__VA_ARGS__)
#define PUSH_FIELDS_3(COUT4,COUT5, ...)           temp.member_types.push_back(is_valid_type<COUT4>);     temp.member_names.push_back(#COUT5);   temp.offset.push_back(offset);   offset+=is_valid_type_offset<COUT4>;     PUSH_FIELDS_2(__VA_ARGS__)
#define PUSH_FIELDS_2(COUT2,COUT3, ...)           temp.member_types.push_back(is_valid_type<COUT2>);     temp.member_names.push_back(#COUT3);   temp.offset.push_back(offset);   offset+=is_valid_type_offset<COUT2>;     PUSH_FIELDS_1(__VA_ARGS__)
#define PUSH_FIELDS_1(COUT0,COUT1, ...)           temp.member_types.push_back(is_valid_type<COUT0>);     temp.member_names.push_back(#COUT1);   temp.offset.push_back(offset);   offset+=is_valid_type_offset<COUT0>;

#define RECORD_FUNCS(NAME)      temp.func[0] = &NAME::_FUN0;        temp.func[1] = &NAME::_FUN1;        temp.func[2] = &NAME::_FUN2;        temp.func[3] = &NAME::_FUN3;    \
                                temp.func[4] = &NAME::_FUN4;        temp.func[5] = &NAME::_FUN5;        temp.func[6] = &NAME::_FUN6;        temp.func[7] = &NAME::_FUN7;    \
                                temp.func[8] = &NAME::_FUN8;        temp.func[9] = &NAME::_FUN9;        temp.func[10] = &NAME::_FUN10;      temp.func[11] = &NAME::_FUN11;  \
                                temp.func[12] = &NAME::_FUN12;      temp.func[13] = &NAME::_FUN13;      temp.func[14] = &NAME::_FUN14;      temp.func[15] = &NAME::_FUN15;

#endif