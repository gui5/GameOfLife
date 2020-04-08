CC=gcc CXX=g++ cmake -GNinja ..\
  -DCMAKE_TOOLCHAIN_FILE=/home/gui/Projects/cpp/lib/vcpkg/scripts/buildsystems/vcpkg.cmake \
  -DVCPKG_TARGET_TRIPLET=x64-linux