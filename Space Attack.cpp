#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<cstdlib>
using namespace std;

class HERO
{
   public:
	int x_cordinate;
    int y_cordinate;
	static int health;
	void setCursorPosition (int x, int y)
	{
		HANDLE output= GetStdHandle(STD_OUTPUT_HANDLE);
		COORD pos= {x,y};
		SetConsoleCursorPosition(output,pos); 
	}
	
	void  draw_ship(int x_co,int y_co)
	{
		x_cordinate=x_co;
		y_cordinate=y_co;
			setCursorPosition(x_co,y_co);
				cout<<"   *  ";
			setCursorPosition(x_co,y_co+1);//middel print
				cout<<"  ***  ";
			setCursorPosition(x_co,y_co+2);
				cout<<" ***** ";
	}
	void  DEL_draw_ship(int x_co,int y_co)
	{
		x_cordinate=x_co;
		y_cordinate=y_co;	
			setCursorPosition(x_co,y_co);
				cout<<"      ";
			setCursorPosition(x_co,y_co+1);
				cout<<"       ";
			setCursorPosition(x_co,y_co+2);
				cout<<"       ";
	}

	void MISS_FIRE()
	{  
		int n=1;
		setCursorPosition(x_cordinate,n);
		for(int Q=n;Q<=y_cordinate-1;Q++)
		{ 
			setCursorPosition(x_cordinate + 3,n);
			cout<<"|";
			if(Q!=y_cordinate-1)
				n++;
		}
	}

	void DEL_MISS_FIRE()
	{  
		int n=1;
		setCursorPosition(x_cordinate,n);
		for(int Q=n;Q<=y_cordinate-1;Q++){ 
			setCursorPosition(x_cordinate + 3,n);
			cout<<" ";
			if(Q!=y_cordinate-1)
				n++;
		}
	}
	
	bool HERO_HEALTH_CHECK()
	{
		if(health<1)
			return 1;
		else 
			return 0;
	}

	void Move_HeroShip_UP()
	{
		y_cordinate=--y_cordinate;
		if(y_cordinate<=16)
			y_cordinate=++y_cordinate;
		setCursorPosition(x_cordinate,y_cordinate+1);
			cout<<"         ";
		setCursorPosition(x_cordinate,y_cordinate+2);
			cout<<"        ";
		setCursorPosition(x_cordinate,y_cordinate+3);
			cout<<"          ";
		draw_ship(x_cordinate,y_cordinate);
	}
	
	void Move_HeroShip_DOWN()
	{
		y_cordinate=++y_cordinate;
		if(y_cordinate>=29)
			y_cordinate=--y_cordinate;
		setCursorPosition(x_cordinate,y_cordinate-1);
			cout<<"         ";
		setCursorPosition(x_cordinate,y_cordinate);
			cout<<"        ";
		setCursorPosition(x_cordinate,y_cordinate+1);
			cout<<"          ";
		draw_ship(x_cordinate,y_cordinate);
	}
	void Move_HeroShip_LEFT()
	{
		x_cordinate=--x_cordinate;
		if(x_cordinate==-1)
			x_cordinate=++x_cordinate;
		setCursorPosition(x_cordinate-1,y_cordinate);
			cout<<"           ";
		setCursorPosition(x_cordinate-2,y_cordinate);
			cout<<"          ";
		setCursorPosition(x_cordinate-8,y_cordinate);
			cout<<"             ";
		draw_ship(x_cordinate,y_cordinate);
	}
	
	void Move_HeroShip_RIGHT()
	{	
		x_cordinate=++x_cordinate;
		if(x_cordinate==60)
			x_cordinate=--x_cordinate;
		setCursorPosition(x_cordinate-1,y_cordinate);
			cout<<"           ";
		setCursorPosition(x_cordinate-2,y_cordinate);
			cout<<"          ";
		setCursorPosition(x_cordinate-8,y_cordinate);
			cout<<"             ";
		draw_ship(x_cordinate,y_cordinate);
	}
	
	};
	
	class ENEMY
	{
	public:
		
		int x_cordinate_Enemy[4];
		int y_cordinate_Enemy[4];
		
		void setCursorPosition (int x, int y)
		{
			HANDLE output= GetStdHandle(STD_OUTPUT_HANDLE);
			COORD pos= {x,y};
			SetConsoleCursorPosition(output,pos); 
		}

		void  edraw_ship(int x_co,int y_co,int index)
		{
			x_cordinate_Enemy[index]=x_co;
			y_cordinate_Enemy[index]=y_co;
		
			setCursorPosition(x_co,y_co);
					cout<<" ***** ";
			setCursorPosition(x_co,y_co+1);
					cout<<"  ***  ";
			setCursorPosition(x_co,y_co+2);
					cout<<"   *   ";
		}

		void  DEL_edraw_ship(int x_co,int y_co,int index)
		{
			x_cordinate_Enemy[index]=x_co;
			y_cordinate_Enemy[index]=y_co;
			setCursorPosition(x_co,y_co);
				cout<<"       ";
			setCursorPosition(x_co,y_co+1);
				cout<<"       ";
			setCursorPosition(x_co,y_co+2);
				cout<<"     ";
		}
	};
	class GAME
	{
	public:
			int TIME;
			int ENEMY_HIT;	
		
			HERO H;
			ENEMY E;
	
	void setCursorPosition (int x, int y)
	{
		HANDLE output= GetStdHandle(STD_OUTPUT_HANDLE);
		COORD pos= {x,y};
		SetConsoleCursorPosition(output,pos); 
	}
	void Laser(int p)
	{  
		char a;
		int n=E.y_cordinate_Enemy[p]+3;
		for(int Q=E.y_cordinate_Enemy[p];Q<=H.y_cordinate-4;Q++)
		{ 
			setCursorPosition(E.x_cordinate_Enemy[p]+2,n);
					cout<<"|";
			if(Q!=H.y_cordinate-1)
				n++;
		}
	}
	void DEL_Laser(int p)
	{  
		char a;
		int n=E.y_cordinate_Enemy[p]+3;
		for(int Q=E.y_cordinate_Enemy[p];Q<=H.y_cordinate-4;Q++)
		{ 
			setCursorPosition(E.x_cordinate_Enemy[p]+2,n);
				cout<<" ";
			if(Q!=H.y_cordinate-1)
				n++;
		}
	}
	bool Fire(int n)

	{
		if(H.x_cordinate==E.x_cordinate_Enemy[n]-1)
		{
				Laser(n);
				Sleep(500);
				DEL_Laser(n);
				return 1;
		}
		else
				return 0;
	}
	bool ENEMY_Fire(int n){
		if(H.x_cordinate==E.x_cordinate_Enemy[n]-1||H.x_cordinate==E.x_cordinate_Enemy[n]-2)
		{
			cout<<"hit";
			return 1;
		}
		else 
			return 0;
	}
	int calculate_score_ENDLESS()
	{int score;
	score=550+50*ENEMY_HIT;
	return score;
	}
	int calculate_score()
	{int score;
	score=TIME+50*ENEMY_HIT;
	return score;
	}
	};
	int HERO::health=0;
	
	
	int main()
	{	
		int DESIRE_LOCATION_X;
		int DESIRE_LOCATION_Y;
		int side_line=0;
		int DELAY_TIME;
		int hardness=0;
		bool ENDLESSe=false;
		char option;
		cout<<"FOR ENDLESS MODE PRESS E ELSE PRESS ANY KEY:";
		cin>>option;
		if(option=='E'||option=='e')
		{
			ENDLESSe=true;
		}
		else
			ENDLESSe=false;
		
			cout<<"ENTER YOUR DESIRE LOCATION \n(remember x should be between 0 to 60) ENTER X:";		
			cin>>DESIRE_LOCATION_X;	
	cout<<"(remember x should be between 16 to 29) ENTER Y:";
			cin>>DESIRE_LOCATION_Y;		
	//addexception of set hero ship	
			
	cout<<"ENTER LEVEL OF HARDNESS\n1.level 1\n2.level 2\n3.level 3\n4.level IMMPOSSIABLE\nCHOOSE: ";
	cin>>option;
	
	switch(option)
	{
		case '1':
				hardness=75000000;
		break;
		
		case '2':
				hardness=55000000;
		break;
		
		case '3':
				hardness=15000000;
		break;
		
		case '4':
				hardness=1000000;
		break;			
	}//switch
		
	system("cls");	
	cout<<"                                \"THE GAME\"";
	cout<<"press esc to exit! "<<endl;
	GAME G;
	
	G.H.x_cordinate=DESIRE_LOCATION_X;
	G.H.y_cordinate=DESIRE_LOCATION_Y;
	G.E.x_cordinate_Enemy[0]=7;
	G.E.y_cordinate_Enemy[0]=14;
	G.E.x_cordinate_Enemy[1]=19;
	G.E.y_cordinate_Enemy[1]=11;
	G.E.x_cordinate_Enemy[2]=30;
	G.E.y_cordinate_Enemy[2]=8;
	G.E.x_cordinate_Enemy[3]=45;
	G.E.y_cordinate_Enemy[3]=5;
	G.H.draw_ship(G.H.x_cordinate,G.H.y_cordinate);
	G.E.edraw_ship(G.E.x_cordinate_Enemy[0],G.E.y_cordinate_Enemy[0],0);
	G.E.edraw_ship(G.E.x_cordinate_Enemy[1],G.E.y_cordinate_Enemy[1],1);
	G.E.edraw_ship(G.E.x_cordinate_Enemy[2],G.E.y_cordinate_Enemy[2],2);
	G.E.edraw_ship(G.E.x_cordinate_Enemy[3],G.E.y_cordinate_Enemy[3],3);
	
	bool exit = false;
	bool onLeft_0 = true;
	bool onLeft_1 = false;
	bool onLeft_2 = true;
	bool onLeft_3 = false;
	bool STOP_ENEMY[4]={false,false,false,false};
	
	G.TIME=10000;
	G.H.health=5;
	G.ENEMY_HIT=0;
	
	for(;side_line<=40;side_line++)
	{
		G.setCursorPosition(68,side_line);
		cout<<":";
	}
	while(exit==false)
	{
		 	for(DELAY_TIME=0;DELAY_TIME<=hardness;DELAY_TIME++);
    
	 G.setCursorPosition(69,4);
     G.TIME--;
     cout<<"  TIME:"<<G.TIME;
     G.setCursorPosition(69,5);
	 cout<<"  HITS:"<<G.ENEMY_HIT;
     G.setCursorPosition(69,6);
	 cout<<"HEALTH:"<<G.H.health;	
    
	 if(STOP_ENEMY[0]==false)
	 { 
		 if (onLeft_0 == true)
		 {
			 G.E.edraw_ship(G.E.x_cordinate_Enemy[0],G.E.y_cordinate_Enemy[0],0);
			 G.E.x_cordinate_Enemy[0]++;
		 }//if  
	 }//force stop
	 if(STOP_ENEMY[1]==false)
	 { 
		 if (onLeft_1 == true)
		 {
		     G.E.edraw_ship(G.E.x_cordinate_Enemy[1],G.E.y_cordinate_Enemy[1],1);
			 G.E.x_cordinate_Enemy[1]++;
		 }
	 }//force stop
	 if(STOP_ENEMY[2]==false)
	 { 
		 if (onLeft_2 == true)
		 {
		     G.E.edraw_ship(G.E.x_cordinate_Enemy[2],G.E.y_cordinate_Enemy[2],2);
			 G.E.x_cordinate_Enemy[2]++;
		 }
	 }//force stop
	 if(STOP_ENEMY[3]==false)
	 { 
		 if (onLeft_3 == true)
		 {
		     G.E.edraw_ship(G.E.x_cordinate_Enemy[3],G.E.y_cordinate_Enemy[3],3);
			 G.E.x_cordinate_Enemy[3]++;
		 }
	 }//force stop
	 if(STOP_ENEMY[0]==false)
	 { 
		 if (onLeft_0 == false)
		 {
		     G.E.edraw_ship(G.E.x_cordinate_Enemy[0],G.E.y_cordinate_Enemy[0],0);
			 G.E.x_cordinate_Enemy[0]--;
		 }
	 }//force stop
	 if(STOP_ENEMY[1]==false)
	 { 
		 if (onLeft_1 == false)
		 {
		     G.E.edraw_ship(G.E.x_cordinate_Enemy[1],G.E.y_cordinate_Enemy[1],1);
			 G.E.x_cordinate_Enemy[1]--;
		 }
	 }//force stop
	 if(STOP_ENEMY[2]==false)
	 { 
		 if (onLeft_2 == false)
		 {
			 G.E.edraw_ship(G.E.x_cordinate_Enemy[2],G.E.y_cordinate_Enemy[2],2);
			 G.E.x_cordinate_Enemy[2]--;
		 }
	 }//force stop
	 if(STOP_ENEMY[3]==false)
	 {
		 if (onLeft_3 == false)
		 {
		     G.E.edraw_ship(G.E.x_cordinate_Enemy[3],G.E.y_cordinate_Enemy[3],3);
			 G.E.x_cordinate_Enemy[3]--;
		 }
	 }//force stop

	 if(G.E.x_cordinate_Enemy[0]==60)
	 {
		onLeft_0=false;
	 }
	
	 if(G.E.x_cordinate_Enemy[1]==60)
	 {
		onLeft_1=false;
	  }  		
	 if(G.E.x_cordinate_Enemy[2]==60)
	 {
		onLeft_2=false;
	 }  
	 if(G.E.x_cordinate_Enemy[3]==60)
	 {
		onLeft_3=false;
	 }  		  
	 if(G.E.x_cordinate_Enemy[0]==0)
	 {
		onLeft_0=true;
	  }  		
	 if(G.E.x_cordinate_Enemy[1]==0)
	 {
		onLeft_1=true;
	  } 		
	 if(G.E.x_cordinate_Enemy[2]==0)
	 {
		onLeft_2=true;
	  } 
	 if(G.E.x_cordinate_Enemy[3]==0)
	 {
		onLeft_3=true;
	  } 
	 if (GetAsyncKeyState(VK_ESCAPE))
	 {
        G.setCursorPosition(0,30);	
            exit = true;
    }
	 if (GetAsyncKeyState(VK_UP))
	 {
		 G.H.Move_HeroShip_UP();
      }	
	 if (GetAsyncKeyState(VK_DOWN))
	 {
		 G.H.Move_HeroShip_DOWN();
    }			  		  		  
	 if (GetAsyncKeyState(VK_RIGHT))
	 {
		 G.H.Move_HeroShip_RIGHT();
     }	
	 if (GetAsyncKeyState(VK_LEFT))
	 {
			G.H.Move_HeroShip_LEFT();
     }	        
	 if(G.E.x_cordinate_Enemy[0]%20==0)
	 {
		 G.Laser(0);
		 Sleep(50);
	if(G.ENEMY_Fire(0))
	{		
		G.H.health--;
		G.H.DEL_draw_ship(G.H.x_cordinate,G.H.y_cordinate);
		Sleep(500);
		G.DEL_Laser(0);
		G.H.draw_ship(G.H.x_cordinate,G.H.y_cordinate);
	}
		G.DEL_Laser(0);
	}
	 if(G.E.x_cordinate_Enemy[1]%16==0)
	 {
		 G.Laser(1);
		Sleep(50);
		if(G.ENEMY_Fire(1))
		{
		G.H.health--;
		G.H.DEL_draw_ship(G.H.x_cordinate,G.H.y_cordinate);
		Sleep(500);
		G.DEL_Laser(1);
		G.H.draw_ship(G.H.x_cordinate,G.H.y_cordinate);
		}
		G.DEL_Laser(1);}
	 //enemy fire
	 if(G.E.x_cordinate_Enemy[2]%11==0)
	 {
	G.Laser(2);
	Sleep(50);
	if(G.ENEMY_Fire(2))
	{
		G.H.health--;
		G.H.DEL_draw_ship(G.H.x_cordinate,G.H.y_cordinate);
		Sleep(500);
		G.DEL_Laser(2);
	}
		G.DEL_Laser(2);
	 }///enemy fire
	 if(G.E.x_cordinate_Enemy[3]%24==0)
	 {
			 G.Laser(3);
			Sleep(50);
	if(G.ENEMY_Fire(3))
	{
		G.H.health--;
		G.H.DEL_draw_ship(G.H.x_cordinate,G.H.y_cordinate);
		Sleep(500);
		G.DEL_Laser(3);
		G.H.draw_ship(G.H.x_cordinate,G.H.y_cordinate);
	}
			G.DEL_Laser(3);
	 }///enemy fire
	 if(	ENDLESSe==false)
	 {
		 if (G.TIME==0)
		 {
			G.setCursorPosition(0,30);
			exit=true;
		 }
	 }//endless mode

	 if(G.H.HERO_HEALTH_CHECK())
	 {
		G.setCursorPosition(0,30);
		exit=true;
	 }
	 if (GetAsyncKeyState(VK_SPACE))
        {
		int found=0;
		if(G.Fire(1))
	{
		
		if(	ENDLESSe==true)
		{	
		STOP_ENEMY[1]=false;
		}
		else if(ENDLESSe==false)
		{
			G.E.DEL_edraw_ship(G.E.x_cordinate_Enemy[1],G.E.y_cordinate_Enemy[1],1);
			G.E.DEL_edraw_ship(72,20,1);
     		STOP_ENEMY[1]=true;
		}
					Sleep(500);


		G.ENEMY_HIT++;
		found=1;
		
	}//fire of enemy 2
	else if(G.Fire(0))
	{
	found=1;
	if(	ENDLESSe==true)
	{
		STOP_ENEMY[0]=false;
	}else if(	ENDLESSe==false)
	{
		STOP_ENEMY[0]=true;
		G.E.DEL_edraw_ship(G.E.x_cordinate_Enemy[0],G.E.y_cordinate_Enemy[0],0);
		G.E.DEL_edraw_ship(72,20,0);
	}
		Sleep(500);

		G.ENEMY_HIT++;
		
	}//fire of enemy 1
	else if(G.Fire(2))
	{
	found=1;
	if(	ENDLESSe==true)
	{
		STOP_ENEMY[2]=false;
	}
	else if(ENDLESSe==false) 
	{
		G.E.DEL_edraw_ship(G.E.x_cordinate_Enemy[2],G.E.y_cordinate_Enemy[2],2);
		G.E.DEL_edraw_ship(72,20,2);
		STOP_ENEMY[2]=true;
	}
	G.ENEMY_HIT++;
			Sleep(500);

		
	}//fire of enemy 3
	else if(G.Fire(3))
	{found=1;
	if(	ENDLESSe==true)
	{
	STOP_ENEMY[3]=false;
	}
	else if(ENDLESSe==false)
	{
			STOP_ENEMY[3]=true;
		G.E.DEL_edraw_ship(G.E.x_cordinate_Enemy[3],G.E.y_cordinate_Enemy[3],3);
		G.E.DEL_edraw_ship(72,20,3);
	}
	G.ENEMY_HIT++;
			Sleep(500);
		
	}//fire of enemy 1
	if (found==0)
	{
	G.H.MISS_FIRE();
	Sleep(20);
	G.H.DEL_MISS_FIRE();
    } 
	
	   }//space function
	  
	   if(STOP_ENEMY[0]==true && STOP_ENEMY[1]==true&&STOP_ENEMY[2]==true && STOP_ENEMY[3]==true)
	   {
	   	cout<<"you win";
	   	exit=true;
	   }
       
	}//while
	
	system("cls");
	//set exception that time will not shown in negative
	
	cout<<endl<<endl<<endl<<endl<<endl<<"YOUR SCORE :"<<G.calculate_score_ENDLESS()<<endl;
	cout<<"HEALTH REMAING: "<<G.H.health<<endl;
	cout<<"ENEMY SHIP/SHIPS DESTROYED: "	<<G.ENEMY_HIT;
	Sleep(650);
	return 0;
}//main

