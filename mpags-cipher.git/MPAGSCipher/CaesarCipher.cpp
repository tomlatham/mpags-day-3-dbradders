#include "CaesarCipher.hpp"
#include "ProcessCommandLine.hpp"
#include <iostream>
#include <string>
#include "CipherMode.hpp"

//initialise variables

CaesarCipher::CaesarCipher(const size_t key) : key_{key}
{
}

// Create second constructor that takes a key as string

CaesarCipher::CaesarCipher(const std::string& key) : key_{0}
{
   bool isNumber{!key.empty()};
   for (const auto& elem : key){
      if (! std::isdigit(elem)){
      isNumber = false;
    }
   }
    if (isNumber == true){
      key_ = std::stoul(key);
    }
    else{
      std::cerr << "[error] problem converting Caesar cipher key, the key must be a positive integer" << std::endl;
    }
}
// Add member function to encrypt/decrypt string
std::string CaesarCipher::applyCipher(const std::string &inputText,
			  const CipherMode Cipher_Mode) const // Recall CipherMode enum
{
 // Create the output string
  std::string outputText {};

  // Make sure that the key is in the range 0 - 25
  const size_t truncatedKey { key_ % alphabetSize_ };

  // Loop over the input text
  char processedChar {'x'};
  for ( const auto& origChar : inputText ) {

    // For each character in the input text, find the corresponding position in
    // the alphabet by using an indexed loop over the alphabet container
    for ( size_t i{0}; i < alphabetSize_; ++i ) {

      if ( origChar == alphabet_[i] ) {

	// Apply the appropriate shift (depending on whether we're encrypting
	// or decrypting) and determine the new character
	// Can then break out of the loop over the alphabet

	// Make conditional from "encrypt" enum value of CipherMode
	if ( Cipher_Mode == CipherMode::encrypt ) {
	  processedChar = alphabet_[ (i + truncatedKey) % alphabetSize_ ];
	} else {
	  processedChar = alphabet_[ (i + alphabetSize_ - truncatedKey) % alphabetSize_ ];
	}
	break;
      }
    }

    // Add the new character to the output text
    outputText += processedChar;
  }

  return outputText;
}
