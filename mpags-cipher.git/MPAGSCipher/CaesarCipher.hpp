#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP

#include <vector>
#include <string>
#include "CipherMode.hpp"

class CaesarCipher {
public:
  explicit CaesarCipher(const size_t key);//Transform to size_t for consistency
  
  explicit CaesarCipher(const std::string& key);

  size_t key_;

  // Include function applyCipher
  std::string applyCipher(const std::string& key, const CipherMode Cipher_Mode) const;

  // Make alphabet and alphabet size private members
private:
  const std::vector<char> alphabet_ {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
				     'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
				     'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
				     'Y', 'Z'};
  const size_t alphabetSize_ { alphabet_.size() };
};

#endif
