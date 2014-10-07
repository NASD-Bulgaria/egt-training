#include "Application.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "RenderableImage.h"
#include "IWidget.h"
#include "WidgetButtonBase.h"
#include "SoundButton.h"
#include <algorithm>
#include "ButtonDeal.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include "HelpButton.h"


using std::cout;
using std::endl;

Application::Application()
    :main_window(NULL),      
      renderer(NULL),
      background_image(NULL),
      font(NULL),
      need_to_exit(false),
      new_game(true),
      in_main(true),
      count(0),
      cards_flip_delay(0)



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


    if ( Mix_OpenAudio ( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) )
    {
        return false;
    }

    if(!InitResources())
    {
        return false;
    }
    if(!InitSounds())
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

    if(!LoadGameState())
    {
        SetDefaultGameState();
    }

    return true;
}

bool Application::InitResources()
{
    font = TTF_OpenFont( "123.ttf", 24 );
    background_image = LoadTexture("background.png");
    held_image = LoadTexture("held.png");
    deal = LoadTexture("DEAL.png");
    draw = LoadTexture("DRAW.png");
    help = LoadTexture("Help.png");
    help_clicked = LoadTexture("Help Clicked.png");
    sound_button_image = LoadTexture("Sound.png");
    sound_button_clicked= LoadTexture("Sound Clicked.png");
    marker= LoadTexture("WinMark.png");
    table= LoadTexture("Table.png");
    cardBack= LoadTexture("cards/cardBack.png");
    LoadCardImages();

    return true;
}

bool Application::InitSounds()
{
    sound = LoadMusic("Azis.mp3");
    sound_effect1= LoadChunk("1.wav");
    if(sound_effect1 == NULL) {
        fprintf(stderr, "Unable to load WAV file: %s\n", Mix_GetError());
    }
//    sound_effect2;
//    sound_effect3;
//    sound_effect4;

    return true;
}


bool Application::InitScene()
{
    SDL_Rect rect;
    rect.x = 422;
    rect.y = 597;
    rect.w = 180;
    rect.h = 106;
    deal_button = new ButtonDeal(deal,draw,draw,rect,this);
    widgets.push_back(deal_button);
    rect.x=242;
    rect.y= 640;
    rect.w=40;
    rect.h=20;
    display_credits = new StatistcDisplays(rect);
    widgets.push_back(display_credits);
    rect.x=730;
    rect.y=640;
//    rect.w=60;
//    rect.h=20;
    last_win = new StatistcDisplays(rect);
    widgets.push_back(last_win);
    rect.x=820;
    rect.y=157;
//    rect.w=60;
//    rect.h=20;
    total_hands_stats = new StatistcDisplays(rect);
    widgets.push_back(total_hands_stats);
    rect.x=820;
    rect.y=197;
//    rect.w=60;
//    rect.h=20;
    total_win_games = new StatistcDisplays(rect);
    widgets.push_back(total_win_games);
    rect.x=820;
    rect.y=237;
//    rect.w=60;
//    rect.h=20;
    total_lost_games = new StatistcDisplays(rect);
    widgets.push_back(total_lost_games);
    rect.x=820;
    rect.y=277;
//    rect.w=60;
//    rect.h=20;
    total_credits_in = new StatistcDisplays(rect);
    widgets.push_back(total_credits_in);
    rect.x=820;
    rect.y=317;
//    rect.w=60;
//    rect.h=20;
    total_credits_won = new StatistcDisplays(rect);
    widgets.push_back(total_credits_won);
    rect.x = 103;
    rect.y = 383;
    rect.w = 145;
    rect.h = 220;
    visibleHand[0] = new CardButton(cardBack,held_image,rect,this,sound_effect1);
    background.SetImage(background_image);
    help_background.SetImage(deal);
    widgets.push_back(visibleHand[0]);
    rect.x = 274;
    rect.y = 383;
    rect.w = 145;
    rect.h = 220;
    visibleHand[1] = new CardButton(cardBack,held_image,rect,this,sound_effect1);
    widgets.push_back(visibleHand[1]);
    rect.x = 445;
    rect.y = 383;
    rect.w = 145;
    rect.h = 220;
    visibleHand[2] = new CardButton(cardBack,held_image,rect,this,sound_effect1);
    widgets.push_back(visibleHand[2]);
    rect.x = 616;
    rect.y = 383;
    rect.w = 145;
    rect.h = 220;
    visibleHand[3] = new CardButton(cardBack,held_image,rect,this,sound_effect1);
    widgets.push_back(visibleHand[3]);
    rect.x = 787;
    rect.y = 383;
    rect.w = 145;
    rect.h = 220;
    visibleHand[4] = new CardButton(cardBack,held_image,rect,this,sound_effect1);
    widgets.push_back(visibleHand[4]);   
    rect.x= 458;
    rect.y=227;
    rect.w=108;
    rect.h=39;
    IWidget* sound_button = new SoundButton(sound_button_image,sound_button_image,sound_button_clicked,rect);
    widgets.push_back(sound_button);
    rect.x=458;
    rect.y=274;
    rect.w = 108;
    rect.h = 39;
    help_button = new HelpButton(help,help_clicked,help_clicked,rect,this);
    rect.h=768;
    rect.w=1024;
    rect.x=0;
    rect.y=0;
    DisplayButton display(marker,table,rect,1);
    display_storage.push_back(display);
    return true;
}

bool Application::InitImages()
{


    return true;
}

void Application::MainLoop()
{
    Mix_PlayMusic(sound,-1);
    while(!need_to_exit)
    {
      Uint32 timeout = SDL_GetTicks() + 50;
      while (!SDL_TICKS_PASSED(SDL_GetTicks(), timeout))
      {
      }
      SDL_GetTicks();
      HandleMouseEvents();
      Draw();
    }
}

void Application::Draw()
{
    SDL_RenderClear ( renderer );


    if(in_main)
    {
        background.Draw(renderer);

        for(size_t i = 0; i < display_storage.size();++i)
        {
            display_storage[i].Draw(renderer);
        }

        for(std::list<IWidget*>::iterator it= widgets.begin();it!= widgets.end();++it)
        {
            (*it)->Draw(renderer);
        }
    }
    else
    {
        help_background.Draw(renderer);
    }

    help_button->Draw(renderer);

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
     score = auto_hold.getScore(hand);

     if(score > 0)
     {
        wining_hands ++;
        cash_out += score;
     }

     SetDisplays(score);
     AddCredits(score);
}

void Application::StartGame()
{
    deck.DeckInit();
    deck.shuffle();
    hand.clear();




    total_hands++;

    for(size_t i=0;i<5;++i)
    {
        Card temp = deck.getCard();
        hand.push_back(temp);
    }


    StartDraft();
}

void Application::Play()
{
    if(new_game)
    {
        if(credits>=bet)
        {

            AddCredits(-bet);
            StartGame();
            new_game = !new_game;
        }
//        else
//        {
//            //TODO
//        }
    }
    else
    {

        Deal();
        new_game = !new_game;
    }
    UpdateDisplays();
    SaveGameState();
}

void Application::SetDisplays(int score)
{
    for(size_t i = 0; i < display_storage.size();++i)
    {
        display_storage[i].SetCurrentScore(score);
    }
}


void Application::Deinit()
{
    Mix_Quit();
    Mix_CloseAudio();
    IMG_Quit();
    SDL_DestroyRenderer ( renderer );
    SDL_DestroyWindow ( main_window );
    SDL_Quit();
    DeinitSounds();
    DeintiTextures();
}

SDL_Texture *Application::LoadTexture(char *resource_name)
{
    SDL_Surface* surface = IMG_Load(resource_name);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer,surface);

    SDL_FreeSurface(surface);

    return texture;
}

Mix_Music *Application::LoadMusic(char *resource_name)
{
    return Mix_LoadMUS(resource_name);
}

Mix_Chunk *Application::LoadChunk(char *resource_name)
{
     return Mix_LoadWAV(resource_name);

}

void Application::HandleMouseEvents()
{
    int x;
    int y;
    Uint32 mouse_state;
    IsExit();
    mouse_state = SDL_GetMouseState(&x,&y);

    if(in_main)
    {
        for(std::list<IWidget*>::iterator it = widgets.begin(); it != widgets.end(); ++it)
        {

            if( (*it)->HandleMouseEvent(mouse_state,x,y))
            {
                break;
            }
        }
    }
    help_button->HandleMouseEvent(mouse_state,x,y);
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


//SDL_Texture *Application::LoadText(char *resource_name)
//{
//    SDL_Color textColor = { 125, 125, 255, 125 };
//    SDL_Surface* textSurface = TTF_RenderText_Solid( font, resource_name, textColor );
//    SDL_Texture* texture = SDL_CreateTextureFromSurface( renderer, textSurface );

//    SDL_FreeSurface(textSurface);

//    return texture;
//}



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

void Application::SaveGameState()
{

    ofstream file("recovery.dat", ios::out | ios::binary);
    if(file.is_open())
    {
        deck.save(file);
        int* temp = new int[5];
        bool* tempHold = new bool[5];
        for(int i=0; i<5; i++)
        {
            temp[i] = hand[i].getId();
            tempHold[i] = visibleHand[i]->GetHeld();
            cout<<tempHold[i]<<endl;
        }

        file.write(reinterpret_cast<char*>(temp),sizeof(int)*5);
        file.write(reinterpret_cast<char*>(tempHold),sizeof(bool)*5);

        delete [] temp;
        delete [] tempHold;
        file.write(reinterpret_cast<char*>(&new_game),sizeof(bool));
        file.write(reinterpret_cast<char*>(&credits),sizeof(int));
        file.write(reinterpret_cast<char*>(&total_hands),sizeof(int));
        file.write(reinterpret_cast<char*>(&wining_hands),sizeof(int));
        file.write(reinterpret_cast<char*>(&cash_in),sizeof(int));
        file.write(reinterpret_cast<char*>(&cash_out),sizeof(int));
        file.write(reinterpret_cast<char*>(&bet),sizeof(int));
        file.write(reinterpret_cast<char*>(&score),sizeof(int));

        file.close();
    }
    else
        cout<<"Can't open file."<<endl;
}

bool Application::LoadGameState()
{
   std::ifstream file("recovery.dat", std::ios::in | std::ios::binary);
    if(file.is_open())
    {
        deck.load(file);
        int* temp = new int[5];
        bool* tempHold = new bool[5];
        file.read(reinterpret_cast<char*>(temp),sizeof(int)*5);
        file.read(reinterpret_cast<char*>(tempHold),sizeof(bool)*5);
        file.read(reinterpret_cast<char*>(&new_game),sizeof(bool));
        file.read(reinterpret_cast<char*>(&credits),sizeof(int));
        file.read(reinterpret_cast<char*>(&total_hands),sizeof(int));
        file.read(reinterpret_cast<char*>(&wining_hands),sizeof(int));
        file.read(reinterpret_cast<char*>(&cash_in),sizeof(int));
        file.read(reinterpret_cast<char*>(&cash_out),sizeof(int));
        file.read(reinterpret_cast<char*>(&bet),sizeof(int));
        file.read(reinterpret_cast<char*>(&score),sizeof(int));
        hand.resize(5);

        deal_button->SetButtonState(new_game);

        if(!credits)
        {
            credits=10;
            cash_in+=credits;
            deck.DeckInit();
            deck.shuffle();
            hand.clear();
           for(size_t i =0;i < 5;++i)
           {
               visibleHand[i]->HeldReset();
               visibleHand[i]->setDefault_image(cardBack);
           }

        }
        else
        {
            for(int i=0; i<5; i++)
            {

                hand[i].setId(temp[i]);
                visibleHand[i]->SetImage(cardImages[ temp[i]]);
                visibleHand[i]->HeldReset();
                cout<<"nad ifa " << new_game<<" "<<tempHold[i]<<endl;
                if(tempHold[i]&& !new_game)
                {
                    cout<<tempHold[i]<<endl;
                    visibleHand[i]->AutoHeldSet();
                }
            }


                display_storage[0].SetCurrentScore(score);

        }
        delete [] temp;
        delete [] tempHold;


        file.close();
        UpdateDisplays();
        return true;
    }
    else
    {
        cout<<"Can't open file."<<endl;
    }

    return false;
}

void Application::SetDefaultGameState()
{
    credits = 10;
    bet = 1;
    total_hands = 0;
    wining_hands = 0;
    cash_in = 10;
    cash_out = 0;
    score=0;
    UpdateDisplays();
}

void Application::StartDraft()
{
    count =0;
    cards_flip_delay=SDL_AddTimer(200,&Application::DraftCardsProc,this);
    GetCardsBack();
}

void Application::StopDraft()
{

    SDL_RemoveTimer(cards_flip_delay);
    cards_flip_delay=0;
    AutoHeld();
    SaveGameState();
}

Uint32 Application::DraftCardsProc(Uint32 delay, void *application)
{
    Application* app = reinterpret_cast<Application*>(application);
    app->DraftCards();

    return delay;
}

void Application::DraftCards()
{
    if(count<5)
    {
        Mix_PlayChannel( -1, getSound_effect1(), 0 );

       visibleHand[count]->SetImage(cardImages[hand[count].getId()]);
       ++count;
    }

    else
    {
        StopDraft();
    }
}

void Application::GetCardsBack()
{
    for(size_t i =0;i < 5;++i)
    {
        visibleHand[i]->HeldReset();
        visibleHand[i]->setDefault_image(cardBack);
    }

}

void Application::AutoHeld()
{
    std::vector<bool> check(5,1);

    auto_hold.getMarkup(hand,check);
    int score = auto_hold.getScore(hand);
    SetDisplays(score);
    for(size_t i =0; i < check.size();++i)
    {

       if(check[i])
       {

           visibleHand[i]->AutoHeldSet();
       }

    }
}

string Application::ConvertStatistcsToTexture(int value)
{
    stringstream temp;
    temp<<value;
    return temp.str();
}
bool Application::getIn_main() const
{
    return in_main;
}

void Application::setIn_main(bool value)
{
    in_main = value;
}

Mix_Chunk *Application::getSound_effect1() const
{
    return sound_effect1;
}


int Application::getCount() const
{
    return count;
}

void Application::setCount(int value)
{
    count = value;
}


SDL_TimerID Application::getCards_flip_delay() const
{
    return cards_flip_delay;
}


void Application::AddCredits(int score)
{
    credits+=score;
}
bool Application::getNew_game() const
{
    return new_game;
}

void Application::DeinitSounds()
{
    Mix_FreeChunk( sound_effect1 );
    Mix_FreeChunk( sound_effect2 );
    Mix_FreeChunk( sound_effect3 );
    Mix_FreeChunk( sound_effect4 );

    Mix_FreeMusic( sound );
    sound_effect1 = NULL;
    sound_effect1= NULL;
    sound_effect1= NULL;
    sound_effect1= NULL;
    sound= NULL;

}

void Application::DeintiTextures()
{
   SDL_DestroyTexture(background_image);
   SDL_DestroyTexture(cardBack);
   TTF_CloseFont( font );

   background_image = NULL;
   font= NULL;
   cardBack= NULL;

}

void Application::UpdateDisplays()
{

  display_credits->UpdateText(credits,font,renderer);
  last_win->UpdateText(score,font,renderer);
  total_credits_in->UpdateText(cash_in,font,renderer);
  total_hands_stats->UpdateText(total_hands,font,renderer);
  total_win_games->UpdateText(wining_hands,font,renderer);
  total_lost_games->UpdateText((total_hands-wining_hands),font,renderer);
  total_credits_won->UpdateText(cash_out,font,renderer);
}



