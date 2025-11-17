#pragma once
class GameProfile
{
private:
	char* playerName;
	int* matchScores;
	int maxMatches;
	int currentMatches;
public:
	GameProfile(const char* Name, int capacity);
	GameProfile();
	GameProfile(GameProfile& other);
	~GameProfile();
	void setPlayerName(const char* Name);
	void logScore(int score);
	const char* getPlayerName() const;
	void printPlayerInfo() ;
	int findHighestScore();
};

