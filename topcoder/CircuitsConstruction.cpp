#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1ULL<<30ULL;
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
const ll MAXN = 5004;
vector<ll> g[MAXN];
priority_queue<ll> pq;
string cir;

ll f(ll x, ll p) {
	if (cir[x]=='X') {
		return 1;
	}
	else if (cir[x]=='A') {
		ll ans=f(g[x][0],x)+f(g[x][1],x);
		return ans;
	}
	else if (cir[x]=='B') {
		ll ans=max(f(g[x][0],x),f(g[x][1],x));
		return ans;
	}
	else {
		assert(false);
	}
}

class CircuitsConstruction {
	public:
	int maximizeResistance(string circuit, vector <int> conductors) {
		cir=circuit;
		ll clen = circuit.length();
		stack<ll> S;
		for (ll i=0;i<clen-1;i++) {
			if (circuit[i]!='X') {
				g[i].PB(i+1);
				S.push(i);
			}
			else {
				ll p=S.top();
				S.pop();
				g[p].PB(i+1);
			}
		}
		sort(conductors.begin(),conductors.end(),greater<int>());
		ll num=f(0,-1LL);
		ll ans=0;
		for (ll i=0;i<num;i++) ans+=conductors[i];
		return ans;
	}
};
// BEGIN CUT HERE
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 1) 
	{
		cout << "Testing CircuitsConstruction (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1457116236;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		CircuitsConstruction _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string circuit = "BXBXX";
				int conductors[] = {8, 2, 3};
				_expected = 8;
				_received = _obj.maximizeResistance(circuit, vector <int>(conductors, conductors+sizeof(conductors)/sizeof(int))); break;
			}
			case 1:
			{
				string circuit = "AAXXAXAXX";
				int conductors[] = {1, 1, 2, 8, 10};
				_expected = 22;
				_received = _obj.maximizeResistance(circuit, vector <int>(conductors, conductors+sizeof(conductors)/sizeof(int))); break;
			}
			case 2:
			{
				string circuit = "AXBXX";
				int conductors[] = {8, 2, 3};
				_expected = 11;
				_received = _obj.maximizeResistance(circuit, vector <int>(conductors, conductors+sizeof(conductors)/sizeof(int))); break;
			}
			case 3:
			{
				string circuit = "BAAXBXXBXAXXBBAXXBXXAAXXX";
				int conductors[] = {17, 7, 21, 102, 56, 72, 88, 15, 9, 192, 16, 8, 30};
				_expected = 454;
				_received = _obj.maximizeResistance(circuit, vector <int>(conductors, conductors+sizeof(conductors)/sizeof(int))); break;
			}
			case 4:
			{
				string circuit = "AABAAAAAAAAXXXAXXABAXXAAAAXXAAAXAAXXAXXAXXAXXAAAXXAXXAAXAAXAXAXXAAXXAXAXAXXAAXAXXAXAXXAXAXAXXAXAXAXXAAXXAAAAAXXAXAXAXXAAAXXAXXAXAXAXAXXAXXAXXAAAAAAXAXXXAXXAAXXAAAAAXAAAXXXAXXAAXXXAAAAXXXXAAAXXAAXXXAAAXXXAXAXAXXXXAAAAXXXAAAXXAAAXXXAAXXXAXXAAAAAAXXAXAXXAAXAAXXAAXXXAXXAAAAAAXXAXXAXXXXAXXAAAAXXXXAXXAXAAXXXAAAXAAXAXAAAXXXXAAXXAXXAAXXAAAXAAAXAXXXXAXXXAAAAXXAAAAXXXXAAXXAXXAAXAXAXXAAAAXXXXAAXXXAAAAXAXAXXXAAXXXAAAAAXXAAAXAXXXXAAAXAAXXAXXAXXAAAXAXXAAAXXXXAXAAAXAXXAAXXXAAXXAXXAAAAAXXXAXAAXXAXXXAXXAAXAAXAXXAXXAAXAXXXAAAAXAAAXXXAXAXXXAAAAAAXXAXXAAAXAAXXXXXAAXAXXAAAXXXAAAAXAXXAXAAXXAXXXAAAAAXXXAAXXAAXXXAAAXXAXAXXAXAXXAAAXXAAXAXAXXAXXAAXXAXAAAXXXAAAXXXXAAAXXAAAAAXAXXAXXAXXXAAXXXAAAAAAXXXXXAAXAXXAAAAAAXXAAXXAXXAXXXAAXAXXAAXXXAAXAXXXAAAAXXXXAAAXAXXAXXAAXXXAAAAXAXAXXAAAAXAXXXAXXXAAAXAXAXXAAAAXXXAAXAXXXAAXXAXAXXAAXXAAXAXXAXAAXAXXAXXAXXAAAAXXXAAXXXAAXAXAXXAAAXXAXAXXAAAAXXAXAAXXXAXXAXAXAAXXXAAAAXAXXXAAAXAXXXAXAAXXXAXAAAXXXXAAAAAAAAXAXAXXAXXXAAAAAAAXAXXAAXXXAXXAAXAXXAAXAAAAXAXXAXXXXAAXAXAXXAXAAXXXAAXXAXXAXAXXAAAAAAXXAXXAXXAAXAAAXXXAXAXXAXXAXXAAAXXAXAAXXXXAAAXXAXXAAAAAXAXXAXAAXXXAAAXXAAXXXXAAXAAAXAXAXXAXAXXAAXXXAXXXAAAXAXAXXXAAAAAAXXAAXXXAXXAAAXXAXXAAXXXAAAXXAXAXXAAXXAXXAAAAXXXAXXAAAAXXXXAXAAXXXAAXXAXAAXAAXXXAAXXAAAAAXAXAXXXAXAAXAXXAXXAAXAXXXAXAAXAXAXXXAAAAAAXXAXAXAAXXAXXAAXAAAXXAXXAAXXXAAXXAAXXXAAAXXXAAAXAXXAAXXAAAXXXXXAXAAAAXXXXAAXAXAXXXAXAAAXXAXXAXAXXAAAAAAAXXXXAAAXXXXAXXAAXAXAAXXXAAAXAAXXXAXXAAXAXAXXXAAXXXAAAAAAAAAAXXBAAXAAAXXAXXXAAXAXXXAAAAAXAXXXXAAAXXXAAXXXAXXAAAXAXXAAXXAAXXAXXAAXAXXAAXXXAAAAAXXXXAXXAAAAXAXXXAAAXXAAXXAAXXXAAXAAXXXAAAXAXXAAXXXAXXAAXXAXAAXXXAAAAAXAXXAAAAXXXXXAXXAAXXXXAAAAAXAAXAAXXAXAAXXXXAAAXXXAXXXAAAAXXAAXAXAXXXAAAXAAXXAXAXXXAAXAXXAXXAAAAAXAXAXXAXAXXAXXAAAXXAXAXXXAAXAXXAXXAAAAAXAAAXXXXXAAXAAAXXXAAXXAXAXXAAAAXAXXAXXAAAAXAAXXAXXXXAAXXAXAXXAAAXAXAXXAAXXAAXXAAAAXXXAXXAXAXXAAAAXXAAAXAAXXAXXAAXXAAAAXXAAXAAXAXXXAXXXAXAAXXXXXAAXXXAAAAAAAXXXAAXXAAXXXAAAAXAAXXXXAAAXXAXXAXAXAXXAAXAAAAXXXXXXAAAXAXAXXAXAXXAXAAXXAAXXAAAXAXXAXAAXXAXXAXXAAAXXXAAXXAAAXXXAXAAXAXXAAAAXXXAXXXAAAAAAAXXAXAXXAAXXXAAXAAXXXAAAAXXXXXAAXXAXXAAAXXXAAAXAXAXXAXXAAAAXXAXXAAXXAXXAAXXAXXAAAXAXAXXXAAAAAAAXXAXXXAXXAXXAAXXXXAAAXXAAAAXAAAXAXXAAXXAAXXAAAXXXXAAXXAAXXXAAAAAAAXXAXXAAXXXAAXXXAXXAAAXXXAXAXAXXAAXAXXAXXAAAXXAAAXAXXAXXAXAXXAAAAAXAXXXAAXAXXXAAXXAXXAAXXXAAXXAAXXAAAAAAAAXXXAXXAXXAXXAAXXAAXAXAXXXAAXAAXXXAAXAXXAAAXXAAXXXAXXXAAAAAAXXAAXXAAAXAXXAXXXAXXAAXXXAAAAAAXXXBAAXXAXXXAAXAXXAXXAAAAAXXXAXXAAXXXAAAXXAAXXXAXAAXXAXXAAAAAAAXAXAXAXXAAAXXAAXXAXXAAXXAXAXXAAXXAAAAAXXAXXAAXXXXAXXXAXAAAAAXXXXXAXAAAAXAXXAXAXXXAAXXAAXAXAXXXAXAXXAAAAAXAXXAXXXAAAAXAXXXAAXAXXXAXAAXXXAAAXAXXAXXAAXXAXXAAAAAAXAXXXAAXAXXXAXXAAXXAXAAXXAAXXXAAXAXXXAAAAAAXAAXXAXAXAXAAXXXAXAAAAAXXXXXAAAAXXAAXAXXXAXXAAAAXXAXXXAXAXXXAAAAAAXXAAXXXXAAAAAAAAAXXAXAAAXXXAAXAXXXAXXAAXXXAAXXAXXAXAAAAXXAXXAXAXXAAAAXAXXXAXAXXAXXAAAAAAXXXXAXXAAXXXXXAXAXAAAXXXAXXAAAXXAAXAAXXAAXXXAXAAAXXXXAAXXAXXAAAXAAXXXAXXAAXXAAAXAAXXXAXXXAAAAXAAAAXXXAXXAXAXXAXXAXAAXAXXAXAXXAAAAXAXXXAXAXXAAXAXXAAAAXAXAXXAAXAXXAAAXXXAXXAAXXXBAXAXAAXXXXAAAXXAAXAXXAAXXXAAXXAXAXXAAXAAXXAXXAAAAAAAXXXXAXXAXAXXAAAXAXXXAAXAXAXAXXAAXXXAAAAAAXAXXAAAXXAXAXXXAAAXAAXXXAAAXXXXXAAAAAXXAXXAAXXAAAXAXAXXAXXAXXAAXXAXAXXAAAXAXAAXXXAXXXAAAAAAAAXAXXAXAXXAAXAXXXXAAXXAAAXXAAXAXXAXXAXAAXXXAXAXXAAXXXAAXXAAAAAXXAXXXXAXAAAXAAAXXXAXXAAXXAXAAXXAXXXAAAAAXAAAXAXXXAXAXAAXXXXAXXAAAAAAXXXAXXAXAXAXXAAXXAAAXXXAXXAAAXXAXAAXXAXXAXAXXAAAAAAAXAXAXXXXAAAXXAAXXAXXXAAXAXAXAXXAAXXAAXXXAXAAAXAXAXXAXXAAXXAAAAXAAAXXAXXXXXXAAAXXAXAAXXXAXXAAAAXAXAXXAAAAAXAAXAAXXXAAXXXAXXAAAXAXXXXAXXAAXAXAXXAAAXAAXAAXXXXAAAXXAXXXAAAAXXAAXXXAAXXXAAAAXXAAXAXXAXXXAAAAXAXXAXXAAAXXXXAXXAAAAXXXAXXXAAAAAXAXXAAXXAAAXAAAXAXXXAXXXAAXXAXXAAAXXAAAXAXXXAAAAXXAXXAAAAAXXAXXAXAXXAXAXAXXAXXAAXXAXAAXXXAAAXAXXAXXAXAAXAAXXXAAXXAAXXXAAAAAAXXAAAXXAAAXXXAAXAAXXAAXXXAXXAAXXAAAAXXAAXXXAXAXXAAAXAXXXXAAXXXAXAAXAAXXAXAAAXXXXAAAXXXAXXAXAAXAXAXXAXAXXAAAAXXAXXAXAXXAAAAAAAXXXXXAAAXXAXXAAXXXAAAXXXAAXAXXAAAXXAXXAXXAAXAXXAAAXXXAAXXAXAAXXAXXAXAXAAXAXAXXAAXAXAXXAXXAAAXXAAXAXAXXAXXAAAXXAAXXAXXAAAXXXX";
				int conductors[] = {12442, 28389, 18794, 32602, 15357, 7659, 22285, 23446, 6176, 13888, 2588, 18303, 22877, 9952, 20851, 791, 23039, 20991, 29507, 13658, 30816, 25249, 23640, 3699, 78, 8293, 29853, 23088, 17331, 13729, 7393, 5812, 9845, 7092, 14811, 25452, 8604, 8600, 28780, 23620, 435, 16567, 30501, 13594, 25712, 13312, 8457, 10610, 14743, 1337, 1428, 5228, 19227, 1175, 27132, 17652, 4230, 24204, 20406, 25145, 20892, 17376, 19516, 29792, 23611, 22531, 3598, 25977, 20870, 22946, 13046, 3762, 20035, 14712, 21393, 9674, 29312, 4967, 26635, 7881, 3197, 15815, 27178, 21999, 27334, 25342, 22670, 5610, 6560, 22864, 32567, 20044, 4006, 11513, 10567, 3643, 3508, 4217, 8201, 5994, 13828, 10032, 6963, 7497, 7831, 24106, 1640, 1145, 25303, 18236, 16385, 13955, 30842, 10832, 13581, 24009, 19369, 16637, 32406, 7613, 26210, 20571, 25639, 6992, 10011, 5397, 26506, 27054, 19112, 13759, 15830, 12072, 19806, 12138, 22954, 5745, 26489, 28790, 27315, 24590, 10427, 5544, 30324, 10248, 30550, 32124, 28230, 13284, 30220, 9661, 26269, 23764, 5525, 1874, 21390, 27183, 21825, 25691, 28302, 28703, 30430, 15485, 10621, 1690, 10716, 23417, 21219, 27795, 29103, 20345, 27505, 19317, 2259, 3307, 3776, 22233, 28149, 4572, 1062, 1591, 23653, 20266, 14233, 6657, 17888, 5748, 32720, 27489, 18164, 23002, 28407, 18975, 7514, 6404, 7079, 29126, 22661, 8038, 30229, 23042, 30843, 30658, 32138, 26189, 28388, 14574, 27155, 14538, 13920, 4055, 7801, 11377, 29726, 10950, 30323, 14957, 22443, 27106, 17691, 20162, 11527, 30967, 6047, 20531, 21758, 13941, 4153, 24419, 6069, 3004, 28001, 4410, 1412, 6806, 4417, 10378, 23043, 25605, 7529, 4851, 5480, 19520, 30404, 11524, 16400, 8184, 17866, 4514, 3163, 32479, 18168, 30894, 19133, 20331, 32637, 26850, 25618, 8151, 10807, 16636, 20018, 6252, 28893, 23583, 11974, 17790, 21878, 8282, 11193, 28714, 12058, 19891, 7966, 9455, 24630, 22370, 2376, 13831, 3689, 31348, 13903, 30315, 6206, 5312, 8187, 18420, 20286, 26419, 21384, 30937, 29988, 31230, 755, 21368, 18922, 28673, 23849, 17495, 23566, 24977, 3518, 11016, 9705, 21625, 25825, 12880, 5437, 30014, 15248, 29576, 12557, 30120, 26632, 26946, 20913, 13437, 22144, 30000, 7977, 4752, 6678, 32066, 18866, 6394, 2570, 25615, 12439, 21672, 16170, 24694, 27466, 2838, 1421, 30853, 26803, 11353, 5764, 9113, 6344, 9827, 11982, 22471, 21598, 32131, 21771, 1659, 30526, 20011, 25715, 19551, 24700, 7158, 12232, 22655, 19716, 4585, 20617, 20138, 16502, 6138, 30313, 10523, 28724, 25038, 19200, 23897, 25785, 23239, 15807, 18523, 17708, 4926, 19497, 9712, 308, 4877, 6720, 5982, 19727, 13649, 28478, 32073, 9182, 29038, 27270, 10455, 17475, 13651, 1242, 10258, 23342, 13567, 12750, 12686, 20724, 21315, 13693, 29515, 27810, 1994, 634, 18652, 16784, 26200, 13322, 7369, 6969, 11087, 30864, 31027, 23369, 29047, 72, 2998, 32248, 29950, 17464, 8340, 14487, 1982, 14692, 22799, 26216, 6847, 17474, 8470, 14259, 253, 109, 10276, 22294, 12445, 24934, 31005, 32311, 27351, 20252, 2579, 12112, 21729, 7489, 28183, 15910, 1273, 20334, 1906, 31921, 23238, 1532, 30503, 16820, 25743, 7785, 19404, 11331, 9387, 13052, 4761, 16515, 19257, 15788, 32447, 16817, 14353, 25151, 6906, 28005, 22778, 9135, 14698, 31768, 14365, 2257, 5535, 2788, 20153, 29752, 23795, 21132, 28697, 13144, 4380, 20412, 24771, 2279, 30977, 16530, 28147, 13961, 5069, 7004, 6471, 18859, 16962, 25252, 11452, 12207, 6737, 31338, 19161, 21834, 6375, 25264, 21803, 9737, 31548, 4848, 31198, 7971, 13465, 27159, 5871, 23453, 21087, 27752, 32082, 24496, 8884, 24320, 3842, 12664, 20243, 20993, 13801, 1098, 10828, 18055, 16896, 11847, 8140, 28894, 29367, 7217, 10271, 27378, 12183, 14206, 26291, 27398, 13350, 29355, 21727, 21161, 13067, 28627, 7715, 10726, 13426, 30080, 4530, 23228, 13234, 9665, 19757, 16590, 16429, 11133, 1202, 24922, 9592, 20998, 3093, 24431, 24253, 15089, 1389, 91, 9766, 22739, 21603, 51, 22886, 22456, 7666, 10982, 15251, 8102, 15119, 13338, 16531, 26637, 12256, 28369, 15156, 31297, 8835, 20957, 32030, 31329, 17590, 8652, 3830, 20515, 28879, 10147, 10319, 10180, 4648, 4387, 12400, 14783, 29794, 23607, 19242, 493, 11773, 26420, 14350, 29169, 6437, 22111, 12765, 8915, 20175, 29360, 25152, 18923, 22533, 26069, 15801, 29953, 2430, 30586, 23514, 20914, 15730, 8117, 1045, 24492, 811, 17555, 20639, 32737, 27481, 8937, 7492, 24128, 4496, 16775, 3551, 9802, 28190, 1811, 16340, 19428, 295, 8118, 26868, 16043, 2211, 27413, 23969, 26503, 22438, 1667, 16946, 9347, 13028, 18292, 27545, 14044, 22132, 14901, 13122, 22359, 2260, 30939, 16959, 25816, 24366, 28282, 6051, 24881, 5849, 23191, 12344, 10275, 10463, 25892, 19740, 30286, 28953, 4232, 27129, 16600, 13145, 21611, 11689, 14848, 9334, 28565, 990, 26245, 7871, 22897, 13165, 10929, 2794, 22310, 12013, 10390, 21837, 27651, 21377, 21400, 17233, 10528, 2546, 23851, 15651, 8258, 32257, 24286, 32256, 24571, 26009, 27332, 3876, 25741, 16930, 24482, 13652, 30426, 17126, 25495, 3826, 20683, 15095, 15101, 22080, 28070, 31313, 28778, 15304, 2787, 7009, 31785, 16379, 11067, 18888, 32746, 20504, 20481, 26204, 27320, 10831, 23733, 11375, 6444, 19751, 22743, 15445, 30237, 1017, 12064, 24103, 29581, 28696, 6062, 3835, 19926, 5676, 5350, 7735, 3002, 6398, 22846, 25607, 5635, 10810, 19328, 30876, 32364, 17861, 9423, 27172, 11710, 14160, 12261, 3833, 15674, 7726, 3486, 18456, 25442, 8890, 18390, 31500, 22013, 4830, 12494, 24624, 24999, 27869, 8478, 13472, 4987, 27702, 32211, 17025, 24856, 29662, 4769, 2311, 26100, 9791, 23000, 13461, 2804, 16000, 147, 25126, 19514, 3847, 31538, 12779, 4415, 18748, 15883, 27957, 19233, 29328, 28253, 17302, 19774, 10943, 8069, 25411, 5121, 10065, 28789, 28861, 28156, 2151, 7521, 8625, 15159, 27316, 22971, 32540, 14024, 23242, 1634, 4786, 32420, 3479, 6167, 897, 19893, 559, 16944, 26066, 7213, 28876, 14736, 16976, 6681, 11026, 9174, 14393, 20888, 1749, 24575, 13071, 677, 19525, 20017, 21558, 26167, 11703, 24987, 24053, 15178, 7375, 31144, 21780, 19030, 31661, 32065, 7406, 24858, 14764, 21673, 6600, 15256, 15013, 19809, 32353, 7288, 10465, 8650, 9746, 12251, 25487, 22136, 4127, 14003, 26705, 17304, 207, 15795, 17497, 26530, 19080, 9280, 5582, 29489, 31309, 9949, 15474, 18194, 11653, 28135, 6299, 29826, 7903, 12350, 26929, 23507, 15723, 30302, 21448, 32368, 25268, 16992, 4701, 22548, 7639, 8198, 5765, 5528, 9119, 32504, 9997, 24862, 14830, 164, 18051, 16016, 29278, 22600, 25336, 3145, 30759, 29005, 13061, 31761, 30020, 20439, 25612, 6223, 21201, 24474, 32192, 10618, 22712, 7912, 4049, 28812, 1063, 30560, 25932, 4021, 4895, 9056, 31698, 3278, 10516, 19456, 2988, 25675, 8377, 12540, 9786, 12383, 135, 32693, 16612, 22557, 32085, 7033, 27732, 14813, 2856, 15108, 3042, 28748, 32583, 8528, 13880, 3748, 26472, 184, 11491, 22334, 17929, 194, 2359, 7210, 7117, 31514, 27522, 13453, 31512, 12578, 26097, 9969, 22807, 26852, 30129, 19935, 22090, 5973, 10928, 5788, 9361, 31352, 23200, 12546, 13307, 6307, 25124, 7845, 24516, 13169, 17022, 18833, 24664, 32240, 3470, 7619, 30027, 27627, 22741, 1641, 11430, 18738, 12594, 15863, 4170, 6814, 30250, 14489, 25602, 29657, 3982, 5742, 196, 24082, 26018, 21305, 5524, 9552, 18720, 7769, 28582, 4102, 7295, 28411, 3523, 13543, 8820, 10382, 749, 25339, 5562, 25463, 27718, 20467, 28175, 11782, 32302, 186, 30335, 22953, 27820, 8268, 6372, 10336, 14539, 686, 28273, 32469, 720, 1760, 31837, 16843, 16127, 24923, 25874, 12150, 19934, 16223, 10674, 31207, 12623, 27060, 24729, 10203, 19194, 10662, 28037, 25571, 21018, 28081, 6566, 17745, 28831, 27891, 8622, 22797, 31276, 10571, 27629, 23994, 7720, 28334, 24327, 11730, 6170, 29369, 32297, 4832, 21716, 24348, 7817, 6502, 16787, 29227, 19129, 4346, 24998, 3014, 26029, 2326, 7599, 27866, 31784, 11454, 16561, 4138, 19060, 354, 19305, 80, 3333, 4578, 20222, 23873, 10143, 22340, 4490, 26314, 31680, 23532, 1706, 27484, 31351, 4546, 18812, 1837, 18034, 27335, 13769, 20848, 23142, 30190, 24970, 32717, 28338, 15917, 20395, 24078, 8147, 28187, 10922, 2076, 16598, 17448, 4005, 21251, 25819, 29485, 13722, 15191, 17280, 7574, 15250, 4369, 9645, 32316, 28758, 10725, 1046, 32149, 25299, 16407, 15037, 10023, 20931, 13200, 5560, 4931, 16010, 6965, 6383, 10078, 1127, 14011, 23588, 11435, 22272, 10675, 3130, 9654, 25405, 25894, 26272, 26752, 15400, 12488, 20944, 18669, 4135, 17206, 9346, 4901, 18898, 12156, 27936, 1339, 13058, 19418, 19835, 3085, 20010, 30152, 16060, 18283, 23019, 22327, 20893, 6523, 13026, 4378, 16089, 17755, 1989, 28453, 23520, 24841, 5038, 18384, 7808, 21174, 29616, 25761, 12324, 25798, 27342, 19552, 4778, 3992, 21534, 5262, 10599, 10191, 30569, 25367, 8143, 31953, 13563, 17627, 14930, 16408, 15346, 8659, 8471, 30400, 22772, 7244, 16346, 18980, 21335, 27322, 18956, 16473, 21144, 26268, 3003, 29837, 32380, 27825, 12922, 21140, 30166, 32478, 26283, 12604, 13842, 31398, 29076, 17656, 22637, 23652, 20043, 5287, 22539, 24233, 23521, 26292, 5466, 11987, 7697, 26440, 10491, 9547, 24528, 7998, 14856, 22597, 8621, 18764, 13919, 13571, 21102, 11609, 17792, 31495, 13934, 11899, 19707, 3378, 10839, 26300, 11907, 30461, 14868, 26478, 22257, 20328, 18417, 21438, 16012, 18483, 12029, 2444, 16007, 15697, 25779, 19578, 24523, 22682, 24026, 10051, 1783, 7616, 15018, 30543, 8613, 29316, 32304, 22148, 14576, 30505, 21748, 22366, 3379, 17193, 11992, 18242, 7954, 23080, 12355, 27407, 18879, 27942, 15999, 27127, 21110, 15352, 11104, 23181, 4426, 11001, 17447, 9758, 5924, 24829, 18341, 13893, 29961, 390, 1956, 8378, 2203, 22331, 14722, 17771, 29155, 661, 14879, 4814, 5709, 220, 18682, 25717, 8018, 12259, 20512, 11950, 547, 29598, 28685, 2763, 16986, 7301, 751, 19106, 13737, 21860, 7730, 11382, 26000, 29894, 9478, 4686, 18763, 32010, 6171, 8872, 13233, 25273, 4777, 24940, 22620, 3351, 6324, 21791, 11274, 6798, 3161, 9283, 1493, 6009, 6716, 25887, 23134, 19095, 21756, 979, 12202, 23482, 32445, 15951, 27449, 12619, 2453, 3684, 28516, 29898, 18261, 21420, 24111, 15808, 14514, 30238, 26869, 22434, 5855, 2247, 28642, 17243, 16257, 21609, 24981, 24213, 8572, 29892, 2534, 13499, 28665, 23484, 3571, 27902, 11322, 24859, 5033, 19873, 6981, 11875, 29909, 1615, 14054, 22595, 29873, 12275, 6460, 26151, 5952, 26067, 6194, 7101, 8792, 30529, 10501, 557, 27534, 20558, 273, 19633, 8004, 22949, 23778, 8697, 29819, 11539, 29348, 5327, 21224, 29511, 26843, 4087, 8009, 20182, 9557, 14681, 30850, 2140, 4194, 15298, 28859, 26672, 19367, 27238, 24756, 14795, 29363, 21214, 19303, 10659, 16021, 6968, 29590, 7577, 19565, 9932, 23248, 20046, 752, 8603, 16516, 18243, 19463, 26725, 29242, 23326, 25531, 15549, 25368, 32270, 23686, 26307, 31758, 29013, 15991, 10973, 6713, 24236, 2355, 16646, 20951, 5946, 6207, 28796, 18027, 12934, 5488, 25653, 2507, 14857, 579, 10980, 18562, 11567, 16711, 11814, 8391, 16148, 23500, 20540, 16085, 8614, 19708, 6890, 2365, 7712, 15818, 18208, 23601, 25649, 10052, 31426, 24657, 11514, 13998, 21371, 29836, 31581, 30606, 9470, 31445, 21070, 9882, 10368, 14748, 18508, 739, 22813, 22179, 26342, 16205, 28535, 29709, 9086, 10306, 16544, 9144, 20903, 1082, 9420, 19623, 24847, 17884, 8084, 28544, 18479, 1464, 21389, 32560, 915, 19579, 27581, 27507, 12687, 27974, 22196, 5495, 14842, 29755, 12171, 23314, 11528, 12978, 900, 11853, 20009, 26139, 28450, 31533, 21659, 14032, 20259, 27143, 19375, 13805, 5894, 27635, 15727, 28875, 27518, 28803, 2554, 30111, 15702, 18797, 12774, 28397, 15988, 15933, 11571, 10510, 24631, 27582, 25238, 27763, 5026, 24561, 17628, 19010, 10381, 24932, 19092, 4866, 12034, 8339, 19169, 8168, 29231, 24502, 8376, 23774, 5909, 6122, 21684, 14186, 32568, 26219, 2475, 5971, 16977, 22246, 25640, 30795, 29017, 27196, 1564, 18129, 4068, 31364, 29392, 1110, 14256, 8271, 28446, 30367, 6782, 32047, 12769, 26218, 22048, 3962, 30890, 12628, 20180, 21685, 13050, 976, 13514, 17435, 18783, 4638, 6061, 27464, 30862, 30719, 688, 29056, 30874, 10272, 19646, 63, 4317, 28686, 10253, 9548, 3079, 4571, 24126, 20828, 30622, 11451, 25005, 8746, 28197, 8073, 4189, 4491, 24739, 11615, 17229, 20111, 16726, 30790, 32474, 7526, 19863, 29045, 8379, 21492, 18576, 2067, 23539, 10698, 8658, 14261, 32695, 26797, 24586, 17322, 23122, 13744, 22977, 20097, 794, 19374, 8710, 9527, 1453, 28701, 28549, 20117, 3387, 8892, 32528, 8186, 13881, 30841, 3930, 10330, 7569, 31865, 26247, 3259, 17145, 25570, 15279, 13405, 31485, 16979, 21286, 729, 18727, 16958, 20070, 29007, 26978, 31219, 19541, 15776, 4703, 13423, 24262, 6621, 14136, 15477, 31041, 28671, 3155, 24033, 15623, 3544, 21386, 4408, 18001, 19785, 13192, 1411, 24281, 3254, 7798, 31838, 14747, 2999, 3032, 11340, 7133, 16, 2481, 7501, 5997, 30436, 26862, 13235, 14890, 22053, 2305, 23857, 22213, 4687, 1741, 5173, 19145, 27734, 21186, 11639, 26073, 19420, 29257, 9170, 22073, 2472, 28770, 22100, 16017, 15956, 16779, 27793, 22765, 26949, 7909, 21820, 19207, 993, 7314, 4856, 4041, 21755, 32609, 19307, 6670, 6290, 5549, 19604, 5289, 6018, 31839, 25512, 19677, 20994, 26231, 19162, 20508, 8711, 23644, 23950, 522, 23477, 7070, 2774, 12100, 12007, 6911, 10770, 31718, 684, 19784, 5534, 13644, 22690, 25137, 15036, 8616, 27309, 26610, 12818, 27928, 4677, 30898, 31100, 31002, 30895, 24223, 17948, 14955, 14620, 22113, 28152, 26284, 21783, 31607, 483, 22182, 25144, 7206, 10714, 6642, 23297, 3323, 23563};
				_expected = -1;
				_received = _obj.maximizeResistance(circuit, vector <int>(conductors, conductors+sizeof(conductors)/sizeof(int))); break;
			}
			/*case 5:
			{
				string circuit = ;
				int conductors[] = ;
				_expected = ;
				_received = _obj.maximizeResistance(circuit, vector <int>(conductors, conductors+sizeof(conductors)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				string circuit = ;
				int conductors[] = ;
				_expected = ;
				_received = _obj.maximizeResistance(circuit, vector <int>(conductors, conductors+sizeof(conductors)/sizeof(int))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
