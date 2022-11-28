#include "VigenereCipher.hpp"
#include "CaesarCipher.hpp"
#include "Alphabet.hpp"

#include <algorithm>
#include <string>

VigenereCipher::VigenereCipher(const std::string& key)
{
    this->setKey(key);
}

void VigenereCipher::setKey(const std::string& key)
{
  // Store the key
  key_ = key;
  // Make sure the key is uppercase
  std::transform(key_.begin(), key_.end(), key_.begin(), ::toupper);

  // Remove non-alphabet characters
  key_.erase(std::remove_if(key_.begin(), key_.end(),
                            [](char c) { return !std::isalpha(c); }),
             key_.end());
  // Check if the key is empty and replace with default if so
  if (key_.empty())
  {
  key_ = "key"; // TODO Implement warning for no empty key
  }

  // loop over the key
  charLookup_.clear();
  for (const char letter : key_) {
    // Find the letter position in the alphabet
    if (charLookup_.find(letter) != charLookup_.end()) {
      continue;
    }
    const std::size_t index{Alphabet::alphabet.find(letter)};

    // Create a CaesarCipher using this position as a key
    CaesarCipher caesar{index};
    charLookup_.emplace(std::piecewise_construct, std::make_tuple(letter),
                        std::make_tuple(index));
    // Insert a std::pair of the letter and CaesarCipher into the lookup
  }
}

std::string VigenereCipher::applyCipher(const std::string& inputText,
                                        const CipherMode cipherMode) const
{
    // Store sizes of input text and key
    const std::size_t inputSize{inputText.size()};
    const std::size_t keySize{key_.size()};

    std::string outputText{""};
    outputText.reserve(inputSize);

    // For each letter in input:
    for (std::size_t i{0}; i < inputSize; i++){

      // Find the corresponding letter in the key,
      // repeating/truncating as required
      const char keyChar{key_[i % keySize]};

      // Find the Caesar cipher from the lookup
      const CaesarCipher& cipher{charLookup_.at(keyChar)};
      const std::string oldChar{inputText[i]};

      // Run the (de)encryption
      // Add the result to the output
      outputText += cipher.applyCipher(oldChar, cipherMode);
      }
    return outputText;
}
