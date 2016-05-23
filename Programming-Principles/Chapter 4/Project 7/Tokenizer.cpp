#include <cctype>

#include "Tokenizer.h"

void Tokenizer::AddToken(const std::string& token) {
    _tokens.push_back(token);
}

void Tokenizer::Tokenize(const std::string& str) {
    _tokens.clear();
    VirtualTokenize(str);
    ResetIterator();
}

Tokenizer::CharFamily Tokenizer::GetCharFamily(char c) const {
    if (c >= 0x00 && c <= 0x08) {
        return static_cast<Tokenizer::CharFamily>(Cntrl);
    }
    else if (c == 0x09) {
        return static_cast<Tokenizer::CharFamily>(Cntrl | Blank | Space);
    }
    else if (c >= 0x0A && c <= 0x0D) {
        return static_cast<Tokenizer::CharFamily>(Cntrl | Space);
    }
    else if (c >= 0x0E && c <= 0x1F) {
        return static_cast<Tokenizer::CharFamily>(Cntrl);
    }
    else if (c == 0x20) {
        return static_cast<Tokenizer::CharFamily>(Blank | Space | Print);
    }
    else if (c >= 0x21 && c <= 0x2F) {
        return static_cast<Tokenizer::CharFamily>(Punct | Graph | Print);
    }
    else if (c >= 0x30 && c <= 0x39) { 
        return static_cast<Tokenizer::CharFamily>(Digit | XDigit | AlNum | Graph | Print);
    }
    else if (c >= 0x3a && c <= 0x40) {
        return static_cast<Tokenizer::CharFamily>(Punct | Graph | Print);
    }
    else if (c >= 0x41 && c <= 0x46) {
        return static_cast<Tokenizer::CharFamily>(Upper | Alpha | XDigit | AlNum | Graph | Print);
    }
    else if (c >= 0x47 && c <= 0x5A) {
        return static_cast<Tokenizer::CharFamily>(Upper | Alpha | AlNum | Graph | Print);
    }
    else if (c >= 0x5B && c <= 0x60) {
        return static_cast<Tokenizer::CharFamily>(Punct | Graph | Print);
    }
    else if (c >= 0x61 && c <= 0x66) {
        return static_cast<Tokenizer::CharFamily>(Lower | Alpha | XDigit | AlNum | Graph | Print);
    }
    else if (c >= 0x67 && c <= 0x7A) {
        return static_cast<Tokenizer::CharFamily>(Lower | Alpha | AlNum | Graph | Print);
    }
    else if (c >= 0x7B && c <= 0x7E) {
        return static_cast<Tokenizer::CharFamily>(Punct | Graph | Print);
    }
    else if (c == 0x7F) {
        return static_cast<Tokenizer::CharFamily>(Cntrl);
    }
    return static_cast<Tokenizer::CharFamily>(Unknown);
}

bool Tokenizer::SplitPredicate(char curr, char last) const {
    enum CharFamily charFam1 = GetCharFamily(curr);
    enum CharFamily charFam2 = GetCharFamily(last);

    /* Disable case bits to provide case 
     * insensitive comparison.
     *
     * Disable the XDigit bits to avoid
     * tokenization upon encountering
     * xdigit-char-types.
     */
    charFam1 = static_cast<Tokenizer::CharFamily>(charFam1 & (~Lower) & (~Upper) & (~XDigit));
    charFam2 = static_cast<Tokenizer::CharFamily>(charFam2 & (~Lower) & (~Upper) & (~XDigit));

    if (charFam1 == charFam2) {
        return false;
    }
    return true;
}

void Tokenizer::VirtualTokenize(const std::string& str) {   
    std::size_t strLen { str.length() };
    if (strLen > 1U) 
    {
        std::string token { };
        char c { '\0' };

        for (std::size_t i { 0U }; i < strLen - 1U; ++i)
        {        
            c = str.at(i);    
            if (!std::isspace(c)) token += c;

            if (token.length() > 0U && SplitPredicate(str.at(i), str.at(i + 1U))) {                
                AddToken(token);
                token.clear();
            }
        }
        /* The last character will be omitted by the loop.
         */
        c = str.at(strLen - 1U);
        if (!std::isspace(c)) token += c;

        if (token.length() > 0U) {
            AddToken(token);
            token.clear();
        }

    } else {
        AddToken(str);
    }
}

void Tokenizer::ResetIterator(void) {
    _isIterationStarted = false;
    _iter = _tokens.cbegin();
}

bool Tokenizer::MoveNext(void) {
    if (_iter == _tokens.cend()) {
        return false;
    }
    if (_isIterationStarted) {
        ++_iter;
    } else {
        _isIterationStarted = true;
    }
    return true;
}

const std::string& Tokenizer::GetCurrent(void) const {
    if (!_isIterationStarted) {
        throw std::runtime_error { std::string { "Cannot retrieve the current token. Iteration not started." } };
    }
    if (_tokens.size() == 0U) {
        throw std::runtime_error { std::string { "Tokenizer is empty." } };
    }
    return *_iter;
}

std::size_t Tokenizer::GetTokenCount(void) const {
    return _tokens.size();
}
