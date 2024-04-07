int n, t[2 * ms];

void build() {
  for(int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1]; // Merge
}

void update(int p, int value) { // set value at position p
  for(t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1]; // Merge
}

S query(int l, int r) {
  // initialize with null value
  S resl, resr;
  for (l += n, r += n+1; l < r; l >>= 1, r >>= 1) {
  if (l&1) resl = combine(resl, t[l++]);
  if (r&1) resr = combine(t[--r], resr);
  }
  return combine(resl, resr);
}
