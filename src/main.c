/*
Demo Input Gamepad Tester using SDL1.2
Device:RG35XX OS:Koriki [ok]
*/
#include <stdio.h>
#include <string.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include "config.h"

typedef struct Button_Tag
{
	SDL_Surface * img;						 /* Unselected image                           */
	SDL_Surface * imgSel;   				 /* Selected image                             */
	SDL_Rect	imgPos;						 /* Position of the button image on the screen */
	SDL_Rect	textPos;    				 /* Position of the text under the button      */     
	char 		name[BUTTON_NAME_LENGTH];    /* Text under the button / image file name    */
	int			selected;					 /* Flag - Button pressed / not pressed        */
	int 		code;                        /* The key code of the button                 */
}Button;

Button buttons[NO_BUTTONS] = BUTTONS_CONFIG; /* List of buttons */

SDL_Surface 	* screen 			= NULL;
SDL_Surface 	* textSurface		= NULL;
SDL_Rect 		textLocation 		= { 0, 0, 0, 0 };
TTF_Font    	* textFont   		= NULL;            
SDL_Color   	textColor 			= { 255, 255, 255 }; 
SDL_Color   	backgroundColor	    = { 0, 0, 100 }; 
char 			text[60]     		= "Hold [Menu] button 2 seconds to quit";
SDL_Event   	event 				= {0};
int				running				= 1;
int				startMenuPress		= 0;
SDL_Joystick* joystick;

void initButtons(void)
{
	char filePath[FILE_PATH_LENGTH];
	
	/* Load button images */
	for (int i = 0; i < NO_BUTTONS; ++i)
	{
		sprintf(filePath,"./res/%s.png",buttons[i].name);
		buttons[i].img 	 = IMG_Load(filePath); 	 
		sprintf(filePath,"./res/%s2.png",buttons[i].name);
		buttons[i].imgSel = IMG_Load(filePath);
	}
}

int setup()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER | SDL_INIT_JOYSTICK) != 0)
	{
		fprintf(stderr, "SDL Init error...\n");
		return 0;
	}
	if (TTF_Init() != 0)
	{
		fprintf(stderr, "TTF Init error...\n");
		return 0;
	}
	if (IMG_Init(IMG_INIT_PNG) == 0)
	{
		fprintf(stderr, "IMG Init error...\n");
		return 0;
	}
	joystick = SDL_JoystickOpen(0); // Open the first joystick

    if (!joystick) {
        fprintf(stderr, "Failed to open joystick: %s\n", SDL_GetError());
        return 1;
    }
	SDL_ShowCursor(SDL_DISABLE);
	screen = SDL_SetVideoMode(WINDOW_W, WINDOW_H, 16, SDL_SWSURFACE);
	textFont = TTF_OpenFont("./res/SourceCodePro-Regular.ttf", 16);
	initButtons();
	textLocation.x = 45;
	textLocation.y = 450;
	return 1;
}


void processInput()
{
	int i; 
	
	SDL_PollEvent(&event);
	switch(event.type)
	{
		case SDL_QUIT:
			 running = 0;	
		break;
		case SDL_JOYBUTTONDOWN:
			sprintf(text,"Event SDL_JOYBUTTONDOWN %d", event.jbutton.button);
			for (i = 0; i < NO_BUTTONS; ++i)
			{
				if (event.jbutton.button == MENU_BUTTON)
				{
					if (buttons[MENU_BUTTON_INDEX].selected == 0)
					{
						buttons[MENU_BUTTON_INDEX].selected = 1;
						startMenuPress = SDL_GetTicks();
						buttons[MENU_BUTTON_INDEX].selected = 1;
					}
					else
					{
						if ((SDL_GetTicks() - startMenuPress) >= EXIT_PRESS_TIME)
						{
							running = 0;
						}
					}		
				}
				else
				{
					if ((event.jbutton.button == buttons[i].code) && buttons[i].selected == 0)
					{
						buttons[i].selected = 1;
					}
				}
			}
		break;
		case SDL_JOYBUTTONUP:
			sprintf(text,"Event SDL_JOYBUTTONUP %d", event.jbutton.button);
			for (i = 0; i < NO_BUTTONS; ++i)
			{
				if ((event.jbutton.button == MENU_BUTTON) && (buttons[MENU_BUTTON_INDEX].selected != 0))
				{
					buttons[MENU_BUTTON_INDEX].selected = 0;
				}
				else
				{
					if ((event.jbutton.button == buttons[i].code) && buttons[i].selected != 0)
					{
						buttons[i].selected = 0;
					}
				}
			}
		break;
		default:
			sprintf(text,"Event.type: %d", event.type);
		break;
	}
}

void update(int delta)
{
	//do nothing
	NULL;
}

void renderButtons(void)
{
	for (int i; i < NO_BUTTONS; ++i)
	{
		if (buttons[i].selected == 1)
		{
			SDL_BlitSurface(buttons[i].imgSel, NULL, screen, &buttons[i].imgPos);
		}
		else
		{
			SDL_BlitSurface(buttons[i].img, NULL, screen, &buttons[i].imgPos);
		}
		SDL_FreeSurface(textSurface);
		textSurface = TTF_RenderText_Solid(textFont, buttons[i].name, textColor);
		SDL_BlitSurface(textSurface, NULL, screen, &buttons[i].textPos);
		
	}
}

void render()
{
	Uint32 mapColor = SDL_MapRGB(screen->format,backgroundColor.r,backgroundColor.g,backgroundColor.b);
	SDL_FillRect(screen, NULL, mapColor);
	SDL_FreeSurface(textSurface);
	textSurface = TTF_RenderText_Solid(textFont, text, textColor);
	SDL_BlitSurface(textSurface, NULL, screen, &textLocation);
	renderButtons();
	SDL_Flip(screen);
}

void cleanup()
{
	SDL_FreeSurface(screen);
	SDL_FreeSurface(textSurface);
	TTF_CloseFont(textFont);
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

int main(void)
{
	int new 	= 0;
	int old 	= 0;
	int delta 	= 0;
		
	if (setup() == 0) return 0;
	
	while (running == 1)
	{
		new = SDL_GetTicks();	
		delta = new - old;    				/* Time since last frame */
		processInput();	
		if (delta >= FRAME_TIME)
		{
			update(delta);
			old = new;
		}
		else
		{
			SDL_Delay(FRAME_TIME - delta);
		}
		render();
	}
	cleanup();
	return 0;
}
