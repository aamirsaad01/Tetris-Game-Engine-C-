//Muhammad Saad Aamir
//22i-1059
//Final Project


/* PROGRAMMING FUNDAMENTAL'S PROJECT FOR FALL 2022 BS(CS)
 * You need to define the required function in the part instructed here below.
 * Avoid making any unnecessary changes, particularly the ones you don't understand.
 * The different pieces should be defined using an array - uncomment the following code once you are done creating the array.
 * TIP: Understand thoroughly before getting started with coding.
 * */

//---Piece Starts to Fall When Game Starts---//

void fallingPiece(float& timer, float& delay,int &colorNum,int& rotshape, int&rotationNo,int &fall,int &bomb,int &bombcol,float &dx){
    if (timer>delay){
        
        for (int i=0;i<4;i++){
            point_2[i][0]=point_1[i][0];
            point_2[i][1]=point_1[i][1];
            point_1[i][1]+=1;                   //How much units downward
        }

        if (!anamoly()){
            for(int i=0;i<4;i++)
                gameGrid[point_2[i][1]][point_2[i][0]]=colorNum;
            colorNum=rand()%7+1;
            int n=rand()%8;
            //condition so no consecutive bombs fall
            if(bomb==7&&n==7)
            {
                n=rand()%7;
            }
            bomb=n;
            rotshape=n;
            //rotation shape stores shape and is used in rotation function
            rotationNo=0;
            //as the new block falls rotation No is set to zero
            fall=0;
            //fall which becomes true with space automatically becomes false 
            bombcol=colorNum;
            /*bombcol stores color of piece and in case if it is bomb
              it will be used in falling bomb section to make the whole grid zero*/  

            
            //--- Un-Comment this Part When You Make BLOCKS array---//
            
                for (int i=0;i<4;i++){
                    point_1[i][0] = BLOCKS[n][i] % 2;
                    point_1[i][1] = BLOCKS[n][i] / 2;
                    
                }
                
                //condition so bombs fall from random places
                if(bomb==7)
                {
                    int x=rand()%10;
                    for(int i=0;i<4;i++)
                    point_1[i][0]+=x;
                    
                    

                }
            
        }
        timer=0;
        delay=dx;
    }
}

/////////////////////////////////////////////
///*** START CODING YOUR FUNTIONS HERE ***///
void movingpiece(int& delta_x,int &bomb){
    //this function will move the pieces left and right
    //first it will check for condition that if the movement does not lead to:
    /*moving piece out of grid
     movement may lead to overlap of blocks
    */
    
    
    if(delta_x==1){

        int count=0;    // to check if space is empty or occupied

        for (int i=0;i<4;i++){
            //condtion for overlapping and block remain inside grid
            if(gameGrid[point_1[i][1]][point_1[i][0]+1]==0 && point_1[i][0]<9&&bomb!=7 )
            count++;
            }
            //each shape has four blocks thats why it has to check for four
            if(count==4){    
                for (int i=0;i<4;i++){
                point_1[i][0]+=1;
            }

         delta_x=0;        
        }
    }

    else if(delta_x==-1){
             
        int count=0;
        
        for (int i=0;i<4;i++){
            //condtion for overlapping and block remain inside grid
            if(gameGrid[point_1[i][1]][point_1[i][0]-1]==0 && point_1[i][0]>0&&bomb!=7 )
            count++;
            
            }
             //each shape has four blocks thats why it has to check for four
            if(count==4){   

                for (int i=0;i<4;i++){
                point_1[i][0]-=1;

                }
            }
        delta_x=0;
    }

}
void overlap(int&count1)
{    
    for (int i=0;i<4;i++)
    {        
    if(gameGrid[point_1[i][1]][point_1[i][0]]==0 && point_1[i][0]<=9 &&point_1[i][0]>=0 )
    count1++;
    }
}

void rotatingpiece(bool& rotate, int& rotshape,int& rotationNo,int& count1)

{   
    //if up key is pressed then rotate in main will become true.
    //when rotation is true this function will start working.


    //here the function is checking 2 conditions
    //--first it checked if rotate is true or not
    //--then it determined shape type and perform roation according to it
    
    if(rotate==true && rotshape==6)
    {   
        //rotationNo=0 mean shape is in its orignal orintation
        //incremet in rotationNo means the shape has rotated one time
        //some shapes have 2 rotations and some have 4 and square has none
        //so it will be used in accordance with rotshape
        if(rotationNo==0)
        {
            point_1[0][0]+=1;
            point_1[0][1]+=1;
            point_1[1][0]+=2;
            point_1[2][0]-=1;
            point_1[2][1]+=1;
            
            count1=0;
            overlap(count1);
            //overlap function is check
            //it will if rotation will cause shape to move out grid
            //if rotation will cause overlap in shapes
            //if either of above condition is true rotation will be reversed
            //else rotationNo will icrement
            if(count1!=4)
            {
                point_1[0][0]-=1;
                point_1[0][1]-=1;
                point_1[1][0]-=2;
                point_1[2][0]+=1;
                point_1[2][1]-=1;
                 
            }
            else
            rotationNo++;
        }

        else if(rotationNo==1)
        {
            point_1[0][0]-=1;
            point_1[0][1]-=1;
            point_1[1][0]-=2;
            point_1[2][0]+=1;
            point_1[2][1]-=1;
            
            count1=0;
            overlap(count1);
            if(count1!=4)
            {
                point_1[0][0]+=1;
                point_1[0][1]+=1;
                point_1[1][0]+=2;
                point_1[2][0]-=1;
                point_1[2][1]+=1;


            }
            else
            rotationNo=0;
        }
        
    }
   
    else if(rotate==true && rotshape==1)
    {   
        if(rotationNo==0)
        {
            point_1[0][0]-=1;
            point_1[0][1]+=1;
            point_1[1][0]+=1;
            point_1[2][1]+=1;
            point_1[3][0]+=2;
            count1=0;
            overlap(count1);
            if(count1!=4)
            {
                point_1[0][0]+=1;
                point_1[0][1]-=1;
                point_1[1][0]-=1;
                point_1[2][1]-=1;
                point_1[3][0]-=2;

            }
            else
            rotationNo++;
        }

        else if(rotationNo==1)
        {
            point_1[0][0]+=1;
            point_1[0][1]-=1;
            point_1[1][0]-=1;
            point_1[2][1]-=1;
            point_1[3][0]-=2;
            count1=0;
            overlap(count1);
            if(count1!=4)
            {
                point_1[0][0]-=1;
                point_1[0][1]+=1;
                point_1[1][0]+=1;
                point_1[2][1]+=1;
                point_1[3][0]+=2;

            }
            else
            rotationNo=0;
        }
    }
    else if(rotate==true && rotshape==2)
    {
        if(rotationNo==0)
        {
            point_1[1][0]-=1;
            point_1[2][0]-=1;
            point_1[3][0]+=1;
            point_1[3][1]-=1;
            count1=0;
            overlap(count1);
            if(count1!=4)
            {
                point_1[1][0]+=1;
                point_1[2][0]+=1;
                point_1[3][0]-=1;
                point_1[3][1]+=1;
            }
            else
            rotationNo++;
        }
         else if(rotationNo==1)
        {
            
            point_1[3][0]-=1;
            point_1[3][1]+=1;
            count1=0;
            overlap(count1);
            if(count1!=4)
            {
                point_1[3][0]+=1;
                point_1[3][1]-=1;

            }
            else
            rotationNo++;
        }
         else if(rotationNo==2)
        {
            point_1[0][0]-=1;
            point_1[0][1]+=1;
            point_1[1][0]+=1;
            point_1[2][0]+=1;
            count1=0;
            overlap(count1);
            if(count1!=4)
            {
                point_1[0][0]+=1;
                point_1[0][1]-=1;
                point_1[1][0]-=1;
                point_1[2][0]-=1;

            }
            else
            rotationNo++;    
        }
        else if(rotationNo==3)
        {   point_1[0][0]+=1;
            point_1[0][1]-=1;
            count1=0;
            overlap(count1);
            if(count1!=4)
            {
                point_1[0][0]-=1;
                point_1[0][1]+=1;

            }
            else
            rotationNo=0;
            
        }
    }
    else if(rotate==true && rotshape==3)
    {
        if(rotationNo==0)
        {
            
            point_1[0][0]-=1;
            point_1[0][1]+=1;
            point_1[1][0]-=1;
            point_1[1][1]+=1;
            point_1[2][0]+=1;
            point_1[3][0]+=1;
             
             count1=0;
            overlap(count1);
            if(count1!=4)
            {
                point_1[0][0]+=1;
                point_1[0][1]-=1;
                point_1[1][0]+=1;
                point_1[1][1]-=1;
                point_1[2][0]-=1;
                point_1[3][0]-=1;

            }
            else
            rotationNo++;
        }
        else if(rotationNo==1)
        {
            point_1[0][0]+=1;
            point_1[0][1]-=1;
            point_1[2][0]-=2;
            point_1[2][1]+=1;
            point_1[3][0]-=1;
            count1=0;
            overlap(count1);
            if(count1!=4)
            {
                point_1[0][0]-=1;
                point_1[0][1]+=1;
                point_1[2][0]+=2;
                point_1[2][1]-=1;
                point_1[3][0]+=1;
            }
            else
            rotationNo++;
        }
        else if(rotationNo==2)
        {
            
            point_1[0][0]-=1;
            point_1[1][0]-=1;
            point_1[2][0]+=1;
            point_1[2][1]-=1;
            point_1[3][0]+=1;
            point_1[3][1]-=1;
            count1=0;
            overlap(count1);
            if(count1!=4)
            {
                point_1[0][0]+=1;
                point_1[1][0]+=1;
                point_1[2][0]-=1;
                point_1[2][1]+=1;
                point_1[3][0]-=1;
                point_1[3][1]+=1;

            }
            else
            rotationNo++;
        }
        else if(rotationNo==3)
        {
            
            point_1[0][0]+=1;
            point_1[1][0]+=2;
            point_1[1][1]-=1;
            point_1[3][0]-=1;
            point_1[3][1]+=1;
            count1=0;
            overlap(count1);
            if(count1!=4)
            {
                point_1[0][0]-=1;
                point_1[1][0]-=2;
                point_1[1][1]+=1;
                point_1[3][0]+=1;
                point_1[3][1]-=1;
            }
            else
            rotationNo=0;
        }
        
    }
    else if(rotate==true & rotshape==4)
    {
        if(rotationNo==0)
        {
            point_1[0][0]+=1;
            point_1[1][0]-=1;
            point_1[2][1]-=1;
            point_1[3][1]-=1;
            count1=0;
            overlap(count1);
            if(count1!=4)
            {
                point_1[0][0]-=1;
                point_1[1][0]+=1;
                point_1[2][1]+=1;
                point_1[3][1]+=1;

            }
            else
            rotationNo++;
        }
        else if(rotationNo==1)
        {
            point_1[0][0]-=1;
            point_1[0][1]+=1;
            point_1[1][0]+=2;
            point_1[2][0]+=1;
            point_1[2][1]+=1;
            point_1[3][1]+=2;

            count1=0;
            overlap(count1);
            if(count1!=4)
            {
                point_1[0][0]+=1;
                point_1[0][1]-=1;
                point_1[1][0]-=2;
                point_1[2][0]-=1;
                point_1[2][1]-=1;
                point_1[3][1]-=2;
            }
            else
            rotationNo++;

        }
        else if(rotationNo==2)
        {
            point_1[2][0]+=1;
            point_1[2][1]-=1;
            point_1[3][0]-=1;
            point_1[3][1]-=1;
            count1=0;
            overlap(count1);
            if(count1!=4)
            {
                point_1[2][0]-=1;
                point_1[2][1]+=1;
                point_1[3][0]+=1;
                point_1[3][1]+=1;

            }
            else
            rotationNo++;
        }
        else if(rotationNo==3)
        {
            point_1[0][1]-=1;
            point_1[1][0]-=1;
            point_1[2][0]-=2;
            point_1[2][1]+=1;
            point_1[3][0]+=1;
            count1=0;
            overlap(count1);
            if(count1!=4)
            {
                point_1[0][1]+=1;
                point_1[1][0]+=1;
                point_1[2][0]+=2;
                point_1[2][1]-=1;
                point_1[3][0]-=1;
                
            }
            else
            rotationNo=0;
        }
    }
    else if(rotate==true&& rotshape==5  )
     {
        
        if(rotationNo==0)
        {
            point_1[1][0]+=1;
            point_1[1][1]-=1;
            point_1[2][0]+=2;
            point_1[2][1]-=2;
            point_1[3][0]+=3;
            point_1[3][1]-=3;
            
            int count1=0;    
            overlap(count1);
            if(count1!=4)
            {
                point_1[1][0]-=1;
                point_1[1][1]+=1;
                point_1[2][0]-=2;
                point_1[2][1]+=2;
                point_1[3][0]-=3;
                point_1[3][1]+=3;
                
            }
            else   
            rotationNo++;
        }
        else if(rotationNo==1)
        {
            point_1[1][0]-=1;
            point_1[1][1]+=1;
            point_1[2][0]-=2;
            point_1[2][1]+=2;
            point_1[3][0]-=3;
            point_1[3][1]+=3;
            
            int count1=0;
            overlap(count1);    
            
            if(count1!=4)
            {
                point_1[1][0]+=1;
                point_1[1][1]-=1;
                point_1[2][0]+=2;
                point_1[2][1]-=2;
                point_1[3][0]+=3;
                point_1[3][1]-=3;
            
            }
            else rotationNo=0;

        }
     }  

    rotate=false;
}

bool endgame(bool& over)


{
    //this function will end the game for user
    //'over' is short form of gameover
    //initially 'over' is false
    //but below operated loop will check if:
    //1st row of 0th iteration has any piece in it or not
    //if it has any piece over will become true and its value will be rturned 

    over=0;    
    for(int i=0;i<1;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(gameGrid[i][j]!=0)
            {
                over=1;
                break;
            }
        }
    }
    return over;
    
    

}

void removepiece(int count2, int &points,int &points2, int& total)
{   
    //This fuction will check if row is filled and then remove it & rplace it with the upper.
    //count2 will check if all columns of a row are filled
    //if count2 is true it means all colums are filled
    //here 'points' and 'points2' are condition for grid shrinkage and speed increase
    
    int line=0;
    bool chk=0;
    count2=0;
    for(int i=19;i>0;i--)
    {
        for(int j=0;j<10;j++)
        {
            //gamegrid=8 is shrinked row and it will not be considerd has filled row
             if(gameGrid[i][j]!=0&& gameGrid[i][j]!=8)
            {
                count2++;
            }
        }
        //count2 is 10 points are incremented by 10         
        if(count2==10)
        {
            points+=10;
            line++;
        }
        if(count2==10)
        points2+=10;

        //row which is filled will be emptied
        if(count2==10)
        {
            chk=1;
            //chk 1 will be used to move the upper low one unit down
            int j=0;
            
            {
                while(j<10)
                {
                    gameGrid[i][j]=0;
                    j++;
                    
                }
            }
        }
        
        count2=0;
        if(chk==1)
        {
            //as chk1=true which means a row has been removed
            //so a will store the removed row
            //then rown will start moving down from the bottom
            for(int a=i;a>0;a--)
            {
                int j=0;
                while(j<10)
                {    
                    gameGrid[a][j]=gameGrid[a-1][j];
                    j++;   
                }
                

            }
        }
        chk=0;
        if(line==1)
        total+=10;
        else if (line==2)
        total+=30;
        else if (line>=3)
        total+=60;
        line=0;
    }
    
}

void space(int &fall,float &delay)

{
    //this will be used for fall of blocks at once
    // when space is pressed fall becomes one
    //and delay is zero
    //as zero delay will land the block and !anamoly will become true
    //so delay will be automatically set to its orignal value

    if(fall==1)
    delay=0;

}

void fallingbomb(int & bomb,int &bombcol,bool &bcond1,bool &bcond2,bool &bcond3,int &rowr,bool &bcond4)
{   
    //now bomb is a single piece stored in the 7th row of Blocks array
    //bomb variable stores every value of 'n'(random number in falling piece)
    //when bomb becomes 7 a set of conditions are checked
    //if bomb has a piece exactly below it cond1 becomes true
    //if the piece exactly below the bomb has same colour as the bomb cond2 becomes true.
    //if both cond1 and cond2 are true cond 3 is true
    //if the bomb is falling means bomb varaible stores seven
    //then it will over inside first if condition and return halfway
    //when next piece after bomb will fall
    //if cond 3 is true it will over inside the second if condition
    //and destroy all the pieces
    //it is made sure in the falling piece function that consecutive bombs dont fall 
       
    
    int colm=0;
    if(bomb==7)
    {
        for(int i=0;i<4;i++)
        {
            if(gameGrid[point_1[i][1]+1][point_1[i][0]]!=0)
            {
                bcond1=1;
                
            }
        }
        for(int i=0;i<4;i++)
        {
            if(gameGrid[point_1[i][1]+1][point_1[i][0]]==bombcol)
            {
                bcond2=1;
               
            }
            

        }
        for(int i=0;i<4;i++)
        {
            if(point_1[i][1]+1==rowr && gameGrid[point_1[i][1]][point_1[i][0]]==0)
            {
                if(bcond1==0&&bcond2==0)
                point_1[i][1]+=10;

                
            }
        }
        if(bcond1==1&&bcond2==1) 
        {
            bcond3=1;
        }
        return;

    }
    
    if(bomb!=7&&bcond3==1)
    {
        for(int i=0;i<=rowr;i++)
            {
                for(int j=0;j<10;j++)
                gameGrid[i][j]=0;
            }
            bcond1=0;
            bcond2=0;
            bcond3=0;
            

    }
    
}
    
void gridshrink(int &points,int &rowr)
{
    //This function grids ther srink from bottom as a certain threshhold is reached 
    //As the players has reached 50 of points
    //if condition will become true
    //first for loop is shifting the row at the bottom at the top
    //after it through while loop we have made the last row black
    //rowr is the total no rows which decreases as the grid shrinks
    //and used in the for loop so the the rows which have been shrinked are not considerd
        
    if(points==30)
    {   
        points=0;
        for(int i=0;i<rowr;i++)
        {
            int j=0;
            while(j<10)
            {
                gameGrid[i][j]=gameGrid[i+1][j];
                j++;
            }
        }
        int j=0;
        while(j<10)
        {
            gameGrid[rowr][j]=8;
            j++;
        }
        rowr-=1;
    }

    
}

void startover(bool &newgame,bool &pause,int &total)
{   
    //if the players wants to start over the game after pausing it will do it for him
    //as the user presses 'N' key newgame varible will become true
    //but it will only become true if pause is already true
    //and this is ensured in events section in main
    //as the newgame is true gamegeid will be emptied

    if(newgame==1)
    {
        for(int i=0;i<20;i++)
        {
            int j=0;
            while(j<10)
            {
                gameGrid[i][j]=0;
                j++;
            }
            
            
        }
        pause=0;
        newgame=0;
        total=0;
    }
}

void fast(float &dx,int &points2)
{
    //this function will increase falling speed as user has totald some points
    //dx is a variable in main which is orignally 0.5 and will become 0.3 
    //and delay variable is equal to dx so the speed will become 0. at all points
    //
    if(points2==50)
    {
        points2=0;
        dx=0.3;
    }
}
///*** YOUR FUNCTIONS END HERE ***///
/////////////////////////////////////
