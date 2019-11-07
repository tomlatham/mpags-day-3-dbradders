#include "CaesarCipher.hpp"

//initialise variables

CaesarCipher::CaesarCipher(const size_t key) : key_{key}
{
}

// Create second constructor that takes a key as string

CaesarCipher::CaesarCipher(const std::string& key) : key_{0}
{
   bool isNumber{true};
   for (const auto& elem : key){
      if (! std::isdigit(elem)){
      isNumber = false;
    }
    if (isNumber = true){
      key_ = std::stoul(key);
    }
    else{
      std::cerr << "Input for key must be a number" << std::endl;
    }
   }
}
