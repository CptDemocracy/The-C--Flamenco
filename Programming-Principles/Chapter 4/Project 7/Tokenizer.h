#ifndef TOKENIZER_H_
#define TOKENIZER_H_

#include <vector>
#include <string>

class Tokenizer {
    private:
        std::vector<std::string> _tokens { };
        std::vector<std::string>::const_iterator& _iter { _tokens.cbegin() };
        bool _isIterationStarted { false };

        bool SplitPredicate(char curr, char last) const;

        enum CharFamily {
            Unknown = 0x0,
            AlNum = 0x1,
            Alpha = 0x2,
            Blank = 0x4,
            Cntrl = 0x8,
            Digit = 0x10,
            Graph = 0x20,
            Lower = 0x40,
            Print = 0x80,
            Punct = 0x100,
            Space = 0x200,
            Upper = 0x400,
            XDigit = 0x800
        };
        CharFamily Tokenizer::GetCharFamily(char c) const;
    protected:
        void AddToken(const std::string& token);
        virtual void VirtualTokenize(const std::string& str);
    public:
        virtual ~Tokenizer(void) = default;
        Tokenizer(void) = default;
        void Tokenize(const std::string& str);
        void ResetIterator(void);
        bool MoveNext(void);
        const std::string& GetCurrent(void) const;
        std::size_t GetTokenCount(void) const;
};

#endif /* TOKENIZER_H_ */