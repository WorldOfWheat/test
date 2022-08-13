void ntt(vector<int>& x, int lim, int opt) {
	for (int i = 1, j = 0; i < lim; i++) {
		for (int k = lim >> 1; !((j ^= k) & k); k >>= 1);
		if (i < j) swap(x[i], x[j]);
	}
	for (int m = 2; m <= lim; m <<= 1) {
		int k = m >> 1;
		int gn = fpow(G, (P - 1) / m);
		for (int i = 0; i < lim; i += m) {
			int g = 1;
			for (int j = 0; j < k; ++j, g = 1LL * g * gn % P) {
				int tmp = 1LL * x[i + j + k] * g % P;
				x[i + j + k] = (x[i + j] - tmp + P) % P;
				x[i + j] = (x[i + j] + tmp) % P;
			}
		}
	}
	if (opt == -1) {
		reverse(x.begin() + 1, x.begin() + lim);
		int inv = fpow(lim, P - 2);
		for (int i = 0; i < lim; ++i)
			x[i] = 1LL * x[i] * inv % P;
	}
}
