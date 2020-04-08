
#include <Seed.hpp>
#include <array>
#include <cstring>
int main(int ac, char **av) {

  bool have_0 = false;
  bool have_1 = false;
  char seed[10][10];
  memset(&seed, 0, sizeof(seed));
  if (Seed::get().generate_seed(seed)) {

    for (unsigned i = 0; i < 10; i++) {
      for (unsigned j = 0; j < 10; j++) {
        if (seed[i][j] == 1) {
          have_1 = true;
        }
        if (seed[i][j] == 0) {
          have_0 = true;
        }
        if (have_0 && have_1) {
          return 0;
        }
      }
    }
  }

  return 1;
}