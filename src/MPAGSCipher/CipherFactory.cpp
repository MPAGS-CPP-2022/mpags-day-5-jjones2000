#include "CipherFactory.hpp"
#include "CipherType.hpp"
#include "Cipher.hpp"
#include "CaesarCipher.hpp"
#include "PlayfairCipher.hpp"
#include "VigenereCipher.hpp"

#include <string>
#include <memory>

std::unique_ptr<Cipher> CipherFactory::makeCipher(const CipherType type,
                                      const std::string& key)
{
    switch (type) {
        case CipherType::Caesar:
            return std::make_unique<CaesarCipher>(key);

        case CipherType::Playfair :
            return std::make_unique<PlayfairCipher>(key);

        case CipherType::Vigenere :
            return std::make_unique<VigenereCipher>(key);
    }
    return std::unique_ptr<Cipher>{};
}
