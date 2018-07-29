Iterate all subsets of a bitmask in increasing order

for ( int sub = 0 ; sub = sub - bitmask & bitmask ; ) {
  // do something
}

Iterate all subsets of a bitmask in decreasing order

for(int sub = (mask-1) & bitmask ; sub > 0 ; sub = (sub-1) & bitmask )  {
  // do something
}