#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include <memory>
#include <vector>
#include "SubTexture.h"
#include "SpriteSheet.h"
#include "Assets.h"
#include "ImageLoader.h"
#include "FontLoader.h"
#include "Tile.h"

//Fonts

std::shared_ptr<TTF_Font> Assets::font28{ nullptr };
std::shared_ptr<TTF_Font> Assets::font12{ nullptr };

std::shared_ptr<SDL_Texture> Assets::linkSheet{nullptr};
std::shared_ptr<SDL_Texture> Assets::linkSheet2{nullptr};
std::shared_ptr<SDL_Texture> Assets::tileSheet{nullptr};
std::shared_ptr<SDL_Texture> Assets::menuDekus{ nullptr };
std::shared_ptr<SubTexture> Assets::player1{ nullptr };
std::shared_ptr<SubTexture> Assets::player1_square{ nullptr };
std::shared_ptr<SubTexture> Assets::player2_square{ nullptr };
std::shared_ptr<SubTexture> Assets::player3_square{ nullptr };
std::shared_ptr<SubTexture> Assets::dirt{ nullptr };
std::shared_ptr<SubTexture> Assets::green{ nullptr };
std::shared_ptr<SubTexture> Assets::rock{ nullptr };
std::shared_ptr<SubTexture> Assets::tree{ nullptr };
std::shared_ptr<SubTexture> Assets::grass{ nullptr };
std::shared_ptr<SubTexture> Assets::tallGrass{ nullptr };
std::shared_ptr<SubTexture> Assets::player_face_backward{nullptr};

//Menu assets
std::shared_ptr<SDL_Texture> Assets::menuBackground{ nullptr };
std::vector<std::shared_ptr<SubTexture>> Assets::btn_start{};
std::shared_ptr<SubTexture> Assets::menuDekuBtn1{ nullptr }, Assets::menuDekuBtn2{ nullptr };

std::vector<std::shared_ptr<SubTexture>> Assets::player_face_forward{ Assets::player_face_forward_frames };
std::vector<std::shared_ptr<SubTexture>> Assets::player_face_left{ Assets::player_face_left_frames };
std::vector<std::shared_ptr<SubTexture>> Assets::player_face_right{ Assets::player_face_right_frames };
std::vector<std::shared_ptr<SubTexture>> Assets::player_up{ Assets::player_up_frames };
std::vector<std::shared_ptr<SubTexture>> Assets::player_down{Assets::player_down_frames};
std::vector<std::shared_ptr<SubTexture>> Assets::player_left{ Assets::player_left_frames };
std::vector<std::shared_ptr<SubTexture>> Assets::player_right{ Assets::player_right_frames };


void Assets::init(std::shared_ptr<SDL_Renderer> gRenderer)
{
	font28 = FontLoader::loadFont("res/fonts/slkscr.ttf", 28);
	font12 = FontLoader::loadFont("res/fonts/slkscre.ttf", 12);
	
	linkSheet = ImageLoader::loadImage(gRenderer, "res/textures/imported/link all/linksprites.png");
	linkSheet2 = ImageLoader::loadImage(gRenderer, "res/textures/LinkFrontSleepCompactNoBackground_squared.png");
	tileSheet = ImageLoader::loadImage(gRenderer, "res/textures/imported/tiles sheet.png");
	menuDekus = ImageLoader::loadImage(gRenderer, "res/textures/imported/menu/DekuMenuSprites.png");

	menuBackground = ImageLoader::loadImage(gRenderer, "res/textures/imported/menu/triforce.jpg");
	menuDekuBtn1 = std::shared_ptr<SubTexture>(new SubTexture{ menuDekus, 0, 0, 250, 200 });
	menuDekuBtn2 = std::shared_ptr<SubTexture>(new SubTexture{ menuDekus, 250, 0, 250, 200 });
	btn_start.push_back(menuDekuBtn1);
	btn_start.push_back(menuDekuBtn2);

	player1_square = std::shared_ptr<SubTexture>(new SubTexture{ linkSheet2, 0, 0, width, height });
	player2_square = std::shared_ptr<SubTexture>(new SubTexture{ linkSheet2, width, 0, width, height });
	player3_square = std::shared_ptr<SubTexture>(new SubTexture{ linkSheet2, width * 2, 0, width, height });

	green = std::shared_ptr<SubTexture>(new SubTexture{ tileSheet, 0, 0, 36, 36 });
	dirt = std::shared_ptr<SubTexture>(new SubTexture{ tileSheet, 36, 0, 36, 36 });
	grass = std::shared_ptr<SubTexture>(new SubTexture{ tileSheet, 142, 0, 48, 48 });
	tallGrass = std::shared_ptr<SubTexture>(new SubTexture{ tileSheet, 190, 0, 48, 48 });

	rock = std::shared_ptr<SubTexture>(new SubTexture{ tileSheet, 72, 0, 28, 27 });
	tree = std::shared_ptr<SubTexture>(new SubTexture{ tileSheet, 100, 0, 42, 61 });

	player_face_backward = std::shared_ptr<SubTexture>(new SubTexture{ linkSheet, 0, height * 2, width, height });

	//populating player_face_forward vector
	for (int i = 0; i < player_face_forward_frames; i++) {
		player_face_forward[i] = std::shared_ptr<SubTexture>(new SubTexture{linkSheet, width*i, height*0, width, height});
	}

	//populating player_face_left vector
	for (int i = 0; i < player_face_left_frames; i++) {
		player_face_left[i] = std::shared_ptr<SubTexture>(new SubTexture{ linkSheet, width * i, height * 1, width, height });
	}

	//populating player_face_right vector
	for (int i = 0; i < player_face_right_frames; i++) {
		player_face_right[i] = std::shared_ptr<SubTexture>(new SubTexture{ linkSheet, width * i, height * 3, width, height });
	}

	//populating player_up vector
	for (int i = 0; i < player_up_frames; i++) {
		player_up[i] = std::shared_ptr<SubTexture>(new SubTexture{ linkSheet, width * i, height * 6, width, height });
	}

	//populating player_down vector
	for (int i = 0; i < player_down_frames; i++) {
		player_down[i] = std::shared_ptr<SubTexture>(new SubTexture{ linkSheet, width*i,height*4,width,height });
	}

	//populating player_left vector
	for (int i = 0; i < player_left_frames; i++) {
		player_left[i] = std::shared_ptr<SubTexture>(new SubTexture{ linkSheet, width * i, height * 5, width, height });
	}

	//populating player_right vector
	for (int i = 0; i < player_right_frames; i++) {
		player_right[i] = std::shared_ptr<SubTexture>(new SubTexture{ linkSheet, width * i,height * 7,width,height });
	}

	player1 = player_face_forward[0];

	Tile::init();
}
