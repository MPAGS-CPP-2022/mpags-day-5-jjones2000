#ifndef CIPHERFACTORY_HPP
#define CIPHERFACTORY_HPP

#include <memory>
#include <string>

#include "Cipher.hpp"
#include "CipherType.hpp"


namespace CipherFactory {
    std::unique_ptr<Cipher> makeCipher(const CipherType type,
                                       const std::string& key);
} // namespace CipherFactory
#endif //CIPHERFACTORY_HPP
