#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP

#include <vector>
#include <string>

class CaesarCipher {
public:
  explicit CaesarCipher(const size_t key);//Transform to size_t for consistency
  
  explicit CaesarCipher(const std::string& key);

  size_t key_;
};

#endif
