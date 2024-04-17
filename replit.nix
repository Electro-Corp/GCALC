{ pkgs }: {
    deps = [
      pkgs.zulu17
      pkgs.llvmPackages_13.clang-unwrapped
      pkgs.SDL_image
      pkgs.gdb
      pkgs.SDL2
      pkgs.cmake
      pkgs.SDL2_ttf
      pkgs.ctre 
      pkgs.clang
    ];
}