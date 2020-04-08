#ifndef __CELLFACTORY__
#define __CELLFACTORY__

#include "Cell.hpp"
#include "Seed.hpp"

#include <vector>

struct CellFactory {
  template<unsigned width,unsigned height>
  std::vector<Cell> initialize(Seed &seed){
    unsigned cell_count = width * height;
    char sd[width][heigh];
    memset(&sd,0,sizeof(seed));
    seed.
  }
};

#endif