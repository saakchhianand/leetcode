long long flowerGame(int n, int m) {
    long long nOdds, nEvens, mOdds, mEvens, ans = 0; 
    nEvens = n / 2;
    mEvens = m / 2;
    nOdds = nEvens + (n % 2);
    mOdds = mEvens + (m % 2);

    ans += mEvens * nOdds;
    ans += mOdds * nEvens;

    return ans;
}