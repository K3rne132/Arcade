class Game;

class LedString {
    private:
        int x;
        int y;
        int size;
        const char* str;
        Game* display;
        void draw(const unsigned char* letter, int x, int y, bool reverse = false);
        void displayLetter(char letter, int x, int y, bool reverse = false);

    public:
        LedString(Game* display, const char* str, int size, int x_beg, int y_beg);
        void displayString();
        void displayReverseString();
};
