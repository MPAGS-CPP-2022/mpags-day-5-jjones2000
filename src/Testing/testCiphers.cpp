//! Unit Tests for MPAGSCipher Cipher abstract base class
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "CaesarCipher.hpp"
#include "PlayfairCipher.hpp"
#include "VigenereCipher.hpp"
#include "Cipher.hpp"
#include "CipherMode.hpp"

#include <string>

bool testCipher( const Cipher& cipher, const CipherMode mode,
          const std::string& inputText, const std::string& outputText) {
  return cipher.applyCipher(inputText, mode) == outputText;
}

TEST_CASE("all Cipher encryption", "[ciphers]") {
  std::string key{"key"};
  std::string input{"hello"};

  PlayfairCipher pc{key};
  CaesarCipher cc{1}; // takes int key
  VigenereCipher vc{key};

  std::string ccOut{"IFMMP"};
  std::string pcOut{"DBNVMI"};
  std::string vcOut{"RIJVS"};

  REQUIRE( testCipher(pc, CipherMode::Encrypt, input, pcOut) );
  REQUIRE( testCipher(vc, CipherMode::Encrypt, input, vcOut) );
  REQUIRE( testCipher(cc, CipherMode::Encrypt, input, ccOut) );
}
