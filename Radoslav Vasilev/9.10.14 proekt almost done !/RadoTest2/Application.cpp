#include "Application.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
//#include "RenderableImage.h"
#include "IWidget.h"
#include "WidgetButtonBase.h"
#include "SoundButton.h"
#include <algorithm>
#include "ButtonDeal.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include "HelpButton.h"

Application::Application():
      main_window(NULL),
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


    if ( Mix_OpenAudio ( MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, MIX_MAX_VOLUME ) )
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

    if(!LoadGameState())
    {
        SetDefaultGameState();
    }

    return true;
}

bool Application::InitResources()
{
    font = TTF_OpenFont( "23.ttf", 24 );
    background_image = LoadTexture("images/background.png");
    if(!background_image)
        return false;
    held_image = LoadTexture("images/heldFinal.png");
    if(!held_image)
        return false;
    deal = LoadTexture("images/DEAL.png");
    if(!deal)
        return false;
    draw = LoadTexture("images/DRAW.png");
    if(!draw)
        return false;
    help = LoadTexture("images/Help.png");
    if(!help)
        return false;
    help_clicked = LoadTexture("images/Help Clicked.png");
    if(!help_clicked)
        return false;
    sound_button_image = LoadTexture("images/Sound.png");
    if(!sound_button_image)
        return false;
    sound_button_clicked= LoadTexture("images/Sound Clicked.png");
    if(!sound_button_clicked)
        return false;
    marker= LoadTexture("images/WinMark.png");
    if(!marker)
        return false;
    table= LoadTexture("images/Table.png");
    if(!table)
        return false;
    cardBack= LoadTexture("images/cards/cardBack.png");
    if(!cardBack)
        return false;
    rules=LoadTexture("images/rulesP.png");
    if(!rules)
        return false;
    if(!LoadCardImages())
    {
        return false;
    }

    return true;
}

bool Application::InitSounds()
{
    sound = LoadMusic("sounds/music_background.mp3");
    if(sound == NULL)
    {
        //fprintf(stderr, "Unable to load WAV file: %s\n", Mix_GetError());
        return false;
    }
    sound_effect_select= LoadChunk("sounds/card_select.wav");
    if(sound_effect_select == NULL)
    {
        //fprintf(stderr, "Unable to load WAV file: %s\n", Mix_GetError());
        return false;
    }
    sound_effect_lose = LoadChunk("sounds/lose.wav");
    if(sound_effect_lose == NULL)
    {
       // fprintf(stderr, "Unable to load WAV file: %s\n", Mix_GetError());
        return false;
    }

    sound_effect_win= LoadChunk("sounds/win.wav");
    if(sound_effect_win == NULL)
    {
       // fprintf(stderr, "Unable to load WAV file: %s\n", Mix_GetError());
        return false;
    }

    sound_effect_card_deal=LoadChunk("sounds/deal card.wav");
    if(sound_effect_card_deal == NULL)
    {
        //fprintf(stderr, "Unable to load WAV file: %s\n", Mix_GetError());
        return false;
    }

    sound_effect_button_click=LoadChunk("sounds/button_click.wav");
    if(sound_effect_button_click == NULL)
    {
        //fprintf(stderr, "Unable to load WAV file: %s\n", Mix_GetError());
        return false;
    }
    sound_effect_deal_sound=LoadChunk("sounds/deal sound.wav");
    if(sound_effect_deal_sound == NULL)
    {
        //fprintf(stderr, "Unable to load WAV file: %s\n", Mix_GetError());
        return false;
    }

    return true;
}


bool Application::InitScene()
{
    SDL_Rect rect;
    rect.x = 422;
    rect.y = 597;
    rect.w = 180;
    rect.h = 106;
    deal_button = new ButtonDeal(deal,draw,draw,rect,this,sound_effect_deal_sound);
    widgets.push_back(deal_button);
    rect.x=242;
    rect.y= 640;
    rect.w=40;
    rect.h=20;
    display_credits = new StatistcDisplays(rect);
    widgets.push_back(display_credits);
    rect.x=730;
    rect.y=640;
    last_win = new StatistcDisplays(rect);
    widgets.push_back(last_win);
    rect.x=820;
    rect.y=157;
    total_hands_stats = new StatistcDisplays(rect);
    widgets.push_back(total_hands_stats);
    rect.x=820;
    rect.y=197;
    total_win_games = new StatistcDisplays(rect);
    widgets.push_back(total_win_games);
    rect.x=820;
    rect.y=237;
    total_lost_games = new StatistcDisplays(rect);
    widgets.push_back(total_lost_games);
    rect.x=820;
    rect.y=277;
    total_credits_in = new StatistcDisplays(rect);
    widgets.push_back(total_credits_in);
    rect.x=820;
    rect.y=317;
    total_credits_won = new StatistcDisplays(rect);
    widgets.push_back(total_credits_won);
    background.SetImage(background_image);
    help_background.SetImage(rules );
    rect.x = 103;
    rect.y = 383;
    rect.w = 145;
    rect.h = 220;
    visibleHand[0] = new CardButton(cardBack,held_image,rect,this,sound_effect_select);
    widgets.push_back(visibleHand[0]);
    rect.x = 274;
    rect.y = 383;
    rect.w = 145;
    rect.h = 220;
    visibleHand[1] = new CardButton(cardBack,held_image,rect,this,sound_effect_select);
    widgets.push_back(visibleHand[1]);
    rect.x = 445;
    rect.y = 383;
    rect.w = 145;
    rect.h = 220;
    visibleHand[2] = new CardButton(cardBack,held_image,rect,this,sound_effect_select);
    widgets.push_back(visibleHand[2]);
    rect.x = 616;
    rect.y = 383;
    rect.w = 145;
    rect.h = 220;
    visibleHand[3] = new CardButton(cardBack,held_image,rect,this,sound_effect_select);
    widgets.push_back(visibleHand[3]);
    rect.x = 787;
    rect.y = 383;
    rect.w = 145;
    rect.h = 220;
    visibleHand[4] = new CardButton(cardBack,held_image,rect,this,sound_effect_select);
    widgets.push_back(visibleHand[4]);   
    rect.x= 458;
    rect.y=227;
    rect.w=108;
    rect.h=39;
    IWidget* sound_button = new SoundButton(sound_button_image,sound_button_image,sound_button_clicked,rect,sound_effect_button_click);
    widgets.push_back(sound_button);
    rect.x=458;
    rect.y=274;
    rect.w = 108;
    rect.h = 39;
    help_button = new HelpButton(help,help_clicked,help_clicked,rect,this,sound_effect_button_click);
    rect.h=768;
    rect.w=1024;
    rect.x=0;
    rect.y=0;
    DisplayButton display(marker,table,rect,1);
    display_storage.push_back(display);
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
        Mix_PlayChannel( -1, sound_effect_win, 0 );
     }
     else
     {
         Mix_PlayChannel( -1, sound_effect_lose, 0 );
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


bool Application::LoadCardImages()
{

    cardImages[0] = LoadTexture("images/cards/spat2.png");
    if(!cardImages[0])
        return false;
    cardImages[1] = LoadTexture("images/cards/spat3.png");
    if(!cardImages[1])
        return false;
    cardImages[2] = LoadTexture("images/cards/spat4.png");
    if(!cardImages[2])
        return false;
    cardImages[3] = LoadTexture("images/cards/spat5.png");
    if(!cardImages[3])
        return false;
    cardImages[4] = LoadTexture("images/cards/spat6.png");
    if(!cardImages[4])
        return false;
    cardImages[5] = LoadTexture("images/cards/spat7.png");
    if(!cardImages[5])
        return false;
    cardImages[6] = LoadTexture("images/cards/spat8.png");
    if(!cardImages[6])
        return false;
    cardImages[7] = LoadTexture("images/cards/spat9.png");
    if(!cardImages[7])
        return false;
    cardImages[8] = LoadTexture("images/cards/spat10.png");
    if(!cardImages[8])
        return false;
    cardImages[9] = LoadTexture("images/cards/spatJ.png");
    if(!cardImages[9])
        return false;
    cardImages[10] = LoadTexture("images/cards/spatQ.png");
    if(!cardImages[10])
        return false;
    cardImages[11] = LoadTexture("images/cards/spatK.png");
    if(!cardImages[11])
        return false;
    cardImages[12] = LoadTexture("images/cards/spatA.png");
    if(!cardImages[12])
        return false;
    cardImages[13] = LoadTexture("images/cards/karo2.png");
    if(!cardImages[13])
        return false;
    cardImages[14] = LoadTexture("images/cards/karo3.png");
    if(!cardImages[14])
        return false;
    cardImages[15] = LoadTexture("images/cards/karo4.png");
    if(!cardImages[15])
        return false;
    cardImages[16] = LoadTexture("images/cards/karo5.png");
    if(!cardImages[16])
        return false;
    cardImages[17] = LoadTexture("images/cards/karo6.png");
    if(!cardImages[17])
        return false;
    cardImages[18] = LoadTexture("images/cards/karo7.png");
    if(!cardImages[18])
        return false;
    cardImages[19] = LoadTexture("images/cards/karo8.png");
    if(!cardImages[19])
        return false;
    cardImages[20] = LoadTexture("images/cards/karo9.png");
    if(!cardImages[20])
        return false;
    cardImages[21] = LoadTexture("images/cards/karo10.png");
    if(!cardImages[21])
        return false;
    cardImages[22] = LoadTexture("images/cards/karoJ.png");
    if(!cardImages[22])
        return false;
    cardImages[23] = LoadTexture("images/cards/karoQ.png");
    if(!cardImages[23])
        return false;
    cardImages[24] = LoadTexture("images/cards/karoK.png");
    if(!cardImages[24])
        return false;
    cardImages[25] = LoadTexture("images/cards/karoA.png");
    if(!cardImages[25])
        return false;
    cardImages[26] = LoadTexture("images/cards/kupa2.png");
    if(!cardImages[26])
        return false;
    cardImages[27] = LoadTexture("images/cards/kupa3.png");
    if(!cardImages[27])
        return false;
    cardImages[28] = LoadTexture("images/cards/kupa4.png");
    if(!cardImages[28])
        return false;
    cardImages[29] = LoadTexture("images/cards/kupa5.png");
    if(!cardImages[29])
        return false;
    cardImages[30] = LoadTexture("images/cards/kupa6.png");
    if(!cardImages[30])
        return false;
    cardImages[31] = LoadTexture("images/cards/kupa7.png");
    if(!cardImages[31])
        return false;
    cardImages[32] = LoadTexture("images/cards/kupa8.png");
    if(!cardImages[32])
        return false;
    cardImages[33] = LoadTexture("images/cards/kupa9.png");
    if(!cardImages[33])
        return false;
    cardImages[34] = LoadTexture("images/cards/kupa10.png");
    if(!cardImages[34])
        return false;
    cardImages[35] = LoadTexture("images/cards/kupaJ.png");
    if(!cardImages[35])
        return false;
    cardImages[36] = LoadTexture("images/cards/kupaQ.png");
    if(!cardImages[36])
        return false;
    cardImages[37] = LoadTexture("images/cards/kupaK.png");
    if(!cardImages[37])
        return false;
    cardImages[38] = LoadTexture("images/cards/kupaA.png");
    if(!cardImages[38])
        return false;
    cardImages[39] = LoadTexture("images/cards/pika2.png");
    if(!cardImages[39])
        return false;
    cardImages[40] = LoadTexture("images/cards/pika3.png");
    if(!cardImages[40])
        return false;
    cardImages[41] = LoadTexture("images/cards/pika4.png");
    if(!cardImages[41])
        return false;
    cardImages[42] = LoadTexture("images/cards/pika5.png");
    if(!cardImages[42])
        return false;
    cardImages[43] = LoadTexture("images/cards/pika6.png");
    if(!cardImages[43])
        return false;
    cardImages[44] = LoadTexture("images/cards/pika7.png");
    if(!cardImages[44])
        return false;
    cardImages[45] = LoadTexture("images/cards/pika8.png");
    if(!cardImages[45])
        return false;
    cardImages[46] = LoadTexture("images/cards/pika9.png");
    if(!cardImages[46])
        return false;
    cardImages[47] = LoadTexture("images/cards/pika10.png");
    if(!cardImages[47])
        return false;
    cardImages[48] = LoadTexture("images/cards/pikaJ.png");
    if(!cardImages[48])
        return false;
    cardImages[49] = LoadTexture("images/cards/pikaQ.png");
    if(!cardImages[49])
        return false;
    cardImages[50] = LoadTexture("images/cards/pikaK.png");
    if(!cardImages[50])
        return false;
    cardImages[51] = LoadTexture("images/cards/pikaA.png");
    if(!cardImages[51])
    {
        return false;
    }
    return true;
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
    {
        //cout<<"Can't open file."<<endl;
    }
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

                if(tempHold[i]&& !new_game)
                {
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
       // cout<<"Can't open file."<<endl;
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
    //da sde pogledne
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
    return sound_effect_card_deal;
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
    Mix_FreeChunk( sound_effect_select );
    Mix_FreeChunk( sound_effect_lose );
    Mix_FreeChunk( sound_effect_win );
    Mix_FreeChunk( sound_effect_card_deal );
    Mix_FreeChunk( sound_effect_deal_sound );
    Mix_FreeChunk( sound_effect_button_click );

    Mix_FreeMusic( sound );
    sound_effect_select = NULL;
    sound_effect_lose= NULL;
    sound_effect_win= NULL;
    sound_effect_card_deal= NULL;
    sound= NULL;
    sound_effect_button_click=NULL;
    sound_effect_deal_sound=NULL;

}

void Application::DeintiTextures()
{
   SDL_DestroyTexture(background_image);
   SDL_DestroyTexture(held_image);
   SDL_DestroyTexture(deal);
   SDL_DestroyTexture(draw);
   SDL_DestroyTexture(help);
   SDL_DestroyTexture(help_clicked);
   SDL_DestroyTexture(sound_button_image);
   SDL_DestroyTexture(sound_button_clicked);
   SDL_DestroyTexture(marker);
   SDL_DestroyTexture(table);
   SDL_DestroyTexture(cardBack);

   for(int i=0;i<52;++i)
   {
       SDL_DestroyTexture(cardImages[i]);
       cardImages[i]=NULL;
   }

   TTF_CloseFont( font );

   background_image = NULL;
   held_image= NULL;
   deal= NULL;
   draw= NULL;
   help= NULL;
   help_clicked= NULL;
   sound_button_image= NULL;
   sound_button_clicked= NULL;
   marker= NULL;
   table= NULL;
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



