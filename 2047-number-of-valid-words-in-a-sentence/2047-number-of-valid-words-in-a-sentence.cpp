class Solution {
public:
    int countValidWords(string sentence) {
        istringstream iss(sentence);
        string token;
        int validWordCount = 0;
        while (iss >> token) {
            if (isValidWord(token)) {
                validWordCount++;
            }
        }

        return validWordCount;
    }

private:
    bool isValidWord(const string& word) {
        int hyphenCount = 0;
        int punctuationCount = 0;

        for (size_t i = 0; i < word.size(); ++i) {
            char c = word[i];

            if (isdigit(c)) {
                return false;
            }

            if (c == '-') {
                hyphenCount++;
                if (hyphenCount > 1 || i == 0 || i == word.size() - 1 || !islower(word[i - 1]) || !islower(word[i + 1])) {
                    return false;
                }
            }

            if (c == '!' || c == '.' || c == ',') {
                punctuationCount++;
                if (punctuationCount > 1 || i != word.size() - 1) {
                    return false;
                }
            }
        }

        return true;
    }
};