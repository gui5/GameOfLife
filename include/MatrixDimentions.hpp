#ifndef __MATDIMS__
#define __MATDIMS__

namespace window_resolution {
enum { width = 1024, height = 768 };
}
namespace pixel_size {
enum { side = 8 };
}

namespace matrix {
enum {
  x_lenght = window_resolution::width / pixel_size::side,
  y_lenght = window_resolution::height / pixel_size::side
};
}

#endif