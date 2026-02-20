# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/sudharsan/c_programming_web3/network_internet/pico_2w_client/build/_deps/picotool-src"
  "/home/sudharsan/c_programming_web3/network_internet/pico_2w_client/build/_deps/picotool-build"
  "/home/sudharsan/c_programming_web3/network_internet/pico_2w_client/build/_deps"
  "/home/sudharsan/c_programming_web3/network_internet/pico_2w_client/build/pico-sdk/src/rp2350/boot_stage2/picotool/tmp"
  "/home/sudharsan/c_programming_web3/network_internet/pico_2w_client/build/pico-sdk/src/rp2350/boot_stage2/picotool/src/picotoolBuild-stamp"
  "/home/sudharsan/c_programming_web3/network_internet/pico_2w_client/build/pico-sdk/src/rp2350/boot_stage2/picotool/src"
  "/home/sudharsan/c_programming_web3/network_internet/pico_2w_client/build/pico-sdk/src/rp2350/boot_stage2/picotool/src/picotoolBuild-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/sudharsan/c_programming_web3/network_internet/pico_2w_client/build/pico-sdk/src/rp2350/boot_stage2/picotool/src/picotoolBuild-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/sudharsan/c_programming_web3/network_internet/pico_2w_client/build/pico-sdk/src/rp2350/boot_stage2/picotool/src/picotoolBuild-stamp${cfgdir}") # cfgdir has leading slash
endif()
