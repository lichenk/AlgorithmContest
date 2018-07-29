#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000009LL;
const ll INF = 1ULL<<60ULL;
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }

inline vector<ll> load(string s) {
	stringstream in(s);
	ll x;
	vector<ll> ret;
	while (in>>x) {
		ret.push_back(x);
	}
	return ret;
}
inline ll mul(ll x, ll y) {return (x*y)%MOD;}
inline ll add(ll x, ll y) {return (x+y)%MOD;}
const ll MF=2000;
ll fact[MF],invfact[MF];
ll binom(ll n, ll k) {
	return mul(fact[n],mul(invfact[n-k],invfact[k]));
}
void init() {
	fact[0]=1;
	for (ll x=1;x<MF;x++) fact[x]=mul(fact[x-1],x);
	for (ll x=0;x<MF;x++) invfact[x]=mod_inv(fact[x],MOD);
}
const ll MN=700;
ll cc[MN];
bool seen[MN];
ll f[3][MN];
ll g[MN];
ll getg(ll n, ll l) {
	for (ll x=0;x<=n;x++) g[x]=0;
	g[0]=1;
	for (ll x=0;x<=n;x++) {
		g[x+4]+=mul(g[x],mul(binom(x+4,x),mul(fact[3],l*l*l)));
	}
	return g[n];
}
ll getf(ll n, ll l) {
	for (ll k=0;k<3;k++) for (ll x=0;x<=n;x++) f[k][x]=0;
	f[0][0]=1;
	for (ll x=0;x<=n;x++) {
		for (ll k=0;k<3;k++) {
			ll val=f[k][x];
			if (val==0) continue;
			printf("k:%lld x:%lld val:%lld\n",k,x,val);
			if (k<=2) {
				f[max(k,2LL)][x+4]+=mul(f[k][x],mul(binom(x+4,x),mul(fact[3],l*l*l)));
			}
			if (k<=1) {
				printf("Add %lld to k:%lld x:%lld\n",mul(f[k][x],mul(binom(x+2,x),mul(fact[1],l))),max(k,1LL),x+2);
				f[max(k,1LL)][x+2]+=mul(f[k][x],mul(binom(x+2,x),mul(fact[1],l)));
			}
			if (k<=0) {
				printf("Badd %lld to k:%lld x:%lld\n",f[k][x],max(k,0LL),x+1);
				f[max(k,0LL)][x+1]+=f[k][x];
			}
		}
	}
	return f[0][n]+f[1][n]+f[2][n];
}
class FleaCircus {
	public:
	int countArrangements(vector <string> afterFourClicks) {
		init();
		string inp;
		for (auto &w:afterFourClicks) inp+=w;
		vector<ll> v=load(inp);
		ll n=v.size();
		for (ll x=0;x<n;x++) seen[x]=false;
		for (ll l=0;l<MN;l++) cc[l]=0;
		for (ll x=0;x<n;x++) {
			if (seen[x]) continue;
			ll len=1;
			ll t=v[x];
			seen[x]=true;
			seen[t]=true;
			while(1) {
				if (t==x) break;
				seen[t]=true;
				t=v[t];
				seen[t]=true;
				len++;
			}
			cc[len]++;
		}
		ll ans=1;
		for (ll l=1;l<MN;l++) {
			ll c=cc[l];
			if (c==0) continue;
			//printf("l:%lld cc:%lld\n",l,cc[l]);
			if (0==l%2) {
				ll get=getg(c,l);
				ans=mul(ans,get);
			}
			else {
				ll get=getf(c,l);
				ans=mul(ans,get);
			}
		}
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
		cout << "Testing FleaCircus (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1470719283;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		FleaCircus _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string afterFourClicks[] = {"1 2 0 3"};
				_expected = 1;
				_received = _obj.countArrangements(vector <string>(afterFourClicks, afterFourClicks+sizeof(afterFourClicks)/sizeof(string))); break;
			}
			case 1:
			{
				string afterFourClicks[] = {"1 2 ", "0 3"};
				_expected = 1;
				_received = _obj.countArrangements(vector <string>(afterFourClicks, afterFourClicks+sizeof(afterFourClicks)/sizeof(string))); break;
			}
			case 2:
			{
				string afterFourClicks[] = {"0 1 2"};
				_expected = 4;
				_received = _obj.countArrangements(vector <string>(afterFourClicks, afterFourClicks+sizeof(afterFourClicks)/sizeof(string))); break;
			}
			case 3:
			{
				string afterFourClicks[] = {"0 1 2 3 5 4"};
				_expected = 0;
				_received = _obj.countArrangements(vector <string>(afterFourClicks, afterFourClicks+sizeof(afterFourClicks)/sizeof(string))); break;
			}
			case 4:
			{
				string afterFourClicks[] = {"3 6 7 9 8 2 1", "0 5 1 0 4"};
				_expected = 4;
				_received = _obj.countArrangements(vector <string>(afterFourClicks, afterFourClicks+sizeof(afterFourClicks)/sizeof(string))); break;
			}
			case 5:
			{
				string afterFourClicks[] = {"1 0 7 5 6 3 4 2"};
				_expected = 48;
				_received = _obj.countArrangements(vector <string>(afterFourClicks, afterFourClicks+sizeof(afterFourClicks)/sizeof(string))); break;
			}
			case 6:
			{
				string afterFourClicks[] = {"0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 ", "20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36", " 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 5", "3 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 ", "70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86", " 87 88 89 90 91 92 93 94 95 96 97 98 99 100 101 10", "2 103 104 105 106 107 108 109 110 111 112 113 114 ", "115 116 117 118 119 120 121 122 123 124 125 126 12", "7 128 129 130 131 132 133 134 135 136 137 138 139 ", "140 141 142 143 144 145 146 147 148 149 150 151 15", "2 153 154 155 156 157 158 159 160 161 162 163 164 ", "165 166 167 168 169 170 171 172 173 174 175 176 17", "7 178 179 180 181 182 183 184 185 186 187 188 189 ", "190 191 192 193 194 195 196 197 198 199 200 201 20", "2 203 204 205 206 207 208 209 210 211 212 213 214 ", "215 216 217 218 219 220 221 222 223 224 225 226 22", "7 228 229 230 231 232 233 234 235 236 237 238 239 ", "240 241 242 243 244 245 246 247 248 249 250 251 25", "2 253 254 255 256 257 258 259 260 261 262 263 264 ", "265 266 267 268 269 270 271 272 273 274 275 276 27", "7 278 279 280 281 282 283 284 285 286 287 288 289 ", "290 291 292 293 294 295 296 297 298 299 300 301 30", "2 303 304 305 306 307 308 309 310 311 312 313 314 ", "315 316 317 318 319 320 321 322 323 324 325 326 32", "7 328 329 330 331 332 333 334 335 336 337 338 339 ", "340 341 342 343 344 345 346 347 348 349 350 351 35", "2 353 354 355 356 357 358 359 360 361 362 363 364 ", "365 366 367 368 369 370 371 372 373 374 375 376 37", "7 378 379 380 381 382 383 384 385 386 387 388 389 ", "390 391 392 393 394 395 396 397 398 399 400 401 40", "2 403 404 405 406 407 408 409 410 411 412 413 414 ", "415 416 417 418 419 420 421 422 423 424 425 426 42", "7 428 429 430 431 432 433 434 435 436 437 438 439 ", "440 441 442 443 444 445 446 447 448 449 450 451 45", "2 453 454 455 456 457 458 459 460 461 462 463 464 ", "465 466 467 468 469 470 471 472 473 474 475 476 47", "7 478 479 480 481 482 483 484 485 486 487 488 489 ", "490 491 492 493 494 495 496 497 498 499 500 501 50", "2 503 504 505 506 507 508 509 510 511 512 513 514 ", "515 516 517 518 519 520 521 522 523 524 525 526 52", "7 528 529 530 531 532 533 534 535 536 537 538 539 ", "540 541 542 543 544 545 546 547 548 549 550 551 55", "2 553 554 555 556 557 558 559 560 561 562 563 564 ", "565 566 567 568 569 570 571 572 573 574 575 576 57", "7 578 579 580 581 582 583 584 585 586 587 588 589 ", "590 591 592 593 594 595 596 597 598 599 600 601 60", "2 603 604 605 606 607 608 609 610 611 612 613 614 ", "615 616 617 618 619 620 621 622 623 624 625 626 62", "7 628 629 630 631 632 633 634 635 636 637 638 639 ", "640 641 642 643 644 645 646 647 648 649 650 651"};
				_expected = 92639029;
				_received = _obj.countArrangements(vector <string>(afterFourClicks, afterFourClicks+sizeof(afterFourClicks)/sizeof(string))); break;
			}
			case 7:
			{
				string afterFourClicks[] = {"431 188 112 361 294 232 226 306 34 286 253 430 56 ", "331 152 110 93 275 316 263 218 195 432 419 121 271", " 405 346 28 396 191 49 480 33 72 82 3 259 413 107 ", "15 305 452 207 59 299 422 175 256 131 60 287 366 5", "3 339 423 245 125 359 293 440 25 258 477 277 401 8", " 337 13 437 248 368 398 353 466 444 246 355 289 0 ", "123 104 81 229 393 376 114 167 133 370 179 143 22 ", "243 57 95 454 403 10 79 273 318 146 340 417 214 16", "0 172 202 447 449 382 199 310 260 196 210 216 138 ", "61 122 302 304 159 303 373 126 100 24 438 193 194 ", "338 427 124 280 463 36 255 134 1 221 238 462 120 4", "11 47 237 397 234 365 233 395 173 217 328 384 161 ", "354 99 85 412 469 90 336 170 5 264 450 387 369 178", " 459 301 212 102 70 321 409 389 326 180 351 103 22", "7 43 105 27 399 231 108 187 35 68 435 241 478 283 ", "265 347 205 197 434 222 479 164 476 300 190 324 12", "9 235 254 379 77 9 176 475 410 276 211 267 141 408", " 20 436 98 158 189 317 349 63 374 66 464 375 220 1", "28 295 136 426 37 78 209 314 470 474 76 251 311 30", "8 247 155 482 278 392 156 383 38 21 213 400 457 43", "9 281 116 42 12 83 465 327 109 230 101 415 252 30 ", "168 174 404 262 87 282 74 448 96 142 332 225 54 41", " 371 91 185 323 388 451 64 127 341 44 456 418 390 ", "18 290 364 345 14 274 52 261 298 208 357 433 113 4", "21 312 73 7 92 145 86 236 460 406 360 330 65 441 1", "30 362 165 26 313 429 89 284 420 171 151 250 343 4", "53 2 219 416 348 473 67 201 367 372 75 186 69 118 ", "88 204 363 307 215 270 320 228 144 291 242 333 244", " 19 257 97 377 16 106 461 292 394 39 169 140 322 7", "1 279 198 266 51 149 139 407 350 23 46 428 29 414 ", "45 483 249 424 458 385 471 40 455 391 50 181 224 3", "2 269 315 148 309 137 329 147 84 48 344 4 55 240 4", "25 192 17 342 132 184 80 177 119 335 6 443 162 386", " 352 206 358 442 468 296 381 94 62 200 115 297 11 ", "445 268 272 183 153 135 402 288 285 481 58 239 163", " 157 182 467 380 356 203 446 472 325 117 111 223 1", "50 334 378 319 166 31 154"};
				_expected = 958004148;
				_received = _obj.countArrangements(vector <string>(afterFourClicks, afterFourClicks+sizeof(afterFourClicks)/sizeof(string))); break;
			}
			case 8:
			{
				string afterFourClicks[] = {"0 1 2 3"};
				_expected = 16;
				_received = _obj.countArrangements(vector <string>(afterFourClicks, afterFourClicks+sizeof(afterFourClicks)/sizeof(string))); break;
			}
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
