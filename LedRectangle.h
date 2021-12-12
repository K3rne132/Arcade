class Game;

class LedRectangle {
    private:
        int top;
        int bottom;
        int left;
        int right;
        Game* display;
    public:
        LedRectangle(Game* display, int top, int bottom, int left, int right);
        void displayRectangle();
        void hideRectangle();
};