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
          const std::string& inputText, const std::string& outputText)

TEST_CASE("Playfair Cipher encryption", "[playfair]") {
  PlayfairCipher cc{"hello"};
  REQUIRE( cc.applyCipher("BOBISSOMESORTOFJUNIORCOMPLEXXENOPHONEONEZEROTHING", CipherMode::Encrypt) == "FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA");
}

TEST_CASE("Playfair Cipher decryption", "[playfair]") {
  PlayfairCipher cc{"hello"};
  REQUIRE( cc.applyCipher("FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA", CipherMode::Decrypt) == "BOBISXSOMESORTOFIUNIORCOMPLEXQXENOPHONEONEZEROTHINGZ");
}
