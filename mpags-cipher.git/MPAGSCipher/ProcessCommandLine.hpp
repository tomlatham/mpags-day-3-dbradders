#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

#include <string>
#include <vector>
#include "CipherMode.hpp"

// Create new struct to hold command line information

struct ProgramSettings {
                          bool helpRequested;
			  bool versionRequested;
			  std::string inputFile;
			  std::string outputFile;
			  std::string cipher_key;
			  CipherMode Cipher_Mode;
};

//Implement as an argument in processCommandLine function

bool processCommandLine(const std::vector<std::string>& args,
			ProgramSettings& programSettings
                        );

#endif // MPAGSCIPHER_PROCESSCOMMANDLINE_HPP 
