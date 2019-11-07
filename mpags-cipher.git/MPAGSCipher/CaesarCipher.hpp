#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP

#include <vector>

class CaesarCipher {
public:
  CaesarCipher(const size_t& key);//Transform to size_t for consistency

  size_t key_;
};

#endif
