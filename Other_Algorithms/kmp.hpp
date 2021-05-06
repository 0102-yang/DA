#include <cstring>

class Kmp {
public:
    Kmp() = default;

    ~Kmp() {
        delete[] next;
    }

    long operator()(const char *text, const char *pattern) {
        if (!text || !pattern) { return -1; }

        getNextArray(text, strlen(text));

        auto textLength = strlen(text), patternLength = strlen(pattern);
        auto i(0UL), j(0UL);
        while (i < textLength && j < patternLength) {
            if (text[i] == pattern[j]) {
                ++i, ++j;
            } else if (j == 0) {
                ++i;
            } else {
                j = next[j];
            }
        }

        return j == patternLength ? static_cast<long>(i - patternLength) : -1;
    }


private:
    void getNextArray(const char *string, size_t string_length) {
        /* Initialize the next array */
        this->next = new unsigned long[std::max(2UL, string_length)];
        this->next[0] = this->next[1] = 0;

        unsigned long j = 0;
        for (unsigned long i = 2; i < string_length; i++) {
            while (j != 0 && string[j] != string[i - 1]) {
                j = next[j];
            }
            if (string[j] == string[i - 1]) {
                j++;
            }
            next[i] = j;
        }
    }

private:
    unsigned long *next;
};