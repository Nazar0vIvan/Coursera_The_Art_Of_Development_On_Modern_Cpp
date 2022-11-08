#include <cstdint>
#include <iostream>

using namespace std;

int main() {
  int N, R;
  cin >> N >> R;
  uint64_t mass = 0;
  for (int i = 0; i < N; ++i) {
    int W, H, D;
    cin >> W >> H >> D;
    mass += static_cast<uint64_t>(W) * H * D;
  }
  mass *= R;
  cout << mass << endl;
  return 0;
}

// 10^4 = 10'000
// 10^4 * 10^4 = 10^8 = 100'000'000
// 10^4 * 10^4 * 10^4 = 10^12 = 1'000'000'000'000

// 10^5*10^2*10^12 = 10^19 = 10'000'000'000'000'000'000

// uint64_t (unsigned long long): 0 до 18'446'744'073'709'551'615
// uint32_t От 0 до 4'294'967'295

