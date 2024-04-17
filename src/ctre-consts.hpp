#ifndef CTRE_CONSTS_HPP
#define CTRE_CONSTS_HPP
#include <ctre.hpp>
#include <unordered_map>
#include <string>
#include <string_view>


namespace ctreconst {
    std::vector<std::string_view> consts {
        std::string_view{"a(ab|cd)+"},
        std::string_view{"^\\(|\\)$| "},
    };

    typedef enum {
      IDK,
      SWAG,
    } Regex;
}


// do we have to use this library 
// they use templates everywhere and they forgot how ass c++ templates were
// the compiler just cant deal with it (mucho trieste)
// The templates should make it easier to use.
// what compiler are we using
// i can try using clang

/*
    clang 7.0+ (template UDL, C++17 syntax)
    xcode clang 10.0+ (template UDL, C++17 syntax)
    clang 12.0+ (C++17 syntax, C++20 cNTTP syntax)
    gcc 8.0+ (template UDL, C++17 syntax)
    gcc 9.0+ (C++17 & C++20 cNTTP syntax)
    MSVC 14.29+ (Visual Studio 16.11+) (C++20)
*/

/*
~/GraphingCalculator$ gcc -v
Using built-in specs.
COLLECT_GCC=/nix/store/hf2gy3km07d5m0p1lwmja0rg9wlnmyr7-gcc-12.3.0/bin/gcc
COLLECT_LTO_WRAPPER=/nix/store/hf2gy3km07d5m0p1lwmja0rg9wlnmyr7-gcc-12.3.0/libexec/gcc/x86_64-unknown-linux-gnu/12.3.0/lto-wrapper
Target: x86_64-unknown-linux-gnu
Configured with: ../gcc-12.3.0/configure --prefix=/nix/store/eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee-gcc-12.3.0 --with-gmp-include=/nix/store/eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee-gmp-6.3.0-dev/include --with-gmp-lib=/nix/store/eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee-gmp-6.3.0/lib --with-mpfr-include=/nix/store/eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee-mpfr-4.2.1-dev/include --with-mpfr-lib=/nix/store/eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee-mpfr-4.2.1/lib --with-mpc=/nix/store/eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee-libmpc-1.3.1 --with-native-system-header-dir=/nix/store/eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee-glibc-2.38-27-dev/include --with-build-sysroot=/ --program-prefix= --enable-lto --disable-libstdcxx-pch --without-included-gettext --with-system-zlib --enable-static --enable-languages=c,c++ --disable-multilib --enable-plugin --disable-libcc1 --with-isl=/nix/store/eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee-isl-0.20 --disable-bootstrap --build=x86_64-unknown-linux-gnu --host=x86_64-unknown-linux-gnu --target=x86_64-unknown-linux-gnu
Thread model: posix
Supported LTO compression algorithms: zlib
gcc version 12.3.0 (GCC) 
*/
#endif // CTRE_CONSTS_HPP