#include <algorithm>
#include <cassert>
#include <cstring>
#include <memory>
#include <string>
#include <vector>
 
using namespace std;
 
using uint = unsigned int;
// Buffer size should be 2^12 or 2^13 for optimal performance with files.
const uint BUFFER_SIZE = 1 << 12;
// Maximum possible length of a string representing primitive type
// assuming we won't encounter huge double values.
const uint MAX_LENGTH = 1 << 7;
 
namespace Detail {
  struct Width { uint value; };
  struct Fill { char value; };
  struct Base { uint value; };
  struct Precision { uint value; };
  struct Delimiter { const char* value; };
}  // namespace Detail
 
Detail::Width setWidth(uint value = 0) { return {value}; }
Detail::Fill setFill(char value = ' ') { return {value}; }
Detail::Base setBase(uint value = 10) { assert(2 <= value && value <= 36); return {value}; }
Detail::Precision setPrecision(uint value = 9) { assert(value < MAX_LENGTH); return {value}; }
Detail::Delimiter setDelimiter(const char* value = " ") { return {value}; }
 
/*************************************************** input classes ****************************************************/
class InputDevice {
protected:
  const char* head;
  const char* tail;
 
  InputDevice(const char* head, const char* tail) : head(head), tail(tail), base(setBase().value) {}
  InputDevice(InputDevice const&) = delete;
  InputDevice& operator = (InputDevice const&) = delete;
 
  virtual void fillInput() = 0;
 
  inline char nextChar() {
    if (__builtin_expect(head >= tail, false)) fillInput();
    return *head++;
  }
 
  template <class I> int readUnsignedIntGeneral(I& arg, char c) {
    I value = 0;
    int length = 0;
    for (;; ++length, c = nextChar()) {
      if (isDigit(c)) c -= '0';
      else if (isUpper(c)) c -= 'A' - 10;
      else if (isLower(c)) c -= 'a' - 10;
      else c = base;
      if (c >= base) break;
      value = base * value + c;
    }
    arg = value;
    return --head, length;
  }
 
  template <class I> inline int readUnsignedInt(I& arg, char c) {
    if (__builtin_expect(base > 10, false)) return readUnsignedIntGeneral(arg, c);
    I value = 0;
    int length = 0;
    for (; static_cast<unsigned char>(c - '0') < base; ++length, c = nextChar())
      value = base * value + c - '0';
    arg = value;
    return --head, length;
  }
 
  template <class I> inline int readSignedInt(I& arg, char c) {
    bool negative = c == '-';
    if (negative) c = nextChar();
    typename make_unsigned<I>::type unsignedArg;
    if (readUnsignedInt(unsignedArg, c) == 0) return 0;
    arg = negative ? ~static_cast<I>(unsignedArg - 1) : static_cast<I>(unsignedArg);
    return 1;
  }
 
  template <class F> int readFloatingPoint(F& arg, char c) {
    bool negative = c == '-';
    if (negative) c = nextChar();
    unsigned long long integerPart;
    if (readUnsignedInt(integerPart, c) == 0) return 0;
    if (nextChar() == '.') {
      unsigned long long fractionalPart = 0;
      int fractionalLength = readUnsignedInt(fractionalPart, nextChar());
      if (fractionalLength > 0) {
        unsigned long long basePower = 1;
        for (; fractionalLength; --fractionalLength) basePower *= base;
        arg = static_cast<F>(fractionalPart) / basePower;
      }
    } else --head;
    arg += integerPart;
    if (negative) arg = -arg;
    return 1;
  }
 
public:
  static inline bool isSpace(char c) { return static_cast<unsigned char>(c - '\t') < 5 || c == ' '; }
  static inline bool isDigit(char c) { return static_cast<unsigned char>(c - '0') < 10; }
  static inline bool isUpper(char c) { return static_cast<unsigned char>(c - 'A') < 26; }
  static inline bool isLower(char c) { return static_cast<unsigned char>(c - 'a') < 26; }
  static inline bool isOneOf(char c, const char* str) { return strchr(str, c) != nullptr; }
 
  uint base;
  void putBack() { --head; }  // can be called only once directly after successfully reading a character
 
  inline int readChar(char& arg) {
    if (__builtin_expect(head >= tail, false)) {
      fillInput();
      if (__builtin_expect(head >= tail, false)) return arg = '\0', 0;
    }
    return arg = *head++, 1;
  }
 
  template <class UnaryPredicate>
  inline char skipCharacters(UnaryPredicate isSkipped) {
    char c;
    do { c = nextChar(); } while (isSkipped(c));
    return c;
  }
  inline char skipCharacters() { return skipCharacters(isSpace); }
 
  template <class UnaryPredicate>
  inline int readString(char* arg, int limit, UnaryPredicate isTerminator) {
    skipCharacters(isTerminator);
    // put back first non-skipped character, reserve space for null character
    for (--head, --limit; head < tail; fillInput()) {
      ptrdiff_t chunkSize = find_if(head, min(tail, head + limit), isTerminator) - head;
      arg = copy_n(head, chunkSize, arg);
      head += chunkSize;
      limit -= chunkSize;
      if (chunkSize == 0 || head < tail) break;
    }
    return *arg = '\0', 1;
  }
 
  template <class I> inline int readUnsignedInt(I& arg) { return readUnsignedInt(arg, skipCharacters()) > 0 ? 1 : 0; }
  template <class I> inline int readSignedInt(I& arg) { return readSignedInt(arg, skipCharacters()); }
  template <class F> inline int readFloatingPoint(F& arg) { return readFloatingPoint(arg, skipCharacters()); }
};
 
class InputFile : public InputDevice {
  FILE* file;
  bool lineBuffered;
  bool owner;
  char buffer[BUFFER_SIZE];
 
  void fillInput() override {
    head = buffer;
    *buffer = '\0';
    if (__builtin_expect(!lineBuffered, true)) {
      tail = head + fread(buffer, 1, BUFFER_SIZE, file);
    } else {
      tail = head;
      if (fgets(buffer, BUFFER_SIZE, file)) while (*tail) ++tail;
    }
  }
 
public:
  InputFile(FILE* file = stdin, bool lineBuffered = true, bool takeOwnership = false)
  : InputDevice(buffer, buffer) , file(file), lineBuffered(lineBuffered), owner(takeOwnership) {}
  InputFile(const char* fileName) : InputFile(fopen(fileName, "r"), false, true) {}
  ~InputFile() { if (owner) fclose(file); }
};
 
// Picks up data appended to the string but doesn't handle reallocation.
class InputString : public InputDevice {
  void fillInput() override { while (*tail) ++tail; }
 
public:
  InputString(const string& s) : InputDevice(s.data(), s.data() + s.size()) {}
  InputString(const char* s) : InputDevice(s, s + strlen(s)) {}
};
 
/*************************************************** output classes ***************************************************/
class OutputDevice {
protected:
  char buffer[BUFFER_SIZE + MAX_LENGTH];
  char* output;
  char* end;
  bool separate;
 
  OutputDevice() : output(buffer), end(buffer + BUFFER_SIZE + MAX_LENGTH), separate(false), width(setWidth().value)
  , fill(setFill().value), base(setBase().value), precision(setPrecision().value), delimiter(setDelimiter().value) {}
  OutputDevice(OutputDevice const&) = delete;
  OutputDevice& operator = (OutputDevice const&) = delete;
 
  virtual void writeToDevice(uint count) = 0;
 
  inline void flushMaybe() {
    if (__builtin_expect(output >= buffer + BUFFER_SIZE, false)) {
      writeToDevice(BUFFER_SIZE);
      output = copy(buffer + BUFFER_SIZE, output, buffer);
    }
  }
 
  template <class I> inline char* writeUnsignedInt(I arg, char* last) {
    if (__builtin_expect(arg == 0, false)) *--last = '0';
    if (__builtin_expect(base == 10, true)) {
      for (; arg; arg /= 10) *--last = '0' + arg % 10;
    } else for (; arg; arg /= base) {
      I digit = arg % base;
      *--last = digit < 10 ? '0' + digit : 'A' - 10 + digit;
    }
    return last;
  }
 
  template <class I> inline char* writeSignedInt(I arg, char* last) {
    auto unsignedArg = static_cast<typename make_unsigned<I>::type>(arg);
    if (arg < 0) {
      last = writeUnsignedInt(~unsignedArg + 1, last);
      *--last = '-';
      return last;
    }
    return writeUnsignedInt(unsignedArg, last);
  }
 
  template <class F> char* writeFloatingPoint(F arg, char* last) {
    bool negative = signbit(arg);
    if (negative) arg = -arg;
    if (isnan(arg)) for (int i = 0; i < 3; ++i) *--last = i["NaN"];
    else if (isinf(arg)) for (int i = 0; i < 3; ++i) *--last = i["fnI"];
    else {
      auto integerPart = static_cast<unsigned long long>(arg);
      arg -= integerPart;
      for (int i = 0; i < precision; ++i) arg *= base;
      auto fractionalPart = static_cast<unsigned long long>(arg);
      if ((arg - fractionalPart) * 2 >= static_cast<F>(1)) {
        if (precision == 0) ++integerPart;
        else ++fractionalPart;
      }
      if (precision > 0) {
        char* point = last - precision;
        last = writeUnsignedInt(fractionalPart, last);
        ::fill(point, last, '0');
        last = point;
        *--last = '.';
      }
      last = writeUnsignedInt(integerPart, last);
    }
    if (negative) *--last = '-';
    return last;
  }
 
  inline int writeT(char* first) {
    int delimiterLenght = separate ? writeDelimiter() : 0;
    separate = true;
    int charsWritten = static_cast<int>(end - first);
    if (__builtin_expect(charsWritten < width, false))
      charsWritten += writeFill(width - charsWritten);
    output = copy(first, end, output);
    flushMaybe();
    return delimiterLenght + charsWritten;
  }
 
  inline int writeFill(int count) {
    int result = count;
    if (__builtin_expect(output + count + MAX_LENGTH < end, true)) {
      if (count == 1) *output++ = fill;
      else output = fill_n(output, count, fill);
    } else for (uint chunkSize = static_cast<uint>(buffer + BUFFER_SIZE - output);; chunkSize = BUFFER_SIZE) {
      if (chunkSize > count) chunkSize = count;
      output = fill_n(output, chunkSize, fill);
      flushMaybe();
      if ((count -= chunkSize) == 0) break;
    }
    return result;
  }
 
public:
  int width;
  char fill;
  uint base;
  uint precision;
  string delimiter;
 
  inline int writeChar(char arg) { separate = false; *output++ = arg; flushMaybe(); return 1; }
 
  inline int writeString(const char* arg, int count, bool checkWidth = true) {
    separate = false;
    int result = count + (checkWidth && count < width ? writeFill(width - count) : 0);
    if (__builtin_expect(output + count + MAX_LENGTH < end, true)) {
      if (count == 1) *output++ = *arg;
      else output = copy_n(arg, count, output);
    } else for (int chunkSize = static_cast<int>(buffer + BUFFER_SIZE - output);; chunkSize = BUFFER_SIZE) {
      if (chunkSize > count) chunkSize = count;
      output = copy_n(arg, chunkSize, output);
      flushMaybe();
      if ((count -= chunkSize) == 0) break;
      arg += chunkSize;
    }
    return result;
  }
 
  inline int writeDelimiter() { return writeString(delimiter.c_str(), static_cast<int>(delimiter.size()), false); }
 
  template <class I> inline int writeUnsignedInt(I arg) { return writeT(writeUnsignedInt(arg, end)); }
  template <class I> inline int writeSignedInt(I arg) { return writeT(writeSignedInt(arg, end)); }
  template <class F> inline int writeFloatingPoint(F arg) { return writeT(writeFloatingPoint(arg, end)); }
 
  inline void flush() {
    writeToDevice(static_cast<uint>(output - buffer));
    output = buffer;
  }
  virtual ~OutputDevice() {};
};
 
class OutputFile : public OutputDevice {
  FILE* file;
  bool owner;
 
  void writeToDevice(uint count) override {
    fwrite(buffer, 1, count, file);
    fflush(file);
  }
 
public:
  OutputFile(FILE* file = stdout, bool takeOwnership = false) : file(file), owner(takeOwnership) {}
  OutputFile(const char* fileName) : OutputFile(fopen(fileName, "w"), true) {}
  ~OutputFile() override { flush(); if (owner) fclose(file); }
};
 
class OutputString : public OutputDevice {
  string& str;
 
  void writeToDevice(uint count) override { str.append(buffer, count); }
 
public:
  OutputString(string& str) : OutputDevice(), str(str) {}
  ~OutputString() override { flush(); }
};
 
/**************************************************** read & write ****************************************************/
unique_ptr<InputDevice> input;
unique_ptr<OutputDevice> output;
 
// property setters
inline int read(Detail::Base base) { input->base = base.value; return 0; }
// primitive types
inline int read() { return 0; }
inline int read(char& arg) { return input->readChar(arg); }
template <class I> inline typename enable_if<is_integral<I>::value && is_unsigned<I>::value,
int>::type read(I& arg) { return input->readUnsignedInt(arg); }
template <class I> inline typename enable_if<is_integral<I>::value && is_signed<I>::value,
int>::type read(I& arg) { return input->readSignedInt(arg); }
template <class F> inline typename enable_if<is_floating_point<F>::value,
int>::type read(F& arg) { return input->readFloatingPoint(arg); }
// characters skip
inline int read(const char& arg) { input->skipCharacters([arg](char c) { return arg != c; }); return 0; }
inline int read(const char* arg) {
  if (*arg) input->skipCharacters([arg](char c) { return InputDevice::isOneOf(c, arg); });
  else input->skipCharacters();
  input->putBack(); return 0;
}
inline int read(bool (*isSkipped)(char)) { input->skipCharacters(isSkipped); input->putBack(); return 0; }
// forward declarations so everything compiles
template <class... Ts> int read(char* arg, int limit, bool (*isTerminator)(char), Ts&&... args);
template <class... Ts> int read(char* arg, int limit, const char* terminators, Ts&&... args);
template <class Iterator, class... Ts, typename = decltype(*std::declval<Iterator>())>
int read(Iterator first, Iterator last, Ts&&... args);
template <class Iterator, class... Ts, typename = decltype(*std::declval<Iterator>())>
int read(Iterator first, int count, Ts&&... args);
template <class T, class... Ts, typename = typename enable_if<!is_convertible<T, char*>::value, void>::type>
int read(T&& arg1, Ts&&... args);
// C strings
inline int read(char* arg, int limit, const char* terminators = "") {
  if (!*terminators) return input->readString(arg, limit, InputDevice::isSpace);
  else return input->readString(arg, limit, [terminators](char c) { return InputDevice::isOneOf(c, terminators); });
}
template <class... Ts>
inline int read(char* first, char* last, Ts&&... args) {
  return read(first, static_cast<int>(last - first), forward<Ts>(args)...);
}
template <int N, class... Ts>
inline int read(char (&arg)[N], Ts&&... args) { return read(static_cast<char*>(arg), N, forward<Ts>(args)...); }
template <class... Ts>
inline int read(char* arg, int limit, bool (*isTerminator)(char), Ts&&... args) {
  int argsRead = input->readString(arg, limit, isTerminator);
  return argsRead + read(forward<Ts>(args)...);
}
template <class... Ts>
inline int read(char* arg, int limit, const char* terminators, Ts&&... args) {
  int argsRead = read(arg, limit, terminators);
  return argsRead + read(forward<Ts>(args)...);
}
// complex types and ranges
template <class T1, class T2>
inline int read(pair<T1, T2>& arg) { return read(arg.first) == 1 && read(arg.second) == 1 ? 1 : 0; }
template <class T>
inline int read(vector<T>& arg) {
  uint n;
  if (read(n) == 0) return 0;
  arg.resize(n);
  return read(arg.begin(), arg.end());
}
template <class Iterator, class... Ts, typename>
int read(Iterator first, Iterator last, Ts&&... args) {
  int success = 1;
  for (; first != last; ++first) success &= read(*first);
  return success + read(forward<Ts>(args)...);
}
template <class Iterator, class... Ts, typename>
int read(Iterator first, int count, Ts&&... args) { return read(first, first + count, forward<Ts>(args)...); }
template <class T, class... Ts, typename>
inline int read(T&& arg1, Ts&&... args) {
  int argsRead = read(forward<T>(arg1));
  return argsRead + read(forward<Ts>(args)...);
}
 
// property setters
inline int write(Detail::Width width) { output->width = static_cast<int>(width.value); return 0; }
inline int write(Detail::Fill fill) { output->fill = fill.value; return 0; }
inline int write(Detail::Base base) { output->base = base.value; return 0; }
inline int write(Detail::Precision precision) { output->precision = precision.value; return 0; }
inline int write(Detail::Delimiter delimiter) { output->delimiter = delimiter.value; return 0; }
// primitive types
inline int write() { return 0; }
inline int write(char arg) { return output->writeChar(arg); }
template <class I> inline typename enable_if<is_integral<I>::value && is_unsigned<I>::value,
int>::type write(I arg) { return output->writeUnsignedInt(arg); }
template <class I> inline typename enable_if<is_integral<I>::value && is_signed<I>::value,
int>::type write(I arg) { return output->writeSignedInt(arg); }
template <class F> inline typename enable_if<is_floating_point<F>::value,
int>::type write(F arg) { return output->writeFloatingPoint(arg); }
// complex types
inline int write(const char* arg) { return output->writeString(arg, static_cast<int>(strlen(arg))); }
template <int N>
inline int write(char (&arg)[N]) { return output->writeString(arg, static_cast<int>(strlen(arg))); }
inline int write(const string& arg) { return output->writeString(arg.c_str(), static_cast<int>(arg.size())); }
template <class T1, class T2>
inline int write(const pair<T1, T2>& arg) {
  int charsWritten = write(arg.first);
  charsWritten += output->writeDelimiter();
  return charsWritten + write(arg.second);
}
// forward declarations so everything compiles
template <class Iterator, class... Ts,
typename = typename enable_if<!is_convertible<Iterator, const char*>::value, decltype(*std::declval<Iterator>())>::type>
int write(Iterator first, Iterator last, Ts&&... args);
template <class Iterator, class... Ts,
typename = typename enable_if<!is_convertible<Iterator, const char*>::value, decltype(*std::declval<Iterator>())>::type>
int write(Iterator first, int count, Ts&&... args);
template <class T, class T2, class... Ts> int write(T&& arg, T2&& arg2, Ts&&... args);
// ranges
template <class Iterator, class... Ts, typename>
int write(Iterator first, Iterator last, Ts&&... args) {
  int charsWritten = 0;
  for (; first != last; charsWritten += ++first == last ? 0 : output->writeDelimiter()) charsWritten += write(*first);
  return charsWritten + write(forward<Ts>(args)...);
}
template <class Iterator, class... Ts, typename>
int write(Iterator first, int count, Ts&&... args) { return write(first, first + count, forward<Ts>(args)...); }
template <class T, class T2, class... Ts>
inline int write(T&& arg, T2&& arg2, Ts&&... args) {
  int charsWritten = write(forward<T>(arg));
  return charsWritten + write(forward<T2>(arg2), forward<Ts>(args)...);
}
template <class... Ts>
inline int writeln(Ts&&... args) { return write(forward<Ts>(args)..., '\n'); }
 
void flush() { output->flush(); }



#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
const ll INF=1e9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;

#ifdef DEBUG
     #define debug(args...)            {dbg,args; cerr<<endl;}
#else
    #define debug(args...)              // Just strip off all debug tokens
#endif

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {    
        cerr<<v<<" ";    
        return *this;    
    }
} dbg;
ll n;
const ll mn=5e5+2;
vector<long long> g[mn];
ll vsz[mn];
ll getsz(ll x) {
	ll ans=1;
	for (auto &w:g[x]) {
		ll y=w>>32LL;
		ans+=getsz(y);
	}
	vsz[x]=ans;
	return ans;
}
ll xorbase[mn];
ll lenbase[mn];
ll vans[mn];
map<int,int> dp[mn];
ll dfs(ll x) {
	//printf("dfs:%d\n",x);
	pair<int,long long> largest=MP(-1,-1LL);
	if (!g[x].empty()) {
		for (auto &w:g[x]) {
			ll y=w>>32LL;
			chkmax(largest,MP(vsz[y],w));
		}
		ll ly=largest.second>>32LL;
		ll lt=largest.second&0xffffffff;
		ll xxx=dfs(ly);
		map<int,int> &h=dp[xxx];
		xorbase[x]=xorbase[ly]^(1<<lt);
		lenbase[x]=lenbase[ly]+1;
		{
			ll key=0,val=0;
			for (ll c=0;c<22;c++) {
				ll want=key^(1<<c);
				auto it=h.find(want^xorbase[x]);
				if (it!=h.end()) {
					ll newlen=val+it->second+lenbase[x];
					//printf("want:%d vans:%d\n",want,newlen);
					chkmax(vans[x],newlen);
				}
			}
			{
				// For no c
				ll want=key;
				auto it=h.find(want^xorbase[x]);
				if (it!=h.end()) {
					ll newlen=val+it->second+lenbase[x];
					chkmax(vans[x],newlen);
				}
			}
		}
		{
			ll key=xorbase[x];
			ll val=-lenbase[x];
			auto it=h.find(key);
			if (it==h.end()) {
				h[key]=val;
			}
			else {
				it->second=max((int)it->second,(int)val);
			}
		}
		chkmax(vans[x],vans[ly]);
		for (auto &w:g[x]) {
			ll y=w>>32LL,t=w&0xffffffff;
			if (y==ly) continue;
			ll yyy=dfs(y);
			const map<int,int> &m=dp[yyy];
			chkmax(vans[x],vans[y]);
			ll xby=xorbase[y]^(1<<t);
			ll lby=lenbase[y]+1;
			for (auto &b:m) {
				ll key=b.first, val=b.second;
				key^=xby;
				val+=lby;
				for (ll c=0;c<22;c++) {
					ll want=key^(1<<c);
					auto it=h.find(want^xorbase[x]);
					if (it!=h.end()) {
						ll newlen=val+it->second+lenbase[x];
						chkmax(vans[x],newlen);
					}
				}
				{
					// For no c
					ll want=key;
					auto it=h.find(want^xorbase[x]);
					if (it!=h.end()) {
						ll newlen=val+it->second+lenbase[x];
						chkmax(vans[x],newlen);
					}
				}
			}
			xby^=xorbase[x];
			lby-=lenbase[x];
			for (auto &b:m) {
				ll key=b.first, val=b.second;
				key^=xby;
				val+=lby;
				auto it=h.find(key);
				if (it==h.end()) {
					h[key]=val;
				}
				else {
					it->second=max((int)it->second,(int)val);
				}
			}
		}
		//printf("x:%d. xorbase:%d lenbase:%d. ",x,xorbase[x],lenbase[x]);
		//for (auto &b:h) {
		//	printf("(%d, %d)",b.first^xorbase[x],b.second+lenbase[x]);
		//}
		//printf("\n");
		return xxx;
	}
	else {
		map<int,int> h;
		h[0]=0;
		lenbase[x]=0;
		xorbase[x]=0;
		dp[x]=h;
		return x;
	}
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; scanf("%d",&n);
	for (ll i=1;i<n;i++) {
		ll p; char c; scanf("%d %c\n",&p,&c);
		--p; ll t=c-'a';
		g[p].PB((((long long)i)<<32)|t);
	}
	getsz(0);
	memset(vans,0,sizeof vans);
	dfs(0);
	output.reset(new OutputFile());
	writeln(setDelimiter(" "),vans,n);
}

