#include <tuple>

#include <hep/multi_vector.hpp>

#include <boost/test/unit_test.hpp>

// multi vector with metric (1,3) and general grade list
template <std::size_t L>
using mv4 = hep::multi_vector<float, 1, 3, L>;

BOOST_AUTO_TEST_CASE(component_access)
{
	auto mvs = std::make_tuple(
		mv4< 1>{ 2.0f },
		mv4< 2>{ 3.0f, 5.0f, 7.0f, 11.0f },
		mv4< 4>{ 13.0f, 17.0f, 19.0f, 23.0f,
		         29.0f, 31.0f },
		mv4< 8>{ 37.0f, 41.0f, 43.0f, 47.0f },
		mv4<16>{ 53.0f },
		mv4< 3>{ 59.0f, 61.0f, 67.0f, 71.0f,
		         73.0f },
		mv4< 5>{ 79.0f, 83.0f, 89.0f, 97.0f,
		         101.0f, 103.0f, 107.0f },
		mv4< 9>{ 109.0f, 113.0f, 127.0f,
		         131.0f, 137.0f },
		mv4<17>{ 139.0f, 149.0f },
		mv4< 6>{ 151.0f, 157.0f, 167.0f, 181.0f,
		         163.0f, 173.0f, 179.0f, 191.0f,
		         193.0f, 197.0f },
		mv4<10>{ 199.0f, 211.0f, 223.0f, 229.0f,
		         227.0f, 233.0f, 239.0f, 241.0f },
		mv4<18>{ 251.0f, 257.0f, 263.0f, 269.0f,
		         271.0f },
		mv4<12>{ 277.0f, 281.0f, 283.0f, 307.0f,
		         311.0f, 317.0f, 293.0f, 313.0f,
		         331.0f, 337.0f },
		mv4<20>{ 347.0f, 349.0f, 353.0f, 359.0f,
		         367.0f, 373.0f, 379.0f },
		mv4<24>{ 383.0f, 389.0f, 397.0f, 401.0f,
		         409.0f },
		mv4< 7>{ 419.0f, 421.0f, 431.0f, 439.0f,
		         457.0f, 433.0f, 443.0f, 449.0f,
		         461.0f, 463.0f, 467.0f },
		mv4<11>{ 479.0f, 487.0f, 491.0f, 499.0f,
		         509.0f, 503.0f, 521.0f, 523.0f,
		         541.0f },
		mv4<19>{ 547.0f, 557.0f, 563.0f, 569.0f,
		         571.0f, 577.0f },
		mv4<13>{ 577.0f, 587.0f, 593.0f, 599.0f, 
		         607.0f, 613.0f, 619.0f, 601.0f,
		         617.0f, 631.0f, 641.0f },
		mv4<21>{ 643.0f, 647.0f, 653.0f, 659.0f,
		         661.0f, 673.0f, 677.0f, 683.0f },
		mv4<25>{ 691.0f, 701.0f, 709.0f, 719.0f,
		         727.0f, 733.0f },
		mv4<14>{ 739.0f, 743.0f, 757.0f, 787.0f,
		         751.0f, 761.0f, 769.0f, 797.0f,
		         809.0f, 821.0f, 773.0f, 811.0f,
		         823.0f, 827.0f },
		mv4<22>{ 829.0f, 839.0f, 857.0f, 877.0f,
		         853.0f, 859.0f, 863.0f, 881.0f,
		         883.0f, 887.0f, 907.0f },
		mv4<26>{ 911.0f, 919.0f, 929.0f, 941.0f,
		         937.0f, 947.0f, 953.0f, 967.0f,
		         971.0f },
		mv4<28>{ 977.0f, 983.0f, 991.0f, 1009.0f,
		         1013.0f, 1021.0f, 997.0f, 1019.0f,
		         1031.0f, 1033.0f, 1039.0f },
		mv4<15>{ 1049.0f, 1051.0f, 1061.0f, 1069.0f,
		         1097.0f, 1063.0f, 1087.0f, 1091.0f, 
		         1103.0f, 1109.0f, 1123.0f, 1093.0f,
		         1117.0f, 1129.0f, 1151.0f },
		mv4<23>{ 1163.0f, 1171.0f, 1181.0f, 1193.0f,
		         1217.0f, 1187.0f, 1201.0f, 1213.0f,
		         1223.0f, 1229.0f, 1231.0f, 1237.0f },
		mv4<27>{ 1249.0f, 1259.0f, 1277.0f, 1279.0f,
		         1289.0f, 1283.0f, 1291.0f, 1297.0f,
		         1301.0f, 1303.0f },
		mv4<29>{ 1307.0f, 1319.0f, 1321.0f, 1327.0f, 
		         1367.0f, 1373.0f, 1399.0f, 1361.0f,
		         1381.0f,1409.0f, 1423.0f, 1427.0f },
		mv4<30>{ 1429.0f, 1433.0f, 1447.0f, 1471.0f,
		         1439.0f, 1451.0f, 1453.0f, 1481.0f,
		         1483.0f, 1489.0f, 1459.0f, 1487.0f,
				 1493.0f, 1499.0f, 1511.0f },
		mv4<31>{ 1523.0f, 1531.0f, 1543.0f, 1553.0f,
		         1579.0f, 1549.0f, 1559.0f, 1567.0f,
		         1583.0f, 1597.0f, 1607.0f, 1571.0f,
		         1601.0f, 1609.0f, 1613.0f, 1619.0f }
	);

	// scalar
	BOOST_CHECK_EQUAL(std::get<0>(mvs)[0], 2.0f);

	// vector
	BOOST_CHECK_EQUAL(std::get<1>(mvs)[0], 3.0f);
	BOOST_CHECK_EQUAL(std::get<1>(mvs)[1], 5.0f);
	BOOST_CHECK_EQUAL(std::get<1>(mvs)[2], 7.0f);
	BOOST_CHECK_EQUAL(std::get<1>(mvs)[3], 11.0f);

	// bivector
	BOOST_CHECK_EQUAL(std::get<2>(mvs)[0], 13.0f);
	BOOST_CHECK_EQUAL(std::get<2>(mvs)[1], 17.0f);
	BOOST_CHECK_EQUAL(std::get<2>(mvs)[2], 19.0f);
	BOOST_CHECK_EQUAL(std::get<2>(mvs)[3], 23.0f);
	BOOST_CHECK_EQUAL(std::get<2>(mvs)[4], 29.0f);
	BOOST_CHECK_EQUAL(std::get<2>(mvs)[5], 31.0f);

	// trivector
	BOOST_CHECK_EQUAL(std::get<3>(mvs)[0], 37.0f);
	BOOST_CHECK_EQUAL(std::get<3>(mvs)[1], 41.0f);
	BOOST_CHECK_EQUAL(std::get<3>(mvs)[2], 43.0f);
	BOOST_CHECK_EQUAL(std::get<3>(mvs)[3], 47.0f);

	// quadvector
	BOOST_CHECK_EQUAL(std::get<4>(mvs)[0], 53.0f);

	// scalar + vector
	BOOST_CHECK_EQUAL(std::get<5>(mvs)[0], 59.0f);
	BOOST_CHECK_EQUAL(std::get<5>(mvs)[1], 61.0f);
	BOOST_CHECK_EQUAL(std::get<5>(mvs)[2], 67.0f);
	BOOST_CHECK_EQUAL(std::get<5>(mvs)[3], 71.0f);
	BOOST_CHECK_EQUAL(std::get<5>(mvs)[4], 73.0f);

	// scalar + bivector
	BOOST_CHECK_EQUAL(std::get<6>(mvs)[0], 79.0f);
	BOOST_CHECK_EQUAL(std::get<6>(mvs)[1], 83.0f);
	BOOST_CHECK_EQUAL(std::get<6>(mvs)[2], 89.0f);
	BOOST_CHECK_EQUAL(std::get<6>(mvs)[3], 97.0f);
	BOOST_CHECK_EQUAL(std::get<6>(mvs)[4], 101.0f);
	BOOST_CHECK_EQUAL(std::get<6>(mvs)[5], 103.0f);
	BOOST_CHECK_EQUAL(std::get<6>(mvs)[6], 107.0f);

	// scalar + trivector
	BOOST_CHECK_EQUAL(std::get<7>(mvs)[0], 109.0f);
	BOOST_CHECK_EQUAL(std::get<7>(mvs)[1], 113.0f);
	BOOST_CHECK_EQUAL(std::get<7>(mvs)[2], 127.0f);
	BOOST_CHECK_EQUAL(std::get<7>(mvs)[3], 131.0f);
	BOOST_CHECK_EQUAL(std::get<7>(mvs)[4], 137.0f);

	// scalar + quadvector
	BOOST_CHECK_EQUAL(std::get<8>(mvs)[0], 139.0f);
	BOOST_CHECK_EQUAL(std::get<8>(mvs)[1], 149.0f);

	// vector + bivector
	BOOST_CHECK_EQUAL(std::get<9>(mvs)[0], 151.0f);
	BOOST_CHECK_EQUAL(std::get<9>(mvs)[1], 157.0f);
	BOOST_CHECK_EQUAL(std::get<9>(mvs)[2], 167.0f);
	BOOST_CHECK_EQUAL(std::get<9>(mvs)[3], 181.0f);
	BOOST_CHECK_EQUAL(std::get<9>(mvs)[4], 163.0f);
	BOOST_CHECK_EQUAL(std::get<9>(mvs)[5], 173.0f);
	BOOST_CHECK_EQUAL(std::get<9>(mvs)[6], 179.0f);
	BOOST_CHECK_EQUAL(std::get<9>(mvs)[7], 191.0f);
	BOOST_CHECK_EQUAL(std::get<9>(mvs)[8], 193.0f);
	BOOST_CHECK_EQUAL(std::get<9>(mvs)[9], 197.0f);

	// vector + trivector
	BOOST_CHECK_EQUAL(std::get<10>(mvs)[0], 199.0f);
	BOOST_CHECK_EQUAL(std::get<10>(mvs)[1], 211.0f);
	BOOST_CHECK_EQUAL(std::get<10>(mvs)[2], 223.0f);
	BOOST_CHECK_EQUAL(std::get<10>(mvs)[3], 229.0f);
	BOOST_CHECK_EQUAL(std::get<10>(mvs)[4], 227.0f);
	BOOST_CHECK_EQUAL(std::get<10>(mvs)[5], 233.0f);
	BOOST_CHECK_EQUAL(std::get<10>(mvs)[6], 239.0f);
	BOOST_CHECK_EQUAL(std::get<10>(mvs)[7], 241.0f);

	// vector + quadvector
	BOOST_CHECK_EQUAL(std::get<11>(mvs)[0], 251.0f);
	BOOST_CHECK_EQUAL(std::get<11>(mvs)[1], 257.0f);
	BOOST_CHECK_EQUAL(std::get<11>(mvs)[2], 263.0f);
	BOOST_CHECK_EQUAL(std::get<11>(mvs)[3], 269.0f);
	BOOST_CHECK_EQUAL(std::get<11>(mvs)[4], 271.0f);

	// bivector + trivector
	BOOST_CHECK_EQUAL(std::get<12>(mvs)[0], 277.0f);
	BOOST_CHECK_EQUAL(std::get<12>(mvs)[1], 281.0f);
	BOOST_CHECK_EQUAL(std::get<12>(mvs)[2], 283.0f);
	BOOST_CHECK_EQUAL(std::get<12>(mvs)[3], 307.0f);
	BOOST_CHECK_EQUAL(std::get<12>(mvs)[4], 311.0f);
	BOOST_CHECK_EQUAL(std::get<12>(mvs)[5], 317.0f);
	BOOST_CHECK_EQUAL(std::get<12>(mvs)[6], 293.0f);
	BOOST_CHECK_EQUAL(std::get<12>(mvs)[7], 313.0f);
	BOOST_CHECK_EQUAL(std::get<12>(mvs)[8], 331.0f);
	BOOST_CHECK_EQUAL(std::get<12>(mvs)[9], 337.0f);

	// bivector + quadvector
	BOOST_CHECK_EQUAL(std::get<13>(mvs)[0], 347.0f);
	BOOST_CHECK_EQUAL(std::get<13>(mvs)[1], 349.0f);
	BOOST_CHECK_EQUAL(std::get<13>(mvs)[2], 353.0f);
	BOOST_CHECK_EQUAL(std::get<13>(mvs)[3], 359.0f);
	BOOST_CHECK_EQUAL(std::get<13>(mvs)[4], 367.0f);
	BOOST_CHECK_EQUAL(std::get<13>(mvs)[5], 373.0f);
	BOOST_CHECK_EQUAL(std::get<13>(mvs)[6], 379.0f);

	// trivector + quadvector
	BOOST_CHECK_EQUAL(std::get<14>(mvs)[0], 383.0f);
	BOOST_CHECK_EQUAL(std::get<14>(mvs)[1], 389.0f);
	BOOST_CHECK_EQUAL(std::get<14>(mvs)[2], 397.0f);
	BOOST_CHECK_EQUAL(std::get<14>(mvs)[3], 401.0f);
	BOOST_CHECK_EQUAL(std::get<14>(mvs)[4], 409.0f);

	// scalar + vector + bivector
	BOOST_CHECK_EQUAL(std::get<15>(mvs)[0], 419.0f);
	BOOST_CHECK_EQUAL(std::get<15>(mvs)[1], 421.0f);
	BOOST_CHECK_EQUAL(std::get<15>(mvs)[2], 431.0f);
	BOOST_CHECK_EQUAL(std::get<15>(mvs)[3], 439.0f);
	BOOST_CHECK_EQUAL(std::get<15>(mvs)[4], 457.0f);
	BOOST_CHECK_EQUAL(std::get<15>(mvs)[5], 433.0f);
	BOOST_CHECK_EQUAL(std::get<15>(mvs)[6], 443.0f);
	BOOST_CHECK_EQUAL(std::get<15>(mvs)[7], 449.0f);
	BOOST_CHECK_EQUAL(std::get<15>(mvs)[8], 461.0f);
	BOOST_CHECK_EQUAL(std::get<15>(mvs)[9], 463.0f);
	BOOST_CHECK_EQUAL(std::get<15>(mvs)[10], 467.0f);

	// scalar + vector + trivector
	BOOST_CHECK_EQUAL(std::get<16>(mvs)[0], 479.0f);
	BOOST_CHECK_EQUAL(std::get<16>(mvs)[1], 487.0f);
	BOOST_CHECK_EQUAL(std::get<16>(mvs)[2], 491.0f);
	BOOST_CHECK_EQUAL(std::get<16>(mvs)[3], 499.0f);
	BOOST_CHECK_EQUAL(std::get<16>(mvs)[4], 509.0f);
	BOOST_CHECK_EQUAL(std::get<16>(mvs)[5], 503.0f);
	BOOST_CHECK_EQUAL(std::get<16>(mvs)[6], 521.0f);
	BOOST_CHECK_EQUAL(std::get<16>(mvs)[7], 523.0f);
	BOOST_CHECK_EQUAL(std::get<16>(mvs)[8], 541.0f);

	// scalar + vector + quadvector
	BOOST_CHECK_EQUAL(std::get<17>(mvs)[0], 547.0f);
	BOOST_CHECK_EQUAL(std::get<17>(mvs)[1], 557.0f);
	BOOST_CHECK_EQUAL(std::get<17>(mvs)[2], 563.0f);
	BOOST_CHECK_EQUAL(std::get<17>(mvs)[3], 569.0f);
	BOOST_CHECK_EQUAL(std::get<17>(mvs)[4], 571.0f);
	BOOST_CHECK_EQUAL(std::get<17>(mvs)[5], 577.0f);

	// scalar + bivector + trivector
	BOOST_CHECK_EQUAL(std::get<18>(mvs)[0], 577.0f);
	BOOST_CHECK_EQUAL(std::get<18>(mvs)[1], 587.0f);
	BOOST_CHECK_EQUAL(std::get<18>(mvs)[2], 593.0f);
	BOOST_CHECK_EQUAL(std::get<18>(mvs)[3], 599.0f);
	BOOST_CHECK_EQUAL(std::get<18>(mvs)[4], 607.0f);
	BOOST_CHECK_EQUAL(std::get<18>(mvs)[5], 613.0f);
	BOOST_CHECK_EQUAL(std::get<18>(mvs)[6], 619.0f);
	BOOST_CHECK_EQUAL(std::get<18>(mvs)[7], 601.0f);
	BOOST_CHECK_EQUAL(std::get<18>(mvs)[8], 617.0f);
	BOOST_CHECK_EQUAL(std::get<18>(mvs)[9], 631.0f);
	BOOST_CHECK_EQUAL(std::get<18>(mvs)[10], 641.0f);

	// scalar + bivector + quadvector
	BOOST_CHECK_EQUAL(std::get<19>(mvs)[0], 643.0f);
	BOOST_CHECK_EQUAL(std::get<19>(mvs)[1], 647.0f);
	BOOST_CHECK_EQUAL(std::get<19>(mvs)[2], 653.0f);
	BOOST_CHECK_EQUAL(std::get<19>(mvs)[3], 659.0f);
	BOOST_CHECK_EQUAL(std::get<19>(mvs)[4], 661.0f);
	BOOST_CHECK_EQUAL(std::get<19>(mvs)[5], 673.0f);
	BOOST_CHECK_EQUAL(std::get<19>(mvs)[6], 677.0f);
	BOOST_CHECK_EQUAL(std::get<19>(mvs)[7], 683.0f);

	// scalar + trivector + quadvector
	BOOST_CHECK_EQUAL(std::get<20>(mvs)[0], 691.0f);
	BOOST_CHECK_EQUAL(std::get<20>(mvs)[1], 701.0f);
	BOOST_CHECK_EQUAL(std::get<20>(mvs)[2], 709.0f);
	BOOST_CHECK_EQUAL(std::get<20>(mvs)[3], 719.0f);
	BOOST_CHECK_EQUAL(std::get<20>(mvs)[4], 727.0f);
	BOOST_CHECK_EQUAL(std::get<20>(mvs)[5], 733.0f);

	// vector + bivector + trivector
	BOOST_CHECK_EQUAL(std::get<21>(mvs)[0], 739.0f);
	BOOST_CHECK_EQUAL(std::get<21>(mvs)[1], 743.0f);
	BOOST_CHECK_EQUAL(std::get<21>(mvs)[2], 757.0f);
	BOOST_CHECK_EQUAL(std::get<21>(mvs)[3], 787.0f);
	BOOST_CHECK_EQUAL(std::get<21>(mvs)[4], 751.0f);
	BOOST_CHECK_EQUAL(std::get<21>(mvs)[5], 761.0f);
	BOOST_CHECK_EQUAL(std::get<21>(mvs)[6], 769.0f);
	BOOST_CHECK_EQUAL(std::get<21>(mvs)[7], 797.0f);
	BOOST_CHECK_EQUAL(std::get<21>(mvs)[8], 809.0f);
	BOOST_CHECK_EQUAL(std::get<21>(mvs)[9], 821.0f);
	BOOST_CHECK_EQUAL(std::get<21>(mvs)[10], 773.0f);
	BOOST_CHECK_EQUAL(std::get<21>(mvs)[11], 811.0f);
	BOOST_CHECK_EQUAL(std::get<21>(mvs)[12], 823.0f);
	BOOST_CHECK_EQUAL(std::get<21>(mvs)[13], 827.0f);

	// vector + bivector + quadvector
	BOOST_CHECK_EQUAL(std::get<22>(mvs)[0], 829.0f);
	BOOST_CHECK_EQUAL(std::get<22>(mvs)[1], 839.0f);
	BOOST_CHECK_EQUAL(std::get<22>(mvs)[2], 857.0f);
	BOOST_CHECK_EQUAL(std::get<22>(mvs)[3], 877.0f);
	BOOST_CHECK_EQUAL(std::get<22>(mvs)[4], 853.0f);
	BOOST_CHECK_EQUAL(std::get<22>(mvs)[5], 859.0f);
	BOOST_CHECK_EQUAL(std::get<22>(mvs)[6], 863.0f);
	BOOST_CHECK_EQUAL(std::get<22>(mvs)[7], 881.0f);
	BOOST_CHECK_EQUAL(std::get<22>(mvs)[8], 883.0f);
	BOOST_CHECK_EQUAL(std::get<22>(mvs)[9], 887.0f);
	BOOST_CHECK_EQUAL(std::get<22>(mvs)[10], 907.0f);

	// vector + trivector + quadvector
	BOOST_CHECK_EQUAL(std::get<23>(mvs)[0], 911.0f);
	BOOST_CHECK_EQUAL(std::get<23>(mvs)[1], 919.0f);
	BOOST_CHECK_EQUAL(std::get<23>(mvs)[2], 929.0f);
	BOOST_CHECK_EQUAL(std::get<23>(mvs)[3], 941.0f);
	BOOST_CHECK_EQUAL(std::get<23>(mvs)[4], 937.0f);
	BOOST_CHECK_EQUAL(std::get<23>(mvs)[5], 947.0f);
	BOOST_CHECK_EQUAL(std::get<23>(mvs)[6], 953.0f);
	BOOST_CHECK_EQUAL(std::get<23>(mvs)[7], 967.0f);
	BOOST_CHECK_EQUAL(std::get<23>(mvs)[8], 971.0f);

	// bivector + trivector + quadvector
	BOOST_CHECK_EQUAL(std::get<24>(mvs)[0], 977.0f);
	BOOST_CHECK_EQUAL(std::get<24>(mvs)[1], 983.0f);
	BOOST_CHECK_EQUAL(std::get<24>(mvs)[2], 991.0f);
	BOOST_CHECK_EQUAL(std::get<24>(mvs)[3], 1009.0f);
	BOOST_CHECK_EQUAL(std::get<24>(mvs)[4], 1013.0f);
	BOOST_CHECK_EQUAL(std::get<24>(mvs)[5], 1021.0f);
	BOOST_CHECK_EQUAL(std::get<24>(mvs)[6], 997.0f);
	BOOST_CHECK_EQUAL(std::get<24>(mvs)[7], 1019.0f);
	BOOST_CHECK_EQUAL(std::get<24>(mvs)[8], 1031.0f);
	BOOST_CHECK_EQUAL(std::get<24>(mvs)[9], 1033.0f);
	BOOST_CHECK_EQUAL(std::get<24>(mvs)[10], 1039.0f);

	// scalar + vector + bivector + trivector
	BOOST_CHECK_EQUAL(std::get<25>(mvs)[0], 1049.0f);
	BOOST_CHECK_EQUAL(std::get<25>(mvs)[1], 1051.0f);
	BOOST_CHECK_EQUAL(std::get<25>(mvs)[2], 1061.0f);
	BOOST_CHECK_EQUAL(std::get<25>(mvs)[3], 1069.0f);
	BOOST_CHECK_EQUAL(std::get<25>(mvs)[4], 1097.0f);
	BOOST_CHECK_EQUAL(std::get<25>(mvs)[5], 1063.0f);
	BOOST_CHECK_EQUAL(std::get<25>(mvs)[6], 1087.0f);
	BOOST_CHECK_EQUAL(std::get<25>(mvs)[7], 1091.0f);
	BOOST_CHECK_EQUAL(std::get<25>(mvs)[8], 1103.0f);
	BOOST_CHECK_EQUAL(std::get<25>(mvs)[9], 1109.0f);
	BOOST_CHECK_EQUAL(std::get<25>(mvs)[10], 1123.0f);
	BOOST_CHECK_EQUAL(std::get<25>(mvs)[11], 1093.0f);
	BOOST_CHECK_EQUAL(std::get<25>(mvs)[12], 1117.0f);
	BOOST_CHECK_EQUAL(std::get<25>(mvs)[13], 1129.0f);
	BOOST_CHECK_EQUAL(std::get<25>(mvs)[14], 1151.0f);

	// scalar + vector + bivector + quadvector
	BOOST_CHECK_EQUAL(std::get<26>(mvs)[0], 1163.0f);
	BOOST_CHECK_EQUAL(std::get<26>(mvs)[1], 1171.0f);
	BOOST_CHECK_EQUAL(std::get<26>(mvs)[2], 1181.0f);
	BOOST_CHECK_EQUAL(std::get<26>(mvs)[3], 1193.0f);
	BOOST_CHECK_EQUAL(std::get<26>(mvs)[4], 1217.0f);
	BOOST_CHECK_EQUAL(std::get<26>(mvs)[5], 1187.0f);
	BOOST_CHECK_EQUAL(std::get<26>(mvs)[6], 1201.0f);
	BOOST_CHECK_EQUAL(std::get<26>(mvs)[7], 1213.0f);
	BOOST_CHECK_EQUAL(std::get<26>(mvs)[8], 1223.0f);
	BOOST_CHECK_EQUAL(std::get<26>(mvs)[9], 1229.0f);
	BOOST_CHECK_EQUAL(std::get<26>(mvs)[10], 1231.0f);
	BOOST_CHECK_EQUAL(std::get<26>(mvs)[11], 1237.0f);

	// scalar + vector + trivector + quadvector
	BOOST_CHECK_EQUAL(std::get<27>(mvs)[0], 1249.0f);
	BOOST_CHECK_EQUAL(std::get<27>(mvs)[1], 1259.0f);
	BOOST_CHECK_EQUAL(std::get<27>(mvs)[2], 1277.0f);
	BOOST_CHECK_EQUAL(std::get<27>(mvs)[3], 1279.0f);
	BOOST_CHECK_EQUAL(std::get<27>(mvs)[4], 1289.0f);
	BOOST_CHECK_EQUAL(std::get<27>(mvs)[5], 1283.0f);
	BOOST_CHECK_EQUAL(std::get<27>(mvs)[6], 1291.0f);
	BOOST_CHECK_EQUAL(std::get<27>(mvs)[7], 1297.0f);
	BOOST_CHECK_EQUAL(std::get<27>(mvs)[8], 1301.0f);
	BOOST_CHECK_EQUAL(std::get<27>(mvs)[9], 1303.0f);

	// scalar + bivector + trivector + quadvector
	BOOST_CHECK_EQUAL(std::get<28>(mvs)[0], 1307.0f);
	BOOST_CHECK_EQUAL(std::get<28>(mvs)[1], 1319.0f);
	BOOST_CHECK_EQUAL(std::get<28>(mvs)[2], 1321.0f);
	BOOST_CHECK_EQUAL(std::get<28>(mvs)[3], 1327.0f);
	BOOST_CHECK_EQUAL(std::get<28>(mvs)[4], 1367.0f);
	BOOST_CHECK_EQUAL(std::get<28>(mvs)[5], 1373.0f);
	BOOST_CHECK_EQUAL(std::get<28>(mvs)[6], 1399.0f);
	BOOST_CHECK_EQUAL(std::get<28>(mvs)[7], 1361.0f);
	BOOST_CHECK_EQUAL(std::get<28>(mvs)[8], 1381.0f);
	BOOST_CHECK_EQUAL(std::get<28>(mvs)[9], 1409.0f);
	BOOST_CHECK_EQUAL(std::get<28>(mvs)[10], 1423.0f);
	BOOST_CHECK_EQUAL(std::get<28>(mvs)[11], 1427.0f);

	// vector + bivector + trivector + quadvector
	BOOST_CHECK_EQUAL(std::get<29>(mvs)[0], 1429.0f);
	BOOST_CHECK_EQUAL(std::get<29>(mvs)[1], 1433.0f);
	BOOST_CHECK_EQUAL(std::get<29>(mvs)[2], 1447.0f);
	BOOST_CHECK_EQUAL(std::get<29>(mvs)[3], 1471.0f);
	BOOST_CHECK_EQUAL(std::get<29>(mvs)[4], 1439.0f);
	BOOST_CHECK_EQUAL(std::get<29>(mvs)[5], 1451.0f);
	BOOST_CHECK_EQUAL(std::get<29>(mvs)[6], 1453.0f);
	BOOST_CHECK_EQUAL(std::get<29>(mvs)[7], 1481.0f);
	BOOST_CHECK_EQUAL(std::get<29>(mvs)[8], 1483.0f);
	BOOST_CHECK_EQUAL(std::get<29>(mvs)[9], 1489.0f);
	BOOST_CHECK_EQUAL(std::get<29>(mvs)[10], 1459.0f);
	BOOST_CHECK_EQUAL(std::get<29>(mvs)[11], 1487.0f);
	BOOST_CHECK_EQUAL(std::get<29>(mvs)[12], 1493.0f);
	BOOST_CHECK_EQUAL(std::get<29>(mvs)[13], 1499.0f);
	BOOST_CHECK_EQUAL(std::get<29>(mvs)[14], 1511.0f);

	// scalar + vector + bivector + trivector + quadvector
	BOOST_CHECK_EQUAL(std::get<30>(mvs)[0], 1523.0f);
	BOOST_CHECK_EQUAL(std::get<30>(mvs)[1], 1531.0f);
	BOOST_CHECK_EQUAL(std::get<30>(mvs)[2], 1543.0f);
	BOOST_CHECK_EQUAL(std::get<30>(mvs)[3], 1553.0f);
	BOOST_CHECK_EQUAL(std::get<30>(mvs)[4], 1579.0f);
	BOOST_CHECK_EQUAL(std::get<30>(mvs)[5], 1549.0f);
	BOOST_CHECK_EQUAL(std::get<30>(mvs)[6], 1559.0f);
	BOOST_CHECK_EQUAL(std::get<30>(mvs)[7], 1567.0f);
	BOOST_CHECK_EQUAL(std::get<30>(mvs)[8], 1583.0f);
	BOOST_CHECK_EQUAL(std::get<30>(mvs)[9], 1597.0f);
	BOOST_CHECK_EQUAL(std::get<30>(mvs)[10], 1607.0f);
	BOOST_CHECK_EQUAL(std::get<30>(mvs)[11], 1571.0f);
	BOOST_CHECK_EQUAL(std::get<30>(mvs)[12], 1601.0f);
	BOOST_CHECK_EQUAL(std::get<30>(mvs)[13], 1609.0f);
	BOOST_CHECK_EQUAL(std::get<30>(mvs)[14], 1613.0f);
	BOOST_CHECK_EQUAL(std::get<30>(mvs)[15], 1619.0f);
}
