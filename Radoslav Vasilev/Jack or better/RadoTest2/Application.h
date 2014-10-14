#ifndef APPLICATION_H
#define APPLICATION_H
#include "Background.h"
#include "CardButton.h"
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <vector>
#include <list>
#include <string>
#include "logic/Deck.h"
#include "logic/AutoHold.h"
#include "WinDisplay.h"
#include "StatistcDisplays.h"
#include <SDL2/SDL_timer.h>
#include "Logo.h"


class ButtonDeal;
class IWidget;
class SDL_Window;
class SDL_Texture;
class SDL_Renderer;
class CardButton;
class Logo;

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
    bool LoadLogo();
    bool InitSounds();
    bool InitScene();    
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
    SDL_Texture* LoadTexture(string resource_name);
    Mix_Music* LoadMusic(string resource_name);
    Mix_Chunk* LoadChunk(string resource_name);
    void HandleMouseEvents();
    void IsExit();
    bool LoadCardImages();
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

    AutoHold auto_hold;
    SDL_Window* main_window;
    SDL_Renderer* renderer;
    TTF_Font* font;
    SDL_Texture* background_image; 
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
    SDL_Texture* rules;
    Mix_Music* sound;
    Mix_Chunk* sound_effect_select;
    Mix_Chunk* sound_effect_lose;
    Mix_Chunk* sound_effect_win;
    Mix_Chunk* sound_effect_card_deal;
    Mix_Chunk* sound_effect_button_click;
    Mix_Chunk* sound_effect_deal_sound;

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

    std::vector<WinDisplay> display_storage;
    std::list<IWidget*> widgets;
    std::vector<Card> hand;   
    CardButton* visibleHand[5];
    SDL_Texture* cardImages[52];

    SDL_TimerID cards_flip_delay;
    IWidget* help_button;
    Deck deck;
    ButtonDeal* deal_button;

    SDL_Texture* logo[5];
    Logo *logo_display;

};

#endif // APPLICATION_H
