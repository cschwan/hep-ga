#include <boost/test/unit_test.hpp>
#include <hep/ga.hpp>

BOOST_AUTO_TEST_CASE(next_bit_permutation_1_bit)
{
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(1), 2);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(2), 4);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(4), 8);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(8), 16);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(16), 32);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(32), 64);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(64), 128);
}

BOOST_AUTO_TEST_CASE(next_bit_permutation_2_bits)
{
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(3), 5);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(5), 6);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(6), 9);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(9), 10);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(10), 12);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(12), 17);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(17), 18);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(18), 20);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(20), 24);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(24), 33);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(33), 34);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(34), 36);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(36), 40);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(40), 48);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(48), 65);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(65), 66);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(66), 68);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(68), 72);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(72), 80);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(80), 96);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(96), 129);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(129), 130);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(130), 132);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(132), 136);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(136), 144);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(144), 160);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(160), 192);
}

BOOST_AUTO_TEST_CASE(next_bit_permutation_3_bits)
{
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(7), 11);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(11), 13);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(13), 14);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(14), 19);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(19), 21);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(21), 22);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(22), 25);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(25), 26);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(26), 28);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(28), 35);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(35), 37);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(37), 38);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(38), 41);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(41), 42);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(42), 44);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(44), 49);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(49), 50);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(50), 52);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(52), 56);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(56), 67);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(67), 69);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(69), 70);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(70), 73);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(73), 74);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(74), 76);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(76), 81);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(81), 82);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(82), 84);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(84), 88);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(88), 97);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(97), 98);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(98), 100);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(100), 104);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(104), 112);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(112), 131);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(131), 133);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(133), 134);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(134), 137);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(137), 138);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(138), 140);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(140), 145);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(145), 146);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(146), 148);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(148), 152);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(152), 161);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(161), 162);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(162), 164);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(164), 168);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(168), 176);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(176), 193);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(193), 194);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(194), 196);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(196), 200);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(200), 208);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(208), 224);
}

BOOST_AUTO_TEST_CASE(next_bit_permutation_4_bits)
{
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(15), 23);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(23), 27);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(27), 29);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(29), 30);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(30), 39);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(39), 43);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(43), 45);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(45), 46);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(46), 51);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(51), 53);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(53), 54);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(54), 57);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(57), 58);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(58), 60);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(60), 71);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(71), 75);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(75), 77);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(77), 78);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(78), 83);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(83), 85);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(85), 86);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(86), 89);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(89), 90);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(90), 92);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(92), 99);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(99), 101);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(101), 102);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(102), 105);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(105), 106);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(106), 108);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(108), 113);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(113), 114);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(114), 116);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(116), 120);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(120), 135);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(135), 139);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(139), 141);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(141), 142);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(142), 147);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(147), 149);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(149), 150);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(150), 153);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(153), 154);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(154), 156);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(156), 163);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(163), 165);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(165), 166);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(166), 169);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(169), 170);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(170), 172);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(172), 177);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(177), 178);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(178), 180);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(180), 184);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(184), 195);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(195), 197);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(197), 198);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(198), 201);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(201), 202);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(202), 204);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(204), 209);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(209), 210);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(210), 212);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(212), 216);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(216), 225);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(225), 226);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(226), 228);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(228), 232);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(232), 240);
}

BOOST_AUTO_TEST_CASE(next_bit_permutation_5_bits)
{
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(31), 47);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(47), 55);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(55), 59);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(59), 61);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(61), 62);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(62), 79);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(79), 87);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(87), 91);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(91), 93);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(93), 94);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(94), 103);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(103), 107);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(107), 109);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(109), 110);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(110), 115);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(115), 117);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(117), 118);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(118), 121);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(121), 122);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(122), 124);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(124), 143);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(143), 151);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(151), 155);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(155), 157);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(157), 158);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(158), 167);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(167), 171);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(171), 173);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(173), 174);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(174), 179);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(179), 181);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(181), 182);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(182), 185);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(185), 186);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(186), 188);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(188), 199);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(199), 203);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(203), 205);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(205), 206);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(206), 211);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(211), 213);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(213), 214);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(214), 217);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(217), 218);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(218), 220);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(220), 227);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(227), 229);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(229), 230);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(230), 233);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(233), 234);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(234), 236);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(236), 241);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(241), 242);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(242), 244);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(244), 248);
}

BOOST_AUTO_TEST_CASE(next_bit_permutation_6_bits)
{
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(63), 95);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(95), 111);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(111), 119);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(119), 123);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(123), 125);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(125), 126);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(126), 159);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(159), 175);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(175), 183);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(183), 187);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(187), 189);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(189), 190);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(190), 207);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(207), 215);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(215), 219);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(219), 221);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(221), 222);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(222), 231);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(231), 235);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(235), 237);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(237), 238);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(238), 243);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(243), 245);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(245), 246);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(246), 249);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(249), 250);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(250), 252);
}

BOOST_AUTO_TEST_CASE(next_bit_permutation_7_bits)
{
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(127), 191);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(191), 223);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(223), 239);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(239), 247);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(247), 251);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(251), 253);
	BOOST_CHECK_EQUAL(hep::next_bit_permutation(253), 254);
}
