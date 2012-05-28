#include <tuple>
#include <boost/test/unit_test.hpp>

#include <hep/ga_types.hpp>

BOOST_AUTO_TEST_CASE(index_access)
{
	auto mvs = std::make_tuple(
		mv4<0>{ 2.0 },
		mv4<1,2,4,8>{ 3.0, 5.0, 7.0, 11.0 },
		mv4<3,5,6,9,10,12>{ 13.0, 17.0, 19.0, 23.0, 29.0, 31.0 },
		mv4<7,11,13,14>{ 37.0, 41.0, 43.0, 47.0 },
		mv4<15>{ 53.0 },
		mv4<0,1,2,4,8>{ 59.0, 61.0, 67.0, 71.0, 73.0 },
		mv4<0,3,5,6,9,10,12>{ 79.0, 83.0, 89.0, 97.0, 101.0, 103.0, 107.0 },
		mv4<0,7,11,13,14>{ 109.0, 113.0, 127.0, 131.0, 137.0 },
		mv4<0,15>{ 139.0, 149.0 },
		mv4<1,2,3,4,5,6,8,9,10,12>{
			151.0, 157.0, 163.0, 167.0, 173.0, 179.0, 181.0, 191.0, 193.0, 197.0
		},
		mv4<1,2,4,7,8,11,13,14>{
			199.0, 211.0, 223.0, 227.0, 229.0, 233.0, 239.0, 241.0
		},
		mv4<1,2,4,8,15>{ 251.0, 257.0, 263.0, 269.0, 271.0 },
		mv4<3,5,6,7,9,10,11,12,13,14>{
			277.0, 281.0, 283.0, 293.0, 307.0, 311.0, 313.0, 317.0, 331.0, 337.0
		},
		mv4<3,5,6,9,10,12,15>{
			347.0, 349.0, 353.0, 359.0, 367.0, 373.0, 379.0
		},
		mv4<7,11,13,14,15>{ 383.0, 389.0, 397.0, 401.0, 409.0 },
		mv4<0,1,2,3,4,5,6,8,9,10,12>{
			419.0, 421.0, 431.0, 433.0, 439.0, 443.0, 449.0, 457.0, 461.0,
			463.0, 467.0
		},
		mv4<0,1,2,4,7,8,11,13,14>{
			479.0, 487.0, 491.0, 499.0, 503.0, 509.0, 521.0, 523.0, 541.0
		},
		mv4<0,1,2,4,8,15>{ 547.0, 557.0, 563.0, 569.0, 571.0, 577.0 },
		mv4<0,3,5,6,7,9,10,11,12,13,14>{
			577.0, 587.0, 593.0, 599.0, 601.0, 607.0, 613.0, 617.0, 619.0,
			631.0, 641.0
		},
		mv4<0,3,5,6,9,10,12,15>{
			643.0, 647.0, 653.0, 659.0, 661.0, 673.0, 677.0, 683.0
		},
		mv4<0,7,11,13,14,15>{ 691.0, 701.0, 709.0, 719.0, 727.0, 733.0 },
		mv4<1,2,3,4,5,6,7,8,9,10,11,12,13,14>{
			739.0, 743.0, 751.0, 757.0, 761.0, 769.0, 773.0, 787.0, 797.0,
			809.0, 811.0, 821.0, 823.0, 827.0
		},
		mv4<1,2,3,4,5,6,8,9,10,12,15>{
			829.0, 839.0, 853.0, 857.0, 859.0, 863.0, 877.0, 881.0, 883.0,
			887.0, 907.0
		},
		mv4<1,2,4,7,8,11,13,14,15>{
			911.0, 919.0, 929.0, 937.0, 941.0, 947.0, 953.0, 967.0, 971.0
		},
		mv4<3,5,6,7,9,10,11,12,13,14,15>{
			977.0, 983.0, 991.0, 997.0, 1009.0, 1013.0, 1019.0, 1021.0, 1031.0,
			1033.0, 1039.0
		},
		mv4<0,1,2,3,4,5,6,7,8,9,10,11,12,13,14>{
			1049.0, 1051.0, 1061.0, 1063.0, 1069.0, 1087.0, 1091.0, 1093.0,
			1097.0, 1103.0, 1109.0, 1117.0, 1123.0, 1129.0, 1151.0
		},
		mv4<0,1,2,3,4,5,6,8,9,10,12,15>{
			1163.0, 1171.0, 1181.0, 1187.0, 1193.0, 1201.0, 1213.0, 1217.0,
			1223.0, 1229.0, 1231.0, 1237.0
		},
		mv4<0,1,2,4,7,8,11,13,14,15>{
			1249.0, 1259.0, 1277.0, 1279.0, 1283.0, 1289.0, 1291.0, 1297.0,
			1301.0, 1303.0
		},
		mv4<0,3,5,6,7,9,10,11,12,13,14,15>{
			1307.0, 1319.0, 1321.0, 1327.0, 1361.0,1367.0, 1373.0, 1381.0,
			1399.0, 1409.0, 1423.0, 1427.0
		},
		mv4<1,2,3,4,5,6,7,8,9,10,11,12,13,14,15>{
			1429.0, 1433.0, 1439.0, 1447.0, 1451.0, 1453.0, 1459.0, 1471.0,
			1481.0, 1483.0, 1487.0, 1489.0, 1493.0, 1499.0, 1511.0
		},
		mv4<0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15>{
			1523.0, 1531.0, 1543.0, 1549.0, 1553.0, 1559.0, 1567.0, 1571.0,
			1579.0, 1583.0, 1597.0, 1601.0, 1607.0, 1609.0, 1613.0, 1619.0
		}
	);

	// scalar
	BOOST_CHECK_EQUAL(std::get<0>(mvs).at<0>(), 2.0);

	// vector
	BOOST_CHECK_EQUAL(std::get<1>(mvs).at<1>(), 3.0);
	BOOST_CHECK_EQUAL(std::get<1>(mvs).at<2>(), 5.0);
	BOOST_CHECK_EQUAL(std::get<1>(mvs).at<4>(), 7.0);
	BOOST_CHECK_EQUAL(std::get<1>(mvs).at<8>(), 11.0);

	// bivector
	BOOST_CHECK_EQUAL(std::get<2>(mvs).at<3>(), 13.0);
	BOOST_CHECK_EQUAL(std::get<2>(mvs).at<5>(), 17.0);
	BOOST_CHECK_EQUAL(std::get<2>(mvs).at<6>(), 19.0);
	BOOST_CHECK_EQUAL(std::get<2>(mvs).at<9>(), 23.0);
	BOOST_CHECK_EQUAL(std::get<2>(mvs).at<10>(), 29.0);
	BOOST_CHECK_EQUAL(std::get<2>(mvs).at<12>(), 31.0);

	// trivector
	BOOST_CHECK_EQUAL(std::get<3>(mvs).at<7>(), 37.0);
	BOOST_CHECK_EQUAL(std::get<3>(mvs).at<11>(), 41.0);
	BOOST_CHECK_EQUAL(std::get<3>(mvs).at<13>(), 43.0);
	BOOST_CHECK_EQUAL(std::get<3>(mvs).at<14>(), 47.0);

	// quadvector
	BOOST_CHECK_EQUAL(std::get<4>(mvs).at<15>(), 53.0);

	// scalar + vector
	BOOST_CHECK_EQUAL(std::get<5>(mvs).at<0>(), 59.0);
	BOOST_CHECK_EQUAL(std::get<5>(mvs).at<1>(), 61.0);
	BOOST_CHECK_EQUAL(std::get<5>(mvs).at<2>(), 67.0);
	BOOST_CHECK_EQUAL(std::get<5>(mvs).at<4>(), 71.0);
	BOOST_CHECK_EQUAL(std::get<5>(mvs).at<8>(), 73.0);

	// scalar + bivector
	BOOST_CHECK_EQUAL(std::get<6>(mvs).at<0>(), 79.0);
	BOOST_CHECK_EQUAL(std::get<6>(mvs).at<3>(), 83.0);
	BOOST_CHECK_EQUAL(std::get<6>(mvs).at<5>(), 89.0);
	BOOST_CHECK_EQUAL(std::get<6>(mvs).at<6>(), 97.0);
	BOOST_CHECK_EQUAL(std::get<6>(mvs).at<9>(), 101.0);
	BOOST_CHECK_EQUAL(std::get<6>(mvs).at<10>(), 103.0);
	BOOST_CHECK_EQUAL(std::get<6>(mvs).at<12>(), 107.0);

	// scalar + trivector
	BOOST_CHECK_EQUAL(std::get<7>(mvs).at<0>(), 109.0);
	BOOST_CHECK_EQUAL(std::get<7>(mvs).at<7>(), 113.0);
	BOOST_CHECK_EQUAL(std::get<7>(mvs).at<11>(), 127.0);
	BOOST_CHECK_EQUAL(std::get<7>(mvs).at<13>(), 131.0);
	BOOST_CHECK_EQUAL(std::get<7>(mvs).at<14>(), 137.0);

	// scalar + quadvector
	BOOST_CHECK_EQUAL(std::get<8>(mvs).at<0>(), 139.0);
	BOOST_CHECK_EQUAL(std::get<8>(mvs).at<15>(), 149.0);

	// vector + bivector
	BOOST_CHECK_EQUAL(std::get<9>(mvs).at<1>(), 151.0);
	BOOST_CHECK_EQUAL(std::get<9>(mvs).at<2>(), 157.0);
	BOOST_CHECK_EQUAL(std::get<9>(mvs).at<3>(), 163.0);
	BOOST_CHECK_EQUAL(std::get<9>(mvs).at<4>(), 167.0);
	BOOST_CHECK_EQUAL(std::get<9>(mvs).at<5>(), 173.0);
	BOOST_CHECK_EQUAL(std::get<9>(mvs).at<6>(), 179.0);
	BOOST_CHECK_EQUAL(std::get<9>(mvs).at<8>(), 181.0);
	BOOST_CHECK_EQUAL(std::get<9>(mvs).at<9>(), 191.0);
	BOOST_CHECK_EQUAL(std::get<9>(mvs).at<10>(), 193.0);
	BOOST_CHECK_EQUAL(std::get<9>(mvs).at<12>(), 197.0);

	// vector + trivector
	BOOST_CHECK_EQUAL(std::get<10>(mvs).at<1>(), 199.0);
	BOOST_CHECK_EQUAL(std::get<10>(mvs).at<2>(), 211.0);
	BOOST_CHECK_EQUAL(std::get<10>(mvs).at<4>(), 223.0);
	BOOST_CHECK_EQUAL(std::get<10>(mvs).at<7>(), 227.0);
	BOOST_CHECK_EQUAL(std::get<10>(mvs).at<8>(), 229.0);
	BOOST_CHECK_EQUAL(std::get<10>(mvs).at<11>(), 233.0);
	BOOST_CHECK_EQUAL(std::get<10>(mvs).at<13>(), 239.0);
	BOOST_CHECK_EQUAL(std::get<10>(mvs).at<14>(), 241.0);

	// vector + quadvector
	BOOST_CHECK_EQUAL(std::get<11>(mvs).at<1>(), 251.0);
	BOOST_CHECK_EQUAL(std::get<11>(mvs).at<2>(), 257.0);
	BOOST_CHECK_EQUAL(std::get<11>(mvs).at<4>(), 263.0);
	BOOST_CHECK_EQUAL(std::get<11>(mvs).at<8>(), 269.0);
	BOOST_CHECK_EQUAL(std::get<11>(mvs).at<15>(), 271.0);

	// bivector + trivector
	BOOST_CHECK_EQUAL(std::get<12>(mvs).at<3>(), 277.0);
	BOOST_CHECK_EQUAL(std::get<12>(mvs).at<5>(), 281.0);
	BOOST_CHECK_EQUAL(std::get<12>(mvs).at<6>(), 283.0);
	BOOST_CHECK_EQUAL(std::get<12>(mvs).at<7>(), 293.0);
	BOOST_CHECK_EQUAL(std::get<12>(mvs).at<9>(), 307.0);
	BOOST_CHECK_EQUAL(std::get<12>(mvs).at<10>(), 311.0);
	BOOST_CHECK_EQUAL(std::get<12>(mvs).at<11>(), 313.0);
	BOOST_CHECK_EQUAL(std::get<12>(mvs).at<12>(), 317.0);
	BOOST_CHECK_EQUAL(std::get<12>(mvs).at<13>(), 331.0);
	BOOST_CHECK_EQUAL(std::get<12>(mvs).at<14>(), 337.0);

	// bivector + quadvector
	BOOST_CHECK_EQUAL(std::get<13>(mvs).at<3>(), 347.0);
	BOOST_CHECK_EQUAL(std::get<13>(mvs).at<5>(), 349.0);
	BOOST_CHECK_EQUAL(std::get<13>(mvs).at<6>(), 353.0);
	BOOST_CHECK_EQUAL(std::get<13>(mvs).at<9>(), 359.0);
	BOOST_CHECK_EQUAL(std::get<13>(mvs).at<10>(), 367.0);
	BOOST_CHECK_EQUAL(std::get<13>(mvs).at<12>(), 373.0);
	BOOST_CHECK_EQUAL(std::get<13>(mvs).at<15>(), 379.0);

	// trivector + quadvector
	BOOST_CHECK_EQUAL(std::get<14>(mvs).at<7>(), 383.0);
	BOOST_CHECK_EQUAL(std::get<14>(mvs).at<11>(), 389.0);
	BOOST_CHECK_EQUAL(std::get<14>(mvs).at<13>(), 397.0);
	BOOST_CHECK_EQUAL(std::get<14>(mvs).at<14>(), 401.0);
	BOOST_CHECK_EQUAL(std::get<14>(mvs).at<15>(), 409.0);

	// scalar + vector + bivector
	BOOST_CHECK_EQUAL(std::get<15>(mvs).at<0>(), 419.0);
	BOOST_CHECK_EQUAL(std::get<15>(mvs).at<1>(), 421.0);
	BOOST_CHECK_EQUAL(std::get<15>(mvs).at<2>(), 431.0);
	BOOST_CHECK_EQUAL(std::get<15>(mvs).at<3>(), 433.0);
	BOOST_CHECK_EQUAL(std::get<15>(mvs).at<4>(), 439.0);
	BOOST_CHECK_EQUAL(std::get<15>(mvs).at<5>(), 443.0);
	BOOST_CHECK_EQUAL(std::get<15>(mvs).at<6>(), 449.0);
	BOOST_CHECK_EQUAL(std::get<15>(mvs).at<8>(), 457.0);
	BOOST_CHECK_EQUAL(std::get<15>(mvs).at<9>(), 461.0);
	BOOST_CHECK_EQUAL(std::get<15>(mvs).at<10>(), 463.0);
	BOOST_CHECK_EQUAL(std::get<15>(mvs).at<12>(), 467.0);

	// scalar + vector + trivector
	BOOST_CHECK_EQUAL(std::get<16>(mvs).at<0>(), 479.0);
	BOOST_CHECK_EQUAL(std::get<16>(mvs).at<1>(), 487.0);
	BOOST_CHECK_EQUAL(std::get<16>(mvs).at<2>(), 491.0);
	BOOST_CHECK_EQUAL(std::get<16>(mvs).at<4>(), 499.0);
	BOOST_CHECK_EQUAL(std::get<16>(mvs).at<7>(), 503.0);
	BOOST_CHECK_EQUAL(std::get<16>(mvs).at<8>(), 509.0);
	BOOST_CHECK_EQUAL(std::get<16>(mvs).at<11>(), 521.0);
	BOOST_CHECK_EQUAL(std::get<16>(mvs).at<13>(), 523.0);
	BOOST_CHECK_EQUAL(std::get<16>(mvs).at<14>(), 541.0);

	// scalar + vector + quadvector
	BOOST_CHECK_EQUAL(std::get<17>(mvs).at<0>(), 547.0);
	BOOST_CHECK_EQUAL(std::get<17>(mvs).at<1>(), 557.0);
	BOOST_CHECK_EQUAL(std::get<17>(mvs).at<2>(), 563.0);
	BOOST_CHECK_EQUAL(std::get<17>(mvs).at<4>(), 569.0);
	BOOST_CHECK_EQUAL(std::get<17>(mvs).at<8>(), 571.0);
	BOOST_CHECK_EQUAL(std::get<17>(mvs).at<15>(), 577.0);

	// scalar + bivector + trivector
	BOOST_CHECK_EQUAL(std::get<18>(mvs).at<0>(), 577.0);
	BOOST_CHECK_EQUAL(std::get<18>(mvs).at<3>(), 587.0);
	BOOST_CHECK_EQUAL(std::get<18>(mvs).at<5>(), 593.0);
	BOOST_CHECK_EQUAL(std::get<18>(mvs).at<6>(), 599.0);
	BOOST_CHECK_EQUAL(std::get<18>(mvs).at<7>(), 601.0);
	BOOST_CHECK_EQUAL(std::get<18>(mvs).at<9>(), 607.0);
	BOOST_CHECK_EQUAL(std::get<18>(mvs).at<10>(), 613.0);
	BOOST_CHECK_EQUAL(std::get<18>(mvs).at<11>(), 617.0);
	BOOST_CHECK_EQUAL(std::get<18>(mvs).at<12>(), 619.0);
	BOOST_CHECK_EQUAL(std::get<18>(mvs).at<13>(), 631.0);
	BOOST_CHECK_EQUAL(std::get<18>(mvs).at<14>(), 641.0);

	// scalar + bivector + quadvector
	BOOST_CHECK_EQUAL(std::get<19>(mvs).at<0>(), 643.0);
	BOOST_CHECK_EQUAL(std::get<19>(mvs).at<3>(), 647.0);
	BOOST_CHECK_EQUAL(std::get<19>(mvs).at<5>(), 653.0);
	BOOST_CHECK_EQUAL(std::get<19>(mvs).at<6>(), 659.0);
	BOOST_CHECK_EQUAL(std::get<19>(mvs).at<9>(), 661.0);
	BOOST_CHECK_EQUAL(std::get<19>(mvs).at<10>(), 673.0);
	BOOST_CHECK_EQUAL(std::get<19>(mvs).at<12>(), 677.0);
	BOOST_CHECK_EQUAL(std::get<19>(mvs).at<15>(), 683.0);

	// scalar + trivector + quadvector
	BOOST_CHECK_EQUAL(std::get<20>(mvs).at<0>(), 691.0);
	BOOST_CHECK_EQUAL(std::get<20>(mvs).at<7>(), 701.0);
	BOOST_CHECK_EQUAL(std::get<20>(mvs).at<11>(), 709.0);
	BOOST_CHECK_EQUAL(std::get<20>(mvs).at<13>(), 719.0);
	BOOST_CHECK_EQUAL(std::get<20>(mvs).at<14>(), 727.0);
	BOOST_CHECK_EQUAL(std::get<20>(mvs).at<15>(), 733.0);

	// vector + bivector + trivector
	BOOST_CHECK_EQUAL(std::get<21>(mvs).at<1>(), 739.0);
	BOOST_CHECK_EQUAL(std::get<21>(mvs).at<2>(), 743.0);
	BOOST_CHECK_EQUAL(std::get<21>(mvs).at<3>(), 751.0);
	BOOST_CHECK_EQUAL(std::get<21>(mvs).at<4>(), 757.0);
	BOOST_CHECK_EQUAL(std::get<21>(mvs).at<5>(), 761.0);
	BOOST_CHECK_EQUAL(std::get<21>(mvs).at<6>(), 769.0);
	BOOST_CHECK_EQUAL(std::get<21>(mvs).at<7>(), 773.0);
	BOOST_CHECK_EQUAL(std::get<21>(mvs).at<8>(), 787.0);
	BOOST_CHECK_EQUAL(std::get<21>(mvs).at<9>(), 797.0);
	BOOST_CHECK_EQUAL(std::get<21>(mvs).at<10>(), 809.0);
	BOOST_CHECK_EQUAL(std::get<21>(mvs).at<11>(), 811.0);
	BOOST_CHECK_EQUAL(std::get<21>(mvs).at<12>(), 821.0);
	BOOST_CHECK_EQUAL(std::get<21>(mvs).at<13>(), 823.0);
	BOOST_CHECK_EQUAL(std::get<21>(mvs).at<14>(), 827.0);

	// vector + bivector + quadvector
	BOOST_CHECK_EQUAL(std::get<22>(mvs).at<1>(), 829.0);
	BOOST_CHECK_EQUAL(std::get<22>(mvs).at<2>(), 839.0);
	BOOST_CHECK_EQUAL(std::get<22>(mvs).at<3>(), 853.0);
	BOOST_CHECK_EQUAL(std::get<22>(mvs).at<4>(), 857.0);
	BOOST_CHECK_EQUAL(std::get<22>(mvs).at<5>(), 859.0);
	BOOST_CHECK_EQUAL(std::get<22>(mvs).at<6>(), 863.0);
	BOOST_CHECK_EQUAL(std::get<22>(mvs).at<8>(), 877.0);
	BOOST_CHECK_EQUAL(std::get<22>(mvs).at<9>(), 881.0);
	BOOST_CHECK_EQUAL(std::get<22>(mvs).at<10>(), 883.0);
	BOOST_CHECK_EQUAL(std::get<22>(mvs).at<12>(), 887.0);
	BOOST_CHECK_EQUAL(std::get<22>(mvs).at<15>(), 907.0);

	// vector + trivector + quadvector
	BOOST_CHECK_EQUAL(std::get<23>(mvs).at<1>(), 911.0);
	BOOST_CHECK_EQUAL(std::get<23>(mvs).at<2>(), 919.0);
	BOOST_CHECK_EQUAL(std::get<23>(mvs).at<4>(), 929.0);
	BOOST_CHECK_EQUAL(std::get<23>(mvs).at<7>(), 937.0);
	BOOST_CHECK_EQUAL(std::get<23>(mvs).at<8>(), 941.0);
	BOOST_CHECK_EQUAL(std::get<23>(mvs).at<11>(), 947.0);
	BOOST_CHECK_EQUAL(std::get<23>(mvs).at<13>(), 953.0);
	BOOST_CHECK_EQUAL(std::get<23>(mvs).at<14>(), 967.0);
	BOOST_CHECK_EQUAL(std::get<23>(mvs).at<15>(), 971.0);

	// bivector + trivector + quadvector
	BOOST_CHECK_EQUAL(std::get<24>(mvs).at<3>(), 977.0);
	BOOST_CHECK_EQUAL(std::get<24>(mvs).at<5>(), 983.0);
	BOOST_CHECK_EQUAL(std::get<24>(mvs).at<6>(), 991.0);
	BOOST_CHECK_EQUAL(std::get<24>(mvs).at<7>(), 997.0);
	BOOST_CHECK_EQUAL(std::get<24>(mvs).at<9>(), 1009.0);
	BOOST_CHECK_EQUAL(std::get<24>(mvs).at<10>(), 1013.0);
	BOOST_CHECK_EQUAL(std::get<24>(mvs).at<11>(), 1019.0);
	BOOST_CHECK_EQUAL(std::get<24>(mvs).at<12>(), 1021.0);
	BOOST_CHECK_EQUAL(std::get<24>(mvs).at<13>(), 1031.0);
	BOOST_CHECK_EQUAL(std::get<24>(mvs).at<14>(), 1033.0);
	BOOST_CHECK_EQUAL(std::get<24>(mvs).at<15>(), 1039.0);

	// scalar + vector + bivector + trivector
	BOOST_CHECK_EQUAL(std::get<25>(mvs).at<0>(), 1049.0);
	BOOST_CHECK_EQUAL(std::get<25>(mvs).at<1>(), 1051.0);
	BOOST_CHECK_EQUAL(std::get<25>(mvs).at<2>(), 1061.0);
	BOOST_CHECK_EQUAL(std::get<25>(mvs).at<3>(), 1063.0);
	BOOST_CHECK_EQUAL(std::get<25>(mvs).at<4>(), 1069.0);
	BOOST_CHECK_EQUAL(std::get<25>(mvs).at<5>(), 1087.0);
	BOOST_CHECK_EQUAL(std::get<25>(mvs).at<6>(), 1091.0);
	BOOST_CHECK_EQUAL(std::get<25>(mvs).at<7>(), 1093.0);
	BOOST_CHECK_EQUAL(std::get<25>(mvs).at<8>(), 1097.0);
	BOOST_CHECK_EQUAL(std::get<25>(mvs).at<9>(), 1103.0);
	BOOST_CHECK_EQUAL(std::get<25>(mvs).at<10>(), 1109.0);
	BOOST_CHECK_EQUAL(std::get<25>(mvs).at<11>(), 1117.0);
	BOOST_CHECK_EQUAL(std::get<25>(mvs).at<12>(), 1123.0);
	BOOST_CHECK_EQUAL(std::get<25>(mvs).at<13>(), 1129.0);
	BOOST_CHECK_EQUAL(std::get<25>(mvs).at<14>(), 1151.0);

	// scalar + vector + bivector + quadvector
	BOOST_CHECK_EQUAL(std::get<26>(mvs).at<0>(), 1163.0);
	BOOST_CHECK_EQUAL(std::get<26>(mvs).at<1>(), 1171.0);
	BOOST_CHECK_EQUAL(std::get<26>(mvs).at<2>(), 1181.0);
	BOOST_CHECK_EQUAL(std::get<26>(mvs).at<3>(), 1187.0);
	BOOST_CHECK_EQUAL(std::get<26>(mvs).at<4>(), 1193.0);
	BOOST_CHECK_EQUAL(std::get<26>(mvs).at<5>(), 1201.0);
	BOOST_CHECK_EQUAL(std::get<26>(mvs).at<6>(), 1213.0);
	BOOST_CHECK_EQUAL(std::get<26>(mvs).at<8>(), 1217.0);
	BOOST_CHECK_EQUAL(std::get<26>(mvs).at<9>(), 1223.0);
	BOOST_CHECK_EQUAL(std::get<26>(mvs).at<10>(), 1229.0);
	BOOST_CHECK_EQUAL(std::get<26>(mvs).at<12>(), 1231.0);
	BOOST_CHECK_EQUAL(std::get<26>(mvs).at<15>(), 1237.0);

	// scalar + vector + trivector + quadvector
	BOOST_CHECK_EQUAL(std::get<27>(mvs).at<0>(), 1249.0);
	BOOST_CHECK_EQUAL(std::get<27>(mvs).at<1>(), 1259.0);
	BOOST_CHECK_EQUAL(std::get<27>(mvs).at<2>(), 1277.0);
	BOOST_CHECK_EQUAL(std::get<27>(mvs).at<4>(), 1279.0);
	BOOST_CHECK_EQUAL(std::get<27>(mvs).at<7>(), 1283.0);
	BOOST_CHECK_EQUAL(std::get<27>(mvs).at<8>(), 1289.0);
	BOOST_CHECK_EQUAL(std::get<27>(mvs).at<11>(), 1291.0);
	BOOST_CHECK_EQUAL(std::get<27>(mvs).at<13>(), 1297.0);
	BOOST_CHECK_EQUAL(std::get<27>(mvs).at<14>(), 1301.0);
	BOOST_CHECK_EQUAL(std::get<27>(mvs).at<15>(), 1303.0);

	// scalar + bivector + trivector + quadvector
	BOOST_CHECK_EQUAL(std::get<28>(mvs).at<0>(), 1307.0);
	BOOST_CHECK_EQUAL(std::get<28>(mvs).at<3>(), 1319.0);
	BOOST_CHECK_EQUAL(std::get<28>(mvs).at<5>(), 1321.0);
	BOOST_CHECK_EQUAL(std::get<28>(mvs).at<6>(), 1327.0);
	BOOST_CHECK_EQUAL(std::get<28>(mvs).at<7>(), 1361.0);
	BOOST_CHECK_EQUAL(std::get<28>(mvs).at<9>(), 1367.0);
	BOOST_CHECK_EQUAL(std::get<28>(mvs).at<10>(), 1373.0);
	BOOST_CHECK_EQUAL(std::get<28>(mvs).at<11>(), 1381.0);
	BOOST_CHECK_EQUAL(std::get<28>(mvs).at<12>(), 1399.0);
	BOOST_CHECK_EQUAL(std::get<28>(mvs).at<13>(), 1409.0);
	BOOST_CHECK_EQUAL(std::get<28>(mvs).at<14>(), 1423.0);
	BOOST_CHECK_EQUAL(std::get<28>(mvs).at<15>(), 1427.0);

	// vector + bivector + trivector + quadvector
	BOOST_CHECK_EQUAL(std::get<29>(mvs).at<1>(), 1429.0);
	BOOST_CHECK_EQUAL(std::get<29>(mvs).at<2>(), 1433.0);
	BOOST_CHECK_EQUAL(std::get<29>(mvs).at<3>(), 1439.0);
	BOOST_CHECK_EQUAL(std::get<29>(mvs).at<4>(), 1447.0);
	BOOST_CHECK_EQUAL(std::get<29>(mvs).at<5>(), 1451.0);
	BOOST_CHECK_EQUAL(std::get<29>(mvs).at<6>(), 1453.0);
	BOOST_CHECK_EQUAL(std::get<29>(mvs).at<7>(), 1459.0);
	BOOST_CHECK_EQUAL(std::get<29>(mvs).at<8>(), 1471.0);
	BOOST_CHECK_EQUAL(std::get<29>(mvs).at<9>(), 1481.0);
	BOOST_CHECK_EQUAL(std::get<29>(mvs).at<10>(), 1483.0);
	BOOST_CHECK_EQUAL(std::get<29>(mvs).at<11>(), 1487.0);
	BOOST_CHECK_EQUAL(std::get<29>(mvs).at<12>(), 1489.0);
	BOOST_CHECK_EQUAL(std::get<29>(mvs).at<13>(), 1493.0);
	BOOST_CHECK_EQUAL(std::get<29>(mvs).at<14>(), 1499.0);
	BOOST_CHECK_EQUAL(std::get<29>(mvs).at<15>(), 1511.0);

	// scalar + vector + bivector + trivector + quadvector
	BOOST_CHECK_EQUAL(std::get<30>(mvs).at<0>(), 1523.0);
	BOOST_CHECK_EQUAL(std::get<30>(mvs).at<1>(), 1531.0);
	BOOST_CHECK_EQUAL(std::get<30>(mvs).at<2>(), 1543.0);
	BOOST_CHECK_EQUAL(std::get<30>(mvs).at<3>(), 1549.0);
	BOOST_CHECK_EQUAL(std::get<30>(mvs).at<4>(), 1553.0);
	BOOST_CHECK_EQUAL(std::get<30>(mvs).at<5>(), 1559.0);
	BOOST_CHECK_EQUAL(std::get<30>(mvs).at<6>(), 1567.0);
	BOOST_CHECK_EQUAL(std::get<30>(mvs).at<7>(), 1571.0);
	BOOST_CHECK_EQUAL(std::get<30>(mvs).at<8>(), 1579.0);
	BOOST_CHECK_EQUAL(std::get<30>(mvs).at<9>(), 1583.0);
	BOOST_CHECK_EQUAL(std::get<30>(mvs).at<10>(), 1597.0);
	BOOST_CHECK_EQUAL(std::get<30>(mvs).at<11>(), 1601.0);
	BOOST_CHECK_EQUAL(std::get<30>(mvs).at<12>(), 1607.0);
	BOOST_CHECK_EQUAL(std::get<30>(mvs).at<13>(), 1609.0);
	BOOST_CHECK_EQUAL(std::get<30>(mvs).at<14>(), 1613.0);
	BOOST_CHECK_EQUAL(std::get<30>(mvs).at<15>(), 1619.0);
}
