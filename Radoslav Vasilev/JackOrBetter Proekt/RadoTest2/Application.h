#ifndef APPLICATION_H
#define APPLICATION_H
#include "RenderableImage.h"
#include "Background.h"
#include "CardButton.h"
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <list>
#include <string>
#include "logic/Deck.h"



class IWidget;
class SDL_Window;
class SDL_Texture;
class SDL_Renderer;
class CardButton;

struct proba
{
  int card;
  bool held;
};


class Application
{
public:
    Application();
    ~Application();
    bool Init();
    bool InitResources();
    bool InitScene();
    bool InitImages();
    void MainLoop();
    void DoSomeLogic();
    void Draw();
    void Deal();
    void StartGame();
    void Play();

    bool getNew_game() const;


private:
    void Deinit();
    SDL_Texture* LoadText(char *resource_name);
    SDL_Texture* LoadTexture(char* resource_name);
    void HandleMouseEvents();
    void IsExit();
    void LoadCardImages();

    SDL_Window* main_window;
    SDL_Renderer* renderer;
    SDL_Texture* background_image;
    TTF_Font* font;
    SDL_Texture* card1;
    SDL_Texture* card2;
    SDL_Texture* card3;
    SDL_Texture* card4 ;
    SDL_Texture* card5;
    SDL_Texture* cardBack;
    SDL_Texture* tempDeadl;
    SDL_Texture* testFont;
    bool need_to_exit;
    bool new_game;
    Background background;
    std::vector<RenderableImage> imag;
    std::vector<std::string>paths;
    std::list<IWidget*> widgets;
    std::vector <proba> prob;
    std::vector<Card> hand;
    CardButton* visibleHand[5];
    SDL_Texture* cardImages[52];
    Deck deck;


};

#endif // APPLICATION_H
