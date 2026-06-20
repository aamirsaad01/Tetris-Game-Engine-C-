//Muhammad Saad Aamir
//22i-1059
//Final Project




/* PROGRAMMING FUNDAMENTAL'S PROJECT FOR FALL 2022 BS(CS)
 * You don't need to change anything in the driver code/main function except the part(s) where instructed.
 * You are expected to define your functionalities in the "functionality.h" header and call them here in the instructed part(s).
 * The game is started with a small box, you need to create other possible in "pieces.h" file in form of array.
    E.g., Syntax for 2 pieces, each having four coordinates -> int Pieces[2][4];
 * Load the images into the textures objects from img directory.
 * Don't make any changes to the "utils.h" header file except for changing the coordinate of screen or global variables of the game.
 * SUGGESTION: If you want to make changes in "utils.h", do it once you complete rest of the functionalities.
 * TIP: You can study SFML for drawing scenes, sprites and window.
 * */

#include <SFML/Graphics.hpp>
#include <time.h>
#include "utils.h"
#include "pieces.h"
#include "functionality.h"
#include <iostream>
using namespace std;
using namespace sf;
int main(){
    srand(time(0));
    RenderWindow window(VideoMode(320, 480), title);
    Texture obj1, obj2, obj3;
    Texture obj4,halt,menu,inst;
    /*
        Load "frames.png","tiles.png" and "background.png" for Texture objects
    */
    inst.loadFromFile("img/instructions.png");
    menu.loadFromFile("img/start.png");
    halt.loadFromFile("img/pause.png");
    obj4.loadFromFile("img/gamover.jpg");
    obj1.loadFromFile("img/tiles.png");
    obj2.loadFromFile("img/background.png");
    obj3.loadFromFile("img/frame.png");
    
    Sprite sprite(obj1), background(obj2), frame(obj3),gamover(obj4),hold(halt),str(menu);
    Sprite instructions(inst);
    
    int delta_x=0,colorNum=rand()%7+1;
    int rotshape,rotationNo=0;
    //--rotshape will store shape type and will help in rotating it
    //--rotationNo will store current orientaion of shape and will aid in rotation
    
    float dx=0.5;//this variblw will help in increasing speed

    float timer=0, delay=dx;
    bool rotate=0;
    bool over=0;
    //'over' varible to help in showing gameover screen

    int count1=0;//rotation linked


    int total=0;
    //it will store total total:

    //'over' varible to help in showing gameover screen

    int count2=0;
    //count2 is passed to falling piece it will be check for row removal

    int fall=0;
    // when space is pressed fall will become 1 and it is passed to space function

    int bomb,bombcol;
    //bomb will be passed to falling bomb section 
    //bomb is to check if falling piece is bomb or not
    //bombcol stores color of bomb

    bool bcond1=0,bcond2=0,bcond3=0,bcond4=0;
    //bcond means bomb conditions
    //this are checks passed to falling bombs

    bool  pause=0;
    //pause becomes true when "P" is pressed
    //pause becomes false when "R" is pressed
    //it will pause the game
    //it is also passed to startover function so if new game is started it becoems false
    
    int points=0;
    //points are passed to removepiece function && grid shrink function
    //it is a threshhold for grid shrinkage 
    
    int points2=0;
    //it is passed to fast function and removepiece function
    //it is threshold for increasing speed


    bool start=0;
    //start will help in starting game
    //as enter is pressed it will become true and game will start

    bool newgame=0;
    //newgame will become true
    //it is passed to startover function

    bool guide=0;
    //it will take user to instructions menu

    int rowr=19;
    //it is linked with row removal and shrink.
    //as the rows have been shrinked it will decrement
    //and it is passed to several function so they do not consider removed rows 


    Clock clock;
    while (window.isOpen()){
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer+=time;

        //---Event Listening Part---//
        Event e;
        while (window.pollEvent(e)){                       //Event is occurring - until the game is in running state
            if (e.type == Event::Closed)                   //If cross/close is clicked/pressed
                {
                window.close(); 
                }                           //Opened window disposes
            if (e.type == Event::KeyPressed) {             //If any other key (not cross) is pressed
                if(e.key.code == Keyboard::Enter&&guide==0)
                    start=1;
                else if (e.key.code == Keyboard::I&&start==0)
                    guide=1;
                else if (e.key.code == Keyboard::Escape &&guide==1)
                {    
                    guide=0;
                    start=0;
                }
                else if (e.key.code == Keyboard::N&&pause==1)
                    newgame=1;
                else if (e.key.code == Keyboard::P)
                    pause=1;
                else if (e.key.code == Keyboard::R)
                    pause=0;
                else if (e.key.code == Keyboard::Up&&pause==0)            //Check if the other key pressed is UP key
                    rotate = true;                         //Rotation gets on
                else if (e.key.code == Keyboard::Left&&pause==0)     //Check if the other key pressed is LEFT key
                    delta_x = -1;                          //Change in X-Axis - Negative
                else if (e.key.code == Keyboard::Right&&pause==0)    //Check if the other key pressed is RIGHT key
                    delta_x = 1;                           //Change in X-Axis - Positive
                else if (e.key.code == Keyboard::Space&&pause==0)    //Check if the other key pressed is RIGHT key
                    fall++;
                
                    
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Down))   //Just another way to detect key presses without event listener
            delay=0.03;                                    //If DOWN key is pressed, delay in falling piece decreases from 0 to 0.05


        ///////////////////////////////////////////////
        ///*** START CALLING YOUR FUNCTIONS HERE ***///
        startover(newgame,pause,total);
        
        // the continue writtenhere will not let the functions work
        if(over==1)
        {
            window.clear();
            window.draw(gamover);
            window.display();
            continue;
        }
        else if(guide==1&&start==0)
        {
            
            window.clear();
            window.draw(instructions);
            window.display();
            continue;

        }
        
        else if(pause==1)
        {
                window.clear();
                window.draw(hold);
                window.display();
                continue;
        }
        else if(start==0&&guide==0)
        {
                window.clear();
                window.draw(str);
                window.display();
                continue;
        }
        else if(pause==0)

        {
            if(start==1)
            {
            fallingPiece(timer, delay,colorNum,rotshape,rotationNo,fall,bomb,bombcol,dx); 
            movingpiece(delta_x,bomb);
            overlap(count1);
            rotatingpiece(rotate,rotshape,rotationNo,count1);
            endgame(over);
            removepiece(count2,points,points2,total);
            space(fall,delay);
            fallingbomb(bomb,bombcol,bcond1,bcond2,bcond3,rowr,bcond4);
            gridshrink(points,rowr);
            fast(dx,points2);   
                     
            }
        }        
        
       
        //Example: fallingPiece() function is called here
        ///*** YOUR CALLING STATEMENTS END HERE ***///
        //////////////////////////////////////////////
        
        
        
            window.clear(Color::Black);
            window.draw(background);
        for (int i=0; i<M; i++){
            for (int j=0; j<N; j++){
                if (gameGrid[i][j]==0)
                    continue;
                sprite.setTextureRect(IntRect(gameGrid[i][j]*18,0,18,18));
                sprite.setPosition(j*18,i*18);
                sprite.move(28,31); //offset
                window.draw(sprite);
            }
        }
        for (int i=0; i<4; i++){
            sprite.setTextureRect(IntRect(colorNum*18,0,18,18));
            sprite.setPosition(point_1[i][0]*18,point_1[i][1]*18);
            sprite.move(28,31);
            window.draw(sprite);
          }
        //---The Final on Which Everything is Drawn Over is Loaded---//
        window.draw(frame);
        //---The Window that now Contains the Frame is Displayed---//
        window.display();
        
    }
    cout<<"Total points scored are: "<<total<<endl;
    return 0;
}
