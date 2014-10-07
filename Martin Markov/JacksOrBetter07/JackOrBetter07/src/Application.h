#ifndef APPLICATION_H
#define APPLICATION_H
#include "RenderableImage.h"
#include "Background.h"
#include "CardButton.h"
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <vector>
#include <list>
#include <string>
#include "logic/Deck.h"
#include "logic/AutoHold.h"
#include "DisplayButton.h"
#include "StatistcDisplays.h"
#include <SDL2/SDL_timer.h>


class ButtonDeal;
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
    bool InitSounds();
    bool InitScene();  
    bool InitImages();   
    void MainLoop();
    void Draw();
    void Deal();
    void StartGame();
    void Play();
    void SetDisplays(int score);
    bool getNew_game() const;


    SDL_TimerID getCards_flip_delay() const;


    int getCount() const;
    void setCount(int value);

    Mix_Chunk *getSound_effect1() const;


    bool getIn_main() const;
    void setIn_main(bool value);

private:

    void Deinit();
    void DeinitSounds();
    void DeintiTextures();
    void UpdateDisplays();
//    SDL_Texture* LoadText(char *resource_name);
    SDL_Texture* LoadTexture(char* resource_name);
    Mix_Music* LoadMusic(char* resource_name);
    Mix_Chunk* LoadChunk(char* resource_name);
    void HandleMouseEvents();
    void IsExit();
    void LoadCardImages();
    void AddCredits(int score);
    void SaveGameState();
    bool LoadGameState();
    void SetDefaultGameState();
    void StartDraft();
    void StopDraft();
    static Uint32 DraftCardsProc(Uint32 delay,void*application);
    void DraftCards();
    void GetCardsBack();
    void AutoHeld();
    string ConvertStatistcsToTexture(int value);
    AutoHold auto_hold;
    SDL_Window* main_window;
    SDL_Renderer* renderer;
    SDL_Texture* background_image;
    TTF_Font* font;
    SDL_Texture* held_image;
    SDL_Texture* deal;
    SDL_Texture* draw;
    SDL_Texture* help ;
    SDL_Texture* help_clicked;
    SDL_Texture* sound_button_image;
    SDL_Texture* sound_button_clicked;
    SDL_Texture* marker;
    SDL_Texture* table;
    SDL_Texture* cardBack;
    Mix_Music* sound;
    Mix_Chunk* sound_effect1;
    Mix_Chunk* sound_effect2;
    Mix_Chunk* sound_effect3;
    Mix_Chunk* sound_effect4;
    bool need_to_exit;
    bool new_game;
    bool in_main;
    int bet;
    int credits;
    int total_hands;
    int wining_hands;
    int cash_in;
    int cash_out;
    int score;
    int count;
    StatistcDisplays* display_credits;
    StatistcDisplays* last_win;
    StatistcDisplays* total_credits_in;
    StatistcDisplays* total_hands_stats;
    StatistcDisplays* total_win_games;
    StatistcDisplays* total_lost_games;
    StatistcDisplays* total_credits_won;
    Background background;
    Background help_background;
    std::vector<DisplayButton> display_storage;
    std::vector<std::string>paths;
    std::list<IWidget*> widgets;
    std::vector <proba> prob;
    std::vector<Card> hand;
    CardButton* visibleHand[5];
    SDL_Texture* cardImages[52];
    SDL_TimerID cards_flip_delay;
    IWidget* help_button;
    Deck deck;
    ButtonDeal* deal_button;






};

#endif // APPLICATION_H
