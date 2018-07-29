
bool nim(ll a, ll x) {
  vector<ll> got;
  while(x>0) {
    got.PB(x%a);
    x/=a;
  }
  ll XOR=0; for (auto &w:got) XOR^=w;
  if (XOR==0) {
    for (auto &w:got) if (w>1) return false;
  }
  if (XOR==1) {
    for (auto &w:got) if (w>1) return true;
    return false;
  }
  return true;
}
