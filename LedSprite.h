class Game;

class LedSprite {
    private:
        Game* display;
        long* image;

    public:
        LedSprite(Game* display, long* img);
        void displayImage();
};
