class Solution {
public:
    bool isValid(string word) {
        if (word.length() < 3) return false;
        
        bool hasVowel = false;
        bool hasConsonant = false;
        
        for (char c : word) {
            if (!isalnum(c)) return false; // check if character is not a letter or digit

            if (isalpha(c)) { // check only letters for vowels/consonants
                char lower_c = tolower(c);
                if (lower_c == 'a' || lower_c == 'e' || lower_c == 'i' || lower_c == 'o' || lower_c == 'u') {
                    hasVowel = true;
                } else {
                    hasConsonant = true;
                }
            }
        }
        
        return hasVowel && hasConsonant;
    }
};
