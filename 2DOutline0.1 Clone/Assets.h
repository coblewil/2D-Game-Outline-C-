#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include <memory>
#include <vector>
#include "SubTexture.h"
#include "SpriteSheet.h"

//TO-DO maybe make no assets or anything using a shared pointer static because of destructor concerns. In this case perhaps using getters for each shared_ptr asset, and initialize them based on if they exist already or not (whether or not shared_ptr points to nullptr). OR JUST USE A SINGLETON ASSETS CLASS

//TO-DO make sure each gRenderer object is passed as a const reference
class Assets
{
private:
	static const int width{ 64 }, height{ 64 };
public:
//Variables
	//Fonts
	static std::shared_ptr<TTF_Font> font28;
	static std::shared_ptr<TTF_Font> font12;

	//Sprite Sheets
	static std::shared_ptr<SDL_Texture> linkSheet, linkSheet2, tileSheet, menuDekus, menuBackground;

	//Menu Assets
	static std::vector<std::shared_ptr<SubTexture>> btn_start;
	
	//Single Textures
	static std::shared_ptr<SubTexture> menuDekuBtn1, menuDekuBtn2;
	static std::shared_ptr<SubTexture> player1, player1_square, player2_square, player3_square;
	static std::shared_ptr<SubTexture> dirt, green, grass, tallGrass;
	static std::shared_ptr<SubTexture> rock, tree;
	static std::shared_ptr<SubTexture> player_face_backward;
	
	//Animation Vectors
	static std::vector<std::shared_ptr<SubTexture>> player_face_forward;
	static const int player_face_forward_frames{ 3 };
	static std::vector<std::shared_ptr<SubTexture>> player_face_left;
	static const int player_face_left_frames{ 3 };
	static std::vector<std::shared_ptr<SubTexture>> player_face_right;
	static const int player_face_right_frames{ 3 };
	static std::vector<std::shared_ptr<SubTexture>> player_down;
	static const int player_down_frames{ 10 };
	static std::vector<std::shared_ptr<SubTexture>> player_up;
	static const int player_up_frames{ 10 };
	static std::vector<std::shared_ptr<SubTexture>> player_left;
	static const int player_left_frames{ 10 };
	static std::vector<std::shared_ptr<SubTexture>> player_right;
	static const int player_right_frames{ 10 };

//Public Functions
	static void init(std::shared_ptr<SDL_Renderer> gRenderer);
};

