long f_ma(long* a, long b, long c) {
  *a = *a + (b * c);
  return *a;
}

int main() {
  long a = 5;
  long b = 7;
  long c = 11;
  long res = f_ma(&a, b, c);

  return 0;
}