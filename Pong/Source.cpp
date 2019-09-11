//Ruffo Maximiliano
#include "raylib.h"
int main(void)
{
	// Initialization
	//--------------------------------------------------------------------------------------
	SetTargetFPS(60);
	const int screenWidth = 800;
	const int screenHeight = 450;
	enum PlayerTouched
	{
		nothing, p1, p2
	}BallonColisionSelector;
	enum MenuStage
	{
		Menu,Game,EndGame,WaitMenu,WaitGame
	}MenuSelector;
	enum ColorSelected
	{
		Red, Blue, Orange, Violet
	}ColorP1, ColorP2;
	ColorP1 = Blue;
	ColorP2 = Red;
	MenuSelector = Menu;
	InitWindow(screenWidth, screenHeight, "PONG - By Ruffo Maximiliano");
	const int playerHeightSize = 100;
	const int playerWidthSize = 20;
	const float PlayersSpeed = 5.2f;
	const float normalSpeedBallon = 9.0f;
	const int RadiusBallon = 15;
	Rectangle Player1;
	Rectangle Player2;
	Rectangle MenuPlayer1;
	Rectangle MenuPlayer2;
	Player1.height = playerHeightSize;
	Player2.height = playerHeightSize;
	Player1.width = playerWidthSize;
	Player2.width = playerWidthSize;
	MenuPlayer1.height = playerHeightSize;
	MenuPlayer2.height = playerHeightSize;
	MenuPlayer1.width = playerWidthSize;
	MenuPlayer2.width = playerWidthSize;
	MenuPlayer1.y = ((float)screenHeight / 2) - ((float)Player1.height / 2);
	MenuPlayer2.y = ((float)screenHeight / 2) - ((float)Player2.height / 2);
	Player1.x = 3;
	Player2.x = screenWidth - Player2.width - 3;
	MenuPlayer1.x = 3;
	MenuPlayer2.x = screenWidth - Player2.width - 3;
	int GlobalScorePlayer1 = 0;
	int GlobalScorePlayer2 = 0;
	int ScorePlayer1 = 0;
	int ScorePlayer2 = 0;
	const int maxScoreSet = 7;
	Color PlayColorMenu;
	Color BackColorMenu;
	Color Player1Color;
	Color Player2Color;
	Player1Color = BLUE;
	Player2Color = RED;
	BackColorMenu = WHITE;
	PlayColorMenu = WHITE;
	Vector2 ballPosition;
	Vector2 VelBallon;
	//images an music
	Image Grassground = LoadImage("green-grass-background_1373-334.jpg");
	Image PlayersImage = LoadImage("glasses.png");
	Image PlayersImage2 = LoadImage("glasses2.png");
	Image BallImage = LoadImage("ball.png");
	ImageResize(&Grassground, screenWidth, screenHeight);
	Texture2D BackGround = LoadTextureFromImage(Grassground);
	UnloadImage(Grassground);
	ImageResize(&PlayersImage, Player1.width, Player1.height);
	Texture2D playerTexture = LoadTextureFromImage(PlayersImage);
	UnloadImage(PlayersImage);
	ImageResize(&PlayersImage2, Player2.width, Player2.height);
	Texture2D playerTexture2 = LoadTextureFromImage(PlayersImage2);
	UnloadImage(PlayersImage2);
	ImageResize(&BallImage, RadiusBallon*2, RadiusBallon*2);
	Texture2D BallTexture = LoadTextureFromImage(BallImage);
	UnloadImage(BallImage);
	
	InitAudioDevice();
	Music backMusic = LoadMusicStream("waterflame-endgame.ogg");
	Sound glassBroken = LoadSound("glass-break-song.mp3");
	bool musicStreamIsPlay = false;
	//-----------------------------------------------------------
	//menu loop
	while (!WindowShouldClose() &&
		(MenuSelector == Menu || MenuSelector == WaitMenu || MenuSelector == WaitGame))
	{
		if (MenuSelector != WaitGame)
		{
			if (IsKeyDown(KEY_W) && MenuPlayer1.y > 85)
			{
				MenuPlayer1.y -= PlayersSpeed;
			}
			if (IsKeyDown(KEY_S) && MenuPlayer1.y + MenuPlayer1.height < screenHeight - 20)
			{
				MenuPlayer1.y += PlayersSpeed;
			}
			if (IsKeyDown(KEY_UP) && MenuPlayer2.y > 85)
			{
				MenuPlayer2.y -= PlayersSpeed;
			}
			if (IsKeyDown(KEY_DOWN) && MenuPlayer2.y + MenuPlayer2.height < screenHeight - 20)
			{
				MenuPlayer2.y += PlayersSpeed;
			}
			if (MenuPlayer1.y < 130 && ColorP2 != Red)
			{
				Player1Color = RED;
				ColorP1 = Red;
			}
			if (MenuPlayer1.y > 160 && MenuPlayer1.y < 195 && ColorP2 != Blue)
			{
				Player1Color = BLUE;
				ColorP1 = Blue;
			}
			if (MenuPlayer1.y > 230 && MenuPlayer1.y < 250 && ColorP2 != Orange)
			{
				Player1Color = ORANGE;
				ColorP1 = Orange;
			}
			if (MenuPlayer1.y > 285 && ColorP2 != Violet)
			{
				Player1Color = VIOLET;
				ColorP1 = Violet;
			}
			//player 2
			if (MenuPlayer2.y < 130 && ColorP1 != Red)
			{
				Player2Color = RED;
				ColorP2 = Red;
			}
			if (MenuPlayer2.y > 160 && MenuPlayer2.y < 195 && ColorP1 != Blue)
			{
				Player2Color = BLUE;
				ColorP2 = Blue;
			}
			if (MenuPlayer2.y > 230 && MenuPlayer2.y < 250 && ColorP1 != Orange)
			{
				Player2Color = ORANGE;
				ColorP2 = Orange;
			}
			if (MenuPlayer2.y > 285 && ColorP1 != Violet)
			{
				Player2Color = VIOLET;
				ColorP2 = Violet;
			}
			if (GetMouseY() < screenHeight - 10 && GetMouseY() > screenHeight - 85 &&
				GetMouseX() > (screenWidth / 2) - 85 && GetMouseX() < (screenWidth / 2) + 50)
			{

				PlayColorMenu = YELLOW;
				if (IsMouseButtonReleased(0) && MenuSelector != WaitMenu)
				{
					MenuSelector = Game;
				}

			}
			else
			{
				PlayColorMenu = WHITE;
			}
			BeginDrawing();
			ClearBackground(GRAY);
			DrawText("PONG", (screenWidth / 2) - 70, 10, 50, WHITE);
			DrawText("Use W and S to move Player 1", 10, 70, 10, WHITE);
			DrawText("Use Up Arrow and Down Arrow to move Player 2", (screenWidth / 1.46), 70, 10, WHITE);
			DrawRectangle(screenWidth / 3, 110, 250, 60, RED);
			DrawRectangle(screenWidth / 3, 170, 250, 60, BLUE);
			DrawRectangle(screenWidth / 3, 230, 250, 60, ORANGE);
			DrawRectangle(screenWidth / 3, 290, 250, 60, VIOLET);
			DrawTexture(playerTexture, MenuPlayer1.x, MenuPlayer1.y, Player1Color);
			DrawTexture(playerTexture2, MenuPlayer2.x, MenuPlayer2.y, Player2Color);
			DrawText("Play!", (screenWidth / 2) - 70, screenHeight - 75, 50, PlayColorMenu);
			DrawText(FormatText("Wins Player1: %01i", GlobalScorePlayer1), 9, screenHeight - 20, 17, RAYWHITE);
			DrawText(FormatText("Wins Player2: %01i", GlobalScorePlayer2), screenWidth - 170, screenHeight - 20, 17, RAYWHITE);
			EndDrawing();
			if (MenuSelector == WaitMenu)
			{
				MenuSelector = Menu;
			}
		}
		else
		{
			MenuSelector = Game;
		}
		if (MenuSelector == Game)
		{
			VelBallon = (Vector2) { 0, 0 };
			BallonColisionSelector = nothing;
			switch (GetRandomValue(0, 1))
			{
			case 0:
				VelBallon.x = normalSpeedBallon;
				break;
			case 1:
				VelBallon.x = normalSpeedBallon * -1;
				break;
			}
			ballPosition = (Vector2) { (float)screenWidth / 2, (float)screenHeight / 2 };
			Player1.y = ((float)screenHeight / 2) - ((float)Player1.height / 2);
			Player2.y = ((float)screenHeight / 2) - ((float)Player2.height / 2);
			ScorePlayer1 = 0;
			ScorePlayer2 = 0;
			PlayMusicStream(backMusic);
			musicStreamIsPlay = true;
		}
		// Main game loop
		while (maxScoreSet > ScorePlayer1 && maxScoreSet > ScorePlayer2 && !WindowShouldClose() && MenuSelector == Game)
		{
			UpdateMusicStream(backMusic);
			// Update
			//----------------------------------------------------------------------------------
			if (IsKeyDown(KEY_W) && Player1.y > 0)
			{
				Player1.y -= PlayersSpeed;
			}
			if (IsKeyDown(KEY_S) && Player1.y + Player1.height < screenHeight)
			{
				Player1.y += PlayersSpeed;
			}
			if (IsKeyDown(KEY_UP) && Player2.y > 0)
			{
				Player2.y -= PlayersSpeed;
			}
			if (IsKeyDown(KEY_DOWN) && Player2.y + Player2.height < screenHeight)
			{
				Player2.y += PlayersSpeed;
			}

			ballPosition.x += VelBallon.x;
			ballPosition.y += VelBallon.y;
			//----------------------------------------------------------------------------------
			if (CheckCollisionCircleRec(ballPosition, RadiusBallon, Player1) &&
				BallonColisionSelector != p1)
			{
				VelBallon.x = VelBallon.x * -1;
				if (!IsSoundPlaying)
				{
					PlaySound(glassBroken);
				}
				if (Player1.y + (Player1.height / 2) > ballPosition.y)
				{
					VelBallon.y = -PlayersSpeed;
				}
				if (Player1.y + (Player1.height / 2) < ballPosition.y)
				{
					VelBallon.y = PlayersSpeed;
				}
				if (Player1.y + (Player1.height / 2) - (Player1.height / 4) > ballPosition.y)
				{
					VelBallon.y = -PlayersSpeed -4;
				}
				if (Player1.y + (Player1.height / 2) + (Player1.height / 4) < ballPosition.y)
				{
					VelBallon.y = PlayersSpeed + 4;
				}
				BallonColisionSelector = p1;
			}
			if (CheckCollisionCircleRec(ballPosition, RadiusBallon, Player2) &&
				BallonColisionSelector != p2)
			{
				VelBallon.x = VelBallon.x * -1;
				PlaySound(glassBroken);
				if (Player2.y + (Player2.height / 2) > ballPosition.y)
				{
					VelBallon.y = -PlayersSpeed;
				}
				if (Player2.y + (Player2.height / 2) < ballPosition.y)
				{
					VelBallon.y = PlayersSpeed;
				}
				if (Player2.y + (Player2.height / 2) - (Player2.height / 4) > ballPosition.y)
				{
					VelBallon.y = -PlayersSpeed - 4;
				}
				if (Player2.y + (Player2.height / 2) + (Player2.height / 4) < ballPosition.y)
				{
					VelBallon.y = PlayersSpeed + 4;
				}
				BallonColisionSelector = p2;
			}
			if (ballPosition.y - RadiusBallon / 2 < 0)
				VelBallon.y = VelBallon.y * -1;
			if (ballPosition.y + RadiusBallon > screenHeight)
				VelBallon.y = VelBallon.y * -1;

			if (ballPosition.x - 75 > screenWidth || ballPosition.x + 75 < 0)
			{
				if (ballPosition.x + RadiusBallon > screenWidth)
				{
					ScorePlayer1++;
				}
				else
				{
					ScorePlayer2++;
				}
				ballPosition.x = screenWidth / 2;
				ballPosition.y = screenHeight / 2;
				switch (GetRandomValue(0, 1))
				{
				case 0:
					VelBallon.x = normalSpeedBallon;
					break;
				case 1:
					VelBallon.x = normalSpeedBallon * -1;
					break;
				}
				VelBallon.y = 0;
				BallonColisionSelector = nothing;
			}
			// Draw
			//----------------------------------------------------------------------------------
			BeginDrawing();

			ClearBackground(BLACK);
			DrawTexture(BackGround, 0, 0, WHITE);
			DrawText(FormatText("Player1: %01i", ScorePlayer1), (screenWidth /2) - 250, 13, 17, BLACK);
			DrawText(FormatText("Player2: %01i", ScorePlayer2), (screenWidth / 2) + 170, 13, 17, BLACK);
			DrawTexture(playerTexture, Player1.x, Player1.y, Player1Color);
			DrawTexture(playerTexture2, Player2.x, Player2.y, Player2Color);
			switch (BallonColisionSelector)
			{
			case nothing:
				DrawTexture(BallTexture,ballPosition.x,ballPosition.y,WHITE);
				break;
			case p1:
				DrawTexture(BallTexture, ballPosition.x, ballPosition.y, Player1Color);
				break;
			case p2:
				DrawTexture(BallTexture, ballPosition.x, ballPosition.y, Player2Color);
				break;
			}

			EndDrawing();
			//----------------------------------------------------------------------------------
			if (maxScoreSet <= ScorePlayer1)
			{
				GlobalScorePlayer1++;
				MenuSelector = EndGame;
			}
			if (maxScoreSet <= ScorePlayer2)
			{
				GlobalScorePlayer2++;
				MenuSelector = EndGame;
			}

			while (!WindowShouldClose() && MenuSelector == EndGame)
			{
				BeginDrawing();
				if (musicStreamIsPlay)
				{
					StopMusicStream(backMusic);
					UnloadMusicStream(backMusic);
					musicStreamIsPlay = false;
				}
				ClearBackground(GRAY);
				if (maxScoreSet <= ScorePlayer1)
					DrawText("PLAYER 1 WINS!", (screenWidth / 4), screenHeight / 4, 50, WHITE);
				if (maxScoreSet <= ScorePlayer2)
					DrawText("PLAYER 2 WINS!", (screenWidth / 4), screenHeight / 4, 50, WHITE);
				DrawText(FormatText("Wins Player1: %01i", GlobalScorePlayer1), 9, screenHeight - 20, 17, RAYWHITE);
				DrawText(FormatText("Wins Player2: %01i", GlobalScorePlayer2), screenWidth - 170, screenHeight - 20, 17, RAYWHITE);
				DrawText("Menu!", (screenWidth / 2) + 60, screenHeight - 75, 50, BackColorMenu);
				DrawText("Play!", (screenWidth / 2) - 200, screenHeight - 75, 50, PlayColorMenu);
				BackColorMenu = WHITE;
				PlayColorMenu = WHITE;
				if (GetMouseY() < screenHeight - 10 && GetMouseY() > screenHeight - 85 &&
					GetMouseX() > (screenWidth / 2) + 55 && GetMouseX() < (screenWidth / 2) + 195)
				{

					BackColorMenu = YELLOW;
					if (IsMouseButtonReleased(0))
					{
						MenuSelector = WaitMenu;
					}

				}
				if (GetMouseY() < screenHeight - 10 && GetMouseY() > screenHeight - 85 &&
					GetMouseX() > (screenWidth / 2) - 205 && GetMouseX() < (screenWidth / 2) - 82)
				{

					PlayColorMenu = YELLOW;
					if (IsMouseButtonReleased(0))
					{
						MenuSelector = WaitGame;
					}

				}
				EndDrawing();
			}
		}
	}
	// De-Initialization
	CloseAudioDevice();
	//--------------------------------------------------------------------------------------
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------
	
	return 0;
}