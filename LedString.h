class Game;

class LedString {
    private:
        int x;
        int y;
        int size;
        const char* str;
        Game* display;
        void draw(const unsigned char* letter, int x, int y);
        void displayLetter(char letter, int x, int y);
        void displayDigit(char digit, int x, int y);

    public:
        LedString(Game* display, const char* str, int size, int x_beg, int y_beg);
        void displayString();
        void displayNumber();
};
