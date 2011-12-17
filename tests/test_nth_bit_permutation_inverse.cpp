#include <hep/utils/nth_bit_permutation_inverse.hpp>

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(nth_bit_permutation_inverse_1_bit)
{
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(1), 0);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(2), 1);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(4), 2);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(8), 3);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(16), 4);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(32), 5);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(64), 6);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(128), 7);
}

BOOST_AUTO_TEST_CASE(nth_bit_permutation_inverse_2_bits)
{
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(3), 0);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(5), 1);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(6), 2);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(9), 3);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(10), 4);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(12), 5);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(17), 6);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(18), 7);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(20), 8);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(24), 9);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(33), 10);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(34), 11);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(36), 12);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(40), 13);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(48), 14);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(65), 15);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(66), 16);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(68), 17);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(72), 18);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(80), 19);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(96), 20);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(129), 21);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(130), 22);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(132), 23);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(136), 24);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(144), 25);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(160), 26);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(192), 27);
}

BOOST_AUTO_TEST_CASE(nth_bit_permutation_inverse_3_bits)
{
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(7), 0);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(11), 1);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(13), 2);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(14), 3);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(19), 4);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(21), 5);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(22), 6);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(25), 7);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(26), 8);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(28), 9);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(35), 10);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(37), 11);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(38), 12);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(41), 13);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(42), 14);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(44), 15);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(49), 16);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(50), 17);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(52), 18);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(56), 19);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(67), 20);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(69), 21);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(70), 22);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(73), 23);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(74), 24);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(76), 25);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(81), 26);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(82), 27);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(84), 28);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(88), 29);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(97), 30);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(98), 31);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(100), 32);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(104), 33);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(112), 34);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(131), 35);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(133), 36);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(134), 37);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(137), 38);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(138), 39);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(140), 40);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(145), 41);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(146), 42);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(148), 43);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(152), 44);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(161), 45);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(162), 46);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(164), 47);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(168), 48);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(176), 49);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(193), 50);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(194), 51);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(196), 52);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(200), 53);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(208), 54);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(224), 55);
}

BOOST_AUTO_TEST_CASE(nth_bit_permutation_inverse_4_bits)
{
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(15), 0);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(23), 1);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(27), 2);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(29), 3);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(30), 4);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(39), 5);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(43), 6);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(45), 7);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(46), 8);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(51), 9);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(53), 10);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(54), 11);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(57), 12);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(58), 13);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(60), 14);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(71), 15);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(75), 16);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(77), 17);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(78), 18);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(83), 19);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(85), 20);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(86), 21);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(89), 22);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(90), 23);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(92), 24);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(99), 25);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(101), 26);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(102), 27);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(105), 28);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(106), 29);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(108), 30);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(113), 31);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(114), 32);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(116), 33);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(120), 34);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(135), 35);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(139), 36);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(141), 37);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(142), 38);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(147), 39);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(149), 40);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(150), 41);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(153), 42);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(154), 43);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(156), 44);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(163), 45);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(165), 46);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(166), 47);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(169), 48);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(170), 49);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(172), 50);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(177), 51);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(178), 52);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(180), 53);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(184), 54);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(195), 55);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(197), 56);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(198), 57);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(201), 58);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(202), 59);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(204), 60);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(209), 61);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(210), 62);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(212), 63);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(216), 64);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(225), 65);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(226), 66);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(228), 67);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(232), 68);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(240), 69);
}

BOOST_AUTO_TEST_CASE(nth_bit_permutation_inverse_5_bits)
{
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(31), 0);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(47), 1);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(55), 2);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(59), 3);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(61), 4);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(62), 5);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(79), 6);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(87), 7);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(91), 8);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(93), 9);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(94), 10);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(103), 11);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(107), 12);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(109), 13);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(110), 14);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(115), 15);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(117), 16);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(118), 17);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(121), 18);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(122), 19);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(124), 20);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(143), 21);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(151), 22);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(155), 23);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(157), 24);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(158), 25);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(167), 26);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(171), 27);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(173), 28);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(174), 29);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(179), 30);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(181), 31);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(182), 32);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(185), 33);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(186), 34);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(188), 35);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(199), 36);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(203), 37);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(205), 38);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(206), 39);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(211), 40);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(213), 41);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(214), 42);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(217), 43);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(218), 44);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(220), 45);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(227), 46);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(229), 47);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(230), 48);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(233), 49);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(234), 50);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(236), 51);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(241), 52);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(242), 53);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(244), 54);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(248), 55);
}

BOOST_AUTO_TEST_CASE(nth_bit_permutation_inverse_6_bits)
{
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(63), 0);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(95), 1);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(111), 2);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(119), 3);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(123), 4);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(125), 5);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(126), 6);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(159), 7);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(175), 8);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(183), 9);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(187), 10);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(189), 11);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(190), 12);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(207), 13);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(215), 14);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(219), 15);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(221), 16);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(222), 17);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(231), 18);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(235), 19);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(237), 20);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(238), 21);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(243), 22);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(245), 23);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(246), 24);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(249), 25);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(250), 26);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(252), 27);
}

BOOST_AUTO_TEST_CASE(nth_bit_permutation_inverse_7_bits)
{
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(127), 0);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(191), 1);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(223), 2);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(239), 3);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(247), 4);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(251), 5);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(253), 6);
	BOOST_CHECK_EQUAL(hep::nth_bit_permutation_inverse(254), 7);
}
