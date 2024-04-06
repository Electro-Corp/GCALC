#ifndef CTRE_EXTRA_HPP
#define CTRE_EXTRA_HPP

#include <ctre.hpp>

void ctre::replace(std::string str, std::string_view pattern, std::string_view replacement) {
    if (!has_matches(str, pattern)) { return; }
    auto m = ctre::match<pattern>(str);
    
    
}

void ctre::has_matches(std::string_view str, std::string_view pattern) {
    return ctre::match<pattern>(str);
}

#endif // CTRE_EXTRA_HPP