#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1ULL<<60ULL;
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }

const ll MAXN=1004;
ll fenwick[MAXN];
// T[i] += value
void add(ll *t, ll i, ll value) {
  for (; i < MAXN; i |= i + 1)
    t[i] += value;
}

// sum[0..i]
ll sum(ll *t, ll i) {
  ll res = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1)
    res += t[i];
  return res;
}

void sset(ll *t, ll i, ll value) {
  ll orig = sum(t,i)-sum(t,i-1);
  add(t,i,value-orig);
}

vector<ll> h[MAXN];
vector<ll> g[MAXN];
unordered_set<ll> cycle;
bool cycledone=false;
stack<ll> cstack;
bool seen[MAXN];
void resetseen(ll n) {
	for (ll i=0;i<n;i++) seen[i]=false;
}
void findcycle(ll x, ll p) {
	if(cycledone) return;
	if (seen[x]) {
		ll y=-1;
		while(y!=x) {
			y=cstack.top();
			cstack.pop();
			cycle.insert(y);
		}
		cycledone=true;
	}
	else {
		//printf("fc seeing %lld\n",x);
		cstack.push(x);
		seen[x]=true;
		for (auto &w:h[x]) {
			if (w==p) continue;
			findcycle(w,x);
			if (cycledone) return; // Need this else segfault!!!!
		}
		cstack.pop();
	}
}

ll getfirstcyclevtx(ll x, ll p) {
	if (cycle.find(x)!=cycle.end()) {
		return x;
	}
	else {
		for (auto &w:h[x]) {
			if (w==p) continue;
			ll cand=getfirstcyclevtx(w,x);
			if (cand!=-1) return cand;
		}
	}
	return -1;
}

void resetfenwick(ll n) {
	for (ll i=0;i<n;i++) fenwick[i]=0;
}

vector<int> valvec;
ll final=INF;
void solve(ll x, ll p, ll len, ll inv) {
	ll v=valvec[x];
	inv += sum(fenwick,v-1);
	if (len==0) {
		final = min(final,inv);
		return;
	}
	else {
		add(fenwick,v,1);
		for (auto &w:g[x]) {
			if(w==p) continue;
			solve(w,x,len-1,inv);
		}
		add(fenwick,v,-1);
	}
}

class GraphInversions {
	public:
	int getMinimumInversions(vector <int> A, vector <int> B, vector <int> V, int K) {
		final=INF;
		cycledone=false;
		ll n=A.size();
		resetfenwick(n);
		assert(sum(fenwick,-1)==0);
		{
			set<ll> s;
			for (auto &w:V) s.insert(w);
			vector<ll> vec;
			for (auto &w:s) vec.PB(w);
			ll vsz=vec.size();
			for (ll i=0;i<n;i++) {
				ll key=V[i],imin=0,imax=vsz;
				while(imin<imax) {
					ll imid=imin+(imax-imin)/2;
					if (vec[imid]<key) imin=imid+1;
					else imax=imid;
				}
				V[i]=vsz-1-imin;
			}
		}
		valvec=V;
		for (ll i=0;i<n;i++) {
			h[A[i]].PB(B[i]);
			h[B[i]].PB(A[i]);
		}
		resetseen(n);
		findcycle(0,-1);
		for (ll init=0;init<n;init++) {
			resetseen(n);
			ll fcv = getfirstcyclevtx(init,-1);
			vector<ll> fce;
			for (auto &w:h[fcv]) {
				if (cycle.find(w)!=cycle.end()) {
					fce.PB(w);
				}
			}
			assert(fce.size()==2);
			for (ll exc=0;exc<2;exc++) {
				for (ll x=0;x<n;x++) g[x].clear();
				for (ll i=0;i<n;i++) {
					ll x=A[i],y=B[i];
					if ((x==fce[exc]&&y==fcv)||(y==fce[exc]&&x==fcv)) continue;
					g[x].PB(y); g[y].PB(x);
				}
				resetseen(n);
				resetfenwick(n); // We dont actually need this lol
				solve(init, -1, K-1, 0);
			}
		}
		if (final>=INF) return -1;
		return final;
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
		cout << "Testing GraphInversions (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1457287320;
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
		GraphInversions _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A[] = {0,1,2};
				int B[] = {1,2,0};
				int V[] = {40,50,60};
				int K = 3;
				_expected = 0;
				_received = _obj.getMinimumInversions(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(V, V+sizeof(V)/sizeof(int)), K); break;
			}
			case 1:
			{
				int A[] = {0,1,2,3};
				int B[] = {1,2,3,0};
				int V[] = {60,40,50,30};
				int K = 3;
				_expected = 1;
				_received = _obj.getMinimumInversions(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(V, V+sizeof(V)/sizeof(int)), K); break;
			}
			case 2:
			{
				int A[] = {0,1,2,3,0};
				int B[] = {1,2,3,0,4};
				int V[] = {10,10,10,5,5};
				int K = 5;
				_expected = 1;
				_received = _obj.getMinimumInversions(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(V, V+sizeof(V)/sizeof(int)), K); break;
			}
			case 3:
			{
				int A[] = {0,1,2,3,0,2};
				int B[] = {1,2,3,0,4,5};
				int V[] = {10,2,5,3,7,1};
				int K = 6;
				_expected = -1;
				_received = _obj.getMinimumInversions(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(V, V+sizeof(V)/sizeof(int)), K); break;
			}
			case 4:
			{
				int A[] = {5,7,7,5,5,7,6,4};
				int B[] = {2,0,2,0,1,4,7,3};
				int V[] = {15,10,5,30,22,10,5,2};
				int K = 6;
				_expected = 3;
				_received = _obj.getMinimumInversions(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(V, V+sizeof(V)/sizeof(int)), K); break;
			}
			case 5:
			{
				int A[] = {0, 36, 45, 13, 22, 24, 33, 36, 4, 10, 48, 4, 12, 42, 11, 39, 21, 49, 8, 2, 30, 7, 37, 8, 43, 37, 6, 29, 35, 19, 14, 1, 15, 28, 43, 9, 46, 38, 40, 26, 22, 5, 42, 44, 25, 19, 44, 32, 11, 26};
				int B[] = {31, 7, 29, 5, 18, 0, 0, 28, 23, 18, 17, 39, 1, 34, 41, 16, 39, 33, 28, 25, 39, 38, 2, 35, 46, 6, 45, 3, 27, 21, 3, 31, 9, 20, 48, 47, 47, 15, 36, 4, 12, 17, 27, 10, 13, 34, 32, 14, 15, 49};
				int V[] = {739, 556, 141, 571, 718, 739, 100, 100, 138, 138, 571, 932, 760, 760, 982, 271, 995, 236, 324, 423, 768, 768, 768, 750, 276, 997, 997, 158, 366, 468, 468, 278, 750, 386, 236, 271, 266, 594, 556, 582, 112, 112, 138, 174, 14, 14, 14, 718, 594, 750};
				int K = 1;
				_expected = 0;
				_received = _obj.getMinimumInversions(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(V, V+sizeof(V)/sizeof(int)), K); break;
			}
			case 6:
			{
				int A[] = {29, 507, 446, 9, 214, 10, 89, 602, 629, 307, 326, 612, 709, 17, 468, 79, 427, 161, 729, 719, 678, 103, 618, 150, 139, 547, 466, 523, 297, 148, 369, 672, 123, 82, 226, 581, 488, 94, 625, 426, 536, 539, 328, 51, 13, 98, 440, 654, 613, 303, 669, 234, 506, 658, 102, 497, 380, 583, 205, 361, 414, 505, 635, 645, 425, 268, 231, 316, 418, 290, 502, 462, 551, 145, 496, 107, 99, 152, 386, 54, 345, 473, 214, 175, 143, 271, 120, 691, 679, 93, 525, 116, 110, 369, 101, 614, 586, 94, 546, 672, 99, 638, 15, 701, 120, 621, 619, 274, 286, 548, 475, 349, 322, 237, 593, 426, 146, 712, 22, 417, 445, 105, 11, 390, 642, 129, 230, 270, 215, 91, 649, 608, 735, 290, 331, 482, 744, 67, 72, 479, 4, 69, 373, 32, 545, 562, 616, 454, 315, 752, 582, 720, 486, 72, 98, 750, 3, 131, 248, 206, 30, 504, 561, 481, 480, 37, 578, 13, 446, 429, 100, 394, 531, 428, 280, 126, 441, 238, 169, 494, 61, 750, 208, 142, 378, 141, 649, 538, 611, 314, 119, 706, 467, 293, 592, 229, 226, 192, 10, 4, 374, 396, 769, 293, 520, 713, 256, 220, 464, 411, 730, 550, 725, 445, 165, 752, 132, 430, 656, 240, 6, 743, 470, 401, 275, 115, 761, 401, 504, 24, 675, 682, 182, 26, 34, 368, 248, 105, 64, 136, 361, 252, 55, 30, 88, 677, 143, 584, 94, 48, 721, 232, 432, 212, 155, 202, 163, 564, 296, 572, 623, 713, 677, 52, 584, 680, 344, 67, 128, 58, 337, 81, 107, 371, 198, 441, 481, 101, 558, 632, 335, 95, 434, 56, 401, 280, 634, 312, 582, 306, 185, 182, 716, 630, 204, 589, 1, 352, 380, 158, 244, 346, 274, 742, 4, 570, 671, 117, 47, 404, 393, 295, 424, 409, 166, 51, 36, 289, 728, 230, 159, 659, 8, 668, 501, 503, 181, 296, 357, 606, 14, 665, 336, 238, 25, 416, 450, 630, 586, 59, 360, 473, 633, 499, 255, 184, 83, 318, 315, 440, 202, 310, 768, 513, 719, 596, 684, 760, 705, 281, 105, 472, 377, 360, 142, 465, 284, 268, 113, 345, 45, 512, 261, 737, 711, 92, 470, 78, 136, 446, 640, 761, 600, 281, 17, 569, 657, 738, 381, 21, 151, 127, 710, 728, 329, 255, 565, 176, 35, 383, 238, 319, 0, 171, 600, 219, 631, 330, 186, 71, 745, 758, 574, 412, 619, 66, 657, 415, 440, 661, 133, 338, 313, 422, 492, 628, 526, 589, 693, 93, 233, 560, 189, 541, 248, 216, 769, 449, 51, 245, 455, 155, 732, 410, 698, 303, 557, 587, 577, 294, 242, 69, 563, 698, 121, 442, 734, 536, 493, 164, 753, 135, 519, 764, 207, 713, 347, 611, 269, 579, 303, 211, 417, 151, 333, 461, 487, 324, 393, 63, 502, 621, 433, 443, 308, 658, 436, 396, 628, 373, 534, 214, 748, 130, 769, 459, 530, 495, 334, 626, 435, 306, 514, 467, 106, 147, 114, 556, 197, 718, 528, 373, 33, 425, 132, 178, 579, 546, 49, 599, 771, 260, 283, 144, 443, 370, 546, 770, 376, 491, 471, 489, 379, 430, 128, 212, 520, 321, 47, 49, 227, 585, 641, 188, 636, 99, 743, 300, 676, 577, 480, 686, 688, 174, 66, 724, 537, 518, 664, 72, 519, 681, 269, 244, 211, 513, 516, 405, 51, 384, 14, 400, 61, 323, 379, 80, 355, 299, 217, 194, 582, 399, 114, 15, 406, 693, 642, 209, 54, 270, 215, 422, 31, 655, 138, 485, 480, 119, 423, 601, 23, 612, 276, 148, 588, 168, 489, 246, 236, 284, 314, 515, 754, 770, 388, 95, 305, 597, 428, 511, 766, 397, 24, 318, 559, 210, 157, 153, 398, 643, 605, 467, 690, 707, 641, 229, 653, 394, 156, 399, 488, 85, 300, 251, 339, 68, 517, 609, 253, 749, 173, 150, 670, 220, 183, 327, 632, 760, 161, 321, 103, 124, 282, 129, 302, 675, 7, 166, 181, 16, 402, 277, 700, 412, 766, 157, 648, 471, 744, 104, 385, 712, 608, 701, 38, 325, 16, 70, 474, 225, 179, 222, 73, 160, 104, 742, 458, 353, 102, 549, 89, 685, 495, 23, 267, 447, 756, 85, 199, 41, 473, 137, 491, 390, 65, 708, 262, 308, 366, 308, 83, 676, 566, 409, 770, 272, 552, 257, 237, 647, 755, 639, 730, 350, 512, 607, 9, 490, 748, 273, 538, 686, 589, 310, 621, 18, 703, 364, 227, 503, 556, 511, 719, 133, 28, 37, 627, 552, 751, 416, 395, 688, 265, 282, 714, 482, 479, 466, 577, 740, 156, 462};
				int B[] = {517, 555, 413, 45, 187, 8, 453, 131, 609, 87, 687, 337, 497, 596, 681, 720, 58, 250, 461, 76, 639, 755, 357, 431, 502, 727, 500, 622, 326, 80, 39, 317, 476, 703, 406, 337, 727, 656, 558, 660, 122, 692, 74, 739, 339, 420, 602, 138, 213, 39, 77, 697, 38, 272, 575, 451, 340, 162, 752, 735, 462, 670, 304, 87, 474, 435, 180, 96, 241, 163, 424, 407, 160, 196, 753, 377, 624, 715, 404, 620, 507, 385, 561, 568, 150, 457, 316, 444, 296, 478, 572, 20, 521, 108, 469, 721, 734, 320, 725, 258, 44, 341, 582, 266, 365, 301, 52, 622, 557, 184, 298, 553, 248, 696, 664, 157, 84, 323, 597, 362, 358, 673, 652, 680, 448, 241, 629, 745, 100, 615, 184, 285, 662, 678, 274, 505, 158, 407, 3, 63, 50, 501, 598, 40, 118, 283, 754, 110, 564, 591, 571, 663, 144, 288, 746, 206, 340, 751, 646, 544, 224, 350, 93, 239, 387, 173, 767, 700, 463, 191, 732, 731, 645, 292, 44, 741, 116, 20, 736, 348, 638, 437, 294, 437, 4, 177, 452, 309, 234, 84, 545, 343, 201, 398, 515, 533, 715, 117, 327, 342, 86, 455, 42, 172, 88, 542, 64, 553, 415, 197, 169, 421, 627, 442, 765, 358, 580, 731, 636, 541, 391, 369, 170, 403, 27, 733, 601, 235, 246, 265, 381, 171, 674, 207, 196, 218, 490, 736, 499, 530, 111, 395, 313, 595, 31, 765, 402, 67, 392, 150, 771, 363, 679, 194, 717, 55, 224, 620, 254, 352, 559, 71, 389, 210, 576, 563, 62, 221, 759, 531, 2, 514, 191, 153, 287, 451, 295, 193, 514, 152, 26, 528, 73, 189, 640, 580, 621, 619, 420, 125, 193, 487, 365, 223, 480, 594, 601, 140, 694, 12, 271, 298, 97, 168, 245, 764, 756, 0, 522, 311, 375, 625, 708, 329, 231, 484, 266, 442, 19, 112, 665, 758, 70, 637, 278, 509, 666, 309, 385, 575, 498, 573, 248, 119, 486, 508, 326, 391, 643, 11, 291, 463, 276, 692, 521, 618, 43, 92, 673, 75, 432, 317, 614, 386, 250, 26, 479, 767, 218, 200, 704, 32, 242, 36, 200, 311, 615, 667, 705, 535, 90, 259, 690, 209, 456, 587, 199, 127, 258, 91, 278, 460, 532, 537, 285, 368, 613, 42, 259, 203, 560, 603, 555, 371, 75, 595, 104, 642, 509, 276, 419, 694, 697, 616, 373, 380, 384, 195, 524, 423, 260, 603, 364, 756, 249, 449, 43, 518, 53, 525, 665, 477, 737, 366, 691, 29, 727, 137, 594, 245, 718, 578, 2, 203, 263, 244, 109, 763, 695, 348, 273, 637, 570, 457, 652, 617, 376, 130, 699, 667, 726, 19, 738, 27, 57, 644, 653, 77, 59, 400, 588, 472, 427, 40, 476, 7, 650, 235, 392, 435, 175, 122, 622, 662, 383, 154, 433, 129, 593, 355, 354, 60, 484, 459, 610, 434, 84, 287, 429, 203, 114, 660, 557, 474, 554, 279, 351, 485, 634, 247, 510, 223, 374, 328, 6, 70, 410, 141, 125, 121, 756, 356, 715, 757, 444, 717, 706, 454, 493, 106, 239, 46, 351, 205, 334, 598, 408, 590, 332, 739, 723, 382, 85, 741, 418, 524, 195, 731, 606, 740, 502, 460, 162, 475, 583, 709, 145, 222, 696, 456, 252, 213, 439, 553, 96, 668, 674, 702, 183, 103, 710, 25, 669, 568, 438, 661, 491, 131, 762, 450, 699, 233, 483, 550, 604, 170, 283, 759, 158, 363, 134, 549, 179, 279, 79, 599, 264, 46, 533, 346, 228, 650, 467, 567, 554, 176, 167, 556, 359, 452, 164, 135, 319, 460, 186, 208, 124, 341, 174, 450, 623, 447, 160, 305, 292, 86, 527, 646, 492, 198, 36, 347, 722, 185, 540, 115, 5, 746, 453, 753, 433, 597, 297, 750, 468, 363, 436, 389, 461, 757, 626, 648, 188, 575, 544, 647, 397, 257, 388, 446, 500, 592, 140, 192, 24, 540, 62, 685, 690, 469, 716, 726, 217, 68, 128, 165, 387, 190, 228, 543, 34, 371, 154, 262, 38, 113, 236, 654, 332, 689, 372, 494, 240, 508, 465, 706, 190, 249, 149, 663, 567, 65, 375, 724, 539, 275, 515, 682, 56, 682, 35, 82, 359, 689, 36, 421, 683, 333, 714, 276, 529, 382, 526, 304, 181, 247, 330, 221, 456, 659, 90, 438, 344, 464, 211, 178, 78, 763, 483, 768, 243, 307, 112, 256, 172, 326, 574, 566, 759, 411, 600, 723, 747, 448, 225, 247, 733, 111, 655, 338, 367, 388, 231, 118, 682, 635, 476, 477, 573, 569, 535, 369, 47, 702, 14, 417, 331, 57, 651, 289, 543, 343};
				int V[] = {412, 580, 19, 999, 241, 181, 461, 357, 926, 697, 683, 912, 326, 954, 282, 902, 263, 263, 902, 701, 83, 422, 422, 422, 422, 635, 291, 291, 676, 120, 120, 685, 547, 547, 218, 218, 819, 819, 904, 122, 460, 703, 703, 474, 420, 420, 248, 309, 976, 976, 320, 924, 108, 108, 697, 697, 966, 163, 22, 958, 504, 504, 287, 287, 761, 797, 797, 595, 994, 506, 321, 321, 105, 105, 179, 878, 878, 878, 671, 671, 671, 809, 809, 757, 653, 784, 791, 753, 929, 929, 903, 131, 131, 131, 461, 461, 107, 975, 258, 258, 246, 130, 130, 364, 364, 349, 45, 45, 911, 911, 760, 879, 269, 269, 172, 480, 931, 491, 491, 491, 156, 917, 927, 399, 750, 489, 489, 1000, 150, 146, 421, 421, 522, 608, 608, 608, 143, 143, 109, 81, 81, 311, 311, 311, 471, 471, 700, 700, 36, 35, 15, 602, 617, 404, 719, 511, 511, 511, 588, 691, 698, 844, 640, 640, 640, 640, 640, 171, 358, 54, 483, 483, 788, 788, 788, 487, 487, 487, 947, 947, 736, 352, 352, 237, 860, 860, 20, 20, 303, 303, 303, 175, 415, 415, 415, 832, 832, 615, 554, 554, 554, 334, 334, 492, 492, 822, 822, 101, 101, 812, 26, 26, 724, 842, 499, 499, 633, 456, 98, 395, 213, 213, 862, 862, 110, 16, 651, 646, 999, 999, 906, 637, 472, 360, 360, 64, 64, 64, 295, 777, 777, 375, 270, 270, 871, 342, 342, 197, 197, 197, 121, 121, 126, 567, 567, 338, 338, 24, 193, 835, 835, 139, 789, 789, 286, 601, 601, 209, 209, 181, 174, 288, 288, 48, 919, 650, 985, 968, 968, 435, 435, 284, 205, 205, 696, 466, 153, 153, 75, 687, 950, 950, 950, 103, 103, 454, 991, 494, 300, 336, 570, 934, 510, 437, 746, 746, 675, 299, 299, 787, 787, 514, 514, 666, 582, 938, 938, 726, 959, 932, 951, 951, 78, 928, 928, 928, 993, 267, 267, 815, 428, 901, 445, 643, 182, 565, 813, 290, 290, 625, 668, 668, 668, 668, 668, 245, 519, 945, 945, 457, 937, 937, 707, 220, 805, 962, 962, 733, 756, 682, 682, 682, 114, 332, 67, 67, 801, 2, 302, 302, 91, 91, 91, 91, 820, 820, 940, 827, 827, 462, 280, 280, 663, 990, 990, 102, 397, 587, 89, 266, 881, 881, 891, 119, 195, 578, 870, 440, 926, 926, 481, 407, 875, 875, 875, 493, 493, 493, 867, 319, 319, 239, 641, 965, 965, 9, 257, 257, 543, 577, 137, 137, 843, 88, 419, 419, 556, 556, 556, 208, 741, 372, 372, 735, 61, 501, 800, 387, 387, 387, 434, 325, 790, 759, 759, 759, 247, 446, 446, 335, 335, 335, 335, 335, 256, 256, 277, 277, 214, 580, 612, 612, 794, 794, 737, 737, 732, 424, 541, 541, 367, 283, 66, 840, 830, 830, 830, 816, 816, 573, 852, 852, 155, 155, 606, 606, 606, 234, 234, 679, 227, 720, 720, 85, 574, 44, 44, 752, 752, 84, 206, 206, 774, 834, 834, 353, 351, 351, 600, 600, 890, 658, 658, 296, 296, 683, 692, 692, 692, 546, 546, 544, 544, 56, 56, 112, 977, 202, 202, 767, 767, 393, 665, 271, 271, 271, 610, 610, 610, 749, 749, 749, 749, 138, 138, 138, 19, 19, 743, 743, 527, 527, 289, 289, 8, 29, 886, 886, 967, 967, 967, 161, 161, 47, 27, 278, 278, 374, 392, 310, 310, 500, 792, 792, 792, 779, 779, 661, 347, 414, 817, 817, 371, 226, 226, 141, 141, 942, 942, 942, 426, 191, 55, 55, 304, 729, 382, 382, 382, 92, 699, 699, 41, 160, 160, 868, 723, 475, 475, 210, 333, 824, 824, 94, 94, 894, 381, 196, 196, 566, 566, 186, 186, 186, 73, 73, 219, 292, 292, 660, 619, 973, 973, 956, 51, 51, 670, 553, 553, 935, 935, 431, 273, 5, 5, 76, 76, 76, 952, 952, 285, 513, 513, 513, 513, 521, 521, 667, 230, 230, 747, 496, 970, 970, 316, 169, 165, 165, 165, 165, 165, 913, 542, 535, 593, 678, 678, 678, 318, 613, 848, 739, 49, 690, 690, 550, 550, 550, 550, 308, 308, 738, 312, 548, 548, 326, 187, 681, 207, 298, 298, 62, 369, 821, 821, 821, 925, 599, 184, 590, 77, 77, 136, 282, 282, 331, 331, 386, 386, 441, 441, 441, 93, 93, 944, 133, 133, 497, 497, 745, 745, 825, 406, 406, 406, 265, 954, 954, 971, 604, 604, 604, 452, 662, 662, 470, 470, 804, 804, 332, 214, 316, 343, 827, 904, 76, 511, 869, 296, 262, 858, 266, 898, 551, 236, 663, 692, 348, 16, 944, 920, 738};
				int K = 633;
				_expected = 93327;
				_received = _obj.getMinimumInversions(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(V, V+sizeof(V)/sizeof(int)), K); break;
			}
			/*case 7:
			{
				int A[] = ;
				int B[] = ;
				int V[] = ;
				int K = ;
				_expected = ;
				_received = _obj.getMinimumInversions(vector <int>(A, A+sizeof(A)/sizeof(int)), vector <int>(B, B+sizeof(B)/sizeof(int)), vector <int>(V, V+sizeof(V)/sizeof(int)), K); break;
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
