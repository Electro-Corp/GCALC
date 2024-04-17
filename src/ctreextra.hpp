#ifndef CTRE_EXTRA_HPP
#define CTRE_EXTRA_HPP

#include <ctre.hpp>
#include <ctll/fixed_string.hpp>
#include <string>
#include <string_view>
#include <vector>
#include "ctre-consts.hpp"
namespace ctrea {
  
  bool has_matches(std::string str, std::string_view key) {
      return false;
      //return ctre::match<ctreconst::consts.at(key)>(str);
  }

  void replace(std::string str, ctreconst::Regex key, std::string_view replacement) {
      // if (!has_matches(str, key)) { return; }
      // auto m = ctre::search<ctreconst::consts.at(key)>(str);
      // for (const auto& match : m) {
      //     str.replace(match.begin(), match.end(), replacement);
      // }

      // 
      auto m = ctre::search<" ">(str);
      /*switch (key) { // key has to be an int you cant switch it unless you want to if it
        case ctreconst::Regex.SWAG:
            m = ctre::search<"^\\(|\\)$| ">(str);
          break;
      }*/
      if(key == ctreconst::Regex::SWAG){
        m = ctre::search<"^\\(|\\)$| ">(str);
      }

      for (const auto& match : m) {
          std::string damn(m);
          std::cout << damn << "\n";
          str.replace(damn.begin(), damn.end(), replacement);
      }

      return;
  }
    
}

#endif // CTRE_EXTRA_HPP
// 0004f001