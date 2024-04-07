#ifndef CTRE_EXTRA_HPP
#define CTRE_EXTRA_HPP

#include <ctre.hpp>
#include <ctll/fixed_string.hpp>
#include <string>
#include <string_view>
#include <vector>

namespace ctrea {
  
    bool has_matches(std::string str, auto pattern) noexcept {
      ctll::fixed_string tmp = pattern;
      return ctre::match<tmp>(str);
    }
  
    void replace(auto str, auto pattern, auto replacement) {
        if (!has_matches(str, pattern)) { return; }
        auto m = ctre::search<pattern>(str);
    
        for (const auto& match : m) {
            str.replace(match.begin(), match.end(), replacement);
        }
    }
}

#endif // CTRE_EXTRA_HPP