#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include "Application.h"
#include "RenderableImage.h"
#include "IWidget.h"
#include "WidgetButtonBase.h"
#include <algorithm>
#include "ButtonDeal.h"
#include <sstream>
#include <iostream>

using std::cout;
using std::endl;

Application::Application()
    :main_window(NULL),      
      renderer(NULL),
      background_image(NULL),
      font(NULL),
      need_to_exit(false),
      new_game(true)
{
}

Application::~Application()
{
    Deinit();
}

bool Application::Init()
{
    if ( SDL_Init ( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) )
    {
        return false;
    }

    main_window = SDL_CreateWindow ( "Application", SDL_WINDOWPOS_UNDEFINED,
                                     SDL_WINDOWPOS_UNDEFINED,1024, 768, SDL_WINDOW_SHOWN );
    if ( !main_window )
    {
        return false;
    }

    renderer = SDL_CreateRenderer ( main_window, -1, SDL_RENDERER_ACCELERATED );

    if ( !renderer )
    {
        return false;
    }

    if ( !IMG_Init ( IMG_INIT_PNG ) )
    {
        return false;
    }

    if( TTF_Init() == -1 )
    {
        return false;
    }

    if ( !Mix_Init ( MIX_INIT_MP3 ) )
    {
        return false;
    }


    if ( Mix_OpenAudio ( MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, MIX_MAX_VOLUME ) )
    {
        return false;
    }

    if(!InitResources())
    {
        return false;
    }

    if(!InitScene())
    {
        return false;
    }

    if(!InitImages())
    {
        return false;
    }


    return true;
}

bool Application::InitResources()
{
    font = TTF_OpenFont( "abcd", 28 );
    background_image = LoadTexture("ace.png");
    card1 = LoadTexture("static.png");
    card2 = LoadTexture("ace.png");
    card3 = LoadTexture("K.png");
    card4 = LoadTexture("K1.png");
    card5 = LoadTexture("K2.png");
    testFont = LoadText("GOSHO");
    cardBack= LoadTexture("cards/cardBack.png");
    tempDeadl = LoadTexture("up.png");
    LoadCardImages();

    return true;
}



bool Application::InitScene()
{
    SDL_Rect rect;
   rect.x = 1024/2;
   rect.y = 680;
   rect.w = 50;
   rect.h = 50;
    IWidget* button = new ButtonDeal(card5,card4,card1,rect,this);
     widgets.push_back(button);
    rect.x = 40;
    rect.y = 400;
    rect.w = 150;
    rect.h = 150;
    visibleHand[0] = new CardButton(cardBack,card1,rect,this);
    background.SetImage(background_image);
    widgets.push_back(visibleHand[0]);
    rect.x = 220;
    rect.y = 400;
    rect.w = 150;
    rect.h = 150;
    visibleHand[1] = new CardButton(cardBack,card1,rect,this);
    widgets.push_back(visibleHand[1]);
    rect.x = 420;
    rect.y = 400;
    rect.w = 150;
    rect.h = 150;
    visibleHand[2] = new CardButton(cardBack,card1,rect,this);
    widgets.push_back(visibleHand[2]);
    rect.x = 620;
    rect.y = 400;
    rect.w = 150;
    rect.h = 150;
    visibleHand[3] = new CardButton(cardBack,card1,rect,this);
    widgets.push_back(visibleHand[3]);
    rect.x = 820;
    rect.y = 400;
    rect.w = 150;
    rect.h = 150;
    visibleHand[4] = new CardButton(cardBack,card1,rect,this);
    widgets.push_back(visibleHand[4]);
    //StartGame();
    return true;
}

bool Application::InitImages()
{
    RenderableImage cardA;
    cardA.SetImage(testFont);
    cardA.SetSize(100,100);
    cardA.SetPosition(100,100);
    imag.push_back(cardA);

    return true;
}

void Application::MainLoop()
{
    while(!need_to_exit)
    {
      Uint32 timeout = SDL_GetTicks() + 50;
      while (!SDL_TICKS_PASSED(SDL_GetTicks(), timeout))
      {
      }
      SDL_GetTicks();
      HandleMouseEvents();
      DoSomeLogic();
      Draw();
    }
}


void Application::DoSomeLogic()
{

}

void Application::Draw()
{
    SDL_RenderClear ( renderer );


    background.Draw(renderer);

    for(size_t i = 0; i < imag.size();++i)
    {
        imag[i].Draw(renderer);
    }

    for(std::list<IWidget*>::iterator it= widgets.begin();it!= widgets.end();++it)
    {
        (*it)->Draw(renderer);
    }

    SDL_RenderPresent ( renderer );
}

void Application::Deal()
{
    for(size_t i = 0; i < 5 ; ++i)
    {
        if(!visibleHand[i]->GetHeld())
        {
            Card temp = deck.getCard();
            visibleHand[i]->SetImage(cardImages[temp.getId()]);
            hand[i] = temp;
        }

        visibleHand[i]->HeldReset();
    }
}

void Application::StartGame()
{
    deck.DeckInit();
    deck.shuffle();
    hand.clear();

    for(size_t i=0;i<5 ;++i)
    {
        Card temp = deck.getCard();
        hand.push_back(temp);
        visibleHand[i]->SetImage(cardImages[temp.getId()]);
        visibleHand[i]->HeldReset();
    }

}

void Application::Play()
{
    if(new_game)
    {
        StartGame();
    }
    else
    {
        Deal();
    }

    new_game = !new_game;
}


void Application::Deinit()
{
    Mix_Quit();
    Mix_CloseAudio();
    IMG_Quit();
    SDL_DestroyRenderer ( renderer );
    SDL_DestroyWindow ( main_window );
    SDL_Quit();
}

SDL_Texture *Application::LoadTexture(char *resource_name)
{
    SDL_Surface* surface = IMG_Load(resource_name);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer,surface);

    SDL_FreeSurface(surface);

    return texture;
}

void Application::HandleMouseEvents()
{
    int x;
    int y;
    Uint32 mouse_state;
    IsExit();
    mouse_state = SDL_GetMouseState(&x,&y);

    for(std::list<IWidget*>::iterator it = widgets.begin(); it != widgets.end(); ++it)
    {

        if( (*it)->HandleMouseEvent(mouse_state,x,y))
        {        
            break;
        }
    }
}

void Application::IsExit()
{
    SDL_Event event;

    while ( SDL_PollEvent ( &event ) )
    {
        if ( event.type == SDL_QUIT )
        {
            need_to_exit = true;
        }

    }
}


SDL_Texture *Application::LoadText(char *resource_name)
{
    SDL_Color textColor = { 125, 125, 255, 125 };
    SDL_Surface* textSurface = TTF_RenderText_Solid( font, resource_name, textColor );
    SDL_Texture* texture = SDL_CreateTextureFromSurface( renderer, textSurface );

    SDL_FreeSurface(textSurface);

    return texture;
}



void Application::LoadCardImages()
{

    cardImages[0] = LoadTexture("cards/spat2.png");
    cardImages[1] = LoadTexture("cards/spat3.png");
    cardImages[2] = LoadTexture("cards/spat4.png");
    cardImages[3] = LoadTexture("cards/spat5.png");
    cardImages[4] = LoadTexture("cards/spat6.png");
    cardImages[5] = LoadTexture("cards/spat7.png");
    cardImages[6] = LoadTexture("cards/spat8.png");
    cardImages[7] = LoadTexture("cards/spat9.png");
    cardImages[8] = LoadTexture("cards/spat10.png");
    cardImages[9] = LoadTexture("cards/spatJ.png");
    cardImages[10] = LoadTexture("cards/spatQ.png");
    cardImages[11] = LoadTexture("cards/spatK.png");
    cardImages[12] = LoadTexture("cards/spatA.png");
    cardImages[13] = LoadTexture("cards/karo2.png");
    cardImages[14] = LoadTexture("cards/karo3.png");
    cardImages[15] = LoadTexture("cards/karo4.png");
    cardImages[16] = LoadTexture("cards/karo5.png");
    cardImages[17] = LoadTexture("cards/karo6.png");
    cardImages[18] = LoadTexture("cards/karo7.png");
    cardImages[19] = LoadTexture("cards/karo8.png");
    cardImages[20] = LoadTexture("cards/karo9.png");
    cardImages[21] = LoadTexture("cards/karo10.png");
    cardImages[22] = LoadTexture("cards/karoJ.png");
    cardImages[23] = LoadTexture("cards/karoQ.png");
    cardImages[24] = LoadTexture("cards/karoK.png");
    cardImages[25] = LoadTexture("cards/karoA.png");
    cardImages[26] = LoadTexture("cards/kupa2.png");
    cardImages[27] = LoadTexture("cards/kupa3.png");
    cardImages[28] = LoadTexture("cards/kupa4.png");
    cardImages[29] = LoadTexture("cards/kupa5.png");
    cardImages[30] = LoadTexture("cards/kupa6.png");
    cardImages[31] = LoadTexture("cards/kupa7.png");
    cardImages[32] = LoadTexture("cards/kupa8.png");
    cardImages[33] = LoadTexture("cards/kupa9.png");
    cardImages[34] = LoadTexture("cards/kupa10.png");
    cardImages[35] = LoadTexture("cards/kupaJ.png");
    cardImages[36] = LoadTexture("cards/kupaQ.png");
    cardImages[37] = LoadTexture("cards/kupaK.png");
    cardImages[38] = LoadTexture("cards/kupaA.png");
    cardImages[39] = LoadTexture("cards/pika2.png");
    cardImages[40] = LoadTexture("cards/pika3.png");
    cardImages[41] = LoadTexture("cards/pika4.png");
    cardImages[42] = LoadTexture("cards/pika5.png");
    cardImages[43] = LoadTexture("cards/pika6.png");
    cardImages[44] = LoadTexture("cards/pika7.png");
    cardImages[45] = LoadTexture("cards/pika8.png");
    cardImages[46] = LoadTexture("cards/pika9.png");
    cardImages[47] = LoadTexture("cards/pika10.png");
    cardImages[48] = LoadTexture("cards/pikaJ.png");
    cardImages[49] = LoadTexture("cards/pikaQ.png");
    cardImages[50] = LoadTexture("cards/pikaK.png");
    cardImages[51] = LoadTexture("cards/pikaA.png");


}
bool Application::getNew_game() const
{
    return new_game;
}



