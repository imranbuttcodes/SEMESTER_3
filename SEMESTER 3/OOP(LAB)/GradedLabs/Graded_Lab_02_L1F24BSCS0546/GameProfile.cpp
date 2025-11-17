#include "GameProfile.h"
#include<iostream>
using namespace std;

GameProfile::GameProfile() {
	playerName = (char*)"Guest";
	maxMatches = 5;
	currentMatches = 0;
	matchScores = new int[maxMatches];
	

}
GameProfile::GameProfile(const char* Name, int capacity) :maxMatches(capacity) {
	int len = 0; 
	for (int i = 0; Name[i] != '\0'; i++) {
		len++;
	}
	playerName = new char[len + 1];
	for (int i = 0; Name[i] != '\0'; i++) {
		playerName[i] = Name[i];
	}
	playerName[len] = '\0';
	matchScores = new int[maxMatches];
	for (int i = 0; i < maxMatches; i++) {
		matchScores[i] = 0;
	}
	currentMatches = 0;
}
GameProfile::GameProfile(GameProfile& other):maxMatches(other.maxMatches) {
	int len = 0;
	for (int i = 0; other.playerName[i] != '\0'; i++) {
		len++;
	}
	playerName = new char[len + 1];
	for (int i = 0; other.playerName[i] != '\0'; i++) {
		playerName[i] = other.playerName[i];
	}
	playerName[len] = '\0';
	len = 0;
	matchScores = new int[maxMatches];
	for (int i = 0; i < maxMatches; i++) {
		matchScores[i] = other.matchScores[i];
	}
	currentMatches = other.currentMatches;
}
void GameProfile::setPlayerName(const char* Name) {
	int len = 0;
	for (int i = 0; Name[i] != '\0'; i++) {
		len++;
	}
	if (playerName) {
		delete[] playerName;
	}
	playerName = new char[len + 1];
	for (int i = 0; Name[i] != '\0'; i++) {
		playerName[i] = Name[i];
	}
}
const char* GameProfile::getPlayerName() const {
	return playerName;
}

int GameProfile::findHighestScore() {
	int highestScore = 0;
	if (matchScores[0] == 0)			return 0;
	for (int i = 0; i < maxMatches; i++) {
		if (matchScores[i] > highestScore) {
			highestScore = matchScores[i];
		}
	}
	return highestScore;

}

void GameProfile::printPlayerInfo()  {
	
	cout << "Player Name: " << playerName << endl;
	int totalScore = 0;
	cout << "Scores: ";
	for (int i = 0; i < maxMatches; i++) {
		cout << matchScores[i] << " ";
		totalScore += matchScores[i];
	}
	cout << endl;
	cout << "Total Score: " << totalScore << endl;
	cout << "Higest score: " << findHighestScore() << endl;
}

GameProfile::~GameProfile() {
	delete[] playerName;
	delete[] matchScores;
}


void GameProfile::logScore(int score) {
	static int count = 0;
	if (count > maxMatches) {
		cout << "Can't assign more scores";
	}
	matchScores[count] = score;
	count++;
}