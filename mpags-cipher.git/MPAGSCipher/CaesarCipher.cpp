#include "CaesarCipher.hpp"
#include "ProcessCommandLine.hpp"
#include <string>
#include "CipherMode.hpp"

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
// Add member function to encrypt/decrypt string
CaesarCipher::applyCipher(const std::string &inputText,
			  const CipherMode Cipher_Mode) // Recall CipherMode enum
{
 // Create the output string
  std::string outputText {};

  // Create the alphabet container
  const std::vector<char> alphabet = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
  const size_t alphabetSize = alphabet.size();

  // Make sure that the key is in the range 0 - 25
  const size_t truncatedKey { key % alphabetSize };

  // Loop over the input text
  char processedChar {'x'};
  for ( const auto& origChar : inputText ) {

    // For each character in the input text, find the corresponding position in
    // the alphabet by using an indexed loop over the alphabet container
    for ( size_t i{0}; i < alphabetSize; ++i ) {

      if ( origChar == alphabet[i] ) {

	// Apply the appropriate shift (depending on whether we're encrypting
	// or decrypting) and determine the new character
	// Can then break out of the loop over the alphabet

	// Make conditional from "encrypt" enum value of CipherMode
	if ( Cipher_Mode == CipherMode::encrypt ) {
	  processedChar = alphabet[ (i + truncatedKey) % alphabetSize ];
	} else {
	  processedChar = alphabet[ (i + alphabetSize - truncatedKey) % alphabetSize ];
	}
	break;
      }
    }

    // Add the new character to the output text
    outputText += processedChar;
  }

  return outputText;
}
